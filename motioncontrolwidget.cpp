#include "MotionControlWidget.h"

MotionControlWidget::MotionControlWidget(int radius, int modeKind, QWidget *parent) :
    QWidget(parent), modeKind_(modeKind)
{
    /* create canvas */

    mainLayout = new QVBoxLayout(this);
    mainLayout -> setContentsMargins(0, 0, 0, 0);
    this->setLayout(mainLayout);
    splitter_1 = new QSplitter(this);
    splitter_1 -> setContentsMargins(0, 0, 0, 0);
    mainLayout -> addWidget(splitter_1);

    this->setFocusPolicy(Qt::ClickFocus);


    TestMvSetting(radius);
}

MotionControlWidget::MotionControlWidget(QTextStream &ts, int radius, QWidget *parent) :
    QWidget(parent)
{

    /* create canvas */
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mainLayout);

    this->setFocusPolicy(Qt::ClickFocus);

}

//在数据显示界面的设置栏this->parentWidget());
void MotionControlWidget::TestMvSetting(int radius){
    /* create settings page */
    modeName = "测试模式";
    ctrDescrip = "运动控制";
    settings = new SlidePage(radius, "默认设置", this->parentWidget());
    QWidget *whiteSpace = new QWidget(this);
    whiteSpace->setFixedHeight(30);
    textInputItem *rename = new textInputItem("当前模式", this);
    rename->setValue(modeName);
    textInputItem *redesc = new textInputItem("当前控制", this);
    redesc->setValue(ctrDescrip);
    QWidget *whiteSpace_2 = new QWidget(this);
    whiteSpace_2->setFixedHeight(30);
    textButton *saveBtn = new textButton("Save to file", this);
//    connect(saveBtn, &textButton::clicked, this, [=](){
//        QString savePath = QFileDialog::getSaveFileName(this, tr("Save map"), " ", tr("Map file(*.map)"));
//        if(!savePath.isEmpty())
//            SaveToFile(savePath);
//    });
    settings->AddContent(saveBtn);
    settings->AddContent(whiteSpace_2);
    settings->AddContent(whiteSpace);
    settings->AddContent(redesc);
    settings->AddContent(rename);
    settings->show();
    /* create settings page */

    /* create widgets */
    QTimer *delay = new QTimer(this);
    connect(delay, &QTimer::timeout, this, [=](){Init();});
    delay->setSingleShot(true);
    delay->start(10);
}

