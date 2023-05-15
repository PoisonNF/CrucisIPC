#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainterPath>
#include <QRegion>
#include <QTimer>

#if (QT_VERSION > QT_VERSION_CHECK(6,3,0))
#include <QFileDialog>
#endif


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setMouseTracking(true);
#ifdef Q_OS_LINUX
    ui->verticalLayout->setContentsMargins(0, 0, 0, 0);
    cornerRadius = 0;
#endif
    QTimer *t = new QTimer(this);
    connect(t, &QTimer::timeout, this, [=](){Init();});
    t->setSingleShot(true);
    t->start(10);

    connect(ui->adjSizeBtn, &QPushButton::clicked, this, [=](){controlWindowScale();});
}

void MainWindow::Init(){
    /* 创建主窗口小部件并设置掩码、样式表和阴影 */
#ifdef Q_OS_LINUX
    QPainterPath path;
    path.addRect(ui->mainWidget->rect());
#else
    QPainterPath path;
    path.addRoundedRect(ui->mainWidget->rect(), cornerRadius - 1, cornerRadius - 1);
#endif
    QRegion mask(path.toFillPolygon().toPolygon());
    ui->mainWidget->setMask(mask);

    QString mainStyle;
    ui->mainWidget->setObjectName("mainWidget");
    mainStyle = "QWidget#mainWidget{background-color:" + mainBackGround.name() + QString::asprintf(";border-radius:%dpx", cornerRadius) + "}";
    ui->mainWidget->setStyleSheet(mainStyle);
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
#ifdef Q_OS_WINDOWS
    //增加窗口阴影
    windowShadow = new QGraphicsDropShadowEffect(this);
    windowShadow->setBlurRadius(30);
    windowShadow->setColor(QColor(0, 0, 0));
    windowShadow->setOffset(0, 0);
    ui->mainWidget->setGraphicsEffect(windowShadow);
#endif
#endif
    /**********************************************************/

    /* 创建边界以覆盖区域的锯齿形边缘 */
#ifdef Q_OS_WINDOWS
    border = new QWidget(this);
    border->move(ui->mainWidget->pos() - QPoint(1, 1));
    border->resize(ui->mainWidget->size() + QSize(2, 2));
    QString borderStyle;
    borderStyle = "background-color:#00FFFFFF;border:1.5px solid #686868; border-radius:" + QString::asprintf("%d",cornerRadius) + "px";
    border->setStyleSheet(borderStyle);
    border->setAttribute(Qt::WA_TransparentForMouseEvents);
    border->show();
#endif
    /*****************************************************************/

    /* 创建设置关于页 */
    defaultSettingsPage = new SlidePage(cornerRadius, "ABOUT", ui->mainWidget);
    textInputItem *version = new textInputItem("version", defaultSettingsPage);
    version->setValue("1.3-beta");
    version->setEnabled(false);
    textInputItem *updateDate = new textInputItem("last-upd", defaultSettingsPage);
    updateDate->setValue("2021/12/6 10:14");
    updateDate->setEnabled(false);
    textInputItem *Author = new textInputItem("author", defaultSettingsPage);
    Author->setValue("Linloir | PoisonNF");
    Author->setEnabled(false);
    textInputItem *lic = new textInputItem("lic", defaultSettingsPage);
    lic->setValue("MIT License");
    lic->setEnabled(false);
    textInputItem *GitHub = new textInputItem("git", defaultSettingsPage);
    GitHub->setValue("github.com/PoisonNF");
    GitHub->setEnabled(false);
    defaultSettingsPage->AddContent(GitHub);
    defaultSettingsPage->AddContent(lic);
    defaultSettingsPage->AddContent(Author);
    defaultSettingsPage->AddContent(updateDate);
    defaultSettingsPage->AddContent(version);
    curSettingsPage = defaultSettingsPage;
    defaultSettingsPage->show();
    pageList.push_back(defaultSettingsPage);

    /************************/

    /* 初始化主界面上部标题栏 */
    //主标题设置
    QFont titleFont = QFont("Corbel Light", 24);
    QFontMetrics titleFm(titleFont);
    Heading = new QLineEdit(this);
    Heading->setFont(titleFont);
    Heading->setText("CrucisIPC");
    Heading->setMaxLength(20);
    Heading->setReadOnly(true);
    Heading->setMinimumHeight(titleFm.height());
    Heading->setMaximumWidth(titleFm.size(Qt::TextSingleLine, "CrucisIPC").width() + 10);
    Heading->setStyleSheet("background-color:#00000000;border-style:none;border-width:0px;margin-left:1px;");
    connect(Heading, &QLineEdit::textEdited, Heading, [=](QString text){Heading->setMaximumWidth(titleFm.size(Qt::TextSingleLine, text).width());});

    //副标题设置
    QFont descFont = QFont("Corbel Light", 12);
    QFontMetrics descFm(descFont);
    Subtitle = new QLineEdit(this);
    Subtitle->setFont(descFont);
    Subtitle->setText("Controller and Observer for AUV");
    Subtitle->setMaxLength(128);
    Subtitle->setReadOnly(true);
    Subtitle->setMinimumHeight(descFm.lineSpacing());
    Subtitle->setStyleSheet("background-color:#00000000;border-style:none;border-width:0px;");

    //配置设置图标的大小
    settingsIcon = new customIcon(":/icons/icons/settings.svg", "settings", 5, this);
    settingsIcon->setMinimumHeight(Heading->height() * 0.7);
    settingsIcon->setMaximumWidth(Heading->height() * 0.7);

    //点击设置图标调出副窗口
    connect(settingsIcon, &customIcon::clicked, this, [=](){
        //设置图标转动，0 逐渐变为 90度，持续时间为 750 毫秒，并使用插值曲线使动画效果更加自然
        QPropertyAnimation *rotate = new QPropertyAnimation(settingsIcon, "rotationAngle", this);
        rotate->setDuration(750);
        rotate->setStartValue(0);
        rotate->setEndValue(90);
        rotate->setEasingCurve(QEasingCurve::InOutExpo);
        rotate->start();

        //当前设置界面滑入
        curSettingsPage->slideIn();
    });

    //配置层图标的大小
    layersIcon = new customIcon(":/icons/icons/layers.svg", "layers", 5, this);
    layersIcon->setMinimumHeight(Heading->height() * 0.7);
    layersIcon->setMaximumWidth(Heading->height() * 0.7);

    /*****************************************************************/

    /* 布局配置 */
    QWidget *titleInnerWidget = new QWidget(this);
    titleInnerWidget->setFixedHeight(Heading->height());
    QHBoxLayout *innerLayout = new QHBoxLayout(titleInnerWidget);   //水平布局
    titleInnerWidget->setLayout(innerLayout);
    innerLayout->setContentsMargins(0, 0, 0, 0);
    innerLayout->setSpacing(10);
    innerLayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    innerLayout->addWidget(Heading);
    innerLayout->addWidget(settingsIcon);
    innerLayout->addWidget(layersIcon);

    QWidget *titleWidget = new QWidget(this);
    titleWidget->setMaximumHeight(Heading->height() + Subtitle->height());
    QVBoxLayout *outerLayout = new QVBoxLayout(titleWidget);        //垂直布局
    titleWidget->setLayout(outerLayout);
    outerLayout->setContentsMargins(0, 0, 0, 0);
    outerLayout->setSpacing(0);
    outerLayout->addWidget(titleInnerWidget);
    outerLayout->addWidget(Subtitle);

    /*****************************************************************/

    /* 创建主界面 */
    defaultPage = new QWidget(ui->mainWidget);
    defaultPage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //放置两个大图标
    bigIconButton *Data_display = new bigIconButton(":/icons/icons/create.png", "数据显示", 10, this);
    Data_display->setScale(0.9);
    bigIconButton *Motion_control = new bigIconButton(":/icons/icons/open.png", "运动控制", 10, this);

    //数据显示按钮槽函数连接
    connect(Data_display, &bigIconButton::clicked, this, [=](){
        //左图标事件槽函数
        qDebug() << "Data_displayBtn";
        ChangeDDWidget();
    });

    //运动控制按钮槽函数连接
    connect(Motion_control, &bigIconButton::clicked, this, [=](){
        //右图标事件槽函数
        qDebug() << "Motion_controlBtn";
    });

    //两个大按钮进行水平布局
    QHBoxLayout *defaultPageLayout = new QHBoxLayout(defaultPage);
    defaultPage->setLayout(defaultPageLayout);
    defaultPageLayout->setContentsMargins(50, 30, 50, 80);
    defaultPageLayout->setSpacing(20);
    defaultPageLayout->addWidget(Data_display);
    defaultPageLayout->addWidget(Motion_control);

    ui->displayLayout->addWidget(titleWidget);
    ui->displayLayout->addWidget(defaultPage);
    ui->displayLayout->setAlignment(Qt::AlignTop);

    InitLayersPage();   //层页界面和按钮初始化
}

