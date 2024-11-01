#include "instructionregister.h"
#include "QDebug"
// Constructor
InstructionRegister::InstructionRegister() {
    qDebug() << "InstruReg successfully initiated";
}

// Returns the current instruction
string InstructionRegister::GetInstruction() {
    return value;
}

// Returns the direction value
int InstructionRegister::GetDirection() {
    return Direction;
}

// Sets the direction value
void InstructionRegister::SetDirection(int value) {
    Direction = value;
}
vector<string>& InstructionRegister::GetUnusedInstrucitons(){
    return UnusedInstructions;
}

// Decodes the instruction and sets the direction based on the operation type
void InstructionRegister::decode() {
    auto it = find(ControlUnitOperations.begin(), ControlUnitOperations.end(), value[0]);
    if (it != ControlUnitOperations.end()) {
        Direction = 1;
    }
    auto it2 = find(ALUOperations.begin(), ALUOperations.end(), value[0]);
    if(it2 != ALUOperations.end())
    {
        it = find(ALUOperations.begin(), ALUOperations.end(), value[0]);
        if (it != ALUOperations.end()) {
            Direction = 2;
        }
    }
    else{
        UnusedInstructions.push_back(value);
    }
}
