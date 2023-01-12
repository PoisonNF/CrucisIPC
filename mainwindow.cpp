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
    createDB();     //创建数据库
    createTable();  //创建数据表
    queryTable();   //查询
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*创建数据库*/
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
/*创建数据表*/
void MainWindow::createTable()
{
    QSqlQuery query;
    QString jystr = QString("CREATE TABLE jy901 ("
                          "ID INT PRIMARY KEY NOT NULL,"
                          "Data TEXT NOT NULL,"
                          "X REAL,"
                          "Y REAL,"
                          "Z REAL)");
    query.exec(jystr);
    qDebug() << "jy901数据表创建";

    QString rmstr = QString("CREATE TABLE rm3100 ("
                            "ID INT PRIMARY KEY NOT NULL,"
                            "X REAL,"
                            "Y REAL,"
                            "Z REAL)");
    query.exec(rmstr);
    qDebug() << "rm3100数据表创建";
}
/*查询*/
void MainWindow::queryTable()
{

    QString jystr = QString("SELECT * FROM jy901");
    JYmodel.setQuery(jystr);
    ui->JY901TB->setModel(&JYmodel);
    ui->JY901TB->verticalHeader()->setHidden(true);//把QTableView中第一列的默认数字列去掉
    ui->JY901TB->setColumnWidth(0,50);
    ui->JY901TB->setColumnWidth(1,75);
    ui->JY901TB->setColumnWidth(2,100);
    ui->JY901TB->setColumnWidth(3,100);
    //ui->JY901TB->resizeColumnsToContents();//将列宽自适应数据长度
    //ui->JY901TB->resizeRowsToContents();//将行宽自适应数据长度
    ui->JY901TB->setAlternatingRowColors(true);//QTableView隔行换色

    QString rmstr = QString("SELECT * FROM rm3100");
    RMmodel.setQuery(rmstr);
    ui->RM3100TB->setModel(&RMmodel);
    ui->RM3100TB->verticalHeader()->setHidden(true);
    ui->RM3100TB->setColumnWidth(0,50);
    ui->RM3100TB->setColumnWidth(1,100);
    ui->RM3100TB->setColumnWidth(2,100);
    ui->RM3100TB->setColumnWidth(3,100);
    ui->RM3100TB->setAlternatingRowColors(true);
}

/*开启槽函数*/
void MainWindow::on_OpenPB_clicked()
{
    QSerialPort::BaudRate baudRate = QSerialPort::Baud115200;
    QSerialPort::DataBits dataBits = QSerialPort::Data8;
    QSerialPort::StopBits stopBits = QSerialPort::OneStop;
    QSerialPort::Parity checkBits  = QSerialPort::NoParity;

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

/*关闭槽函数*/
void MainWindow::on_ClosePB_clicked()
{
    serialPort->close();
    QMessageBox::information(this,"提示",ui->UartCB->currentText()+"已关闭");
}

/*发送槽函数*/
void MainWindow::on_SendPB_clicked()
{
    serialPort->write(ui->SendLE->text().toLocal8Bit().data());
}

/*清空槽函数*/
void MainWindow::on_ClearPB_clicked()
{
    ui->ReceivePTE->clear();
}

/*串口准备接收槽函数*/
void MainWindow::serialPortReadReady_Slot()
{
    QString buf;
    buf = QString(serialPort->readLine());
    ui->ReceivePTE->ensureCursorVisible(); //通过滚动文本编辑确保光标可见,始终显示最新一行
    ui->ReceivePTE->insertPlainText(buf);


    //以空格进行分割
    QStringList data = buf.split(u' ');

    //如果是JY901的数据
    if(data.at(0) == 'J')
    {
        //查询数据表中是否已经存在数据
        QString checkstr = QString("SELECT * FROM jy901 WHERE ID = '%1'").arg(data.at(1));
        QSqlQuery query(checkstr);
        if(query.next()) //存在数据，执行更新操作
        {
            QString updatestr = QString("UPDATE jy901 SET Data = '%2', X = %3, Y = %4, Z = %5 WHERE ID = %1")
                    .arg(data.at(1),data.at(2),data.at(3),data.at(4),data.at(5));
            query.exec(updatestr);
        }
        else
        {
            QString insertstr = QString("INSERT INTO jy901 VALUES(%1,'%2',%3,%4,%5)")
                    .arg(data.at(1),data.at(2),data.at(3),data.at(4),data.at(5));
            query.exec(insertstr);
        }

        //QString deletestr = QString("DELETE FROM jy901 WHERE ID = %1").arg(data.at(1));
        //query.exec(deletestr);
    }

    //如果是RM3100的数据
    if(data.at(0) == 'R')
    {
        //查询数据表中是否已经存在数据
        QString checkstr = QString("SELECT * FROM rm3100 WHERE ID = '%1'").arg(data.at(1));
        QSqlQuery query(checkstr);
        if(query.next()) //存在数据，执行更新操作
        {
            QString updatestr = QString("UPDATE rm3100 SET X = %2, Y = %3, Z = %4 WHERE ID = %1")
                    .arg(data.at(1),data.at(2),data.at(3),data.at(4));
            query.exec(updatestr);
        }
        else //不存在数据，执行插入操作
        {
            QString insertstr = QString("INSERT INTO rm3100 VALUES(%1,%2,%3,%4)")
                    .arg(data.at(1),data.at(2),data.at(3),data.at(4));
            query.exec(insertstr);
        }
        //QString deletestr = QString("DELETE FROM rm3100 WHERE ID = %1").arg(data.at(1));
        //query.exec(deletestr);
    }
    queryTable();   //显示到Table View上

}