//层页初始化函数
void MainWindow::InitLayersPage()
{
    layersPage = new SlidePage(cornerRadius, "功能选择", ui->mainWidget);

    //标题到可选项之间的留白
    QWidget *whiteSpace = new QWidget(layersPage);
    whiteSpace->setFixedHeight(30);

    modeSelGroup = new singleSelectGroup("模式", layersPage);
    selectionItem *testModeItem = new selectionItem("数据显示", "展示所有传感器的数据", layersPage);
    selectionItem *travelModeItem = new selectionItem("运动控制", "进行PID和手柄控制", layersPage);
    modeSelGroup->AddItem(testModeItem);
    modeSelGroup->AddItem(travelModeItem);

//    subModeSelGroup = new singleSelectGroup("控制", layersPage);
//    selectionItem *mvCtrItem = new selectionItem("运动控制", "待填", layersPage);
//    selectionItem *balCtrItem = new selectionItem("调平控制", "待填", layersPage);
//    selectionItem *actCtrItem = new selectionItem("动作控制", "待填", layersPage);

//    subModeSelGroup->AddItem(mvCtrItem);
//    subModeSelGroup->AddItem(balCtrItem);
//    subModeSelGroup->AddItem(actCtrItem);

    textButton *ensureBtn = new textButton("确认", layersPage);

    //按照从下到上的顺序排布
    layersPage->AddContent(ensureBtn);          //确认按钮
    //layersPage->AddContent(subModeSelGroup);  //副模式组
    layersPage->AddContent(modeSelGroup);       //主模式组
    layersPage->AddContent(whiteSpace);         //留白
    layersPage->show(); //界面显示

    //将层页放入页表容器中
    pageList.push_back(layersPage);

    //按下层图标的时候，触发层页滑入
    connect(layersIcon, &customIcon::clicked, layersPage, &SlidePage::slideIn);

    connect(testModeItem, &selectionItem::selected, this, [=](){
        //modeKind = MODE::TEST_MV_CTR;
        //subModeSelGroup->SetSelection(mvCtrItem);
        //emit ModeKindChange(modeKind);
        qDebug()<<"进入数据显示界面";
    });
    connect(travelModeItem, &selectionItem::selected, this, [=](){
        //modeKind = MODE::TRAVEL_MV_CTR;
        //subModeSelGroup->SetSelection(mvCtrItem);
        //emit ModeKindChange(modeKind);

        qDebug()<<"进入运动控制界面";
    });
//    connect(mvCtrItem, &selectionItem::selected, this, [=](){
//        //modeKind = MODE::TEST_MV_CTR;
//        //emit ModeKindChange(modeKind);

//        qDebug()<<"modeKind = TEST_MV_CTR";
//    });
//    connect(balCtrItem, &selectionItem::selected, this, [=](){
//        //modeKind = MODE::TEST_BAL_CTR;
//        //emit ModeKindChange(modeKind);

//        qDebug()<<"modeKind = TEST_BAL_CTR";
//    });
//    connect(actCtrItem, &selectionItem::selected, this, [=](){
//        //modeKind = MODE::TEST_ACT_CTR;
//        //emit ModeKindChange(modeKind);

//        qDebug()<<"modeKind = TEST_ACT_CTR";
//    });

    //connectPage3DLight(layersPage);
    connect(ensureBtn, &textButton::clicked, this, [=](){
        //ChangeMyWidget(); //切换界面
        layersPage->slideOut();
    });
}


