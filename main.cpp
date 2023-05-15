#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    //int id = QFontDatabase::addApplicationFont(":/fonts/fonts/corbel.ttf");
    //qDebug() << id;
    //QFontDatabase::addApplicationFont(":/fonts/fonts/corbell.ttf");
    //Qt::AA_EnableHighDpiScaling;
#ifdef Q_OS_LINUX
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlag(Qt::FramelessWindowHint);

    //设置窗口属性，在窗口中绘制的区域支持 alpha 通道
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.show();
    return a.exec();

}
