#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <string>
#include<sstream>

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
		cout << "RegisterSingle successfully initiated" << endl;
	}

protected:
	string value;
};

class InstructionRegister :public RegisterSingle {
private:
	int Direction = 0;
	vector<char> ControlUnitOperations{ '1','2','3','4','B','C' };
	vector<char>ALUOperations{ '5','6' };

public:
	string GetInstruction() {
		return value;
	}
	int GetDirection() {
		return Direction;
	}
	void SetDirection(int value) {
		Direction = value;
	}

	void decode() {
		auto it = find(ControlUnitOperations.begin(), ControlUnitOperations.end(), value[0]);
		if (it != ControlUnitOperations.end())
		{
			Direction = 1;
		}
		else
		{
			auto it = find(ALUOperations.begin(), ALUOperations.end(), value[0]);
			if (it != ALUOperations.end()) {
				Direction = 2;
			}
		}
	}
	InstructionRegister() {
		cout << "InstruReg successfully initiated" << endl;
	}
};

class Register {
private:
	vector<RegisterSingle> RegisterVector;
public:
	Register() {
		RegisterVector.resize(16);
		cout << "Register_16 successfully initiated" << endl;
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
		cout << "Getting memory value at address " << address << ": " << memoryslots[address] << endl;
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
		cout << "Memory successfully initiated" << endl;
	}
};


class ProgramCounter {
	Memory& mainMemory;
	string instruc;
	int counter = 0;
	InstructionRegister& instructionReg;
public:
	void GetMemory() {

	}
	bool isEndOfProgram() {
		cout << "Checking if end of program with instruction: " << instruc << endl;
		return instruc == "C000";
	}
	void PassInstruction() {
		cout << "Passing instruction to InstructionRegister: " << instruc << endl;
		instructionReg.SetRegisterSingle(instruc);
	}
	void runInstructions() {
		instruc = (mainMemory.GetMemoryValue(counter) + mainMemory.GetMemoryValue(counter + 1));
		cout << "Fetched instruction: " << instruc << endl;

		if (isEndOfProgram()) {
			cout << "End of the program" << endl;
		}
		counter += 2;
		PassInstruction();
	}
	ProgramCounter(Memory& mainMemory2, InstructionRegister& instructionRegister)
		: mainMemory(mainMemory2), instructionReg(instructionRegister) {
		cout << "ProgramCounter initialized" << endl;
	}
};



class ALU {
	Memory& mainmemory;
	Register Register_16;
	InstructionRegister& instruRegister;
	string& instruction;

public:
	ALU(Memory& memory, InstructionRegister& instruReg, Register& register_16, string& instruction2) : mainmemory(memory), instruRegister(instruReg), Register_16(register_16), instruction(instruction2) {
		cout << "ALU successfully initiated" << endl;
	}
	void GetMemory(Memory& memory) {
		mainmemory = memory;
	}
	void SetInstruction(string instru) {
		instruction = instru;
	}
	void Decode() {
		if (instruction[0] == '5') {

		}
		else if (instruction[0] == '6') {

		}
	}
};

//control unit where main instructions of the machine are carried out
class ControlUnit {
private:
	Memory& mainmemory;
	Register Register_16;
	InstructionRegister& instruRegister;
	string& instruction;
public:
	ControlUnit(Memory& memory, InstructionRegister& InstruReg, Register& register_16, string& instruction2) : instruRegister(InstruReg), Register_16(register_16), mainmemory(memory), instruction(instruction2) {
		cout << "CU successfully initiated" << endl;
	}

	void GetMemory(Memory& memory) {
		mainmemory = memory;
	}
	void CoutInstruction() {
		cout << instruction << endl;
	}
	void Decode() {
		if (instruction[0] == '1') {

		}
		else if (instruction[0] == '2') {

		}
		else if (instruction[0] == '3') {

		}
		else if (instruction[0] == '4') {

		}
		else if (instruction[0] == 'A') {

		}
		else if (instruction[0] == 'B') {

		}
	}

	//load Register from memory
	void Load(int address, int RegisterSinglenumber) {
		Register_16.SetRegisterSingle(RegisterSinglenumber, mainmemory.GetMemoryValue(address));
	}
	void Load(string value, int RegisterSinglenumber) {
		Register_16.SetRegisterSingle(RegisterSinglenumber, value);
	}

	void Store(int address, int RegisterSinglenumber) {
		mainmemory.SetMemoryValue(address, Register_16.GetRegisterValue(RegisterSinglenumber));
	}
	void Move(int RegisterSinglenumber1, int RegisterSinglenumber2) {
		Register_16.SetRegisterSingle(RegisterSinglenumber2, Register_16.GetRegisterValue(RegisterSinglenumber1));
	}
};


class CPU {
private:
	Memory& mainmemory;
	ProgramCounter programCounter;
	InstructionRegister instruReg;
	Register register_16;
	ControlUnit cu;
	ALU alu;
	string instruction = "0000";
	int Direction = 0;
public:

	CPU(Memory& mainmemory2)
		: mainmemory(mainmemory2), cu(mainmemory, instruReg, register_16, instruction),
		alu(mainmemory, instruReg, register_16, instruction),
		programCounter(mainmemory, instruReg), instruReg() {
		cout << "CPU successfully initiated" << endl;
	}

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


	void CheckEnd() {
		if (instruReg.ReturnValue() == "C000") {
			cout << "program exited by user through instructions" << endl;
			exit(0);
		}
	}


	void cycle() {
		programCounter.runInstructions();

		cout << "Attempted to Fetch From memory" << endl;
		CheckEnd();
		instruReg.decode();
		instruction = instruReg.GetInstruction();
		Direction = instruReg.GetDirection();

		if (Direction == 1) {
			cu.Decode();
			cu.CoutInstruction();
		}
		else if (Direction == 2) {
			alu.Decode();
		}
		instruReg.SetDirection(0);
	}

	void Start() {
		cycle();
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
	Machine() : cpu(mainmemory) {
		cout << "Machine Successfully Initiated" << endl;
	}
	void SetMainMemoryValue(int address, string value) {
		mainmemory.SetMemoryValue(address, value);
	}

	void Start() {
		cout << "Attempted CPU Start" << endl;
		cpu.Start();
	}
};



int main() {
	cout << "Give me file name" << endl;
	string filename = "textcase.txt";
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
	for (int i = 0; i < (instructions.size()); i += 2) {
		cout << "Setting memory at address " << i << " " << i + 1 << " to value " << instructions[i] << " " << instructions[i + 1] << endl;
		machine.SetMainMemoryValue(i, instructions[i]);
		machine.SetMainMemoryValue(i + 1, instructions[i + 1]);
	}
	machine.Start();
	//regex




}