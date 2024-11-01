#include "memory.h"
#include "QDebug"
// Constructor
Memory::Memory() {
    memoryslots.resize(256, "00");
    qDebug() << "Memory successfully initiated";
}

// Sets a memory value at the specified address
void Memory::SetMemoryValue(int address, const string& value) {
    string modifiedValue = value.size() == 1 ? "0" + value : value;
    memoryslots[address] = modifiedValue;
}

// Gets the memory value at the specified address
string Memory::GetMemoryValue(int address) {
    return memoryslots[address];
}

// Clears the memory slot at the specified address
void Memory::ClearSlot(int address) {
    memoryslots[address] = "00";
}

// Resizes the memory slots to the specified size
void Memory::ResizeMemory(int memorysize) {
    memoryslots.resize(memorysize);
}

// Clears all memory slots
void Memory::Clear() {
    for (size_t i = 0; i < memoryslots.size(); i++) {
        memoryslots[i] = "00";
    }
}
bool Memory::IsEmpty(){
    for(size_t i = 0; i < memoryslots.size(); i++){
        if(!(memoryslots[i] == "00")){
            qDebug() << "Memory is Allocated";
            MemoryEmpty = false;
            return false;
        }
        qDebug() << "Memory is Empty";
        MemoryEmpty = true;
        return true;
    }
}