/* 切换到数据显示窗口 */
void MainWindow::ChangeDataDisplayWidget()
{
    if(DDWidgetFlag)
    {
        DDWidgetFlag = false;

        //旧界面隐藏
        ui->displayLayout->removeWidget(defaultPage);
        defaultPage->hide();

        //切换新界面
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        mousePressed = true;
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
        lastPos = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
#else
        lastPos = event->globalPos() - this->frameGeometry().topLeft();
#endif
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() == Qt::NoButton)
        mousePressed = false;
    if(!mousePressed){
        mouseState = 0;
        if(!maximized && abs(event->pos().x() - ui->mainWidget->pos().x()) < 5)
            mouseState |= AT_LEFT;
        if(!maximized && abs(event->pos().y() - ui->mainWidget->pos().y()) < 5)
            mouseState |= AT_TOP;
        if(!maximized && abs(event->pos().x() - ui->mainWidget->pos().x() - ui->mainWidget->width()) < 5)
            mouseState |= AT_RIGHT;
        if(!maximized && abs(event->pos().y() - ui->mainWidget->pos().y() - ui->mainWidget->height()) < 5)
            mouseState |= AT_BOTTOM;
        if(mouseState == AT_TOP_LEFT  || mouseState == AT_BOTTOM_RIGHT)
            setCursor(Qt::SizeFDiagCursor);
        else if(mouseState == AT_TOP_RIGHT || mouseState == AT_BOTTOM_LEFT)
            setCursor(Qt::SizeBDiagCursor);
        else if(mouseState & (AT_LEFT | AT_RIGHT))
            setCursor(Qt::SizeHorCursor);
        else if(mouseState & (AT_TOP | AT_BOTTOM))
            setCursor(Qt::SizeVerCursor);
        else
            unsetCursor();
    }
    else{
        if(mouseState == 0){
            if(maximized){
                qreal wRatio = (double)event->pos().x() / (double)ui->mainWidget->width();
                controlWindowScale();
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
                this->move(QPoint(event->globalPosition().x() - ui->mainWidget->width() * wRatio, -30));
#else
                this->move(QPoint(event->globalPos().x() - ui->mainWidget->width() * wRatio, -30));
#endif
                lastPos = QPoint(ui->mainWidget->width() * wRatio, event->pos().y());
            }
            else
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
                this->move(event->globalPosition().toPoint() - lastPos);
#else
                this->move(event->globalPos() - lastPos);
#endif
        }
        else{
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
            QPoint d = event->globalPosition().toPoint() - frameGeometry().topLeft() - lastPos;
#else
            QPoint d = event->globalPos() - frameGeometry().topLeft() - lastPos;
#endif
            if(mouseState & AT_LEFT){
                this->move(this->frameGeometry().x() + d.x(), this->frameGeometry().y());
                this->resize(this->width() - d.x(), this->height());
            }
            if(mouseState & AT_RIGHT){
                this->resize(this->width() + d.x(), this->height());
            }
            if(mouseState & AT_TOP){
                this->move(this->frameGeometry().x(), this->frameGeometry().y() + d.y());
                this->resize(this->width(), this->height() - d.y());
            }
            if(mouseState & AT_BOTTOM){
                this->resize(this->width(), this->height() + d.y());
            }
        }
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
        lastPos = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
#else
        lastPos = event->globalPos() - this->frameGeometry().topLeft();
#endif
    }
}

