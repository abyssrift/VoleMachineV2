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
public:
	void decode() {
		switch (value[0]) {
		case('1') :{
			//load register with bit pattern found in memory address
			}
		case('2') :{
			//load register with bit pattern XY (user input)
			}
		case('3'): {
			//Store the bit pattern in Register R to memory cel XY
		}
		case('4'): {
			//Move bit pattern from register r to register s
		}
		case('5'): {
			//ADD bit patterns in register S and T as though they are represented in floating point notation  and leave result in R
		}
		case('6'): {
			//
		}
		case('B'): {

		}
		case('C'): {

		}
		}
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
	void Clear() {
		for (int i = 0; i < memoryslots.size(); i++)
		{
			memoryslots[i] = "00";
		}
	}
	Memory() {
		Clear();
	}
};



class CPU {
private:
	Register reggie;


protected:
	Register& getRegister() {
		return reggie;
	}
public:
	CPU() {
	}
};

class ALU: public CPU {

public:
	ALU() {

	}
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
	Memory mainmemory;
	Register Register_16;

public:
	int fetch();

	void GetMemory(Memory memorytoget) {
		mainmemory = memorytoget;
	}
	void GetReggie(Register RegisterClass) {
		Register_16 = getRegister();
	}
	void execute() {
		
	}
	//load Register from memory
	void Load(int address,int RegisterSinglenumber) {
		Register_16.SetRegisterSingle(RegisterSinglenumber, mainmemory.GetMemoryValue(address));
	}
	void Load(string value, int RegisterSinglenumber) {
		Register_16.SetRegisterSingle(RegisterSinglenumber, value);
	}

	void Store(int address, int RegisterSinglenumber) {
		mainmemory.SetMemoryValue(address, Register_16.GetRegisterValue(RegisterSinglenumber));
	}

	ControlUnit() {

	}
};


/*class machine {
private:
	Memory mainmemory;
	CPU cpu;
	ControlUnit cu;
	ALU alu;
public:
	Memory Getmemory() {
		return mainmemory;
	}
	CPU GetCpu() {
		return cpu;
	}
	ControlUnit GetCu() {
		return cu;
	}
	ALU GetAlu() {
		return alu;
	}

	machine(string mainmemory,string cpu, string cu, string alu) {
	
	}
};*/



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


	Memory mainmemory;
	CPU cpu;
	ControlUnit cu;
	cu.GetMemory(mainmemory);
	ALU alu;
	vector<string> instructions;
	while (file >> word) {
		instructions.push_back(word.substr(0, 2));
		instructions.push_back(word.substr(2, 4));
	}
	for (int i = 0; i < instructions.size(); i++)
	{
		mainmemory.SetMemoryValue(i,instructions[i]);
		mainmemory.SetMemoryValue(i+1,instructions[i + 1]);
	}

	cout <<  "instructions vector size" << instructions.size() << endl;

	//regex




}
