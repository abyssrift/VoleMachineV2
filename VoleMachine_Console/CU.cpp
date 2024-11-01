#include "VoleMachineHeader.h"
// ControlUnit class methods
ControlUnit::ControlUnit(Memory& memory, InstructionRegister& InstruReg, Register& register_16, string& instruction2, ProgramCounter& ProgramCounter)
        : mainmemory(memory), instruRegister(InstruReg), Register_16(register_16), instruction(instruction2), programcounter(ProgramCounter) {
    // Constructor implementation
    cout << "CU successfully initiated" << endl;
}

void ControlUnit::GetMemory(Memory& memory) {
    // Load memory for the control unit to process
    mainmemory = memory;
}

void ControlUnit::CoutInstruction() {
    // Output the current instruction
    cout << instruction << endl;
}

void ControlUnit::Load(int address, int RegisterSinglenumber) {
    // Load a value from memory to a register
    Register_16.SetRegisterSingle(RegisterSinglenumber, mainmemory.GetMemoryValue(address));
}

void ControlUnit::Load(string value, int RegisterSinglenumber) {
    // Load a string value into a register
    Register_16.SetRegisterSingle(RegisterSinglenumber, value);
}

void ControlUnit::Store(int address, int RegisterSinglenumber) {
    // Store the value of a register to memory
    mainmemory.SetMemoryValue(address, Register_16.GetRegisterValue(RegisterSinglenumber));
}

void ControlUnit::Move(int RegisterSinglenumber1, int RegisterSinglenumber2) {
    // Move the value from one register to another
    Register_16.SetRegisterSingle(RegisterSinglenumber2, Register_16.GetRegisterValue(RegisterSinglenumber1));
}

void ControlUnit::Rotate(int Registernumber, string rotations) {
    // Rotate the bits of a register
    string valueInRegister = HextoBin(Register_16.GetRegisterValue(Registernumber));
    int iterations = stoi(rotations,nullptr,16);
    for (int i = 0; i < iterations; i++) {
        string rest = valueInRegister.substr(0,valueInRegister.length() - 1);
        char lastBit = valueInRegister[valueInRegister.length() - 1];
        valueInRegister = lastBit + rest;
    }
    valueInRegister = BintoHex(valueInRegister);
    Register_16.SetRegisterSingle(Registernumber, valueInRegister);
}

void ControlUnit::equality_jump(int address, int Registernumber) {
    // Conditional jump based on equality
    if(Register_16.GetRegisterValue(Registernumber) == Register_16.GetRegisterValue(0)){
        programcounter.SetCounter(address);
    }
}

void ControlUnit::comparison_jump(int address, int Registernumber) {
    // Conditional jump based on comparison
    int8_t register0 = static_cast<int8_t>(bitset<8>(Register_16.GetRegisterValue(Registernumber)).to_ulong());
    int8_t register1 = static_cast<int8_t>(bitset<8>(Register_16.GetRegisterValue(0)).to_ulong());
    if(HextoDec(BintoHex(bitset<8>(register1).to_string())) > HextoDec(BintoHex(bitset<8>(register0).to_string()))){
        programcounter.SetCounter(address);
    }
}

void ControlUnit::Decode() {
    // Decode the instruction for control unit processing
    if (instruction[0] == '1') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        int memoryaddress = HextoDec(instruction.substr(2, 4));
        Load(memoryaddress, Registernumber);
    }
    else if (instruction[0] == '2') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        string value = instruction.substr(2, 4);
        Load(value, Registernumber);
    }
    else if (instruction[0] == '3') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        int memoryaddress = HextoDec(instruction.substr(2, 4));
        Store(memoryaddress, Registernumber);
    }
    else if (instruction[0] == '4') {
        int RegisternumberR = HextoDec(instruction.substr(2, 1));
        int RegisternumberS = HextoDec(instruction.substr(3, 1));
        Move(RegisternumberR, RegisternumberS);
    }
    else if (toupper(instruction[0]) == 'A') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        string rotations = instruction.substr(2, 4);
        Rotate(Registernumber, rotations);
    }
    else if (toupper(instruction[0]) == 'B') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        int memoryaddress = HextoDec(instruction.substr(2, 4));
        equality_jump(memoryaddress, Registernumber);
    }
    else if (toupper(instruction[0]) == 'D') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        int memoryaddress = HextoDec(instruction.substr(2, 4));
        comparison_jump(memoryaddress, Registernumber);


    }
}
