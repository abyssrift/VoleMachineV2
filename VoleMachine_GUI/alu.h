#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>
#include "memory.h"           // Include necessary headers for dependencies
#include "register.h"
#include "instructionregister.h"

using namespace std;

class ALU {
private:
    Memory& mainmemory;
    Register& Register_16;
    InstructionRegister& instruRegister;
    string& instruction;

    // Conversion functions
    int HextoDec(string hex);
    string DectoHex(int dec);
    string HextoBin(string hex);
    string BintoHex(string bin);
    double BintoDec(string bin);
    string DectoBin(double dec);

public:
    ALU(Memory& memory, InstructionRegister& instruReg, Register& register_16, string& instruction2);

    string floating_point_sum(string num1, string num2);
    string twosComplements_sum(string num1, string num2);

    void Add2complement(int R, int S, int T);
    void AddFloat(int RegisternumberR, int RegisternumberS, int RegisternumberT);
    void bitwiseOR(int R, int S, int T);
    void bitwiseAND(int R, int S, int T);
    void bitwiseXOR(int R, int S, int T);

    void SetInstruction(string instru);
    void Decode();
};

#endif // ALU_H
