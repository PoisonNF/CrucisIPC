#ifndef SERIALREADDATA_H
#define SERIALREADDATA_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <QDebug>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "./log/log.h"

class SerialReadData : public QObject
{
    Q_OBJECT
public:
    explicit SerialReadData(QSerialPort *serial = nullptr,QObject *parent = nullptr);

    void SRDworking();    //线程任务函数
private:
    QSerialPort *m_pserial;
    QByteArray serialBuf;  //储存接收到的数据
signals:
    void sigDataSort(QByteArray serialBuf);
};

#endif // SERIALREADDATA_H