void MotionControlWidget::Init(){
//layout

    //1为最大的布局器，2，3，4分别为垂直布局器，对应左中右
    splitter_1 = new QSplitter(this);
    splitter_1->setOrientation(Qt::Horizontal);
    splitter_2 = new QSplitter(splitter_1);
    splitter_2->setOrientation(Qt::Vertical);
    splitter_3 = new QSplitter(splitter_1);
    splitter_3->setOrientation(Qt::Vertical);
    splitter_4 = new QSplitter(splitter_1);
    splitter_4->setOrientation(Qt::Vertical);

    mainLayout->addWidget(splitter_1);
    splitter_1->addWidget(splitter_2);
    splitter_1->addWidget(splitter_3);
    splitter_1->addWidget(splitter_4);

    QSizePolicy sizepolicy = QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
    sizepolicy.setVerticalPolicy(QSizePolicy::Expanding);
    sizepolicy.setHorizontalPolicy(QSizePolicy::Expanding);

    splitter_1->setSizePolicy(sizepolicy);
    splitter_2->setSizePolicy(sizepolicy);
    splitter_3->setSizePolicy(sizepolicy);
    splitter_4->setSizePolicy(sizepolicy);

//PID参数设置与发送
    QFont titleFont = QFont("Corbel", 20);
    PIDTitle = new QLabel(this);
    PIDTitle->setText("PID");
    PIDTitle->setFont(titleFont);
    PIDTitle->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    PIDTitle->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *PIDSplitter = new QWidget(this);
    PIDSplitter->setFixedSize(30, 6);
    PIDSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    //设置字体和大小
    QFont PIDDataFont = QFont("Corbel", 15);

    //当前PID值标签
    QLabel *CurrentPID = new QLabel("Current PID",this);
    CurrentPID->setMinimumHeight(20);
    CurrentPID->setFont(PIDDataFont);

    CurrPID_P->setMinimumHeight(20);
    CurrPID_P->setFont(PIDDataFont);
    CurrPID_I->setMinimumHeight(20);
    CurrPID_I->setFont(PIDDataFont);
    CurrPID_D->setMinimumHeight(20);
    CurrPID_D->setFont(PIDDataFont);

    //设置PID值标签
    QLabel *SetPID = new QLabel("Set PID",this);
    SetPID->setMinimumHeight(20);
    SetPID->setFont(PIDDataFont);
    //PID值的输入框
    PID_P_TII = new textInputItem("Set P:",this);
    PID_I_TII = new textInputItem("Set I:",this);
    PID_D_TII = new textInputItem("Set D:",this);

    PID_P_TII->setMaximumWidth(420);
    PID_P_TII->setMaximumWidth(420);
    PID_P_TII->setMaximumWidth(420);

    //设置PID值的按钮
    textButton *SetPIDBTN = new textButton("SetPID",this);
    SetPIDBTN->setMaximumWidth(420);

    //连接函数，按下按钮时，发送信号给主窗口，将PID值从串口发出。同时设置当前PID值的标签
    connect(SetPIDBTN,&textButton::clicked,this,[=](){

        //判断输入的是否是数字
        if(!PID_P_TII->value().toInt() || !PID_I_TII->value().toInt() || !PID_D_TII->value().toInt())
        {
            qDebug() << "不是数字";
            QMessageBox::warning(this,"错误","请输入数字");
        }
        else
        {
            emit SetPIDSignal();    //发射信号

            //保存PID值为现PID值
            CurrPID_P->setText(QString("P:     %1").arg(PID_P_TII->value()));
            CurrPID_I->setText(QString("I:     %1").arg(PID_I_TII->value()));
            CurrPID_D->setText(QString("D:     %1").arg(PID_D_TII->value()));

        }
    });

    QWidget *PIDDataWidget = new QWidget(this);
    PIDDataWidget->setSizePolicy(sizepolicy);
    //设置最小大小
    PIDDataWidget->setMinimumSize(450,300);
    QVBoxLayout *PIDDataLayout = new QVBoxLayout(this);
    PIDDataWidget->setLayout(PIDDataLayout);
    PIDDataLayout->setContentsMargins(0, 0, 0, 0);
    PIDDataLayout->setAlignment(Qt::AlignTop);
    PIDDataLayout->addWidget(CurrentPID);
    PIDDataLayout->addWidget(CurrPID_P);
    PIDDataLayout->addWidget(CurrPID_I);
    PIDDataLayout->addWidget(CurrPID_D);
    PIDDataLayout->addWidget(SetPID);
    PIDDataLayout->addWidget(PID_P_TII);
    PIDDataLayout->addWidget(PID_I_TII);
    PIDDataLayout->addWidget(PID_D_TII);
    PIDDataLayout->addWidget(SetPIDBTN);


    PIDWidget = new QWidget(this);
    PIDWidget->setSizePolicy(sizepolicy);
    QVBoxLayout *PIDLayout = new QVBoxLayout(this);
    PIDWidget->setLayout(PIDLayout);
    PIDLayout->setContentsMargins(0, 0, 0, 0);
    PIDLayout->setAlignment(Qt::AlignTop);
    PIDLayout->addWidget(PIDTitle);
    PIDLayout->addWidget(PIDSplitter);
    PIDLayout->addWidget(PIDDataWidget);

    splitter_2->addWidget(PIDWidget);

//按键显示和读取，发送动作命令
    RM3100Title = new QLabel(this);
    RM3100Title->setText("RM3100");
    RM3100Title->setFont(titleFont);
    RM3100Title->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    RM3100Title->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *RM3100Splitter = new QWidget(this);
    RM3100Splitter->setFixedSize(30, 6);
    RM3100Splitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    QLabel *RM3100NO1 = new QLabel("NO1:",this);    //RM3100 1号标签
    QLabel *RM3100NO2 = new QLabel("NO2:",this);    //RM3100 2号标签
    QLabel *RM3100NO3 = new QLabel("NO3:",this);    //RM3100 3号标签
    QLabel *RM3100NO4 = new QLabel("NO4:",this);    //RM3100 4号标签

    //设置字体和大小
    QFont RM3100DataFont = QFont("Corbel", 15);

    RM3100NO1->setMinimumHeight(25);
    RM3100NO1->setFont(RM3100DataFont);
    RM3100NO2->setMinimumHeight(25);
    RM3100NO2->setFont(RM3100DataFont);
    RM3100NO3->setMinimumHeight(25);
    RM3100NO3->setFont(RM3100DataFont);
    RM3100NO4->setMinimumHeight(25);
    RM3100NO4->setFont(RM3100DataFont);

    RM3100DataNO1->setMinimumSize(300,25);
    RM3100DataNO1->setFont(RM3100DataFont);
    RM3100DataNO2->setMinimumSize(300,25);
    RM3100DataNO2->setFont(RM3100DataFont);
    RM3100DataNO3->setMinimumSize(300,25);
    RM3100DataNO3->setFont(RM3100DataFont);
    RM3100DataNO4->setMinimumSize(300,25);
    RM3100DataNO4->setFont(RM3100DataFont);

    QWidget *RM3100DataWidget = new QWidget(this);
    RM3100DataWidget->setSizePolicy(sizepolicy);
    RM3100DataWidget->setMinimumSize(450,300);
    QVBoxLayout *RM3100DataLayout = new QVBoxLayout(this);
    RM3100DataWidget->setLayout(RM3100DataLayout);
    RM3100DataLayout->setContentsMargins(0, 0, 0, 0);
    RM3100DataLayout->setAlignment(Qt::AlignTop);
    RM3100DataLayout->addWidget(RM3100NO1);
    RM3100DataLayout->addWidget(RM3100DataNO1);
    RM3100DataLayout->addWidget(RM3100NO2);
    RM3100DataLayout->addWidget(RM3100DataNO2);
    RM3100DataLayout->addWidget(RM3100NO3);
    RM3100DataLayout->addWidget(RM3100DataNO3);
    RM3100DataLayout->addWidget(RM3100NO4);
    RM3100DataLayout->addWidget(RM3100DataNO4);


    RM3100Widget = new QWidget(this);
    RM3100Widget->setSizePolicy(sizepolicy);
    QVBoxLayout *RM3100Layout = new QVBoxLayout(this);
    RM3100Widget->setLayout(RM3100Layout);
    RM3100Layout->setContentsMargins(0, 0, 0, 0);
    RM3100Layout->setAlignment(Qt::AlignTop);
    RM3100Layout->addWidget(RM3100Title);
    RM3100Layout->addWidget(RM3100Splitter);
    RM3100Layout->addWidget(RM3100DataWidget);

    splitter_2->addWidget(RM3100Widget);

//动力系统
    QLabel *PropulsionSysLabel = new QLabel(this);
    PropulsionSysLabel->setText("Propulsion System");
    PropulsionSysLabel->setFont(titleFont);
    PropulsionSysLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    PropulsionSysLabel->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *PropulsionSysSplitter = new QWidget(this);
    PropulsionSysSplitter->setFixedSize(30, 6);
    PropulsionSysSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    //推进器名称标签和数据标签设置
    QLabel *Thruster1 = new QLabel("Thruster1",this);
    QLabel *Thruster2 = new QLabel("Thruster2",this);
    QLabel *Thruster3 = new QLabel("Thruster3",this);
    QLabel *Thruster4 = new QLabel("Thruster4",this);

    //设置字体和大小
    QFont ThrusterDataFont = QFont("Corbel", 15);

    Thruster1->setMinimumHeight(25);
    Thruster1->setFont(ThrusterDataFont);
    Thruster2->setMinimumHeight(25);
    Thruster2->setFont(ThrusterDataFont);
    Thruster3->setMinimumHeight(25);
    Thruster3->setFont(ThrusterDataFont);
    Thruster4->setMinimumHeight(25);
    Thruster4->setFont(ThrusterDataFont);

    ThrusterData1->setMinimumSize(100,20);
    ThrusterData1->setFont(ThrusterDataFont);
    ThrusterData2->setMinimumSize(100,20);
    ThrusterData2->setFont(ThrusterDataFont);
    ThrusterData3->setMinimumSize(100,20);
    ThrusterData3->setFont(ThrusterDataFont);
    ThrusterData4->setMinimumSize(100,20);
    ThrusterData4->setFont(ThrusterDataFont);

    //舵机名称标签和数据标签设置
    QLabel *Servo1 = new QLabel("Servo1",this);
    QLabel *Servo2 = new QLabel("Servo2",this);
    QLabel *Servo3 = new QLabel("Servo3",this);
    QLabel *Servo4 = new QLabel("Servo4",this);

    //设置字体和大小
    QFont ServoDataFont = QFont("Corbel", 15);

    Servo1->setMinimumHeight(25);
    Servo1->setFont(ServoDataFont);
    Servo2->setMinimumHeight(25);
    Servo2->setFont(ServoDataFont);
    Servo3->setMinimumHeight(25);
    Servo3->setFont(ServoDataFont);
    Servo4->setMinimumHeight(25);
    Servo4->setFont(ServoDataFont);

    ServoData1->setMinimumSize(100,20);
    ServoData1->setFont(ServoDataFont);
    ServoData2->setMinimumSize(100,20);
    ServoData2->setFont(ServoDataFont);
    ServoData3->setMinimumSize(100,20);
    ServoData3->setFont(ServoDataFont);
    ServoData4->setMinimumSize(100,20);
    ServoData4->setFont(ServoDataFont);

//    propellerWidget = new QWidget(splitter_3);
//    propellerWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    QGridLayout *propellerLayout = new QGridLayout(propellerWidget);
//    propellerLayout->setContentsMargins(0, 0, 0, 0);
//    propellerWidget->setLayout(propellerLayout);
    //将推进器相关的控件垂直布局
    QWidget *ThrusterDataWidget = new QWidget(this);
    QVBoxLayout *ThrusterDataLayout = new QVBoxLayout(this);
    ThrusterDataWidget->setLayout(ThrusterDataLayout);
    ThrusterDataLayout->setContentsMargins(0, 0, 0, 0);
    ThrusterDataLayout->setAlignment(Qt::AlignTop);
    ThrusterDataLayout->addWidget(Thruster1);
    ThrusterDataLayout->addWidget(ThrusterData1);
    ThrusterDataLayout->addWidget(Thruster2);
    ThrusterDataLayout->addWidget(ThrusterData2);
    ThrusterDataLayout->addWidget(Thruster3);
    ThrusterDataLayout->addWidget(ThrusterData3);
    ThrusterDataLayout->addWidget(Thruster4);
    ThrusterDataLayout->addWidget(ThrusterData4);

    //将舵机相关的控件垂直布局
    QWidget *ServoDataWidget = new QWidget(this);
    QVBoxLayout *ServoDataLayout = new QVBoxLayout(this);
    ServoDataWidget->setLayout(ServoDataLayout);
    ServoDataLayout->setContentsMargins(0, 0, 0, 0);
    ServoDataLayout->setAlignment(Qt::AlignTop);
    ServoDataLayout->addWidget(Servo1);
    ServoDataLayout->addWidget(ServoData1);
    ServoDataLayout->addWidget(Servo2);
    ServoDataLayout->addWidget(ServoData2);
    ServoDataLayout->addWidget(Servo3);
    ServoDataLayout->addWidget(ServoData3);
    ServoDataLayout->addWidget(Servo4);
    ServoDataLayout->addWidget(ServoData4);

    //将推进器和舵机的布局再进行水平布局
    QWidget *PropulsionSysDataWidget = new QWidget(this);
    QHBoxLayout *PropulsionSysDataLayout = new QHBoxLayout(this);
    PropulsionSysDataWidget->setLayout(PropulsionSysDataLayout);
    PropulsionSysDataLayout->setContentsMargins(0, 0, 0, 0);
    PropulsionSysDataLayout->setAlignment(Qt::AlignTop);
    PropulsionSysDataLayout->addWidget(ThrusterDataWidget);
    PropulsionSysDataLayout->addWidget(ServoDataWidget);

    QWidget *PropulsionSysWidget = new QWidget(this);
    QVBoxLayout *PropulsionSysLayout = new QVBoxLayout(PropulsionSysWidget);
    PropulsionSysWidget->setLayout(PropulsionSysLayout);
    PropulsionSysLayout->setContentsMargins(0, 0, 0, 0);
    PropulsionSysLayout->setAlignment(Qt::AlignTop);
    PropulsionSysLayout->addWidget(PropulsionSysLabel);
    PropulsionSysLayout->addWidget(PropulsionSysSplitter);
    PropulsionSysLayout->addWidget(PropulsionSysDataWidget);

    splitter_3->addWidget(PropulsionSysWidget);

//串口LOG
    //log标签设置
    QLabel *logLabel = new QLabel(this);
    logLabel->setText("Log From Uart");
    logLabel->setFont(titleFont);
    logLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    logLabel->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *logSplitter = new QWidget(this);
    logSplitter->setFixedSize(30, 6);
    logSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

//    ScrollAreaCustom *logDisplay = new ScrollAreaCustom(this);
//    logDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //log框设置，包含PTE和LE，使用垂直布局
    //用于显示接收串口传过来的数据
    logPTE = new QPlainTextEdit;
    logPTE->setReadOnly(true);
    logPTE->setMinimumSize(300,185);
    logPTE->setStyleSheet("background-color: black; color: black;border-radius:3px; background-color: #00000000;font: 20px 'Corbel Light'; border: 1px solid darkgray;");

    //串口发送行
    logTII = new textInputItem("Send Line:",this);

    QWidget *logWidget = new QWidget(this);
    QVBoxLayout *logLayout = new QVBoxLayout(this); //垂直布局
    logWidget->setLayout(logLayout);
    logWidget->setContentsMargins(0, 0, 0, 0);
    logLayout->setAlignment(Qt::AlignTop);
    logLayout->addWidget(logLabel);
    logLayout->addWidget(logSplitter);
    logLayout->addWidget(logPTE);
    logLayout->addWidget(logTII);
    //logLayout->addWidget(logDisplay);

    //底下两个按钮的设置，使用水平布局
    textButton *SendBTN = new textButton("Send",this);
    textButton *ClearBTN = new textButton("Clear",this);

    //按下发送键，发送发送数据信号给主窗口
    connect(SendBTN,&textButton::clicked,this,[=](){
        emit SendDataSignal();
    });

    //按下清屏键，清除接收框和发送框所有的数据
    connect(ClearBTN,&textButton::clicked,this,[=]()
    {
        logPTE->clear();
        logTII->setValue("");
        qDebug() << "Clear complete";
    });

    QWidget *BTNWidget = new QWidget(this);
    QHBoxLayout *BTNLayout = new QHBoxLayout(this); //水平布局
    BTNWidget->setLayout(BTNLayout);
    BTNLayout->addWidget(SendBTN);
    BTNLayout->addWidget(ClearBTN);

    //垂直布局，将logWidget、BTNWidget摆放
    splitter_3->addWidget(logWidget);
    splitter_3->addWidget(BTNWidget);

//3d模型
    QLabel *model3DTitle = new QLabel(this);
    model3DTitle = new QLabel(this);
    model3DTitle->setText("3Dmodel");
    model3DTitle->setFont(titleFont);
    model3DTitle->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    model3DTitle->setStyleSheet("color:#2c2c2c");

    //info底下的小横条
    QWidget *model3DSplitter = new QWidget(this);
    //info底下的小横条长度30，高度6
    model3DSplitter->setFixedSize(30, 6);
    model3DSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    view = new Qt3DExtras::Qt3DWindow();
     //设置背景颜色
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
    //静态创建了一个 QWidget容器以便将其嵌入到其他 QWidget 界面中。
    container = QWidget::createWindowContainer(view);
    //将容器设置为当前窗口的子窗口
    container->setParent(this);

    //最小容器
    container->setMinimumSize(300,300);
    //最大容器为全屏
    QSize screenSize = view->screen()->size();
    container->setMaximumSize(screenSize);

    mRootEntity = new Qt3DCore::QEntity;

    Qt3DRender::QCamera* camEntity = view->camera();
    //设置了相机的投影方式为透视投影,该函数的第一个参数是视野角度（单位为度），第二个参数是宽高比，第三个和第四个参数分别是近平面和远平面的距离。
    camEntity->lens()->setPerspectiveProjection(10.0f, 9.0f / 9.0f, 0.1f, 1000.0f);
    //设置了相机的位置,为xyz
    camEntity->setPosition(QVector3D(0, -10.0f, 0.0f));
    //设置了相机的上方向
    camEntity->setUpVector(QVector3D(0, 1, 0));
    //设置了相机的视点中心,视点中心用于确定相机的注视点
    camEntity->setViewCenter(QVector3D(0, 0, 0));
    //相机实体与轨道摄像机控制器关联起来,可以使用鼠标或手指控制相机的旋转和缩放
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(mRootEntity);
    camController->setCamera(camEntity);

    //灯光配置
    lightEntity = new Qt3DCore::QEntity(mRootEntity);
    light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1.2f);
    lightEntity->addComponent(light);

    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(camEntity->position());
    lightEntity->addComponent(lightTransform);

    view->setRootEntity(mRootEntity);
    modifier = new SceneModifier(mRootEntity);

    QWidget *qt3dWidget = new QWidget(this);
    QVBoxLayout *qt3dLayout = new QVBoxLayout(this);
    qt3dWidget->setLayout(qt3dLayout);
    qt3dLayout->setContentsMargins(10, 0, 0, 0);
    qt3dLayout->setAlignment(Qt::AlignTop);
    qt3dLayout->addWidget(model3DTitle);
    qt3dLayout->addWidget(model3DSplitter);
    qt3dLayout->addWidget(container);

    //获取了 Qt3D 中的一个 QWidget 的尺寸策略
    sizepolicy = qt3dWidget->sizePolicy();
    //获取了 Qt3D 中的一个 QWidget 的尺寸策略
    sizepolicy.setRetainSizeWhenHidden(true);
    //配置好的尺寸策略设置回QWidget ,下一次将其显示时，能够保持之前的尺寸大小。
    qt3dWidget->setSizePolicy(sizepolicy);

    splitter_4->addWidget(qt3dWidget);

