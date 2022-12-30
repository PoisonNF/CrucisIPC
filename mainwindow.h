#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QString>
#include <QSerialPortInfo>
#include <QMessageBox>

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
};
#endif // MAINWINDOW_H
