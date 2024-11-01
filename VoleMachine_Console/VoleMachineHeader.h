// vole_machine.h
#ifndef VOLE_MACHINE_H
#define VOLE_MACHINE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdint>

using namespace std;

// Utility functions for conversions between hexadecimal, decimal, and binary
int HextoDec(string hex);
string DectoHex(int dec);
string HextoBin(string hex);
string BintoHex(string bin);
double BintoDec(string bin);
string DectoBin(double dec);

// Single Register class - Represents an 8-bit register in the machine
class RegisterSingle {
public:
    void SetRegisterSingle(string s);
    void SetRegisterSingle(int n, char s);
    string ReturnValue();
    RegisterSingle();

protected:
    string value;
};

// Instruction Register class - Inherits from RegisterSingle, stores and decodes instructions
class InstructionRegister : public RegisterSingle {
public:
    string GetInstruction();
    int GetDirection();
    void SetDirection(int value);
    void decode();
    InstructionRegister();

private:
    int Direction = 0;
    vector<char> ControlUnitOperations{'1','2','3','4', 'A','B','C','D'};
    vector<char> ALUOperations{'5','6','7','8','9'};
};

// Register class - Contains a vector of RegisterSingle objects representing multiple registers
class Register {
public:
    Register();
    void SetRegisterSingle(int index, string s);
    RegisterSingle GetRegister(int index);
    string GetRegisterValue(int index);

private:
    vector<RegisterSingle> RegisterVector;
};

// Memory class - Represents main memory, storing values in memory slots
class Memory {
public:
    Memory();
    void SetMemoryValue(int address, string value);
    string GetMemoryValue(int address);
    void ClearSlot(int address);
    void ResizeMemory(int memorysize);
    void Clear();

private:
    vector<string> memoryslots;
};

// Program Counter class - Handles the instruction flow control and manages the program counter
class ProgramCounter {
public:
    ProgramCounter(Memory& mainMemory2, InstructionRegister& instructionRegister);
    void GetMemory();
    void SetCounter(int value);
    int GetCounter();
    bool isEndOfProgram();
    void PassInstruction();
    void runInstructions();

private:
    Memory& mainMemory;
    InstructionRegister& instructionReg;
    string instruc;
    int counter = 0;
};

// Arithmetic Logic Unit (ALU) class - Executes arithmetic and logic operations
class ALU {
public:
    ALU(Memory& memory, InstructionRegister& instruReg, Register& register_16, string& instruction2);
    string floating_point_sum(string num1, string num2);
    string twosComplements_sum(string num1, string num2);
    void Add2complement(int R, int S, int T);
    void AddFloat(int R, int S, int T);
    void bitwiseOR(int R, int S, int T);
    void bitwiseAND(int R, int S, int T);
    void bitwiseXOR(int R, int S, int T);
    void SetInstruction(string instru);
    void Decode();

private:
    Memory& mainmemory;
    Register& Register_16;
    InstructionRegister& instruRegister;
    string& instruction;
};

// Control Unit class - Executes control flow and handles instructions
class ControlUnit {
public:
    ControlUnit(Memory& memory, InstructionRegister& InstruReg, Register& register_16, string& instruction2, ProgramCounter& ProgramCounter);
    void GetMemory(Memory& memory);
    void CoutInstruction();
    void Load(int address, int RegisterSinglenumber);
    void Load(string value, int RegisterSinglenumber);
    void Store(int address, int RegisterSinglenumber);
    void Move(int RegisterSinglenumber1, int RegisterSinglenumber2);
    void Rotate(int Registernumber, string rotations);
    void equality_jump(int address, int Registernumber);
    void comparison_jump(int address, int Registernumber);
    void Decode();

private:
    Memory& mainmemory;
    Register& Register_16;
    InstructionRegister& instruRegister;
    string& instruction;
    string CurrentOperation;
    ProgramCounter& programcounter;
};

// Central Processing Unit (CPU) class - Main execution control, integrates all components
class CPU {
public:
    CPU(Memory& mainmemory2);
    ControlUnit& GetControlUnit();
    Register& GetRegisters();
    ALU& GetALU();
    InstructionRegister& GetInstructionReg();
    Memory& GetMemory();
    void DisplayMemory();
    void DisplayRegisters();
    void CheckEnd();
    void cycle();
    void Start();

private:
    Memory& mainmemory;
    ProgramCounter programCounter;
    InstructionRegister instruReg;
    Register register_16;
    ControlUnit cu;
    ALU alu;
    string instruction = "0000";
    int Direction = 0;
};
class Machine {
private:
    Memory mainmemory;
    CPU cpu;
public:
    Memory& GetMemory();
    CPU& GetCpu();
    Register& GetRegister();
    Machine();
    void SetMainMemoryValue(int address, string value);

    void Start();
};

#endif // VOLE_MACHINE_H
