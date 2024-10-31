#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <string>
#include<sstream>
#include<cmath>
#include<math.h>
#include <bits/stdc++.h>


using namespace std;

int HextoDec(string hex){
    int dec;
    dec = stoi(hex, nullptr,16);
    return dec;
}
string DectoHex(int dec){
    stringstream ss;
    ss << hex << dec;
    string hex_num = ss.str();
    transform(hex_num.begin(),hex_num.end(),hex_num.begin(),::toupper);
    return hex_num;
}

string HextoBin(string hex){
    int dec;
    dec = stoi(hex, nullptr,16);
    bitset<8> bin(dec);
    return bin.to_string();
}
string BintoHex(string bin){
    int dec;
    stringstream ss;
    dec = stoi(bin, nullptr,2);
    ss << hex << dec;
    string hex = ss.str();
    transform(hex.begin(),hex.end(),hex.begin(),::toupper);
    return hex;
}
double BintoDec(string bin){
    char sign = bin[0];
    string base = bin.substr(1,3);
    int base_int = stoi(base, nullptr,2);
    string mantissa = bin.substr(4,7);
    int mantissa_int = stoi(mantissa, nullptr,2);
    double dec = ((mantissa_int / 16.0) + 1) * pow(2,(base_int-3));
    if (sign == '0') return dec;
    else return dec * -1;
}
string DectoBin(double dec){
    double fraction = abs(dec - (int) dec);
    int counter = 0,j = 0;
    char sign;
    bitset<8> base_bin = abs((int) dec);
    string base;
    string exponent;
    string mantissa;
    string fraction_bin;
    string bin;
    base = base_bin.to_string();
    if (dec >= 0) sign = '0';
    else sign = '1';
    for (int i = 0; i < 8; ++i) {
        fraction *= 2;
        if ((int) fraction == 1) fraction_bin += '1';
        else if ((int) fraction == 0) fraction_bin += '0';
        fraction = fraction - (int) fraction;
    }
    string full_bin = base + '.' + fraction_bin;
    if ((int) dec == 0){
        counter--;
        while (full_bin[9 + j] == '0'){
            counter--;
            j++;
        }
        j = 0;
        for (int i = 10 + ((counter + 1) * -1); i < full_bin.size(); ++i) {
            if (mantissa.size() == 4) break;
            if (full_bin[i] == '.') continue;
            mantissa += full_bin[i];
        }
    }
    else{
        while (full_bin[j] == '0'){
            counter++;
            j++;
        }
        counter = 7 - counter;
        j = 0;
        for (int i = 8 + (counter * -1); i < full_bin.size(); ++i) {
            if (mantissa.size() == 4) break;
            if (full_bin[i] == '.') continue;
            mantissa += full_bin[i];
        }
    }
    if ((3 + counter) >= 0){
        bitset<3> exponent_bin(3 + counter);
        exponent = exponent_bin.to_string();
    }
    else{
        bitset<3> exponent_bin((3 + counter) * -1);
        exponent = exponent_bin.to_string();
    }
    bin = sign + exponent + mantissa;
    return bin;
}

class RegisterSingle
{
public:
    void SetRegisterSingle(string s) {
        if(s.size() == 1){
            s = "0" + s;
        }
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
        value = "00";
    }

protected:
    string value;
};

class InstructionRegister:public RegisterSingle {
private:
    int Direction = 0;
    vector<char> ControlUnitOperations{'1','2','3','4', 'A','B','C','D'};
    vector<char>ALUOperations{'5','6','7','8','9'};

public:
    string GetInstruction(){
        return value;
    }
    int GetDirection() {
        return Direction;
    }
    void SetDirection(int value){
        Direction = value;
    }

