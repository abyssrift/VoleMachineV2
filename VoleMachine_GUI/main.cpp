#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include "machine.h"
#include <cpu.h>
#include <memory.h>
#include <qobject.h>


int main(int argc, char *argv[])
{
    Memory mainmemory;
    CPU cpu(mainmemory);
    Machine machine(cpu,mainmemory);
    QApplication a(argc, argv);
    MainWindow w(machine,cpu); // Create MainWindow first // Pass MainWindow pointer to Machine
    QObject::connect(&cpu, &CPU::requestmemoryupdate, &w, &MainWindow::DisplayMemory);
    QObject::connect(&cpu,&CPU::requestregisterupdate,&w,&MainWindow::DisplayRegister_16);
    QObject::connect(&cpu,&CPU::requestinstruregupdate,&w,&MainWindow::DisplayInstruReg);
    QObject::connect(&cpu,&CPU::requestprogramcounterupdate,&w,&MainWindow::DisplayProgramCounter);
    QObject::connect(&cpu, &CPU::requesttimerstop,&w,&MainWindow::StopTimer);
    QObject::connect(&cpu, &CPU::requestregistercomparison,&w,&MainWindow::DisplayRegisterComparison);
    QObject::connect(&cpu, &CPU::requestunusedinstructions,&w,&MainWindow::ProcessAndDisplayUnusedInstructions);
    w.show();
    w.setWindowTitle("James Volt Machine");
     w.setWindowIcon(QIcon(":/new/prefix2/IconsResources/IconResources/jamesvolticon.png"));
    return a.exec();
}


