#include "machine.h"
#include "QDebug"



using namespace std;

Machine::Machine(CPU& cpu2, Memory& mainmemory2) :  cpu(cpu2) , mainmemory(mainmemory2) {
    qDebug() << "Machine Successfully Initiated";
}

Memory& Machine::GetMemory() {
    return mainmemory;
}

CPU& Machine::GetCpu() {
    return cpu;
}

Register& Machine::GetRegister() {
    return cpu.GetRegisters();
}

void Machine::SetMainMemoryValue(int address, const std::string& value) {
    mainmemory.SetMemoryValue(address, value);
}

void Machine::Start() {
    qDebug() << "Attempted CPU Start";
    cpu.Start();
}

void Machine::ResetMemory(){
    mainmemory.Clear();
}

void Machine::ResetRegisters(){
    cpu.ResetRegisters();
}
void Machine::SetSpeed(int value){
    cpu.SetSpeed(value);
}
void Machine::OneCycle(){
    cpu.cycle();
}
string Machine::GetScreenMemory(){
    return cpu.GetMemoryValue(0);
}
bool Machine::GetStopCycles(){
    StopCycles = cpu.GetStopCycles();
}
QString Machine::Getregister_16(){
    return cpu.getRegister_16StateAsQString();
}
QString Machine::Getmemory_16(){
    return cpu.getMemoryStateAsQString();
}
