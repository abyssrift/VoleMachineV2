#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>
#include "memory.h"
#include "programcounter.h"
#include "instructionregister.h"
#include "register.h"
#include "controlunit.h"
#include <QObject>
#include "alu.h"

class MainWindow;

class CPU : public QObject{
    Q_OBJECT
private:
    Memory& mainmemory;
    ProgramCounter programCounter;
    InstructionRegister instruReg;
    Register register_16;
    ControlUnit cu;
    ALU alu;
    std::string instruction = "0000";
    int Direction = 0;
    int Speed = 0;
    vector<string> UnusedInstructions;

public:
    explicit CPU(Memory& mainmemory2, QObject *parent = nullptr);  // Constructor declaration

    ControlUnit& GetControlUnit();
    Register& GetRegisters();
    ALU& GetALU();
    InstructionRegister& GetInstructionReg();
    Memory& GetMemory();

    void DisplayMemory();
    void DisplayRegisters();
    bool IsEnd();
    void cycle();
    void ResetRegisters();
    bool StopCycles = false;
    bool GetStopCycles();
    void SetSpeed(int value);
    void SetMemoryUI();
    void ResetCounter();
    string GetMemoryValue(int value);
    int GetCounter();
    bool EmptyMemoryError();
    QString getMemoryStateAsQString();
    QString getRegister_16StateAsQString();
    QString getInstruRegStateAsQString();
    QString getProgramCounterStateAsQString();
    QString CompareRegister_16StateAsQString();
    vector<string> getunusedinstructionsStateAsQString();
signals:
    void requestmemoryupdate(const QString& message);
    void requestregisterupdate(const QString& message);
    void requestprogramcounterupdate(const QString& message);
    void requestinstruregupdate(const QString& message);
    void requesttimerstop();
    void requestregistercomparison(const QString& message);
    void requestunusedinstructions(vector<string> unusedinstructions);
public slots:
    void Start();

};

#endif // CPU_H
