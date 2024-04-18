/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionsave_gif;
    QAction *actionsave_png;
    QAction *actionsave_JPEG;
    QWidget *centralwidget;
    myglwidget *glWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_modelName;
    QLabel *label_facet_amount;
    QLabel *label_vertex_amount;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QSpinBox *spinBox_xRotate;
    QLabel *label_5;
    QSpinBox *spinBox_yRotate;
    QLabel *label_6;
    QSpinBox *spinBox_zRotate;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_Scale;
    QPushButton *pushButton_resetMove;
    QCheckBox *checkBox_dashed;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_xMove;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_yMove;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_zMove;
    QFrame *line_4;
    QLabel *label_7;
    QFrame *line_6;
    QCheckBox *checkBox_round;
    QPushButton *pushButton_moveReset;
    QPushButton *pushButton_go;
    QPushButton *pushButton_rotate;
    QPushButton *pushButton_scale;
    QPushButton *pushButton_rotateReset;
    QRadioButton *radio_facet;
    QRadioButton *radio_vertex;
    QRadioButton *radio_full;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_setColor_3;
    QPushButton *pushButton_setColor_2;
    QPushButton *pushButton_setColor;
    QPushButton *pushButton_resetBasis;
    QCheckBox *checkBox_projection;
    QLabel *label_11;
    QLabel *label_12;
    QSlider *Vertex_slider;
    QSlider *Facet_slider;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 670);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionsave_gif = new QAction(MainWindow);
        actionsave_gif->setObjectName(QString::fromUtf8("actionsave_gif"));
        actionsave_png = new QAction(MainWindow);
        actionsave_png->setObjectName(QString::fromUtf8("actionsave_png"));
        actionsave_JPEG = new QAction(MainWindow);
        actionsave_JPEG->setObjectName(QString::fromUtf8("actionsave_JPEG"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        glWidget = new myglwidget(centralwidget);
        glWidget->setObjectName(QString::fromUtf8("glWidget"));
        glWidget->setGeometry(QRect(10, 10, 600, 600));
        layoutWidget = new QWidget(glWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 530, 581, 65));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_modelName = new QLabel(layoutWidget);
        label_modelName->setObjectName(QString::fromUtf8("label_modelName"));
        QFont font;
        font.setUnderline(false);
        font.setStrikeOut(false);
        label_modelName->setFont(font);
        label_modelName->setStyleSheet(QString::fromUtf8("color: rgb(0, 180, 0);"));

        gridLayout_2->addWidget(label_modelName, 0, 0, 1, 1);

        label_facet_amount = new QLabel(layoutWidget);
        label_facet_amount->setObjectName(QString::fromUtf8("label_facet_amount"));
        label_facet_amount->setFont(font);
        label_facet_amount->setStyleSheet(QString::fromUtf8("color: rgb(0, 180, 0);"));

        gridLayout_2->addWidget(label_facet_amount, 2, 0, 1, 1);

        label_vertex_amount = new QLabel(layoutWidget);
        label_vertex_amount->setObjectName(QString::fromUtf8("label_vertex_amount"));
        label_vertex_amount->setFont(font);
        label_vertex_amount->setStyleSheet(QString::fromUtf8("color: rgb(0, 180, 0);"));

        gridLayout_2->addWidget(label_vertex_amount, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(630, 379, 270, 80));
        horizontalLayout_9 = new QHBoxLayout(groupBox_3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_4);

        spinBox_xRotate = new QSpinBox(groupBox_3);
        spinBox_xRotate->setObjectName(QString::fromUtf8("spinBox_xRotate"));
        spinBox_xRotate->setMinimum(-360);
        spinBox_xRotate->setMaximum(360);

        horizontalLayout_9->addWidget(spinBox_xRotate);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_5);

        spinBox_yRotate = new QSpinBox(groupBox_3);
        spinBox_yRotate->setObjectName(QString::fromUtf8("spinBox_yRotate"));
        spinBox_yRotate->setMinimum(-360);
        spinBox_yRotate->setMaximum(360);

        horizontalLayout_9->addWidget(spinBox_yRotate);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_6);

        spinBox_zRotate = new QSpinBox(groupBox_3);
        spinBox_zRotate->setObjectName(QString::fromUtf8("spinBox_zRotate"));
        spinBox_zRotate->setMinimum(-360);
        spinBox_zRotate->setMaximum(360);

        horizontalLayout_9->addWidget(spinBox_zRotate);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(630, 470, 101, 72));
        gridLayout = new QGridLayout(groupBox_5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        doubleSpinBox_Scale = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_Scale"));
        doubleSpinBox_Scale->setMinimum(-100.000000000000000);
        doubleSpinBox_Scale->setMaximum(100.000000000000000);

        gridLayout->addWidget(doubleSpinBox_Scale, 0, 0, 1, 1);

        pushButton_resetMove = new QPushButton(centralwidget);
        pushButton_resetMove->setObjectName(QString::fromUtf8("pushButton_resetMove"));
        pushButton_resetMove->setGeometry(QRect(900, 491, 81, 51));
        pushButton_resetMove->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 190, 111);\n"
