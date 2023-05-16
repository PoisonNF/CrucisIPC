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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *mainLayout;
    QWidget *titleBar;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *minimumBtn;
    QPushButton *adjSizeBtn;
    QPushButton *closeBtn;
    QWidget *mainDisplayWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *displayLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1158, 832);
        MainWindow->setMouseTracking(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMouseTracking(true);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 30, 30, 30);
        mainWidget = new QWidget(centralwidget);
        mainWidget->setObjectName("mainWidget");
        mainWidget->setMouseTracking(true);
        verticalLayout_3 = new QVBoxLayout(mainWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        mainLayout = new QVBoxLayout();
        mainLayout->setSpacing(5);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(-1, 0, -1, -1);
        titleBar = new QWidget(mainWidget);
        titleBar->setObjectName("titleBar");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleBar->sizePolicy().hasHeightForWidth());
        titleBar->setSizePolicy(sizePolicy);
        titleBar->setMinimumSize(QSize(0, 30));
        titleBar->setMaximumSize(QSize(16777215, 30));
        titleBar->setMouseTracking(true);
        horizontalLayout_2 = new QHBoxLayout(titleBar);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(13);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 15, 20, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minimumBtn = new QPushButton(titleBar);
        minimumBtn->setObjectName("minimumBtn");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(minimumBtn->sizePolicy().hasHeightForWidth());
        minimumBtn->setSizePolicy(sizePolicy1);
        minimumBtn->setMinimumSize(QSize(12, 12));
        minimumBtn->setMaximumSize(QSize(12, 12));
        minimumBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#c2c2c2;border-radius:6px}\n"
"QPushButton:hover {background-color:#f9bf45;border-radius:6px;}\n"
"QPushButton:pressed {background-color:#ffb11b;border-radius:6px;}"));

        horizontalLayout->addWidget(minimumBtn);

        adjSizeBtn = new QPushButton(titleBar);
        adjSizeBtn->setObjectName("adjSizeBtn");
        adjSizeBtn->setMinimumSize(QSize(12, 12));
        adjSizeBtn->setMaximumSize(QSize(12, 12));
        adjSizeBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#c2c2c2;border-radius:6px}\n"
"QPushButton:hover {background-color:#227d51;border-radius:6px;}\n"
"QPushButton:pressed {background-color:#2d6d4b;border-radius:6px;}"));

        horizontalLayout->addWidget(adjSizeBtn);

        closeBtn = new QPushButton(titleBar);
        closeBtn->setObjectName("closeBtn");
        sizePolicy.setHeightForWidth(closeBtn->sizePolicy().hasHeightForWidth());
        closeBtn->setSizePolicy(sizePolicy);
        closeBtn->setMinimumSize(QSize(12, 12));
        closeBtn->setMaximumSize(QSize(12, 12));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#c2c2c2;border-radius:6px}\n"
"QPushButton:hover {background-color:#cb4042;border-radius:6px;}\n"
"QPushButton:pressed {background-color:#ab3b3a;border-radius:6px;}"));

        horizontalLayout->addWidget(closeBtn);


        horizontalLayout_2->addLayout(horizontalLayout);


        mainLayout->addWidget(titleBar);

        mainDisplayWidget = new QWidget(mainWidget);
        mainDisplayWidget->setObjectName("mainDisplayWidget");
        mainDisplayWidget->setMouseTracking(true);
        verticalLayout_2 = new QVBoxLayout(mainDisplayWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        displayLayout = new QVBoxLayout();
        displayLayout->setObjectName("displayLayout");
        displayLayout->setContentsMargins(30, 15, 30, 30);

        verticalLayout_2->addLayout(displayLayout);


        mainLayout->addWidget(mainDisplayWidget);


        verticalLayout_3->addLayout(mainLayout);


        verticalLayout->addWidget(mainWidget);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(minimumBtn, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::showMinimized));
        QObject::connect(closeBtn, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        minimumBtn->setText(QString());
        adjSizeBtn->setText(QString());
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
