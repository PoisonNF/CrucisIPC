#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

#include <QString>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort *serialPort; //定义一个SerialPort
private slots:
    //开启槽函数
    void on_OpenPB_clicked();
    //关闭槽函数
    void on_ClosePB_clicked();
    //发送槽函数
    void on_SendPB_clicked();
    //清空槽函数
    void on_ClearPB_clicked();
    //串口准备接收槽函数
    void serialPortReadReady_Slot();
private:
    Ui::MainWindow *ui;
    //创建数据库
    void createDB();
    //创建数据表
    void createTable();
    //查询
    void queryTable();
    QSqlDatabase db;//建立QT和数据库连接
    QSqlQueryModel model;//保存结果集
};
#endif // MAINWINDOW_H
