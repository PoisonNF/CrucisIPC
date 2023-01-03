#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*读取可使用的串口号*/
    QStringList serialNamePort;
    serialPort = new QSerialPort(this);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) { //将可用的端口放入info中
        serialNamePort << info.portName();      //将端口名传给QStringList
    }
    ui->UartCB->addItems(serialNamePort);       //输出到串口号CB上

    /*关联控件和槽函数*/
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(serialPortReadReady_Slot()));

    /*SQLite相关初始化*/
    //创建数据库
    createDB();
    //创建数据表
    createTable();
    //查询
    queryTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//创建数据库
void MainWindow::createDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("CrucisIPC.db");
    if(db.open()==true)
    {
        qDebug() << "创建或者打开数据库成功！";
    }
    else
    {
        qDebug() << "创建或者打开数据库失败！";
    }
}
//创建数据表
void MainWindow::createTable()
{
    QSqlQuery query;
    QString str = QString("CREATE TABLE jy901 ("
                          "ID INT PRIMARY KEY NOT NULL,"
                          "Data TEXT NOT NULL,"
                          "X REAL,"
                          "Y REAL,"
                          "Z REAL)");
    query.exec(str);
}
//查询
void MainWindow::queryTable()
{
    QString str = QString("SELECT * FROM jy901");
    model.setQuery(str);
    ui->JY901TB->setModel(&model);
}

//开启槽函数
void MainWindow::on_OpenPB_clicked()
{
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity checkBits;

    //获取波特率控件上面的数据
    if(ui->BaudCB->currentText() == "9600") baudRate = QSerialPort::Baud9600;
    else if (ui->BaudCB->currentText() == "115200") baudRate = QSerialPort::Baud115200;

    //获取数据位控件上面的数据
    if(ui->DataCB->currentText() == "5") dataBits = QSerialPort::Data5;
    else if(ui->DataCB->currentText() == "6") dataBits = QSerialPort::Data6;
    else if(ui->DataCB->currentText() == "7") dataBits = QSerialPort::Data7;
    else if(ui->DataCB->currentText() == "8") dataBits = QSerialPort::Data8;

    //获取停止位控件上面的数据
    if(ui->StopCB->currentText() == "1") stopBits = QSerialPort::OneStop;
    else if(ui->StopCB->currentText() == "1.5") stopBits = QSerialPort::OneAndHalfStop;
    else if(ui->StopCB->currentText() == "2") stopBits = QSerialPort::TwoStop;

    //获取校验位控件上面的数据
    if(ui->checkCB->currentText() == "None") checkBits = QSerialPort::NoParity;
    else if(ui->checkCB->currentText() == "Odd") checkBits = QSerialPort::OddParity;
    else if(ui->checkCB->currentText() == "Even") checkBits = QSerialPort::EvenParity;

    //为串口赋值
    serialPort->setPortName(ui->UartCB->currentText());
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(checkBits);
    if(serialPort->open(QIODevice::ReadWrite)== true)
    {
        QMessageBox::information(this,"提示",ui->UartCB->currentText()+"打开成功");
    }
    else
    {
        QMessageBox::critical(this,"提示",ui->UartCB->currentText()+"打开失败");
    }

}

//关闭槽函数
void MainWindow::on_ClosePB_clicked()
{
    serialPort->close();
    QMessageBox::information(this,"提示",ui->UartCB->currentText()+"已关闭");
}

//发送槽函数
void MainWindow::on_SendPB_clicked()
{
    serialPort->write(ui->SendLE->text().toLocal8Bit().data());
}

//清空槽函数
void MainWindow::on_ClearPB_clicked()
{
    ui->ReceivePTE->clear();
}

//串口准备接收槽函数
void MainWindow::serialPortReadReady_Slot()
{
    QString buf;
    buf = QString(serialPort->readAll());
    ui->ReceivePTE->appendPlainText(buf);

    QStringList data = buf.split(u' ');
    QString updatestr = QString("UPDATE jy901 SET Data = '%2', X = %3, Y = %4, Z = %5 WHERE ID = %1")
            .arg(data.at(0)).arg(data.at(1)).arg(data.at(2)).arg(data.at(3)).arg(data.at(4));
    QString str = QString("INSERT INTO jy901 VALUES(%1,'%2',%3,%4,%5)")
            .arg(data.at(0)).arg(data.at(1)).arg(data.at(2)).arg(data.at(3)).arg(data.at(4));
    QString deletestr = QString("DELETE FROM jy901 WHERE id = %1").arg(data.at(0));
    QSqlQuery query;
    query.exec(str);
    query.exec(updatestr);
    //query.exec(deletestr);
    queryTable();
}