    void decode() {
        auto it = find(ControlUnitOperations.begin(), ControlUnitOperations.end(), value[0]);
        if(it != ControlUnitOperations.end())
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
    InstructionRegister()  {
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
        if(value.size() == 1){
            value = "0" + value;
        }
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
        cout << "Memory successfully initiated" << endl;
    }
};


class ProgramCounter {
    Memory& mainMemory;
    string instruc;
    int counter = 0;
    InstructionRegister& instructionReg;
public:
    void GetMemory(){

    }
    void SetCounter(int value){
        counter = value;
    }
    int GetCounter(){
        return counter;
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
private:
    Memory& mainmemory;
    Register& Register_16;
    InstructionRegister& instruRegister;
    string& instruction;

public:
    ALU(Memory& memory, InstructionRegister& instruReg, Register& register_16, string& instruction2) : mainmemory(memory), instruRegister(instruReg), Register_16(register_16), instruction(instruction2) {
        cout << "ALU successfully initiated" << endl;
    }

    string floating_point_sum(string num1, string num2){
        string bin1 = HextoBin(num1);
        string bin2 = HextoBin(num2);
        double num1_dec = BintoDec(bin1);
        double num2_dec = BintoDec(bin2);
        double sum = num1_dec + num2_dec;
        string bin_sum = DectoBin(sum);
        return BintoHex(bin_sum);
    }
    string twosComplements_sum(string num1, string num2) {
        string bin1 = HextoBin(num1);
        string bin2 = HextoBin(num2);
        int8_t operand1 = static_cast<int8_t>(bitset<8>(bin1).to_ulong());
        int8_t operand2 = static_cast<int8_t>(bitset<8>(bin2).to_ulong());

        // Perform addition
        int8_t sum = operand1 + operand2;

        // Convert the result to an 8-bit binary string
        return BintoHex(bitset<8>(sum).to_string());
    }

    void Add2complement(int R , int S, int T){
        Register_16.SetRegisterSingle(R, twosComplements_sum(Register_16.GetRegisterValue(S), Register_16.GetRegisterValue(T)));
    }
    void AddFloat(int R, int S, int T){
        Register_16.SetRegisterSingle(R, floating_point_sum(Register_16.GetRegisterValue(S), Register_16.GetRegisterValue(T)));
    }
    void bitwiseOR(int R, int S, int T){
        Register_16.SetRegisterSingle(R,DectoHex((HextoDec(Register_16.GetRegisterValue(S)) | HextoDec(Register_16.GetRegisterValue(T)))));
    }
    void bitwiseAND(int R, int S, int T){
        Register_16.SetRegisterSingle(R,DectoHex((HextoDec(Register_16.GetRegisterValue(S)) & HextoDec(Register_16.GetRegisterValue(T)))));
    }
    void bitwiseXOR(int R, int S, int T){
        Register_16.SetRegisterSingle(R,DectoHex((HextoDec(Register_16.GetRegisterValue(S)) ^ HextoDec(Register_16.GetRegisterValue(T)))));
    }

    void SetInstruction(string instru) {
        instruction = instru;
    }
    void Decode() {
        if (instruction[0] == '5') {
            int R = HextoDec(instruction.substr(1,1));
            int S = HextoDec(instruction.substr(2,1));
            int T = HextoDec(instruction.substr(3,1));
            Add2complement(R,S,T);
        }
        else if (instruction[0] == '6') {
            int R = HextoDec(instruction.substr(1,1));
            int S = HextoDec(instruction.substr(2,1));
            int T = HextoDec(instruction.substr(3,1));
            AddFloat(R,S,T);
        }
        else if (instruction[0] == '7') {
            int R = HextoDec(instruction.substr(1,1));
            int S = HextoDec(instruction.substr(2,1));
            int T = HextoDec(instruction.substr(3,1));
            bitwiseOR(R,S,T);
        }
        else if (instruction[0] == '8') {
            int R = HextoDec(instruction.substr(1,1));
            int S = HextoDec(instruction.substr(2,1));
            int T = HextoDec(instruction.substr(3,1));
            bitwiseAND(R,S,T);
        }
        else if (instruction[0] == '9') {
            int R = HextoDec(instruction.substr(1,1));
            int S = HextoDec(instruction.substr(2,1));
            int T = HextoDec(instruction.substr(3,1));
            bitwiseXOR(R,S,T);
        }
    }


};

//control unit where main instructions of the machine are carried out
class ControlUnit {
private:
    Memory& mainmemory;
    Register& Register_16;
    InstructionRegister& instruRegister;
    string& instruction;
    string CurrentOperation;
    ProgramCounter& programcounter;
public:
    ControlUnit(Memory& memory, InstructionRegister& InstruReg, Register& register_16, string& instruction2, ProgramCounter& ProgramCounter) : instruRegister(InstruReg), Register_16(register_16) , mainmemory(memory), instruction(instruction2), programcounter(ProgramCounter){
        cout << "CU successfully initiated" << endl;
    }

