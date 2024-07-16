#include "serialdataanalyze.h"

SerialDataAnalyze::SerialDataAnalyze(QObject *parent)
    : QObject{parent}
{
    Q_UNUSED(parent);
}

//数据分析线程任务函数
void SerialDataAnalyze::SDAworking(QByteArray serialBuf)
{
    qDebug() << serialBuf;

    //根据帧头解析数据，并发送对应信号，显示在界面上
    if(serialBuf.contains("@DUP") && serialBuf.right(1) == "$")
    {
        qDebug() << "STM32数据";
        emit sigAngleDataAnalyze(serialBuf);
        emit sigDepthDataAnalyze(serialBuf);
        emit sigGPSDataAnalyze(serialBuf);
        emit sigThrusterDataAnalyze(serialBuf);
    }
    else
    {
        //如果帧头为ASCII中字符部分则是普通调试信息
        emit sigLogDataDisplay(serialBuf);
    }
}


