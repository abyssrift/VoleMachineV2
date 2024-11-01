/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelp;
    QAction *actionHelp_2;
    QAction *actionTXT_File;
    QAction *actionTXT_File_2;
    QAction *actionInstructions;
    QAction *actionOperating_Machine;
    QWidget *centralwidget;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout;
    QFrame *frame_14;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLabel *Running_Errors;
    QFrame *frame_6;
    QGridLayout *gridLayout_3;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_5;
    QLabel *InstructionRegister_Label;
    QPushButton *OneStep_btn;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *run_btn;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Program_Counter_Label;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *Instructions_Result;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout;
    QTextEdit *ManualInstruBox;
    QPushButton *Enter_btn;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *Current_Speed;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *point5speedbutton;
    QPushButton *pushButton_6;
    QFrame *frame_4;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *Register16_output;
    QLabel *label_4;
    QFrame *frame_15;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_17;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QTextEdit *Screen;
    QFrame *frame_16;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QTextEdit *Console;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QTextEdit *Memory_output;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1140, 900);
        MainWindow->setMinimumSize(QSize(1080, 900));
        MainWindow->setMaximumSize(QSize(1140, 900));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName("actionHelp");
        actionHelp_2 = new QAction(MainWindow);
        actionHelp_2->setObjectName("actionHelp_2");
        actionTXT_File = new QAction(MainWindow);
        actionTXT_File->setObjectName("actionTXT_File");
        actionTXT_File_2 = new QAction(MainWindow);
        actionTXT_File_2->setObjectName("actionTXT_File_2");
        actionInstructions = new QAction(MainWindow);
        actionInstructions->setObjectName("actionInstructions");
        actionOperating_Machine = new QAction(MainWindow);
        actionOperating_Machine->setObjectName("actionOperating_Machine");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(600, 0));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(560, 0, 568, 531));
        frame_2->setMinimumSize(QSize(100, 80));
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        frame_9 = new QFrame(frame_2);
        frame_9->setObjectName("frame_9");
        frame_9->setMaximumSize(QSize(16777215, 16777215));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        frame_9->setLineWidth(2);
        verticalLayout = new QVBoxLayout(frame_9);
        verticalLayout->setObjectName("verticalLayout");
        frame_14 = new QFrame(frame_9);
        frame_14->setObjectName("frame_14");
        frame_14->setMaximumSize(QSize(16777215, 40));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_14);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label = new QLabel(frame_14);
        label->setObjectName("label");
        label->setMaximumSize(QSize(100, 25));

        horizontalLayout_7->addWidget(label);

        Running_Errors = new QLabel(frame_14);
        Running_Errors->setObjectName("Running_Errors");

        horizontalLayout_7->addWidget(Running_Errors);


        verticalLayout->addWidget(frame_14);

        frame_6 = new QFrame(frame_9);
        frame_6->setObjectName("frame_6");
        frame_6->setMaximumSize(QSize(16777215, 100));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_6->setLineWidth(3);
        gridLayout_3 = new QGridLayout(frame_6);
        gridLayout_3->setObjectName("gridLayout_3");
        frame_12 = new QFrame(frame_6);
        frame_12->setObjectName("frame_12");
        frame_12->setMinimumSize(QSize(78, 0));
        frame_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"       background-color: #e8f5e9;\n"
"       color: #2e7d32;      \n"
"       font-size: 10px;            \n"
"       font-family: Consolas, monospace;\n"
"        border: 1px solid #a5d6a7;  \n"
"        padding: 10px;         \n"
"    }"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_12);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        InstructionRegister_Label = new QLabel(frame_12);
        InstructionRegister_Label->setObjectName("InstructionRegister_Label");
        InstructionRegister_Label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"       background-color: #e8f5e9;\n"
