#ifndef SERIALDATAANALYZE_H
#define SERIALDATAANALYZE_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <QDebug>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "./Log/log.h"

//数据类型占用空间
#define FLOAT_SIZE                  sizeof(float)
#define UINT16_T_SIZE               sizeof(unsigned short)
#define UINT8_T_SIZE                sizeof(unsigned char)

//各种数据类型在数据帧的中的起始位置
#define DATA_BASE                   4
#define GRADIENTMAGNET_BASE         DATA_BASE
#define THRUSTER_BASE               (GRADIENTMAGNET_BASE + 4 * FLOAT_SIZE)
#define SERVO_BASE                  (THRUSTER_BASE + 4 * UINT16_T_SIZE)
#define GPS_BASE                    (SERVO_BASE + 4 * UINT16_T_SIZE)
#define DEPTH_BASE                  (GPS_BASE + 3 * UINT8_T_SIZE + 2 * FLOAT_SIZE)
#define DATE_BASE                   (DEPTH_BASE + UINT16_T_SIZE)
#define ANGLE_BASE                  (DATE_BASE + 6 * UINT8_T_SIZE)
#define MAG_BASE                    (ANGLE_BASE + 3 * FLOAT_SIZE)

class SerialDataAnalyze : public QObject
{
    Q_OBJECT
public:
    explicit SerialDataAnalyze(QObject *parent = nullptr);

    void SDAworking(QByteArray serialBuf);
private:

signals: 
    void sigLogDataDisplay(QByteArray serialBuf);
    void sigAngleDataAnalyze(QByteArray ProcessedData);
    void sigDepthDataAnalyze(QByteArray ProcessedData);
    void sigGPSDataAnalyze(QByteArray ProcessedData);
    void sigThrusterDataAnalyze(QByteArray ProcessedData);

};

#endif // SERIALDATAANALYZE_H
