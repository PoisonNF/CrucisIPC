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

#include "slidepage.h"
#include "scenemodifier.h"
#include "customWidgets.h"
#include "scenemodifier.h"

#if (QT_VERSION > QT_VERSION_CHECK(6,3,0))
#include <QFileDialog>
#endif

class MotionControlWidget : public QWidget
{
    Q_OBJECT
private:
    enum MODE{TEST_MV_CTR, TEST_BAL_CTR, TEST_ACT_CTR, TRAVEL_MV_CTR, TRAVEL_BAL_CTR, TRAVEL_ACT_CTR};
    int modeKind_;

    SlidePage *settings;
    Qt3DCore::QEntity *mRootEntity;
    Qt3DCore::QEntity *lightEntity;
    Qt3DRender::QPointLight *light;

    //For display

    QVBoxLayout *mainLayout;
    QSplitter *splitter_1;
    QSplitter *splitter_2;
    QSplitter *splitter_3;
    QSplitter *splitter_4;

    QLabel *PIDTitle;
    QLabel *RM3100Title;
    QLabel *logTitle;
    QLabel *infoTitle;

    QLabel *RM3100DataNO1 = new QLabel(this);   //RM3100 1号数据
    QLabel *RM3100DataNO2 = new QLabel(this);   //RM3100 2号数据
    QLabel *RM3100DataNO3 = new QLabel(this);   //RM3100 3号数据
    QLabel *RM3100DataNO4 = new QLabel(this);   //RM3100 4号数据

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

    QWidget *PIDWidget = nullptr;
    QWidget *RM3100Widget = nullptr;
    QWidget *PropulsionSysWidget = nullptr;
    QWidget *logWidget = nullptr;
    QWidget *infoWidget = nullptr;

    QPlainTextEdit *logPTE;

    void Init();
    void SaveToFile(const QString &path);
    void TestMvSetting(int r);
    void DataSortConnect(); //数据分类链接函数

public:
    explicit MotionControlWidget(int radius, int modeKind, QWidget *parent = nullptr);
    MotionControlWidget(QTextStream &ts, int radius, QWidget *parent = nullptr);

    SlidePage *settingPage(){return settings;}
    Qt3DRender::QPointLight *Light(){return light;}

    Qt3DExtras::Qt3DWindow *view;
    QWidget *container = nullptr;
    SceneModifier *modifier = nullptr;

    textButton *SendBTN;
    textButton *ClearBTN;

    textInputItem *logTII;

    textInputItem *PID_P_TII;   //PID P值输入框
    textInputItem *PID_I_TII;   //PID I值输入框
    textInputItem *PID_D_TII;   //PID D值输入框

    textButton *SetPIDBTN;  //设置PID值

signals:
    void SendDataSignal();
    void StartDataSort(QStringList ProcessedData);
    void AttitudeChange(QString pitch, QString yaw, QString roll);

public slots:
    void DataDisplayPTE(QString serialBuf);

private slots:
    void PropulsionSysDataSort(QStringList ProcessedData);  //动力系统数据分拣槽函数

};

#endif // DATADISPLAYWIDGET_H