//info 显示深度、GPS、电量百分比
    infoTitle = new QLabel(this);
    infoTitle->setText("INFO");
    infoTitle->setFont(titleFont);
    infoTitle->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    infoTitle->setStyleSheet("color:#2c2c2c");

    //info底下的小横条
    QWidget *infoSplitter = new QWidget(this);
    //info底下的小横条长度30，高度6
    infoSplitter->setFixedSize(30, 6);
    infoSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    QFont InfoDataFont = QFont("Corbel", 15);

    //姿态信息标题
    QLabel *AttitudeInfo = new QLabel(this);
    AttitudeInfo->setText("Angle:");
    AttitudeInfo->setMinimumHeight(25);
    AttitudeInfo->setFont(InfoDataFont);

    AttitudeDataInfo->setMinimumHeight(25);
    AttitudeDataInfo->setFont(InfoDataFont);

    infoWidget = new QWidget(this);
    infoWidget->setSizePolicy(sizepolicy);
    QVBoxLayout *infoLayout = new QVBoxLayout(infoWidget);
    infoWidget->setMinimumSize(300,350);
    infoWidget->setLayout(infoLayout);
    infoLayout->setContentsMargins(10, 0, 0, 0);
    infoLayout->setAlignment(Qt::AlignTop);
    infoLayout->addWidget(infoTitle);
    infoLayout->addWidget(infoSplitter);
    infoLayout->addWidget(AttitudeInfo);
    infoLayout->addWidget(AttitudeDataInfo);

    splitter_4->addWidget(infoWidget);

    splitter_1->setStretchFactor(0,2);
    splitter_1->setStretchFactor(1,7);
    splitter_1->setStretchFactor(2,2);

    splitter_2->setStretchFactor(0,1);
    splitter_2->setStretchFactor(1,1);

    splitter_3->setStretchFactor(0,5);
    splitter_3->setStretchFactor(1,1);

    splitter_4->setStretchFactor(0,1);
    splitter_4->setStretchFactor(1,2);

    //内部数据分拣逻辑连接
    DataSortConnect();
}

