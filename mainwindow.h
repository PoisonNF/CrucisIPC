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
    QSerialPort *serialPort;    //定义一个SerialPort
private slots:

    void on_OpenPB_clicked();   //开启槽函数

    void on_ClosePB_clicked();  //关闭槽函数

    void on_SendPB_clicked();   //发送槽函数

    void on_ClearPB_clicked();  //清空槽函数

    void serialPortReadReady_Slot();    //串口准备接收槽函数
private:
    Ui::MainWindow *ui;

    void createDB();    //创建数据库

    void createTable(); //创建数据表

    void queryTable();  //查询

    QSqlDatabase db;        //建立QT和数据库连接
    QSqlQueryModel JYmodel; //保存JY901结果集
    QSqlQueryModel RMmodel; //保存RM3100结果集
    QStringList data;       //保存被切割数据
};
#endif // MAINWINDOW_H
