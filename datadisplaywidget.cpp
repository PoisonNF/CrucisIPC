#include "datadisplaywidget.h"

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

    //1为最大的布局器，2，4，5分别为垂直布局器，对应左中右 3是水平布局器，包括在2内，在state中使用
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

//axis
    QFont titleFont = QFont("Corbel", 20);
    axisTitle = new QLabel(this);
    axisTitle->setText("AXIS");
    axisTitle->setFont(titleFont);
    axisTitle->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    axisTitle->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *axisSplitter = new QWidget(this);
    axisSplitter->setFixedSize(30, 6);
    axisSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

//    AuvLocationGraph * graph = new AuvLocationGraph(this);
//    graph->setSizePolicy(sizepolicy);
//    graph->setMinimumSize(300,300);
//    graph->setObjectName("graph");
//    graph->setStyleSheet("QWidget#graph{border:1px solid #cfcfcf;border-radius:5px;}");


    QWidget *axisDataWidget = new QWidget(this);
    axisDataWidget->setSizePolicy(sizepolicy);
    //设置最小大小
    axisDataWidget->setMinimumSize(300,300);
    QHBoxLayout *axisDataLayout = new QHBoxLayout(this);
    axisDataWidget->setLayout(axisDataLayout);
    axisDataLayout->setContentsMargins(0, 0, 0, 0);
    axisDataLayout->setAlignment(Qt::AlignTop);
    //axisDataLayout->addWidget(graph);

    axisWidget = new QWidget(this);
    axisWidget->setSizePolicy(sizepolicy);
    QVBoxLayout *axisLayout = new QVBoxLayout(this);
    axisWidget->setLayout(axisLayout);
    axisLayout->setContentsMargins(0, 0, 0, 0);
    axisLayout->setAlignment(Qt::AlignTop);
    axisLayout->addWidget(axisTitle);
    axisLayout->addWidget(axisSplitter);
    axisLayout->addWidget(axisDataWidget);

    splitter_2->addWidget(axisWidget);
    splitter_2->addWidget(splitter_3);

//state
    stateTitle = new QLabel(this);
    stateTitle->setText("STATE");
    stateTitle->setFont(titleFont);
    stateTitle->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    stateTitle->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *stateSplitter = new QWidget(this);
    stateSplitter->setFixedSize(30, 6);
    stateSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    ScrollAreaCustom *stateDisplay = new ScrollAreaCustom(this);

    QWidget *stateDataWidget = new QWidget(this);
    stateDataWidget->setSizePolicy(sizepolicy);
    stateDataWidget->setMinimumSize(150,300);
    QHBoxLayout *stateDataLayout = new QHBoxLayout(this);
    stateDataWidget->setLayout(stateDataLayout);
    stateDataLayout->setContentsMargins(0, 0, 0, 0);
    stateDataLayout->setAlignment(Qt::AlignTop);
    stateDataLayout->addWidget(stateDisplay);

    stateWidget = new QWidget(this);
    stateWidget->setSizePolicy(sizepolicy);
    QVBoxLayout *stateLayout = new QVBoxLayout(this);
    stateWidget->setLayout(stateLayout);
    stateLayout->setContentsMargins(0, 0, 0, 0);
    stateLayout->setAlignment(Qt::AlignTop);
    stateLayout->addWidget(stateTitle);
    stateLayout->addWidget(stateSplitter);
    stateLayout->addWidget(stateDataWidget);

    //AuvDepHeiWidget *depHeiWidget = new AuvDepHeiWidget(this);
    //splitter_3为水平布局器，tempwidget将会出现在state的右边
    //QWidget *tempwidget = new QWidget(this);
    splitter_3->addWidget(stateWidget);
    //splitter_3->addWidget(tempwidget);

//推进器转速设置
    QLabel *mvCtrLabel = new QLabel(this);
    mvCtrLabel->setText("MOVE CONTROL");
    mvCtrLabel->setFont(titleFont);
    mvCtrLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    mvCtrLabel->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *mvCtrSplitter = new QWidget(this);
    mvCtrSplitter->setFixedSize(30, 6);
    mvCtrSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    propellerWidget = new QWidget(splitter_4);
    propellerWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QGridLayout *propellerLayout = new QGridLayout(propellerWidget);
    propellerLayout->setContentsMargins(0, 0, 0, 0);
    propellerWidget->setLayout(propellerLayout);

    QWidget *mvCtrWidget = new QWidget(this);
    QVBoxLayout *mvCtrLayout = new QVBoxLayout(mvCtrWidget);
    mvCtrWidget->setLayout(mvCtrLayout);
    mvCtrLayout->setContentsMargins(0, 0, 0, 0);
    mvCtrLayout->setAlignment(Qt::AlignTop);
    mvCtrLayout->addWidget(mvCtrLabel);
    mvCtrLayout->addWidget(mvCtrSplitter);
    mvCtrLayout->addWidget(propellerWidget);


//LOG
    QLabel *logLabel = new QLabel(this);
    logLabel->setText("LOG");
    logLabel->setFont(titleFont);
    logLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    logLabel->setStyleSheet("color:#2c2c2c");

    //小横条设置
    QWidget *logSplitter = new QWidget(this);
    logSplitter->setFixedSize(30, 6);
    logSplitter->setStyleSheet("background-color:#3c3c3c;border-radius:3px;");

    ScrollAreaCustom *logDisplay = new ScrollAreaCustom(this);
    logDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    logPTE = new QPlainTextEdit;
    logPTE->setReadOnly(true);
    logPTE->setMinimumSize(300,150);
    logPTE->setStyleSheet("background-color: black; color: black;border-radius:3px; background-color: #EDEDED;font: 20px 'Corbel Light'; border: 1px solid darkgray;");


    QWidget *logWidget = new QWidget(this);
    QVBoxLayout *logLayout = new QVBoxLayout(this);
    logWidget->setLayout(logLayout);
    logLayout->setContentsMargins(0, 0, 0, 0);
    logLayout->setAlignment(Qt::AlignTop);
    logLayout->addWidget(logLabel);
    logLayout->addWidget(logSplitter);
    logLayout->addWidget(logPTE);
    logLayout->addWidget(logDisplay);

    splitter_4->addWidget(mvCtrWidget);
    splitter_4->addWidget(logWidget);

//3d
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

    splitter_5->addWidget(qt3dWidget);
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

void DataDisplayWidget::DataDisplayPTE(QString serialBuf)
{
    logPTE->ensureCursorVisible();
    logPTE->insertPlainText(serialBuf);
    qDebug()<<serialBuf;
}

void DataDisplayWidget::SaveToFile(const QString &path){
    QFile output(path);
    output.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream ts(&output);
    ts << "VFdGeWFXUnZaekl3TURJd05ESTE=\n";

    output.close();
}
