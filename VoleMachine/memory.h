#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Memory {
public:
    Memory();  // Constructor
    bool MemoryEmpty = true;
    void SetMemoryValue(int address, const string& value);
    string GetMemoryValue(int address);
    void ClearSlot(int address);
    void ResizeMemory(int memorysize);
    void Clear();
    bool IsEmpty();

private:
    vector<string> memoryslots;
};

#endif // MEMORY_H
