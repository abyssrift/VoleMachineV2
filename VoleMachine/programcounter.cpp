#include "programcounter.h"
#include "qlogging.h"
#include <QDebug>
// Constructor
ProgramCounter::ProgramCounter(Memory& mainMemory2, InstructionRegister& instructionRegister)
    : mainMemory(mainMemory2), instructionReg(instructionRegister) {
    qDebug() << "ProgramCounter initialized";
}

void ProgramCounter::GetMemory() {
    // Method implementation (if needed)
}

// Set the counter value
void ProgramCounter::SetCounter(int value) {
    counter = value;
}

// Get the current counter value
int ProgramCounter::GetCounter() {
    return counter;
}

// Check if the end of the program is reached
bool ProgramCounter::isEndOfProgram() {
    qDebug() << "Checking if end of program with instruction: " << instruc;
    return instruc == "C000";
}

// Pass the fetched instruction to the InstructionRegister
void ProgramCounter::PassInstruction() {
    qDebug() << "Passing instruction to InstructionRegister: " << instruc;
    instructionReg.SetRegisterSingle(instruc);
}

// Run the instructions from memory
void ProgramCounter::runInstructions() {
    instruc = (mainMemory.GetMemoryValue(counter) + mainMemory.GetMemoryValue(counter + 1));
    qDebug() << "Fetched instruction: " << instruc;

    if (isEndOfProgram()) {
        qDebug() << "End of the program";
    }
    counter += 2;
    PassInstruction();
}
