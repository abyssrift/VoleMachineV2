#include "VoleMachineHeader.h"
// CPU class methods
CPU::CPU(Memory& mainmemory2)
        : mainmemory(mainmemory2), programCounter(mainmemory2, instruReg), cu(mainmemory2, instruReg, register_16, instruction, programCounter), alu(mainmemory2, instruReg, register_16, instruction) {
    // CPU constructor initializing all components
}

ControlUnit& CPU::GetControlUnit() {
    return cu;
}

Register& CPU::GetRegisters() {
    return register_16;
}

ALU& CPU::GetALU() {
    return alu;
}

InstructionRegister& CPU::GetInstructionReg() {
    return instruReg;
}

Memory& CPU::GetMemory() {
    return mainmemory;
}

void CPU::DisplayMemory() {
    // Display the contents of memory
    cout << "==================================MainMemory==================================" << endl;
    for (int i = 0; i < 251; i+=16) {
        // Only print if there is at least one non-zero value in the current set of cells
        for (int j = 0; j < 16; ++j) {
            cout << mainmemory.GetMemoryValue(i+j);
            if (j != 15) cout << " - ";
        }
            cout << endl;
    }
    cout << "==============================================================================" << endl;
}

void CPU::DisplayRegisters() {
    // Display the contents of the registers
    cout << "====Registers====" << endl;
    for (int i = 0; i < 16; i+=4) {
        // Only print if there is at least one non-zero value in the current set of cells
        for (int j = 0; j < 4; ++j) {
            cout << register_16.GetRegisterValue(i+j);
            if (j != 3) cout << " - ";
        }
        cout << endl;
    }
    cout << "=================" << endl;
}

void CPU::CheckEnd() {
    // Check for the end of program execution
    if (instruReg.ReturnValue() == "C000" || instruReg.ReturnValue() == "c000" || programCounter.GetCounter() >= 255) {
        DisplayMemory();
        DisplayRegisters();
        exit(0);
    }
}

void CPU::cycle() {
    programCounter.runInstructions();

    CheckEnd();
    instruReg.decode();
    instruction = instruReg.GetInstruction();
    Direction = instruReg.GetDirection();

    if (Direction == 1) {
        cu.Decode();
    }
    else if (Direction == 2) {
        alu.Decode();
    }
    instruReg.SetDirection(0);
    if (mainmemory.GetMemoryValue(0) != "00"){
        cout << "======Screen======" << endl;
        cout << mainmemory.GetMemoryValue(0) << endl;
        cout << "==================" << endl;
    }
}

void CPU::Start() {
    for (int i = 0; i < 1000; i++)
    {
        cycle();
    }
}