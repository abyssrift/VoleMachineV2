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
	vector<RegisterSingle> reggie;
public:
	Register() {
		reggie.resize(16);
	}
	void SetRegisterSingle(int index, string s) {
		reggie[index].SetRegisterSingle(s);
	}
	RegisterSingle GetRegister(int index) {
		return reggie[index];
	}
	string GetRegisterValue(int index) {
		return reggie[index].ReturnValue();
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
	Memory() {}
};



class CPU {
private:
	Register reggie;
	ControlUnit cu;
	ALU alu;
	Memory mainmemory;
	InstructionRegister instruReg;
protected:
	Register& getRegister() {
		return reggie;
	}
public:
	CPU(Memory& mainmemory) : cu(mainmemory), alu (mainmemory) {}
	CPU() : cu(mainmemory) , alu(mainmemory) {};
	ControlUnit GetControlUnit() {
		return cu;
	}
	ALU GetALU() {
		return alu;
	}
	Memory GetMemory() {
		return mainmemory;
	}
};

class ALU: public CPU {
	Memory* mainmemory;
	Register Register_16;
	InstructionRegister instruReg;
public:
	void GetReggie(Register& RegisterClass) {
		Register_16 = getRegister();
	}
		void GetMemory(Memory &memory) {
		mainmemory = &memory;
	}
	ALU(Memory& memory) : mainmemory(&memory) {}
};

class ProgramCounter {
	int value;
	int address;
public:
		
};


//control unit where main instructions of the machine are carried out
class ControlUnit: public CPU {
private:
	int ProgramCounter;
	Memory* mainmemory;
	Register Register_16;

public:
	ControlUnit(Memory& memory) : mainmemory(&memory) {}

	void GetMemory(Memory& memory) {
		mainmemory = &memory;
	}
	void GetReggie(Register& RegisterClass) {
		Register_16 = getRegister();
	}

	void Decision(string instruction) {
		
	}
	void execute() {
		
	}
	//load Register from memory
	void Load(int address,int RegisterSinglenumber) {
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


class Machine {
private:
	Memory mainmemory;
	CPU cpu;
public:
	Memory Getmemory() {
		return mainmemory;
	}
	CPU GetCpu() {
		return cpu;
	}
	Machine() : cpu(mainmemory){
		mainmemory.ResizeMemory(256);

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
	InstructionRegister InstruReggie;

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
