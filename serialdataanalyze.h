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
