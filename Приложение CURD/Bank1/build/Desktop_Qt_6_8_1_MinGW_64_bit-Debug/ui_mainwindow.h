/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addButton;
    QTableView *tableView;
    QPushButton *deleteButton;
    QPushButton *switchToTable1;
    QPushButton *switchToTable2;
    QPushButton *switchToTable3;
    QPushButton *pushButton_6;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(994, 546);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 410, 80, 29));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 821, 391));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(120, 410, 83, 29));
        switchToTable1 = new QPushButton(centralwidget);
        switchToTable1->setObjectName("switchToTable1");
        switchToTable1->setGeometry(QRect(850, 10, 131, 61));
        switchToTable2 = new QPushButton(centralwidget);
        switchToTable2->setObjectName("switchToTable2");
        switchToTable2->setGeometry(QRect(850, 80, 131, 61));
        switchToTable3 = new QPushButton(centralwidget);
        switchToTable3->setObjectName("switchToTable3");
        switchToTable3->setGeometry(QRect(850, 150, 131, 61));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(220, 410, 83, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 400, 391, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 430, 621, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 994, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        switchToTable1->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\320\270\320\265\320\275\321\202\321\213", nullptr));
        switchToTable2->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\321\213", nullptr));
        switchToTable3->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\260\320\275\320\267\320\260\320\272\321\206\320\270\320\270", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\270 \320\272\320\260\320\266\320\264\320\276\320\271 \321\217\321\207\320\265\320\271\320\272\320\270 \320\275\320\260\320\266\320\270\320\274\320\260\320\271\321\202\320\265 ENTER, ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\321\202\320\260\320\272\320\266\320\265 \321\201\320\270\321\201\321\202\320\265\320\274\320\260 \320\275\320\265 \320\264\320\260\321\201\321\202 \320\262\320\260\320\274 \321\201\320\276\320\267\320\264\320\260\321\202\321\214 \320\273\321\216\320\264\320\265\320\271 \321\201 \320\276\320\264\320\270\320\275\320\260\320\272\320\276\320\262\320\276\320\271 \320\277\320\276\321\207\321\202\320\276\320\271 \320\270 \320\275\320\276\320\274\320\265\321\200\320\260\320\274\320\270 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
