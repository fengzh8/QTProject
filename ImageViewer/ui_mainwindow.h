/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QLabel *img;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *imgList;
    QPushButton *selectDir;
    QPushButton *previous;
    QPushButton *next;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1297, 654);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        img = new QLabel(widget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(9, 9, 30, 16));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(img->sizePolicy().hasHeightForWidth());
        img->setSizePolicy(sizePolicy);
        img->setScaledContents(true);
        img->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(widget);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        imgList = new QListWidget(groupBox);
        imgList->setObjectName(QString::fromUtf8("imgList"));

        verticalLayout->addWidget(imgList);

        selectDir = new QPushButton(groupBox);
        selectDir->setObjectName(QString::fromUtf8("selectDir"));

        verticalLayout->addWidget(selectDir);

        previous = new QPushButton(groupBox);
        previous->setObjectName(QString::fromUtf8("previous"));

        verticalLayout->addWidget(previous);

        next = new QPushButton(groupBox);
        next->setObjectName(QString::fromUtf8("next"));

        verticalLayout->addWidget(next);


        horizontalLayout->addWidget(groupBox);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1297, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\233\270\350\247\201", nullptr));
        img->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\261\236\346\200\247", nullptr));
        selectDir->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266\345\244\271", nullptr));
        previous->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", nullptr));
        next->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
