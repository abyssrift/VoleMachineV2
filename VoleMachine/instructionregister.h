#ifndef INSTRUCTIONREGISTER_H
#define INSTRUCTIONREGISTER_H

#include "registersingle.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class InstructionRegister : public RegisterSingle {
public:
    InstructionRegister();  // Constructor

    string GetInstruction();
    int GetDirection();
    void SetDirection(int value);
    void decode();
    vector<string>& GetUnusedInstrucitons();
private:
    int Direction = 0;
    vector<char> ControlUnitOperations{'1', '2', '3', '4', 'B', 'C'};
    vector<char> ALUOperations{'5', '6'};
    vector<string> UnusedInstructions;
};

#endif // INSTRUCTIONREGISTER_H
