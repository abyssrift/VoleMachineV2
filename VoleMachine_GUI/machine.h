#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include "memory.h"   // Include the header files for Memory, CPU, and Register
#include "cpu.h"      // Ensure these headers define the needed classes
#include "register.h"

class MainWindow;

class Machine {
private:
    Memory& mainmemory;
    CPU& cpu;


public:
    Machine(CPU& cpu2, Memory& mainmemory);  // Constructor declaration
    Memory& GetMemory();
    CPU& GetCpu();
    Register& GetRegister();
    void SetMainMemoryValue(int address, const std::string& value);
    void Start();
    void ResetMemory();
    void ResetRegisters();
    string GetScreenMemory();
    void SetSpeed(int value);
    void OneCycle();
    bool StopCycles = false;
    bool GetStopCycles();
    QString Getregister_16();
    QString Getmemory_16();
};

#endif // MACHINE_H
