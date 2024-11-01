#include "VoleMachineHeader.h"
// Machine class methods

Memory& Machine::GetMemory() {
    return mainmemory;
}
CPU& Machine::GetCpu() {
    return cpu;
}
Register& Machine::GetRegister(){
    return(cpu.GetRegisters());
}
Machine::Machine() : cpu(mainmemory){
    cout << "Machine Successfully Initiated" << endl;
}
void Machine::SetMainMemoryValue(int address, string value) {
    mainmemory.SetMemoryValue(address, value);
}

void Machine::Start() {
    cout << "Attempted CPU Start" << endl;
    cpu.Start();
}