#ifndef PROGRAMCOUNTER_H
#define PROGRAMCOUNTER_H

#include "memory.h"
#include "instructionregister.h"
#include <string>
#include <iostream>
using namespace std;

class ProgramCounter {
public:
    ProgramCounter(Memory& mainMemory2, InstructionRegister& instructionRegister);  // Constructor

    void GetMemory();
    void SetCounter(int value);
    int GetCounter();
    bool isEndOfProgram();
    void PassInstruction();
    void runInstructions();

private:
    Memory& mainMemory;
    string instruc;
    int counter = 2;
    InstructionRegister& instructionReg;
};

#endif // PROGRAMCOUNTER_H