void MainWindow::resizeEvent(QResizeEvent *event){
    //Resize border
    if(border)
        border->resize(ui->mainWidget->size() + QSize(2, 2));

    //Resize mask
    QPainterPath path;
#ifdef Q_OS_WINDOWS
    path.addRoundedRect(ui->mainWidget->rect(), cornerRadius - 1, cornerRadius - 1);
#else
    path.addRect(ui->mainWidget->rect());
#endif
    QRegion mask(path.toFillPolygon().toPolygon());
    ui->mainWidget->setMask(mask);

    //Resize all pages
    for(int i = 0; i < pageList.size(); i++){
        pageList[i]->resize(ui->mainWidget->width() * 0.4 < pageList[i]->preferWidth ? pageList[i]->preferWidth - 1 : ui->mainWidget->width() * 0.4 - 1, ui->mainWidget->height());
        pageList[i]->resize(pageList[i]->width() + 1, pageList[i]->height());
    }
}

void MainWindow::controlWindowScale(){
#ifdef Q_OS_WINDOWS
    if(!maximized){
        lastGeometry = this->frameGeometry();
        windowShadow->setEnabled(false);
        ui->verticalLayout->setContentsMargins(0, 0, 0, 0);
        border->hide();
        QString mainStyle = "QWidget#mainWidget{background-color:" + mainBackGround.name() + ";border-radius:0px;}";
        ui->mainWidget->setStyleSheet(mainStyle);
        this->showMaximized();
        maximized = true;
        QPainterPath path;
        path.addRect(ui->mainWidget->rect());
        QRegion mask(path.toFillPolygon().toPolygon());
        ui->mainWidget->setMask(mask);
    }
    else{
        ui->verticalLayout->setContentsMargins(30, 30, 30, 30);
        this->showNormal();
        QString mainStyle = "QWidget#mainWidget{background-color:" + mainBackGround.name() + QString::asprintf(";border-radius:%dpx", cornerRadius) + "}";
        ui->mainWidget->setStyleSheet(mainStyle);
        QPainterPath path;
        path.addRoundedRect(ui->mainWidget->rect(), cornerRadius - 1, cornerRadius - 1);
        QRegion mask(path.toFillPolygon().toPolygon());
        ui->mainWidget->setMask(mask);
        border->show();
        windowShadow->setEnabled(true);
        this->resize(lastGeometry.width(), lastGeometry.height());
        this->move(lastGeometry.x(), lastGeometry.y());
        maximized = false;
    }
#endif
}


