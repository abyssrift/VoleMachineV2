#include "cpu.h"
#include "QDebug"
#include <QMessageBox>
#include <QThread>
#include <ui_mainwindow.h>
#include <mainwindow.h>
using namespace std;

std::vector<std::string> previousMemoryState;

CPU::CPU(Memory& mainmemory2,QObject* parent)
    : mainmemory(mainmemory2), QObject(parent),
    programCounter(mainmemory, instruReg),
    instruReg(),
    cu(mainmemory, instruReg, register_16, instruction, programCounter),
    alu(mainmemory, instruReg, register_16, instruction) {
    qDebug() << "CPU successfully initiated";
}

ControlUnit& CPU::GetControlUnit() {
    return cu;
}

Register& CPU::GetRegisters() {
    return register_16;
}

ALU& CPU::GetALU() {
    return alu;
}

InstructionRegister& CPU::GetInstructionReg() {
    return instruReg;
}

Memory& CPU::GetMemory() {
    return mainmemory;
}

void CPU::DisplayMemory() {
    qDebug() << "==================MainMemory==============";
    for (int i = 0; i < 251; i += 5) {
        if (mainmemory.GetMemoryValue(i) != "00" || mainmemory.GetMemoryValue(i + 1) != "00" ||
            mainmemory.GetMemoryValue(i + 2) != "00" || mainmemory.GetMemoryValue(i + 3) != "00" ||
            mainmemory.GetMemoryValue(i + 4) != "00") {

            qDebug() << mainmemory.GetMemoryValue(i) << " - "
                 << mainmemory.GetMemoryValue(i + 1) << " - "
                 << mainmemory.GetMemoryValue(i + 2) << " - "
                 << mainmemory.GetMemoryValue(i + 3) << " - "
                 << mainmemory.GetMemoryValue(i + 4);
        }
    }
    qDebug() << "===========================================";
}

void CPU::DisplayRegisters() {
    qDebug() << "==================Registers==============";
    for (int i = 0; i < 12; i += 4) {
            qDebug() << register_16.GetRegisterValue(i) << " - "
                 << register_16.GetRegisterValue(i + 1) << " - "
                 << register_16.GetRegisterValue(i + 2) << " - "
                 << register_16.GetRegisterValue(i + 3);
        }
    qDebug() << "===========================================";
}

bool CPU::IsEnd() {
    if (instruReg.ReturnValue() == "C000" || programCounter.GetCounter() >= 255) {
        qDebug() << "program exited by user through instructions";
        DisplayMemory();
        DisplayRegisters();
        return true;
    }
    return false;
}
bool CPU::EmptyMemoryError(){
    if(mainmemory.IsEmpty()){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical); // Set the icon to critical (error)
        msgBox.setText("Error!"); // Set the main text
        msgBox.setInformativeText("Memory Is Empty! Unable to run"); // Set the detailed message
        msgBox.setStandardButtons(QMessageBox::Ok); // Add an OK button
        msgBox.exec(); // Display the message box
        msgBox.setWindowIcon(QIcon(":/new/prefix2/IconsResources/IconResources/jamesvolticon.png"));
        msgBox.setWindowTitle("Memory Error!");
        return true;
    }
    return false;
}
int CPU::GetCounter(){
    return programCounter.GetCounter();
}
void CPU::SetSpeed(int value){
    Speed = value;
}

void CPU::SetMemoryUI() {
    QString memoryState = getMemoryStateAsQString();
}
bool CPU::GetStopCycles(){
    return StopCycles;
}
void CPU::ResetCounter(){
    programCounter.SetCounter(0);
}

void CPU::cycle() {
    programCounter.runInstructions();
    if(IsEnd()){
        emit requesttimerstop();
    }
    instruReg.decode();
    instruction = instruReg.GetInstruction();
    Direction = instruReg.GetDirection();
    if (Direction == 1) {
        cu.Decode();
        cu.CoutInstruction();
    } else if (Direction == 2) {
        alu.Decode();
    }
    instruReg.SetDirection(0);
    SetMemoryUI();
    UnusedInstructions = instruReg.GetUnusedInstrucitons();
    emit requestmemoryupdate(getMemoryStateAsQString());
    emit requestregisterupdate(getRegister_16StateAsQString());
    emit requestinstruregupdate(getInstruRegStateAsQString());
    emit requestprogramcounterupdate(getProgramCounterStateAsQString());
    emit requestregistercomparison(CompareRegister_16StateAsQString());
    emit requestunusedinstructions(UnusedInstructions);
}

