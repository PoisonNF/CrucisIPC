#include "serialreaddata.h"

SerialReadData::SerialReadData(QSerialPort *serial,QObject *parent)
    : QObject{parent}
{
    Q_UNUSED(parent);
    qDebug() << "构造serial" <<serial;
    m_pserial = serial;
    qDebug() << "串口复制" << m_pserial;
}

void SerialReadData::SRDworking()
{
    while(m_pserial->waitForReadyRead(FRAMEEND_BASE + 1)) {
        serialBuf += m_pserial->readAll();
    }

    //LOG_INFO((char *)"串口收到数据%s",serialBuf.toStdString());

    //发射信号给数据分拣线程
    emit sigDataSort(serialBuf);
    //qDebug() << serialBuf.toHex();
    serialBuf.clear();
}
