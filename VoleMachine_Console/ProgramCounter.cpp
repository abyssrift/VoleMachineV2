#include "VoleMachineHeader.h"
// ProgramCounter class methods
ProgramCounter::ProgramCounter(Memory& mainMemory2, InstructionRegister& instructionRegister)
        : mainMemory(mainMemory2), instructionReg(instructionRegister), counter(0) {
    // Constructor implementation
}

void ProgramCounter::GetMemory() {
    // Load the program instructions from memory
}

void ProgramCounter::SetCounter(int value) {
    // Set the program counter to a specified value
    counter = value;
}

int ProgramCounter::GetCounter() {
    // Retrieve the current program counter value
    return counter;
}

bool ProgramCounter::isEndOfProgram() {
    // Check if the end of the program has been reached
    return instruc == "C000";
}

void ProgramCounter::PassInstruction() {
    // Pass the next instruction to the InstructionRegister
    instructionReg.SetRegisterSingle(instruc);
}

void ProgramCounter::runInstructions() {
    // Main loop to run instructions in sequence
    instruc = (mainMemory.GetMemoryValue(counter) + mainMemory.GetMemoryValue(counter + 1));
    if (isEndOfProgram()) {
        cout << "End of the program" << endl;
    }
    counter += 2;
    PassInstruction();
}