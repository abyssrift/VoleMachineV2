#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;



class RegisterSingle
{
public:
	void SetRegisterSingle(string s) {
		value = s;
	}
	void SetRegisterSingle(int n, char s) {
		value[n] = s;
	}
	string ReturnValue() {
		return value;
	}
	RegisterSingle()
	{
		value = "0000";
	}

protected:
	string value;
};

class InstructionRegister:public RegisterSingle {
private:
	vector<char> ControlUnitOperations{'1','2','3','4','B','C'};
	vector<char>ALUOperations{ '5','6' };
public:
	void decode() {
		auto it = find(ControlUnitOperations.begin(), ControlUnitOperations.end(), value[0]);
			if(it != ControlUnitOperations.end()){
			
		}
	}
	string GetInstruction() {
		return value;
	}
};

class Register {
private:
	vector<RegisterSingle> RegisterVector;
public:
	Register() {
		RegisterVector.resize(16);
	}
	void SetRegisterSingle(int index, string s) {
		RegisterVector[index].SetRegisterSingle(s);
	}
	RegisterSingle GetRegister(int index) {
		return RegisterVector[index];
	}
	string GetRegisterValue(int index) {
		return RegisterVector[index].ReturnValue();
	}
};

//main memory where the memory slots contain address and value
class Memory {
private:
	vector<string> memoryslots;
public:
	void SetMemoryValue(int address, string value) {
		memoryslots[address] = value;
	}
	string GetMemoryValue(int address) {
		return memoryslots[address];
	}
	void ClearSlot(int address) {
		memoryslots[address] = "00";
	}
	void ResizeMemory(int memorysize) {
		memoryslots.resize(memorysize);
	}
	void Clear() {
		for (int i = 0; i < memoryslots.size(); i++)
		{
			memoryslots[i] = "00";
		}
	}
	Memory() {
		memoryslots.resize(256, "00");
	}
};




class ProgramCounter {
	int value;
	int address;
public:

};




class ALU {
	Memory* mainmemory;
	Register Register_16;
	InstructionRegister instruRegister;

public:
	ALU(Memory& memory, InstructionRegister& instruReg, Register& register_16) : mainmemory(&memory), instruRegister(instruReg), Register_16(register_16) {}
	void GetMemory(Memory& memory) {
		mainmemory = &memory;
	}
};

//control unit where main instructions of the machine are carried out
class ControlUnit {
private:
	int ProgramCounter;
	Memory* mainmemory;
	Register Register_16;
	InstructionRegister instruRegister;


public:
	ControlUnit(Memory& memory, InstructionRegister& InstruReg, Register& register_16) : mainmemory(&memory) , instruRegister(InstruReg), Register_16(register_16){}

	void GetMemory(Memory& memory) {
		mainmemory = &memory;
	}

	void Decision(string instruction) {

	}
	void execute() {

	}
	//load Register from memory
	void Load(int address, int RegisterSinglenumber) {
		Register_16.SetRegisterSingle(RegisterSinglenumber, mainmemory->GetMemoryValue(address));
	}
	void Load(string value, int RegisterSinglenumber) {
		Register_16.SetRegisterSingle(RegisterSinglenumber, value);
	}

	void Store(int address, int RegisterSinglenumber) {
		mainmemory->SetMemoryValue(address, Register_16.GetRegisterValue(RegisterSinglenumber));
	}
	void Move(int RegisterSinglenumber1, int RegisterSinglenumber2) {
		Register_16.SetRegisterSingle(RegisterSinglenumber2, Register_16.GetRegisterValue(RegisterSinglenumber1));
	}

};


class CPU {
private:
	Memory mainmemory;
	InstructionRegister instruReg;
	Register register_16;
	ControlUnit cu;
	ALU alu;
public:
	CPU(Memory& mainmemory) : cu(mainmemory,instruReg,register_16), alu (mainmemory,instruReg,register_16) {}
	ControlUnit& GetControlUnit() {
		return cu;
	}

	ALU& GetALU() {
		return alu;
	}

	InstructionRegister& GetInstructionReg() {
		return instruReg;
	}

	Memory& GetMemory() {
		return mainmemory;
	}
};



class Machine {
private:
	Memory mainmemory;
	CPU cpu;
public:
	Memory& Getmemory() {
		return mainmemory;
	}
	CPU& GetCpu() {
		return cpu;
	}
	Machine() : cpu(mainmemory){
	}
	void SetMainMemoryValue(int address, string value) {
		mainmemory.SetMemoryValue(address, value);
	}
};



int main(){
	cout << "Give me file name" << endl;
	string filename;
	cin >> filename;
	fstream file(filename, ios::in);
	if (!file) {
		cout << "invalid file try again" << endl;
		main();
	} 
	string word;

	Machine machine;

	vector<string> instructions;
	while (file >> word) {
		instructions.push_back(word.substr(0, 2));
		instructions.push_back(word.substr(2, 4));
	}
	for (int i = 0; i < instructions.size(); i++)
	{
		machine.SetMainMemoryValue(i,instructions[i]);
		machine.SetMainMemoryValue(i+1,instructions[i + 1]);
	}

	cout <<  "instructions vector size" << instructions.size() << endl;

	//regex




}