void CPU::Start() {
    for (int i =0; i < 255; i++) {
        if(IsEnd() || EmptyMemoryError()){
            emit requestmemoryupdate(getMemoryStateAsQString());
            emit requestregisterupdate(getRegister_16StateAsQString());
            emit requestinstruregupdate(getInstruRegStateAsQString());
            emit requestprogramcounterupdate(getProgramCounterStateAsQString());
            break;
        }
        cycle();
    }
}



QString CPU::getRegister_16StateAsQString() {
    QString RegistersQString;

    RegistersQString += "-------------------------------------------------\n";

    for (int i = 0; i < 16; ++i) {
        RegistersQString += QString("R%1: %2 | ")
                                .arg(i, 2, 10, QChar('0'))
                                .arg(QString::fromStdString(register_16.GetRegisterValue(i)), 2, QChar('0'));
        if ((i + 1) % 4 == 0) {
            RegistersQString += "\n";
        }
    }

    RegistersQString += "-------------------------------------------------\n";
    return RegistersQString;
}



void CPU::ResetRegisters(){
    register_16.ResetRegisters();
}
QString OldRegister_16 = "";

QString CPU::CompareRegister_16StateAsQString() {

    if (programCounter.GetCounter() == 0) {
        return "";
    }

    QString diffResult;
    QString newRegister_16 = getRegister_16StateAsQString();


    QStringList oldValues = OldRegister_16.split('|', Qt::SkipEmptyParts);
    QStringList newValues = newRegister_16.split('|', Qt::SkipEmptyParts);


    oldValues.removeAll("-------------------------------------------------");
    newValues.removeAll("-------------------------------------------------");

    for (int i = 0; i < oldValues.size() && i < newValues.size(); ++i) {
        QString oldRegister = oldValues[i].section(':', 0, 0).trimmed();
        QString oldValue = oldValues[i].section(':', 1).trimmed();
        QString newRegister = newValues[i].section(':', 0, 0).trimmed();
        QString newValue = newValues[i].section(':', 1).trimmed();
        if (oldRegister == newRegister && oldValue != newValue) {
            diffResult = QString("%1: %2").arg(newRegister).arg(newValue);
            break;
        }
    }

    OldRegister_16 = newRegister_16;
    qDebug() << "diff" << diffResult;
    return diffResult;
}


QString CPU::getMemoryStateAsQString() {
    QString MemoryQString;
    int columns = 16;

    MemoryQString += "      ";
    for (int j = 0; j < columns; ++j) {
        MemoryQString += QString("%1 ").arg(j, 2, 16, QChar('0')).toUpper();
        if (j == 7) {
            MemoryQString += "  ";
        }
    }
    MemoryQString += "\n";
    MemoryQString += "    ----------------------------------------------------\n";

    for (int i = 0; i < 256; ++i) {
        if (i % columns == 0) {
            MemoryQString += QString("0x%1| ").arg(i, 2, 16, QChar('0')).toUpper();
        }

        MemoryQString += QString("%1 ").arg(QString::fromStdString(mainmemory.GetMemoryValue(i)), 2, QChar('0'));

        if ((i % columns == 7) && (i % columns != 15)) {
            MemoryQString += "  ";
        }
        if (i % columns == (columns - 1)) {
            MemoryQString += "\n";
        }
    }
    MemoryQString += "    ----------------------------------------------------";

    return MemoryQString;
}
QString CPU::getInstruRegStateAsQString(){
    return QString::fromStdString(instruReg.GetInstruction());
}

string CPU::GetMemoryValue(int value){
    return mainmemory.GetMemoryValue(value);
}
string DectoHex(int dec){
    stringstream ss;
    ss << hex << dec;
    string hex_num = ss.str();
    transform(hex_num.begin(),hex_num.end(),hex_num.begin(),::toupper);
    return hex_num;
}

QString CPU::getProgramCounterStateAsQString(){
    return QString::fromStdString(DectoHex(programCounter.GetCounter()));
}