"color: rgb(198, 70, 0);"));
        checkBox_dashed = new QCheckBox(centralwidget);
        checkBox_dashed->setObjectName(QString::fromUtf8("checkBox_dashed"));
        checkBox_dashed->setGeometry(QRect(880, 100, 75, 23));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(726, 49, 41, 41));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(855, 49, 20, 41));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(630, 40, 341, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(630, 284, 270, 80));
        horizontalLayout_7 = new QHBoxLayout(groupBox_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label);

        doubleSpinBox_xMove = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_xMove->setObjectName(QString::fromUtf8("doubleSpinBox_xMove"));
        doubleSpinBox_xMove->setMinimum(-10000.000000000000000);
        doubleSpinBox_xMove->setMaximum(10000.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_xMove);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_2);

        doubleSpinBox_yMove = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_yMove->setObjectName(QString::fromUtf8("doubleSpinBox_yMove"));
        doubleSpinBox_yMove->setMinimum(-10000.000000000000000);
        doubleSpinBox_yMove->setMaximum(10000.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_yMove);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_3);

        doubleSpinBox_zMove = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_zMove->setObjectName(QString::fromUtf8("doubleSpinBox_zMove"));
        doubleSpinBox_zMove->setMinimum(-10000.000000000000000);
        doubleSpinBox_zMove->setMaximum(10000.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_zMove);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(620, 80, 351, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(630, 20, 151, 17));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label_7->setFont(font1);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(630, 547, 351, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        checkBox_round = new QCheckBox(centralwidget);
        checkBox_round->setObjectName(QString::fromUtf8("checkBox_round"));
        checkBox_round->setGeometry(QRect(760, 100, 66, 23));
        pushButton_moveReset = new QPushButton(centralwidget);
        pushButton_moveReset->setObjectName(QString::fromUtf8("pushButton_moveReset"));
        pushButton_moveReset->setGeometry(QRect(909, 305, 72, 26));
        pushButton_moveReset->setStyleSheet(QString::fromUtf8("color: rgb(229, 165, 10);\n"
"background-color: rgb(249, 240, 107);"));
        pushButton_go = new QPushButton(centralwidget);
        pushButton_go->setObjectName(QString::fromUtf8("pushButton_go"));
        pushButton_go->setGeometry(QRect(909, 338, 72, 26));
        pushButton_go->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 240, 164);\n"
"color: rgb(38, 162, 105);"));
        pushButton_rotate = new QPushButton(centralwidget);
        pushButton_rotate->setObjectName(QString::fromUtf8("pushButton_rotate"));
        pushButton_rotate->setGeometry(QRect(909, 433, 72, 26));
        pushButton_rotate->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 240, 164);\n"
"color: rgb(38, 162, 105);"));
        pushButton_scale = new QPushButton(centralwidget);
        pushButton_scale->setObjectName(QString::fromUtf8("pushButton_scale"));
        pushButton_scale->setGeometry(QRect(740, 490, 151, 52));
        QFont font2;
        font2.setPointSize(14);
        pushButton_scale->setFont(font2);
        pushButton_scale->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 240, 164);\n"