"       color: #2e7d32;      \n"
"       font-size: 10px;            \n"
"       font-family: Consolas, monospace;\n"
"        border: 1px solid #a5d6a7;  \n"
"                \n"
"    }"));

        horizontalLayout_5->addWidget(InstructionRegister_Label);


        gridLayout_3->addWidget(frame_12, 0, 0, 3, 1);

        OneStep_btn = new QPushButton(frame_6);
        OneStep_btn->setObjectName("OneStep_btn");
        OneStep_btn->setMinimumSize(QSize(0, 24));
        OneStep_btn->setMaximumSize(QSize(350, 50));
        OneStep_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 247);\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        gridLayout_3->addWidget(OneStep_btn, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(frame_6);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: orange;\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        gridLayout_3->addWidget(pushButton_7, 2, 4, 1, 1);

        pushButton_5 = new QPushButton(frame_6);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: Red;\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        gridLayout_3->addWidget(pushButton_5, 0, 4, 1, 1);

        run_btn = new QPushButton(frame_6);
        run_btn->setObjectName("run_btn");
        run_btn->setMinimumSize(QSize(0, 24));
        run_btn->setMaximumSize(QSize(350, 50));
        run_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 247);\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        gridLayout_3->addWidget(run_btn, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(frame_6);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 24));
        pushButton_2->setMaximumSize(QSize(350, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: green;\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        gridLayout_3->addWidget(pushButton_2, 2, 3, 1, 1);

        pushButton_3 = new QPushButton(frame_6);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(0, 24));
        pushButton_3->setMaximumSize(QSize(350, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: green;\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        gridLayout_3->addWidget(pushButton_3, 0, 3, 1, 1);

        frame_13 = new QFrame(frame_6);
        frame_13->setObjectName("frame_13");
        frame_13->setStyleSheet(QString::fromUtf8("QLabel{\n"
"       background-color: #e8f5e9;\n"
"       color: #2e7d32;      \n"
"       font-size: 10px;            \n"
"       font-family: Consolas, monospace;\n"
"        border: 1px solid #a5d6a7;  \n"
"        padding: 10px;         \n"
"    }"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_13);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        Program_Counter_Label = new QLabel(frame_13);
        Program_Counter_Label->setObjectName("Program_Counter_Label");

        horizontalLayout_6->addWidget(Program_Counter_Label);


        gridLayout_3->addWidget(frame_13, 0, 1, 3, 1);


        verticalLayout->addWidget(frame_6);

        frame_5 = new QFrame(frame_9);
        frame_5->setObjectName("frame_5");
        frame_5->setMaximumSize(QSize(16777215, 50));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(frame_5);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(200, 18));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        Instructions_Result = new QLabel(frame_5);
        Instructions_Result->setObjectName("Instructions_Result");
        Instructions_Result->setEnabled(true);

        horizontalLayout_3->addWidget(Instructions_Result);


        verticalLayout->addWidget(frame_5);

        frame_7 = new QFrame(frame_9);
        frame_7->setObjectName("frame_7");
        frame_7->setMinimumSize(QSize(0, 100));
        frame_7->setMaximumSize(QSize(16777215, 100));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        frame_7->setLineWidth(2);
        horizontalLayout = new QHBoxLayout(frame_7);
        horizontalLayout->setObjectName("horizontalLayout");
        ManualInstruBox = new QTextEdit(frame_7);
        ManualInstruBox->setObjectName("ManualInstruBox");
        ManualInstruBox->setMaximumSize(QSize(16777215, 80));
        ManualInstruBox->setFrameShape(QFrame::Box);
        ManualInstruBox->setFrameShadow(QFrame::Raised);
        ManualInstruBox->setLineWidth(2);

        horizontalLayout->addWidget(ManualInstruBox);

        Enter_btn = new QPushButton(frame_7);
        Enter_btn->setObjectName("Enter_btn");
        Enter_btn->setMaximumSize(QSize(100, 16777215));
        Enter_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 247);\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        horizontalLayout->addWidget(Enter_btn);


        verticalLayout->addWidget(frame_7);

        frame_11 = new QFrame(frame_9);
        frame_11->setObjectName("frame_11");
        frame_11->setMaximumSize(QSize(16777215, 40));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(frame_11);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        Current_Speed = new QLabel(frame_11);
        Current_Speed->setObjectName("Current_Speed");

        horizontalLayout_4->addWidget(Current_Speed);


        verticalLayout->addWidget(frame_11);

        frame_10 = new QFrame(frame_9);
        frame_10->setObjectName("frame_10");
        frame_10->setMaximumSize(QSize(16777215, 80));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(frame_10);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 247);\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_4 = new QPushButton(frame_10);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 247);\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_4);

        point5speedbutton = new QPushButton(frame_10);
        point5speedbutton->setObjectName("point5speedbutton");
        point5speedbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 247);\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        horizontalLayout_2->addWidget(point5speedbutton);

        pushButton_6 = new QPushButton(frame_10);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 247);\n"
"    color:wheat;\n"
"    border-radius: 10px;\n"
"    width: 100px;\n"
"    height: 50px;\n"
"}\n"
"QPushButton:hover {\n"
"    opacity:0.4;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(32, 32, 168);\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_6);


        verticalLayout->addWidget(frame_10);


        verticalLayout_6->addWidget(frame_9);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(10, 0, 551, 531));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 530, 491, 311));
        frame->setMinimumSize(QSize(0, 0));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName("gridLayout_4");
        frame_8 = new QFrame(frame);
        frame_8->setObjectName("frame_8");
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        frame_8->setLineWidth(2);
        verticalLayout_2 = new QVBoxLayout(frame_8);
        verticalLayout_2->setObjectName("verticalLayout_2");
        Register16_output = new QTextEdit(frame_8);
        Register16_output->setObjectName("Register16_output");
        Register16_output->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"       background-color: #e8f5e9;\n"