    void GetMemory(Memory& memory) {
        mainmemory = memory;
    }
    void CoutInstruction(){
        cout << instruction << endl;
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
    void Rotate(int Registernumber, string rotations) {
        string valueInRegister = HextoBin(Register_16.GetRegisterValue(Registernumber));
        int iterations = stoi(rotations,nullptr,16);
        for (int i = 0; i < iterations; i++) {
            string rest = valueInRegister.substr(0,valueInRegister.length() - 1);
            char lastBit = valueInRegister[valueInRegister.length() - 1];
            valueInRegister = lastBit + rest;
        }
        valueInRegister = BintoHex(valueInRegister);
        Register_16.SetRegisterSingle(Registernumber, valueInRegister);
    }
    void equality_jump(int address,int Registernumber){
        if(Register_16.GetRegisterValue(Registernumber) == Register_16.GetRegisterValue(0)){
            programcounter.SetCounter(address);
        }
    }
    void comparison_jump(int address,int Registernumber){
        int8_t register0 = static_cast<int8_t>(bitset<8>(Register_16.GetRegisterValue(Registernumber)).to_ulong());
        int8_t register1 = static_cast<int8_t>(bitset<8>(Register_16.GetRegisterValue(0)).to_ulong());
        if(HextoDec(BintoHex(bitset<8>(register1).to_string())) > HextoDec(BintoHex(bitset<8>(register0).to_string()))){
            programcounter.SetCounter(address);
        }
    }
    void Decode() {
        if (instruction[0] == '1') {
            int Registernumber = HextoDec(instruction.substr(1,1));
            int memoryaddress = HextoDec(instruction.substr(2,4));
            Load(memoryaddress,Registernumber);
        }
        else if (instruction[0] == '2') {
            int Registernumber = HextoDec(instruction.substr(1,1));
            string value = instruction.substr(2,4);
            Load(value,Registernumber);
        }
        else if (instruction[0] == '3') {
            int Registernumber = HextoDec(instruction.substr(1,1));
            int memoryaddress = HextoDec(instruction.substr(2,4));
            Store(memoryaddress,Registernumber);
        }
        else if (instruction[0] == '4') {
            int RegisternumberR = HextoDec(instruction.substr(2,1));
            int RegisternumberS = HextoDec(instruction.substr(3,1));
            Move(RegisternumberR,RegisternumberS);
        }
        else if (toupper(instruction[0]) == 'A') {
            int Registernumber = HextoDec(instruction.substr(1,1));
            string rotations = instruction.substr(2,4);
            Rotate(Registernumber, rotations);
        }
        else if (toupper(instruction[0]) == 'B') {
            int Registernumber = HextoDec(instruction.substr(1,1));
            int memoryaddress = HextoDec(instruction.substr(2,4));
            equality_jump(memoryaddress,Registernumber);
        }
        else if (toupper(instruction[0]) == 'D') {
            int Registernumber = HextoDec(instruction.substr(1,1));
            int memoryaddress = HextoDec(instruction.substr(2,4));
            comparison_jump(memoryaddress,Registernumber);
        }
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
            : mainmemory(mainmemory2), cu(mainmemory, instruReg, register_16, instruction, programCounter),
              alu(mainmemory, instruReg, register_16, instruction),
              programCounter(mainmemory, instruReg), instruReg() {
        cout << "CPU successfully initiated" << endl;
    }

    ControlUnit& GetControlUnit() {
        return cu;
    }

    Register& GetRegisters(){
        return register_16;
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
    void DisplayMemory() {
        cout << "==================MainMemory==============" << endl;
        for (int i = 0; i < 251; i+=5) {
            // Only print if there is at least one non-zero value in the current set of cells
            if (mainmemory.GetMemoryValue(i) != "00" || mainmemory.GetMemoryValue(i + 1) != "00" ||
                mainmemory.GetMemoryValue(i + 2) != "00" || mainmemory.GetMemoryValue(i + 3) != "00" ||
                mainmemory.GetMemoryValue(i + 4) != "00") {

                cout << mainmemory.GetMemoryValue(i) << " - "
                     << mainmemory.GetMemoryValue(i + 1) << " - "
                     << mainmemory.GetMemoryValue(i + 2) << " - "
                     << mainmemory.GetMemoryValue(i + 3) << " - "
                     << mainmemory.GetMemoryValue(i + 4) << endl;
            }
        }
        cout << "===========================================" << endl;
    }
    void DisplayRegisters(){
        cout << "==================Registers==============" << endl;
        for (int i = 0; i < 12; i+=4) {
            // Only print if there is at least one non-zero value in the current set of cells
            if (register_16.GetRegisterValue(i) != "00" || register_16.GetRegisterValue(i + 1) != "00" ||
                register_16.GetRegisterValue(i + 2) != "00" || register_16.GetRegisterValue(i + 3) != "00") {

                cout << register_16.GetRegisterValue(i) << " - "
                     << register_16.GetRegisterValue(i + 1) << " - "
                     << register_16.GetRegisterValue(i + 2) << " - "
                     << register_16.GetRegisterValue(i + 3) << endl;
            }
        }
        cout << "===========================================" << endl;
    }
    void CheckEnd() {
        if (instruReg.ReturnValue() == "C000" || instruReg.ReturnValue() == "c000" || programCounter.GetCounter() >= 255) {
            cout << "program exited by user through instructions" << endl;
            DisplayMemory();
            DisplayRegisters();
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
        for (int i = 0; i < 1000; i++)
        {
            cycle();
        }

    }
};



class Machine {
private:
    Memory mainmemory;
    CPU cpu;
public:
    Memory& GetMemory() {
        return mainmemory;
    }
    CPU& GetCpu() {
        return cpu;
    }
    Register& GetRegister(){
        return(cpu.GetRegisters());
    }
    Machine() : cpu(mainmemory){
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



int main(){
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
    for (int i = 0; i < (instructions.size()); i+=2) {
        cout << "Setting memory at address " << i << " " << i+1 << " to value " << instructions[i] << " " << instructions[i+1] << endl;
        machine.SetMainMemoryValue(i, instructions[i]);
        machine.SetMainMemoryValue(i + 1, instructions[i + 1]);
    }
    machine.Start();
    //regex

}