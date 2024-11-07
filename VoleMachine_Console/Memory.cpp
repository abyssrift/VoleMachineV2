#include "VoleMachineHeader.h"
// Memory class methods
Memory::Memory() {
    // Memory constructor to initialize memory slots
    memoryslots.resize(256, "00");
}

void Memory::SetMemoryValue(int address, string value) {
    // Set a value in memory at a specific address
    if(value.size() == 1){
        value = "0" + value;
    }
    memoryslots[address] = value;
}

string Memory::GetMemoryValue(int address) {
    // Retrieve a value from a specific memory address
    return memoryslots[address];
}

void Memory::ClearSlot(int address) {
    // Clear the memory slot at the specified address
    memoryslots[address] = "00";
}

void Memory::ResizeMemory(int memorysize) {
    // Resize the memory to fit the specified number of slots
    memoryslots.resize(memorysize);
}

void Memory::Clear() {
    // Clear all memory slots
    for (int i = 0; i < memoryslots.size(); i++)
    {
        memoryslots[i] = "00";
    }
}