"       color: #2e7d32;      \n"
"       font-size: 14px;            \n"
"       font-family: Consolas, monospace;\n"
"        border: 1px solid #a5d6a7;  \n"
"        padding: 10px;         \n"
"    }"));
        Register16_output->setLineWidth(2);
        Register16_output->setReadOnly(true);

        verticalLayout_2->addWidget(Register16_output);


        gridLayout_4->addWidget(frame_8, 2, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setMaximumSize(QSize(16777215, 35));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        frame_15 = new QFrame(centralwidget);
        frame_15->setObjectName("frame_15");
        frame_15->setGeometry(QRect(500, 530, 631, 311));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_15);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_17 = new QFrame(frame_15);
        frame_17->setObjectName("frame_17");
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_17);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_6 = new QLabel(frame_17);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(16777215, 30));

        verticalLayout_4->addWidget(label_6);

        Screen = new QTextEdit(frame_17);
        Screen->setObjectName("Screen");
        Screen->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"       background-color: #e8f5e9;\n"
"       color: #2e7d32;      \n"
"       font-size: 30px;            \n"
"       font-family: Consolas, monospace;\n"
"        border: 1px solid #a5d6a7;  \n"
"        padding: 10px;         \n"
"		\n"
"    }"));
        Screen->setReadOnly(true);

        verticalLayout_4->addWidget(Screen);


        verticalLayout_3->addWidget(frame_17);

        frame_16 = new QFrame(frame_15);
        frame_16->setObjectName("frame_16");
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_16);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_7 = new QLabel(frame_16);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(16777215, 25));

        verticalLayout_5->addWidget(label_7);

        Console = new QTextEdit(frame_16);
        Console->setObjectName("Console");
        Console->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"       background-color: #e8f5e9;\n"
"       color: #2e7d32;      \n"
"       font-size: 14px;            \n"
"       font-family: Consolas, monospace;\n"
"        border: 1px solid #a5d6a7;  \n"
"        padding: 10px;         \n"
"		\n"
"    }"));

        verticalLayout_5->addWidget(Console);


        verticalLayout_3->addWidget(frame_16);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(20, 10, 531, 511));
        frame_3->setMinimumSize(QSize(0, 0));
        frame_3->setMaximumSize(QSize(16777215, 16777215));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        frame_3->setProperty("color", QVariant(QColor(0, 0, 0)));
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setObjectName("gridLayout_2");
        label_3 = new QLabel(frame_3);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setMaximumSize(QSize(16777215, 50));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        Memory_output = new QTextEdit(frame_3);
        Memory_output->setObjectName("Memory_output");
        Memory_output->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"       background-color: #e8f5e9;\n"
"       color: #2e7d32;      \n"
"       font-size: 14px;            \n"
"       font-family: Consolas, monospace;\n"
"        border: 1px solid #a5d6a7;  \n"
"        padding: 10px;         \n"
"    }"));
        Memory_output->setLineWidth(2);
        Memory_output->setReadOnly(true);

        gridLayout_2->addWidget(Memory_output, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1140, 31));
        menubar->setStyleSheet(QString::fromUtf8("	color: black;\n"
"	border: none;\n"
"    border-bottom: 2px solid rgb(241, 255, 255 );\n"
"    padding: 5px; "));
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
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionHelp_2->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionTXT_File->setText(QCoreApplication::translate("MainWindow", "TXT File", nullptr));
        actionTXT_File_2->setText(QCoreApplication::translate("MainWindow", "TXT File", nullptr));
        actionInstructions->setText(QCoreApplication::translate("MainWindow", "Instructions", nullptr));
        actionOperating_Machine->setText(QCoreApplication::translate("MainWindow", "Operating Machine", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Control Panel</span></p><p align=\"center\"><span style=\" font-size:12pt;\"><br/></span></p></body></html>", nullptr));
        Running_Errors->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        InstructionRegister_Label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Instruction</p><p align=\"center\">0000</p></body></html>", nullptr));
        OneStep_btn->setText(QCoreApplication::translate("MainWindow", "StepOver", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Reset Counter", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", " Clear Screen", nullptr));
        run_btn->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Reset Memory", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Reset Register", nullptr));
        Program_Counter_Label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Counter</p><p align=\"center\">00</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Manual Instructions</span></p></body></html>", nullptr));
        Instructions_Result->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ManualInstruBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Place Manual Instructions Here", nullptr));
        Enter_btn->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Speed Controller", nullptr));
        Current_Speed->setText(QCoreApplication::translate("MainWindow", "Current Speed : 1x", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "0.1x", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "0.25x", nullptr));
        point5speedbutton->setText(QCoreApplication::translate("MainWindow", "0.5x", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "1x", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Registers</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Screen</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Console</span></p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Main Memory</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
