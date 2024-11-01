#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include <iostream>
#include <string>
#include "memory.h"
#include "register.h"
#include "instructionregister.h"
#include "programcounter.h"

using namespace std;

class ControlUnit {
private:
    Memory& mainmemory;
    Register& Register_16;
    InstructionRegister& instruRegister;
    string& instruction;
    ProgramCounter& programcounter;

public:
    ControlUnit(Memory& memory, InstructionRegister& InstruReg, Register& register_16, string& instruction2, ProgramCounter& ProgramCounter);

    void GetMemory(Memory& memory);
    void CoutInstruction();

    void Load(int address, int RegisterSinglenumber);
    void Load(string value, int RegisterSinglenumber);
    void Store(int address, int RegisterSinglenumber);
    void Move(int RegisterSinglenumber1, int RegisterSinglenumber2);
    void Jump(int address, int Registernumber);
    void Decode();
};

#endif // CONTROL_UNIT_H
