#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cpu.h>
#include "ui_mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <instructioninfodialog.h>
#include<QMessageBox>
#include <qslider.h>
#include <QSlider>
#include <QInputDialog>
#include <QDebug>
#include <cmath>
#include <QMouseEvent>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QRubberBand>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include<QCursor>
#include<QRadioButton>
#include <QPushButton>
#include <vector>
#include <qtimer.h>
#include <machine.h>
#include <algorithm>
#include<cpu.h>
#include <QObject>
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <sstream>


QT_BEGIN_NAMESPACE
class Machine;

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Machine& machine,CPU& cpu,QWidget *parent = nullptr);
    ~MainWindow();
    void SetInstructionRegister(std::string instruction);
    void updateRegisterDisplay(const QString& registerData);
    void updateMemoryDisplay(const QString& memorystate);
public slots:
    void DisplayMemory(const QString& message);
    void DisplayRegister_16(const QString& message);
    void DisplayInstruReg(const QString& message);
    void StopTimer();
    void DisplayProgramCounter(const QString& message);
    void DisplayRegisterComparison(const QString& message);
    void ProcessAndDisplayUnusedInstructions(vector<string> unusedinstructions);
    void createFileWithUserName();
    void importFile();
    void DisplayHelp();
private slots:
    void on_run_btn_clicked();

    void on_pushButton_3_clicked();

    void on_Enter_btn_clicked();

    void InstructionError(QString);

    void on_pushButton_2_clicked();

    void on_OneStep_btn_clicked();

    void callonecycle();

    void RefreshUI();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_point5speedbutton_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

signals:

private:
    Ui::MainWindow *ui;
   Machine& initialisedMachine;
    CPU& cpu;
    bool Running = false;
    bool CanRun = true;
    void PrintToScreen();
   QTimer* timer;
    QMenu *Import;
   vector<string> UsedInstructionForCompiler;
};
#endif // MAINWINDOW_H
