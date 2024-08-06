#ifndef DATADISPLAYWIDGET_H
#define DATADISPLAYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QSplitter>
#include <Qt3DCore>
#include <Qt3DExtras>
#include <Qt3DRender>
#include <QDebug>
#include <QPainter>
#include <QLineEdit>
#include <QPaintEvent>
#include <QTimer>
#include <QFont>
#include <QtGui/QScreen>
#include <QGuiApplication>
#include <QPlainTextEdit>

#include "./frame/slidepage.h"
#include "./frame/customWidgets.h"
#include "serialdataanalyze.h"

#if (QT_VERSION > QT_VERSION_CHECK(6,3,0))
#include <QFileDialog>
#endif

class DataDisplayWidget : public QWidget
{
    Q_OBJECT
private:
    enum MODE{TEST_MV_CTR, TEST_BAL_CTR, TEST_ACT_CTR, TRAVEL_MV_CTR, TRAVEL_BAL_CTR, TRAVEL_ACT_CTR};

    SlidePage *settings;
    Qt3DCore::QEntity *mRootEntity;
    Qt3DCore::QEntity *lightEntity;
    Qt3DRender::QPointLight *light;

    QFont TitleFont = QFont("Corbel", 20);

    QVBoxLayout *mainLayout;
    QSplitter *splitter_1;
    QSplitter *splitter_2;
    QSplitter *splitter_3;
    QSplitter *splitter_4;

    QLabel *JY901STitle;
    QLabel *FluxgateTitle;
    QLabel *logTitle;
    QLabel *infoTitle;

    QLabel *JY901SDataAcc = new QLabel(this);    //显示JY901S中加速度数据
    QLabel *JY901SDataGyro = new QLabel(this);   //显示JY901S中角速度数据
    QLabel *JY901SDataAngle = new QLabel(this);  //显示JY901S中欧拉角数据
    QLabel *JY901SDataMag = new QLabel(this);    //显示JY901S中磁场数据

    QLabel *FluxgateDataNO1 = new QLabel(this);   //Fluxgate 1号数据
    QLabel *FluxgateDataNO2 = new QLabel(this);   //Fluxgate 2号数据
    QLabel *FluxgateDataNO3 = new QLabel(this);   //Fluxgate 3号数据
    QLabel *FluxgateDataNO4 = new QLabel(this);   //Fluxgate 4号数据

    QLabel *ThrusterData1 = new QLabel(this);   //1号推进器的数据
    QLabel *ThrusterData2 = new QLabel(this);   //2号推进器的数据
    QLabel *ThrusterData3 = new QLabel(this);   //3号推进器的数据
    QLabel *ThrusterData4 = new QLabel(this);   //4号推进器的数据

    QLabel *ServoData1 = new QLabel(this);  //1号舵机的数据
    QLabel *ServoData2 = new QLabel(this);  //2号舵机的数据
    QLabel *ServoData3 = new QLabel(this);  //3号舵机的数据
    QLabel *ServoData4 = new QLabel(this);  //4号舵机的数据

    QString modeName;
    QString ctrDescrip;

    QWidget *JY901SWidget = nullptr;
    QWidget *FluxgateWidget = nullptr;
    QWidget *PropulsionSysWidget = nullptr;
    QWidget *logWidget = nullptr;
    QWidget *infoWidget = nullptr;

    //log
    QPlainTextEdit *logPTE;
    QTextCursor TextCursor;

    //Info
    QLabel *AttitudeDataInfo = new QLabel(this);    //Info姿态数据
    QLabel *DepthDataInfo = new QLabel(this);       //Info深度数据
    QLabel *GPSDataInfo = new QLabel(this);         //InfoGPS数据
    QLabel *JoystickAxisDataInfo = new QLabel(this);        //Info手柄坐标数据
    QLabel *JoystickButtonDataInfo = new QLabel(this);        //Info手柄按键数据

    QSizePolicy sizepolicy; //布局器
    QFont titleFont;        //标题字体

    void Init();
    void InitLayout();      //初始化总体布局
    void InitJY901SWidget();   //初始化JY901S窗口
    void InitFluxgateWidget();   //初始化磁通门窗口
    void InitPropulsionSysWidget(); //初始化动力系统窗口
    void InitLogWidget();           //初始化串口log窗口
    void InitInfoWidget();          //初始化信息窗口
    void SaveToFile(const QString &path);
    void ModeSelectPage(int r);  //模式选择页

public:
    explicit DataDisplayWidget(int radius, QWidget *parent = nullptr);
    DataDisplayWidget(QTextStream &ts, int radius, QWidget *parent = nullptr);

    SlidePage *settingPage(){return settings;}
    Qt3DRender::QPointLight *Light(){return light;}

    Qt3DExtras::Qt3DWindow *view;
    QWidget *container = nullptr;

    textButton *SendBTN;    //串口发送按钮
    textButton *ClearBTN;   //串口清空按钮

    textInputItem *logTII;  //串口发送栏

signals:
    void sigLogDataSend();  //发送数据信号往主窗口

public slots:
    void slotLogDataDisplay(QByteArray serialBuf);
    void slotDepthDataDisplay(QByteArray ProcessedData);
    void slotAngleDataDisplay(QByteArray ProcessedData);     //JY901S数据分拣槽函数
    void slotFluxgateDataDisplay(QByteArray ProcessedData);  //磁通门数据分拣槽函数
    void slotThrusterDataDisplay(QByteArray ProcessedData);  //动力系统数据分拣槽函数
    void slotGPSDataDisplay(QByteArray ProcessedData);

};

#endif // DATADISPLAYWIDGET_H