"color: rgb(38, 162, 105);"));
        pushButton_rotateReset = new QPushButton(centralwidget);
        pushButton_rotateReset->setObjectName(QString::fromUtf8("pushButton_rotateReset"));
        pushButton_rotateReset->setGeometry(QRect(910, 400, 72, 26));
        pushButton_rotateReset->setStyleSheet(QString::fromUtf8("color: rgb(229, 165, 10);\n"
"background-color: rgb(249, 240, 107);"));
        radio_facet = new QRadioButton(centralwidget);
        radio_facet->setObjectName(QString::fromUtf8("radio_facet"));
        radio_facet->setGeometry(QRect(880, 60, 62, 23));
        radio_vertex = new QRadioButton(centralwidget);
        radio_vertex->setObjectName(QString::fromUtf8("radio_vertex"));
        radio_vertex->setGeometry(QRect(760, 60, 71, 23));
        radio_full = new QRadioButton(centralwidget);
        radio_full->setObjectName(QString::fromUtf8("radio_full"));
        radio_full->setGeometry(QRect(650, 60, 50, 23));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(630, 200, 341, 80));
        horizontalLayout_10 = new QHBoxLayout(groupBox_4);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_setColor_3 = new QPushButton(groupBox_4);
        pushButton_setColor_3->setObjectName(QString::fromUtf8("pushButton_setColor_3"));

        horizontalLayout_10->addWidget(pushButton_setColor_3);

        pushButton_setColor_2 = new QPushButton(groupBox_4);
        pushButton_setColor_2->setObjectName(QString::fromUtf8("pushButton_setColor_2"));

        horizontalLayout_10->addWidget(pushButton_setColor_2);

        pushButton_setColor = new QPushButton(groupBox_4);
        pushButton_setColor->setObjectName(QString::fromUtf8("pushButton_setColor"));

        horizontalLayout_10->addWidget(pushButton_setColor);

        pushButton_resetBasis = new QPushButton(centralwidget);
        pushButton_resetBasis->setObjectName(QString::fromUtf8("pushButton_resetBasis"));
        pushButton_resetBasis->setGeometry(QRect(790, 570, 191, 25));
        pushButton_resetBasis->setStyleSheet(QString::fromUtf8("color: rgb(0, 180, 0);\n"
"background-color: rgba(0, 0, 0, 100);\n"
"border-color: rgb(0, 255, 0);"));
        checkBox_projection = new QCheckBox(centralwidget);
        checkBox_projection->setObjectName(QString::fromUtf8("checkBox_projection"));
        checkBox_projection->setGeometry(QRect(630, 570, 161, 23));
        checkBox_projection->setStyleSheet(QString::fromUtf8("color: rgb(0, 180, 0);"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(630, 140, 151, 17));
        label_11->setFont(font1);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(630, 170, 151, 17));
        label_12->setFont(font1);
        Vertex_slider = new QSlider(centralwidget);
        Vertex_slider->setObjectName(QString::fromUtf8("Vertex_slider"));
        Vertex_slider->setGeometry(QRect(769, 140, 201, 20));
        Vertex_slider->setMinimum(1);
        Vertex_slider->setMaximum(10);
        Vertex_slider->setOrientation(Qt::Horizontal);
        Facet_slider = new QSlider(centralwidget);
        Facet_slider->setObjectName(QString::fromUtf8("Facet_slider"));
        Facet_slider->setGeometry(QRect(770, 170, 201, 20));
        Facet_slider->setMinimum(1);
        Facet_slider->setMaximum(10);
        Facet_slider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setAutoFillBackground(false);
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionsave_gif);
        menuFile->addAction(actionsave_png);
        menuFile->addAction(actionsave_JPEG);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3D Viwer", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionsave_gif->setText(QCoreApplication::translate("MainWindow", "save GIF", nullptr));
        actionsave_png->setText(QCoreApplication::translate("MainWindow", "save BMP", nullptr));
        actionsave_JPEG->setText(QCoreApplication::translate("MainWindow", "save JPEG", nullptr));
        label_modelName->setText(QString());
        label_facet_amount->setText(QString());
        label_vertex_amount->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        pushButton_resetMove->setText(QCoreApplication::translate("MainWindow", "RETURN", nullptr));
        checkBox_dashed->setText(QCoreApplication::translate("MainWindow", "dashed", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Mode view", nullptr));
        checkBox_round->setText(QCoreApplication::translate("MainWindow", "round", nullptr));
        pushButton_moveReset->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_go->setText(QCoreApplication::translate("MainWindow", "GO", nullptr));
        pushButton_rotate->setText(QCoreApplication::translate("MainWindow", "ROT", nullptr));
        pushButton_scale->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_rotateReset->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        radio_facet->setText(QCoreApplication::translate("MainWindow", "Facet", nullptr));
        radio_vertex->setText(QCoreApplication::translate("MainWindow", "Vertex", nullptr));
        radio_full->setText(QCoreApplication::translate("MainWindow", "Full", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Color picker", nullptr));
        pushButton_setColor_3->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        pushButton_setColor_2->setText(QCoreApplication::translate("MainWindow", "Vertex color", nullptr));
        pushButton_setColor->setText(QCoreApplication::translate("MainWindow", "Facet color", nullptr));
        pushButton_resetBasis->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        checkBox_projection->setText(QCoreApplication::translate("MainWindow", "Central projection", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Vertex's thickness", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Facet's thickness", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
