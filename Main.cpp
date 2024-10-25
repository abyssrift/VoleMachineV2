#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class RegisterSingle {
public:
	void SetRegisterSingle(string s) {
		cout << "Setting RegisterSingle to: " << s << endl;
		value = s;
	}
	void SetRegisterSingle(int n, char s) {
		cout << "Setting RegisterSingle at index " << n << " to: " << s << endl;
		value[n] = s;
	}
	string ReturnValue() {
		cout << "Returning RegisterSingle value: " << value << endl;
		return value;
	}
	RegisterSingle() {
		value = "0000";
		cout << "RegisterSingle initialized with value: " << value << endl;
	}
protected:
	string value;
};

class InstructionRegister : public RegisterSingle {
private:
	int Direction = 0;
	vector<char> ControlUnitOperations{ '1', '2', '3', '4', 'B', 'C' };
	vector<char> ALUOperations{ '5', '6' };
public:
	bool Loaded;

	int GetDirection() {
		cout << "Getting Direction from InstructionRegister: " << Direction << endl;
		return Direction;
	}

	void decode() {
		cout << "Decoding instruction: " << value[0] << endl;
		auto it = find(ControlUnitOperations.begin(), ControlUnitOperations.end(), value[0]);
		if (it != ControlUnitOperations.end()) {
			Direction = 1;
			cout << "Passing instruction to Control Unit" << endl;
			PassInstructionToCU();
		}
		else {
			it = find(ALUOperations.begin(), ALUOperations.end(), value[0]);
			if (it != ALUOperations.end()) {
				Direction = 2;
				cout << "Passing instruction to ALU" << endl;
				PassInstructionsToALU();
			}
		}
		cout << "Resetting Direction and Loaded status in InstructionRegister" << endl;
		Direction = 0;
		Loaded = false;
		value = "0000";
	}
	InstructionRegister() {
		Loaded = false;
		cout << "InstructionRegister initialized" << endl;
	}
	void PassInstructionToCU() {
		cout << "Instruction passed to Control Unit" << endl;
	}
	void PassInstructionsToALU() {
		cout << "Instruction passed to ALU" << endl;
	}
};

class Register {
private:
	vector<RegisterSingle> RegisterVector;
public:
	Register() {
		RegisterVector.resize(16);
		cout << "Register initialized with 16 RegisterSingle slots" << endl;
	}
	void SetRegisterSingle(int index, string s) {
		cout << "Setting RegisterSingle at index " << index << " with value: " << s << endl;
		RegisterVector[index].SetRegisterSingle(s);
	}
	RegisterSingle GetRegister(int index) {
		cout << "Fetching RegisterSingle at index: " << index << endl;
		return RegisterVector[index];
	}
	string GetRegisterValue(int index) {
		cout << "Getting value from RegisterSingle at index: " << index << endl;
		return RegisterVector[index].ReturnValue();
	}
};

class Memory {
private:
	vector<string> memoryslots;
public:
	void SetMemoryValue(int address, string value) {
		cout << "Setting memory at address " << address << " to value: " << value << endl;
		memoryslots[address] = value;
	}
	string GetMemoryValue(int address) {
		cout << "Getting memory value at address " << address << ": " << memoryslots[address] << endl;
		return memoryslots[address];
	}
	void ClearSlot(int address) {
		cout << "Clearing memory slot at address " << address << endl;
		memoryslots[address] = "00";
	}
	void ResizeMemory(int memorysize) {
		cout << "Resizing memory to size: " << memorysize << endl;
		memoryslots.resize(memorysize);
	}
	void Clear() {
		cout << "Clearing all memory slots" << endl;
		for (int i = 0; i < memoryslots.size(); i++) {
			memoryslots[i] = "00";
		}
	}
	Memory() {
		memoryslots.resize(256, "00");
		cout << "Memory initialized with 256 slots set to '00'" << endl;
	}
};

class ProgramCounter {
	Memory mainMemory;
	string instruc;
	int counter = 0;
	InstructionRegister instructionReg;
public:
	bool isEndOfProgram() {
		cout << "Checking if end of program with instruction: " << instruc << endl;
		return instruc == "C000";
	}
	void PassInstruction() {
		cout << "Passing instruction to InstructionRegister: " << instruc << endl;
		instructionReg.SetRegisterSingle(instruc);
		instructionReg.Loaded = true;
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
	ProgramCounter(Memory& mainMemory, InstructionRegister& instructionRegister)
		: mainMemory(mainMemory), instructionReg(instructionRegister) {
		cout << "ProgramCounter initialized" << endl;
	}
};

class ALU {
	Memory* mainmemory;
	Register Register_16;
	InstructionRegister instruRegister;
	string instruction;

public:
	ALU(Memory& memory, InstructionRegister& instruReg, Register& register_16)
		: mainmemory(&memory), instruRegister(instruReg), Register_16(register_16) {
		cout << "ALU initialized" << endl;
	}
	void GetMemory(Memory& memory) {
		mainmemory = &memory;
		cout << "Memory set in ALU" << endl;
	}
	void Decode() {
		cout << "Decoding ALU instruction: " << instruction << endl;
		if (instruction[0] == '5') {
			cout << "Performing ALU operation for code '5'" << endl;
		}
		else if (instruction[0] == '6') {
			cout << "Performing ALU operation for code '6'" << endl;
		}
	}
};

class ControlUnit {
private:
	Memory* mainmemory;
	Register Register_16;
	InstructionRegister instruRegister;
	string instruction;
public:
	ControlUnit(Memory& memory, InstructionRegister& InstruReg, Register& register_16)
		: instruRegister(InstruReg), Register_16(register_16), mainmemory(&memory) {
		cout << "Control Unit initialized" << endl;
	}