//数据分类链接函数
void MotionControlWidget::DataSortConnect()
{
    //姿态分拣
    connect(this,&MotionControlWidget::StartDataSort,this,&MotionControlWidget::AttitudeDataSort);
    //推进力分拣
    connect(this,&MotionControlWidget::StartDataSort,this,&MotionControlWidget::PropulsionSysDataSort);

    //根据姿态，3D模型转向
    connect(this,&MotionControlWidget::AttitudeChange,modifier,&SceneModifier::OnSetRotation);
}

//数据显示到PlainTextEdit中，发起数据分拣信号
void MotionControlWidget::DataDisplayPTE(QString serialBuf)
{
    if(!this->isHidden())
    {
        logPTE->ensureCursorVisible();
        logPTE->insertPlainText(serialBuf);
        //qDebug()<<serialBuf;

        //开始数据分拣
        //以空格进行分割数据，用于判断数据来源
        QStringList ProcessedData = serialBuf.split(u' ');
        //qDebug() << ProcessedData;

        emit StartDataSort(ProcessedData);
    }
}

void MotionControlWidget::PropulsionSysDataSort(QStringList ProcessedData)
{
    //是推进器的数据
    if(ProcessedData.at(0) == "T")
    {
        if(ProcessedData.at(1) == "1")
        {
            //qDebug() << "NO1的数据";
            ThrusterData1->setText(QString("%1")
                                   .arg(ProcessedData.at(2)));
        }
        else if(ProcessedData.at(1) == "2")
        {
            //qDebug() << "NO2的数据";
            ThrusterData2->setText(QString("%1")
                                   .arg(ProcessedData.at(2)));
        }
        else if(ProcessedData.at(1) == "3")
        {
            //qDebug() << "NO3的数据";
            ThrusterData3->setText(QString("%1")
                                   .arg(ProcessedData.at(2)));
        }
        else if(ProcessedData.at(1) == "4")
        {
            //qDebug() << "NO4的数据";
            ThrusterData4->setText(QString("%1")
                                   .arg(ProcessedData.at(2)));
        }
    }
    //是舵机的数据
    else if(ProcessedData.at(0) == "S")
    {
        if(ProcessedData.at(1) == "1")
        {
            //qDebug() << "NO1的数据";
            ServoData1->setText(QString("%1")
                                   .arg(ProcessedData.at(2)));
        }
        else if(ProcessedData.at(1) == "2")
        {
            //qDebug() << "NO2的数据";
            ServoData2->setText(QString("%1")
                                   .arg(ProcessedData.at(2)));
        }
        else if(ProcessedData.at(1) == "3")
        {
            //qDebug() << "NO3的数据";
            ServoData3->setText(QString("%1")
                                   .arg(ProcessedData.at(2)));
        }
        else if(ProcessedData.at(1) == "4")
        {
            //qDebug() << "NO4的数据";
            ServoData4->setText(QString("%1")
                                   .arg(ProcessedData.at(2)));
        }
    }
}

void MotionControlWidget::AttitudeDataSort(QStringList ProcessedData)
{
    //如果是JY901S的数据
    if(ProcessedData.count() > 0 && ProcessedData.at(0) == "J")
    {
        //如果是姿态角数据
        if(ProcessedData.at(1) == "Angle")
        {
            //qDebug() << "姿态角";
            AttitudeDataInfo->setText(QString("Roll%1    Pitch%2    Yaw%3")
                                     .arg(ProcessedData.at(2),ProcessedData.at(3),ProcessedData.at(4)));    //Roll Pitch Yaw
            emit AttitudeChange(ProcessedData.at(3),ProcessedData.at(4),ProcessedData.at(2));   //发射信号，改变3D模型朝向
        }
    }
}

void MotionControlWidget::SaveToFile(const QString &path){
    QFile output(path);
    output.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream ts(&output);
    ts << "VFdGeWFXUnZaekl3TURJd05ESTE=\n";

    output.close();
}