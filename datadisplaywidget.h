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

#if (QT_VERSION > QT_VERSION_CHECK(6,3,0))
#include <QFileDialog>
#endif


class DataDisplayWidget : public QWidget
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
    QSplitter *splitter_5;
    QLabel *JY901STitle;
    QLabel *RM3100Title;
    QLabel *logTitle;
    QLabel *infoTitle;

    QString modeName;
    QString ctrDescrip;

    QWidget *JY901SWidget = nullptr;
    QWidget *RM3100Widget = nullptr;
    QWidget *propellerWidget = nullptr;
    QWidget *infoWidget;

    QPlainTextEdit *logPTE;
    textInputItem *logTII;

    void Init();
    void SaveToFile(const QString &path);
    void TestMvSetting(int r);
    void TestMvMode();


public:
    explicit DataDisplayWidget(int radius, int modeKind, QWidget *parent = nullptr);
    DataDisplayWidget(QTextStream &ts, int radius, QWidget *parent = nullptr);

    SlidePage *settingPage(){return settings;}
    Qt3DRender::QPointLight *Light(){return light;}

    Qt3DExtras::Qt3DWindow *view;
    QWidget *container = nullptr;
    SceneModifier *modifier = nullptr;

    textButton *SendBTN;
    textButton *ClearBTN;

signals:
    void setDel(DataDisplayWidget* target);
    //void SendDataSignal(QString DataBuf);

public slots:
    void doModeChange(int);
    void DataDisplayPTE(QString serialBuf);
    //void SendData(QString DataBuf);
};

#endif // DATADISPLAYWIDGET_H
