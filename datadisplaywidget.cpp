#include "datadisplaywidget.h"
#include "customWidgets.h"

DataDisplayWidget::DataDisplayWidget(int radius, int modeKind, QWidget *parent) :
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

DataDisplayWidget::DataDisplayWidget(QTextStream &ts, int radius, QWidget *parent) :
    QWidget(parent)
{

    /* create canvas */
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mainLayout);

    this->setFocusPolicy(Qt::ClickFocus);

}

//在数据显示界面的设置栏
void DataDisplayWidget::TestMvSetting(int radius){
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

void DataDisplayWidget::Init(){
//layout

    //1为最大的布局器，2，4，5分别为垂直布局器，对应左中右 3是水平布局器，包括在2内，在RM3100中使用
    splitter_1 = new QSplitter(this);
    splitter_1->setOrientation(Qt::Horizontal);
    splitter_2 = new QSplitter(splitter_1);
    splitter_2->setOrientation(Qt::Vertical);
    splitter_3 = new QSplitter(splitter_2);
    splitter_3->setOrientation(Qt::Horizontal);
    splitter_4 = new QSplitter(splitter_1);
    splitter_4->setOrientation(Qt::Vertical);
    splitter_5 = new QSplitter(splitter_1);
    splitter_5->setOrientation(Qt::Vertical);

    mainLayout->addWidget(splitter_1);
    splitter_1->addWidget(splitter_2);
    splitter_1->addWidget(splitter_4);
    splitter_1->addWidget(splitter_5);

    QSizePolicy sizepolicy = QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
    sizepolicy.setVerticalPolicy(QSizePolicy::Expanding);
    sizepolicy.setHorizontalPolicy(QSizePolicy::Expanding);

    splitter_1->setSizePolicy(sizepolicy);
    splitter_2->setSizePolicy(sizepolicy);
    splitter_3->setSizePolicy(sizepolicy);
    splitter_4->setSizePolicy(sizepolicy);
    splitter_5->setSizePolicy(sizepolicy);

//JY901S
    QFont titleFont = QFont("Corbel", 20);
    JY901STitle = new QLabel(this);
    JY901STitle->setText("JY901S");
    JY901STitle->setFont(titleFont);
    JY901STitle->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    JY901STitle->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *JY901SSplitter = new QWidget(this);
    JY901SSplitter->setFixedSize(30, 6);
    JY901SSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    QLabel *JY901SAcc = new QLabel(this);    //JY901S加速度数据标签
    QLabel *JY901SGyro = new QLabel(this);   //JY901S中角速度标签
    QLabel *JY901SAngle = new QLabel(this);  //JY901S中欧拉角标签
    QLabel *JY901SMag = new QLabel(this);    //JY901S中磁场标签

    //设置字体和大小
    QFont AccFont = QFont("Corbel", 15);
    QFont GyroFont = QFont("Corbel", 15);
    QFont AngleFont = QFont("Corbel", 15);
    QFont MagFont = QFont("Corbel", 15);

    JY901SAcc->setMinimumHeight(25);
    JY901SAcc->setFont(AccFont);
    JY901SGyro->setMinimumHeight(25);
    JY901SGyro->setFont(AccFont);
    JY901SAngle->setMinimumHeight(25);
    JY901SAngle->setFont(AccFont);
    JY901SMag->setMinimumHeight(25);
    JY901SMag->setFont(AccFont);

    JY901SDataAcc->setMinimumSize(300,25);
    JY901SDataAcc->setFont(AccFont);
    JY901SDataGyro->setMinimumSize(300,25);
    JY901SDataGyro->setFont(GyroFont);
    JY901SDataAngle->setMinimumSize(300,25);
    JY901SDataAngle->setFont(AngleFont);
    JY901SDataMag->setMinimumSize(300,25);
    JY901SDataMag->setFont(MagFont);

    JY901SAcc->setText("Acc:");
    JY901SGyro->setText("Gyro:");
    JY901SAngle->setText("Angle:");
    JY901SMag->setText("Mag:");

    QWidget *JY901SDataWidget = new QWidget(this);
    JY901SDataWidget->setSizePolicy(sizepolicy);
    //设置最小大小
    JY901SDataWidget->setMinimumSize(450,300);
    QVBoxLayout *JY901SDataLayout = new QVBoxLayout(this);
    JY901SDataWidget->setLayout(JY901SDataLayout);
    JY901SDataLayout->setContentsMargins(0, 0, 0, 0);
    JY901SDataLayout->setAlignment(Qt::AlignTop);
    JY901SDataLayout->addWidget(JY901SAcc);
    JY901SDataLayout->addWidget(JY901SDataAcc);
    JY901SDataLayout->addWidget(JY901SGyro);
    JY901SDataLayout->addWidget(JY901SDataGyro);
    JY901SDataLayout->addWidget(JY901SAngle);
    JY901SDataLayout->addWidget(JY901SDataAngle);
    JY901SDataLayout->addWidget(JY901SMag);
    JY901SDataLayout->addWidget(JY901SDataMag);

    JY901SWidget = new QWidget(this);
    JY901SWidget->setSizePolicy(sizepolicy);
    QVBoxLayout *JY901SLayout = new QVBoxLayout(this);
    JY901SWidget->setLayout(JY901SLayout);
    JY901SLayout->setContentsMargins(0, 0, 0, 0);
    JY901SLayout->setAlignment(Qt::AlignTop);
    JY901SLayout->addWidget(JY901STitle);
    JY901SLayout->addWidget(JY901SSplitter);
    JY901SLayout->addWidget(JY901SDataWidget);

    splitter_2->addWidget(JY901SWidget);
    //splitter_2->addWidget(splitter_3);

//RM3100
    RM3100Title = new QLabel(this);
    RM3100Title->setText("RM3100");
    RM3100Title->setFont(titleFont);
    RM3100Title->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    RM3100Title->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *RM3100Splitter = new QWidget(this);
    RM3100Splitter->setFixedSize(30, 6);
    RM3100Splitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    ScrollAreaCustom *RM3100Display = new ScrollAreaCustom(this);

    QWidget *RM3100DataWidget = new QWidget(this);
    RM3100DataWidget->setSizePolicy(sizepolicy);
    RM3100DataWidget->setMinimumSize(450,300);
    QHBoxLayout *RM3100DataLayout = new QHBoxLayout(this);
    RM3100DataWidget->setLayout(RM3100DataLayout);
    RM3100DataLayout->setContentsMargins(0, 0, 0, 0);
    RM3100DataLayout->setAlignment(Qt::AlignTop);
    RM3100DataLayout->addWidget(RM3100Display);

    RM3100Widget = new QWidget(this);
    RM3100Widget->setSizePolicy(sizepolicy);
    QVBoxLayout *RM3100Layout = new QVBoxLayout(this);
    RM3100Widget->setLayout(RM3100Layout);
    RM3100Layout->setContentsMargins(0, 0, 0, 0);
    RM3100Layout->setAlignment(Qt::AlignTop);
    RM3100Layout->addWidget(RM3100Title);
    RM3100Layout->addWidget(RM3100Splitter);
    RM3100Layout->addWidget(RM3100DataWidget);

    //AuvDepHeiWidget *depHeiWidget = new AuvDepHeiWidget(this);
    //splitter_3为水平布局器，tempwidget将会出现在RM3100的右边
    //QWidget *tempwidget = new QWidget(this);
    splitter_2->addWidget(RM3100Widget);
    //splitter_3->addWidget(RM3100Widget);
    //splitter_3->addWidget(tempwidget);

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

//    propellerWidget = new QWidget(splitter_4);
//    propellerWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    QGridLayout *propellerLayout = new QGridLayout(propellerWidget);
//    propellerLayout->setContentsMargins(0, 0, 0, 0);
//    propellerWidget->setLayout(propellerLayout);

    QWidget *PropulsionSysWidget = new QWidget(this);
    QVBoxLayout *PropulsionSysLayout = new QVBoxLayout(PropulsionSysWidget);
    PropulsionSysWidget->setLayout(PropulsionSysLayout);
    PropulsionSysLayout->setContentsMargins(0, 0, 0, 0);
    PropulsionSysLayout->setAlignment(Qt::AlignTop);
    PropulsionSysLayout->addWidget(PropulsionSysLabel);
    PropulsionSysLayout->addWidget(PropulsionSysSplitter);
    PropulsionSysLayout->addWidget(PropulsionSysWidget);


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
    logPTE->setMinimumSize(300,150);
    logPTE->setStyleSheet("background-color: black; color: black;border-radius:3px; background-color: #00000000;font: 20px 'Corbel Light'; border: 1px solid darkgray;");

    //串口发送行
    logTII = new textInputItem("Send Line:",this);

    QWidget *logWidget = new QWidget(this);
    QVBoxLayout *logLayout = new QVBoxLayout(this); //垂直布局
    logWidget->setLayout(logLayout);
    logLayout->setContentsMargins(0, 0, 0, 0);
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

    //垂直布局，将PropulsionSysWidget、logWidget、BTNWidget摆放
    splitter_4->addWidget(PropulsionSysWidget);
    splitter_4->addWidget(logWidget);
    splitter_4->addWidget(BTNWidget);

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
    camEntity->setPosition(QVector3D(0, -10.0f, 5.0f));
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

    splitter_5->addWidget(qt3dWidget);

//info
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

    infoWidget = new QWidget(this);
    infoWidget->setSizePolicy(sizepolicy);
    QVBoxLayout *infoLayout = new QVBoxLayout(infoWidget);
    infoWidget->setMinimumSize(300,350);
    infoWidget->setLayout(infoLayout);
    infoLayout->setContentsMargins(10, 0, 0, 0);
    infoLayout->setAlignment(Qt::AlignTop);
    infoLayout->addWidget(infoTitle);
    infoLayout->addWidget(infoSplitter);

    splitter_5->addWidget(infoWidget);

    splitter_1->setStretchFactor(0,2);
    splitter_1->setStretchFactor(1,7);
    splitter_1->setStretchFactor(2,2);

    splitter_2->setStretchFactor(0,1);
    splitter_2->setStretchFactor(1,1);

    splitter_4->setStretchFactor(0,5);
    splitter_4->setStretchFactor(1,1);

    splitter_5->setStretchFactor(0,1);
    splitter_5->setStretchFactor(1,2);

    //内部数据分拣逻辑连接
    DataSortConnect();
}


void DataDisplayWidget::doModeChange(int modeKind)
{
    if(modeKind_ == modeKind)
        return;

    switch (modeKind)
    {
    case MODE::TEST_MV_CTR:
        TestMvMode();
        break;
    default:
        break;
    }

    modeKind_ = modeKind;
}


void DataDisplayWidget::TestMvMode()
{

}

void DataDisplayWidget::DataSortConnect()
{
    connect(this,&DataDisplayWidget::StartDataSort,this,&DataDisplayWidget::JY901SDataSort);
}

void DataDisplayWidget::DataDisplayPTE(QString serialBuf)
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

void DataDisplayWidget::JY901SDataSort(QStringList ProcessedData)
{
    //是JY901S的数据
    if(ProcessedData.count() > 0 && ProcessedData.at(0) == "J")
    {
        //qDebug() << "JY901S的数据";
        //是加速度
        if(ProcessedData.at(1) == "Acc")
        {
            //qDebug() << "Acc的数据";
            JY901SDataAcc->setText(QString("%1    %2    %3    %4")
                                   .arg(ProcessedData.at(2),ProcessedData.at(3),ProcessedData.at(4),ProcessedData.at(5)));
        }
        //是角速度
        if(ProcessedData.at(1) == "Gyro")
        {
            //qDebug() << "Gyro的数据";
            JY901SDataGyro->setText(QString("%1    %2    %3    %4")
                                    .arg(ProcessedData.at(2),ProcessedData.at(3),ProcessedData.at(4),ProcessedData.at(5)));
        }
        //是欧拉角
        if(ProcessedData.at(1) == "Angle")
        {
            //qDebug() << "Angle的数据";
            JY901SDataAngle->setText(QString("%1    %2    %3    %4")
                                     .arg(ProcessedData.at(2),ProcessedData.at(3),ProcessedData.at(4),ProcessedData.at(5)));
        }
        //是磁场
        if(ProcessedData.at(1) == "Mag")
        {
            //qDebug() << "Mag的数据";
            JY901SDataMag->setText(QString("%1    %2    %3    %4")
                                   .arg(ProcessedData.at(2),ProcessedData.at(3),ProcessedData.at(4),ProcessedData.at(5)));
        }
    }
}

void DataDisplayWidget::SaveToFile(const QString &path){
    QFile output(path);
    output.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream ts(&output);
    ts << "VFdGeWFXUnZaekl3TURJd05ESTE=\n";

    output.close();
}
