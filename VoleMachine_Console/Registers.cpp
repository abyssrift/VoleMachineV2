#include "VoleMachineHeader.h"
// RegisterSingle class methods
RegisterSingle::RegisterSingle() {
    // Constructor implementation
    value = "00";
}

void RegisterSingle::SetRegisterSingle(string s) {
    // Set register value with a string
    if(s.size() == 1){
        s = "0" + s;
    }
    value = s;
}

void RegisterSingle::SetRegisterSingle(int n, char s) {
    // Set register value with an int and char
    value[n] = s;
}

string RegisterSingle::ReturnValue() {
    // Return the value in register
    return value;
}

// InstructionRegister class methods
InstructionRegister::InstructionRegister() : RegisterSingle() {
    // Constructor implementation
    cout << "InstruReg successfully initiated" << endl;
}

string InstructionRegister::GetInstruction() {
    // Retrieve the instruction part of the register value
    return value;
}

int InstructionRegister::GetDirection() {
    // Retrieve the direction part of the register value
    return Direction;
}

void InstructionRegister::SetDirection(int value) {
    // Set the direction part of the instruction
    Direction = value;
}

void InstructionRegister::decode() {
    // Decode the instruction for processing
    auto it = find(ControlUnitOperations.begin(), ControlUnitOperations.end(), value[0]);
    if(it != ControlUnitOperations.end())
    {
        Direction = 1;
    }
    else
    {
        auto it = find(ALUOperations.begin(), ALUOperations.end(), value[0]);
        if (it != ALUOperations.end()) {
            Direction = 2;
        }
    }
}

// Register class methods
Register::Register() {
    // Constructor for creating a list of registers
    RegisterVector.resize(16);
    cout << "Register_16 successfully initiated" << endl;
}

void Register::SetRegisterSingle(int index, string s) {
    // Set the value of a specific register
    RegisterVector[index].SetRegisterSingle(s);
}

RegisterSingle Register::GetRegister(int index) {
    // Retrieve a specific register
    return RegisterVector[index];
}

string Register::GetRegisterValue(int index) {
    // Get the value in a specific register
    return RegisterVector[index].ReturnValue();
}
