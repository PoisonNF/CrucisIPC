/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QPlainTextEdit *plainTextEdit_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QTableView *JY901TB;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QPlainTextEdit *plainTextEdit_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QPlainTextEdit *plainTextEdit_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QPlainTextEdit *plainTextEdit_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *UartCB;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *BaudCB;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *DataCB;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *StopCB;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *checkCB;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_6;
    QPlainTextEdit *ReceivePTE;
    QGridLayout *gridLayout_2;
    QLineEdit *SendLE;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *OpenPB;
    QSpacerItem *horizontalSpacer;
    QPushButton *ClosePB;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *SendPB;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *ClearPB;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(858, 779);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 841, 721));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        verticalLayout_3->addWidget(label_7);

        plainTextEdit_2 = new QPlainTextEdit(layoutWidget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setMinimumSize(QSize(0, 0));
        plainTextEdit_2->setReadOnly(true);

        verticalLayout_3->addWidget(plainTextEdit_2);


        gridLayout_3->addLayout(verticalLayout_3, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        JY901TB = new QTableView(layoutWidget);
        JY901TB->setObjectName("JY901TB");

        verticalLayout->addWidget(JY901TB);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");

        verticalLayout_5->addWidget(label_9);

        plainTextEdit_5 = new QPlainTextEdit(layoutWidget);
        plainTextEdit_5->setObjectName("plainTextEdit_5");
        plainTextEdit_5->setReadOnly(true);

        verticalLayout_5->addWidget(plainTextEdit_5);


        gridLayout_3->addLayout(verticalLayout_5, 2, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName("label_10");

        verticalLayout_2->addWidget(label_10);

        plainTextEdit_3 = new QPlainTextEdit(layoutWidget);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setReadOnly(true);

        verticalLayout_2->addWidget(plainTextEdit_3);


        gridLayout_3->addLayout(verticalLayout_2, 1, 0, 2, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        verticalLayout_4->addWidget(label_8);

        plainTextEdit_4 = new QPlainTextEdit(layoutWidget);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setReadOnly(true);

        verticalLayout_4->addWidget(plainTextEdit_4);


        gridLayout_3->addLayout(verticalLayout_4, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        UartCB = new QComboBox(layoutWidget);
        UartCB->setObjectName("UartCB");

        horizontalLayout->addWidget(UartCB);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(15);
        label->setFont(font);

        horizontalLayout->addWidget(label);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        BaudCB = new QComboBox(layoutWidget);
        BaudCB->addItem(QString());
        BaudCB->addItem(QString());
        BaudCB->setObjectName("BaudCB");

        horizontalLayout_2->addWidget(BaudCB);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        DataCB = new QComboBox(layoutWidget);
        DataCB->addItem(QString());
        DataCB->addItem(QString());
        DataCB->addItem(QString());
        DataCB->addItem(QString());
        DataCB->setObjectName("DataCB");

        horizontalLayout_3->addWidget(DataCB);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        StopCB = new QComboBox(layoutWidget);
        StopCB->addItem(QString());
        StopCB->addItem(QString());
        StopCB->addItem(QString());
        StopCB->setObjectName("StopCB");

        horizontalLayout_4->addWidget(StopCB);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        checkCB = new QComboBox(layoutWidget);
        checkCB->addItem(QString());
        checkCB->addItem(QString());
        checkCB->addItem(QString());
        checkCB->setObjectName("checkCB");

        horizontalLayout_5->addWidget(checkCB);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 1, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        ReceivePTE = new QPlainTextEdit(layoutWidget);
        ReceivePTE->setObjectName("ReceivePTE");
        ReceivePTE->setReadOnly(true);

        verticalLayout_6->addWidget(ReceivePTE);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        SendLE = new QLineEdit(layoutWidget);
        SendLE->setObjectName("SendLE");

        gridLayout_2->addWidget(SendLE, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        OpenPB = new QPushButton(layoutWidget);
        OpenPB->setObjectName("OpenPB");

        horizontalLayout_6->addWidget(OpenPB);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        ClosePB = new QPushButton(layoutWidget);
        ClosePB->setObjectName("ClosePB");

        horizontalLayout_6->addWidget(ClosePB);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        SendPB = new QPushButton(layoutWidget);
        SendPB->setObjectName("SendPB");

        horizontalLayout_6->addWidget(SendPB);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        ClearPB = new QPushButton(layoutWidget);
        ClearPB->setObjectName("ClearPB");

        horizontalLayout_6->addWidget(ClearPB);


        gridLayout_2->addLayout(horizontalLayout_6, 1, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_2);


        gridLayout_4->addLayout(verticalLayout_6, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 858, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CrucisIPC", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\216\250\350\277\233\345\231\250\351\200\237\347\216\207", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "JY901S", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "OpenMV", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "RM3100", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Jetson", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        BaudCB->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        BaudCB->setItemText(1, QCoreApplication::translate("MainWindow", "115200", nullptr));

        BaudCB->setCurrentText(QCoreApplication::translate("MainWindow", "115200", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        DataCB->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        DataCB->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        DataCB->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        DataCB->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        DataCB->setCurrentText(QCoreApplication::translate("MainWindow", "8", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        StopCB->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        StopCB->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        StopCB->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        checkCB->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        checkCB->setItemText(1, QCoreApplication::translate("MainWindow", "Odd", nullptr));
        checkCB->setItemText(2, QCoreApplication::translate("MainWindow", "Even", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        OpenPB->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        ClosePB->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
        SendPB->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        ClearPB->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
