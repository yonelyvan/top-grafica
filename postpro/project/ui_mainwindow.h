/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QWidget *centralWidget;
    QLabel *label_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLabel *label_histogram;
    QLabel *label_img;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QSlider *hs_equalize;
    QLabel *label_4;
    QPushButton *pushButton;
    QWidget *tab_2;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_6;
    QSlider *horizontalSlider_convB;
    QSlider *horizontalSlider_convG;
    QSlider *horizontalSlider_convR;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QSlider *horizontalSlider_conv_CG;
    QSlider *horizontalSlider_conv_CR;
    QSlider *horizontalSlider_conv_CB;
    QWidget *tab_4;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1271, 749);
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 90, 59, 14));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 1261, 691));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_histogram = new QLabel(tab_3);
        label_histogram->setObjectName(QStringLiteral("label_histogram"));
        label_histogram->setGeometry(QRect(10, 20, 231, 171));
        label_histogram->setStyleSheet(QStringLiteral("border: 1px solid black"));
        label_histogram->setScaledContents(true);
        label_img = new QLabel(tab_3);
        label_img->setObjectName(QStringLiteral("label_img"));
        label_img->setGeometry(QRect(250, 20, 751, 571));
        label_img->setStyleSheet(QStringLiteral("border: 1px solid black"));
        label_img->setScaledContents(true);
        tabWidget = new QTabWidget(tab_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(1010, 0, 241, 651));
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 40, 171, 21));
        label->setScaledContents(false);
        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(11, 60, 221, 20));
        horizontalSlider->setMinimum(-255);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(11, 100, 171, 16));
        horizontalSlider_2 = new QSlider(tab);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(11, 120, 221, 20));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setValue(50);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        hs_equalize = new QSlider(tab);
        hs_equalize->setObjectName(QStringLiteral("hs_equalize"));
        hs_equalize->setGeometry(QRect(10, 180, 221, 20));
        hs_equalize->setMaximum(20);
        hs_equalize->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(11, 160, 171, 16));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 221, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 60, 201, 16));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 211, 31));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 80, 201, 22));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 120, 181, 16));
        horizontalSlider_convB = new QSlider(tab_2);
        horizontalSlider_convB->setObjectName(QStringLiteral("horizontalSlider_convB"));
        horizontalSlider_convB->setGeometry(QRect(30, 200, 191, 16));
        horizontalSlider_convB->setMaximum(100);
        horizontalSlider_convB->setValue(50);
        horizontalSlider_convB->setOrientation(Qt::Horizontal);
        horizontalSlider_convG = new QSlider(tab_2);
        horizontalSlider_convG->setObjectName(QStringLiteral("horizontalSlider_convG"));
        horizontalSlider_convG->setGeometry(QRect(30, 170, 191, 16));
        horizontalSlider_convG->setMaximum(100);
        horizontalSlider_convG->setValue(50);
        horizontalSlider_convG->setOrientation(Qt::Horizontal);
        horizontalSlider_convR = new QSlider(tab_2);
        horizontalSlider_convR->setObjectName(QStringLiteral("horizontalSlider_convR"));
        horizontalSlider_convR->setGeometry(QRect(30, 140, 191, 16));
        horizontalSlider_convR->setMaximum(100);
        horizontalSlider_convR->setValue(50);
        horizontalSlider_convR->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 140, 21, 16));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 170, 16, 16));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 200, 21, 16));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 290, 21, 16));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 320, 16, 16));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 350, 21, 16));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 270, 171, 16));
        horizontalSlider_conv_CG = new QSlider(tab_2);
        horizontalSlider_conv_CG->setObjectName(QStringLiteral("horizontalSlider_conv_CG"));
        horizontalSlider_conv_CG->setGeometry(QRect(30, 320, 191, 16));
        horizontalSlider_conv_CG->setMaximum(100);
        horizontalSlider_conv_CG->setValue(50);
        horizontalSlider_conv_CG->setOrientation(Qt::Horizontal);
        horizontalSlider_conv_CR = new QSlider(tab_2);
        horizontalSlider_conv_CR->setObjectName(QStringLiteral("horizontalSlider_conv_CR"));
        horizontalSlider_conv_CR->setGeometry(QRect(30, 290, 191, 16));
        horizontalSlider_conv_CR->setMaximum(100);
        horizontalSlider_conv_CR->setValue(50);
        horizontalSlider_conv_CR->setOrientation(Qt::Horizontal);
        horizontalSlider_conv_CB = new QSlider(tab_2);
        horizontalSlider_conv_CB->setObjectName(QStringLiteral("horizontalSlider_conv_CB"));
        horizontalSlider_conv_CB->setGeometry(QRect(30, 350, 191, 16));
        horizontalSlider_conv_CB->setMaximum(100);
        horizontalSlider_conv_CB->setValue(50);
        horizontalSlider_conv_CB->setOrientation(Qt::Horizontal);
        tabWidget->addTab(tab_2, QString());
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1271, 19));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionAbrir);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", 0));
        label_3->setText(QString());
        label_histogram->setText(QString());
        label_img->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Brillo (-255, 255)", 0));
        label_2->setText(QApplication::translate("MainWindow", "Contraste (0.0, 2.0)", 0));
        label_4->setText(QApplication::translate("MainWindow", "Ecualizar (0-20%)", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Reiniciar Valores", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Exposici\303\263n", 0));
        label_5->setText(QApplication::translate("MainWindow", "Conversion - Escala de grises", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Reiniciar Valores", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "convertir", 0));
        label_6->setText(QApplication::translate("MainWindow", "Convertir - Escala de grises", 0));
        label_7->setText(QApplication::translate("MainWindow", "R", 0));
        label_8->setText(QApplication::translate("MainWindow", "G", 0));
        label_9->setText(QApplication::translate("MainWindow", "B", 0));
        label_10->setText(QApplication::translate("MainWindow", "R", 0));
        label_11->setText(QApplication::translate("MainWindow", "G", 0));
        label_12->setText(QApplication::translate("MainWindow", "B", 0));
        label_13->setText(QApplication::translate("MainWindow", "Transformaciones de color", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Color", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Tab 2", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "archivo", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