	void GetMemory(Memory& memory) {
		mainmemory = &memory;
		cout << "Memory set in Control Unit" << endl;
	}

	void Decode() {
		cout << "Decoding Control Unit instruction: " << instruction << endl;
		if (instruction[0] == '1') {
			cout << "Performing operation for code '1'" << endl;
		}
		else if (instruction[0] == '2') {
			cout << "Performing operation for code '2'" << endl;
		}
		else if (instruction[0] == '3') {
			cout << "Performing operation for code '3'" << endl;
		}
		else if (instruction[0] == '4') {
			cout << "Performing operation for code '4'" << endl;
		}
		else if (instruction[0] == 'A') {
			cout << "Performing operation for code 'A'" << endl;
		}
		else if (instruction[0] == 'B') {
			cout << "Performing operation for code 'B'" << endl;
		}
	}

	void Load(int address, int RegisterSinglenumber) {
		cout << "Loading value from memory address " << address << " to RegisterSingle " << RegisterSinglenumber << endl;
		Register_16.SetRegisterSingle(RegisterSinglenumber, mainmemory->GetMemoryValue(address));
	}
	void Load(string value, int RegisterSinglenumber) {
		cout << "Loading value " << value << " to RegisterSingle " << RegisterSinglenumber << endl;
		Register_16.SetRegisterSingle(RegisterSinglenumber, value);
	}

	void Store(int address, int RegisterSinglenumber) {
		cout << "Storing RegisterSingle " << RegisterSinglenumber << " value to memory address " << address << endl;
		mainmemory->SetMemoryValue(address, Register_16.GetRegisterValue(RegisterSinglenumber));
	}
	void Move(int RegisterSinglenumber1, int RegisterSinglenumber2) {
		cout << "Moving value from RegisterSingle " << RegisterSinglenumber1 << " to RegisterSingle " << RegisterSinglenumber2 << endl;
		Register_16.SetRegisterSingle(RegisterSinglenumber2, Register_16.GetRegisterValue(RegisterSinglenumber1));
	}
};

class CPU {
private:
	ProgramCounter programCounter;
	Memory mainmemory;
	InstructionRegister instruReg;
	Register register_16;
	ControlUnit cu;
	ALU alu;
	int Direction = 0;
public:

	CPU(Memory& mainmemory)
		: cu(mainmemory, instruReg, register_16), alu(mainmemory, instruReg, register_16), programCounter(mainmemory, instruReg) {
		cout << "CPU initialized" << endl;
	}

	void CheckEnd() {
		cout << "Checking if instruction register is loaded" << endl;
		if (instruReg.Loaded) {
			cout << "Instruction register loaded; decoding instruction" << endl;
			instruReg.decode();
			Direction = instruReg.GetDirection();
		}
		else {
			cout << "Instruction register not loaded" << endl;
		}
	}
};

class Machine {
private:
	Memory mainmemory;
	CPU maincpu;
public:
	Machine() : maincpu(mainmemory) {
		cout << "Machine initialized" << endl;
	}
	void SetMainMemoryValue(int address, string value) {
		cout << "Setting machine main memory value at address " << address << " to " << value << endl;
		mainmemory.SetMemoryValue(address, value);
	}
};

int main() {
	cout << "Give me file name" << endl;
	string filename;
	cin >> filename;
	fstream file(filename, ios::in);
	if (!file) {
		cout << "Invalid file, please try again" << endl;
		main();
	}
	string word;

	Machine machine;

	cout << "Loading instructions from file: " << filename << endl;
	vector<string> instructions;
	while (file >> word) {
		instructions.push_back(word.substr(0, 2));
		instructions.push_back(word.substr(2, 4));
		cout << "Instruction read from file: " << word << endl;
	}
	for (int i = 0; i < instructions.size(); i++) {
		cout << "Setting memory at address " << i << " to value " << instructions[i] << endl;
		machine.SetMainMemoryValue(i, instructions[i]);
		machine.SetMainMemoryValue(i + 1, instructions[i + 1]);
	}

	cout << "Instructions vector size: " << instructions.size() << endl;

	return 0;
}
