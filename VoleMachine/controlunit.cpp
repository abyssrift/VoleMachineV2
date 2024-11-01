#include "ControlUnit.h"
#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include<sstream>
#include<cmath>
#include<math.h>
#include <bits/stdc++.h>



int HextoDec(string hex){
    int dec;
    dec = stoi(hex, nullptr,16);
    return dec;
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


ControlUnit::ControlUnit(Memory& memory, InstructionRegister& InstruReg, Register& register_162, string& instruction2, ProgramCounter& ProgramCounter)
    : mainmemory(memory), Register_16(register_162), instruRegister(InstruReg), instruction(instruction2), programcounter(ProgramCounter) {
    cout << "CU successfully initiated" << endl;
}

void ControlUnit::GetMemory(Memory& memory) {
    mainmemory = memory;
}

void ControlUnit::CoutInstruction() {
    cout << instruction << endl;
}

void ControlUnit::Load(int address, int RegisterSinglenumber) {
    Register_16.SetRegisterSingle(RegisterSinglenumber, mainmemory.GetMemoryValue(address));
}

void ControlUnit::Load(string value, int RegisterSinglenumber) {
    Register_16.SetRegisterSingle(RegisterSinglenumber, value);
}

void ControlUnit::Store(int address, int RegisterSinglenumber) {
    if(instruction[2] && instruction[3] == '0'){
        mainmemory.SetMemoryValue(0,Register_16.GetRegisterValue(RegisterSinglenumber));
        return;
    }
    mainmemory.SetMemoryValue(address, Register_16.GetRegisterValue(RegisterSinglenumber));
}

void ControlUnit::Move(int RegisterSinglenumber1, int RegisterSinglenumber2) {
    Register_16.SetRegisterSingle(RegisterSinglenumber2, Register_16.GetRegisterValue(RegisterSinglenumber1));
}

void ControlUnit::Jump(int address, int Registernumber) {
    if (Register_16.GetRegisterValue(Registernumber) == Register_16.GetRegisterValue(0)) {
        programcounter.SetCounter(address);
    }
}


void ControlUnit::Decode() {
    if (instruction[0] == '1') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        int memoryaddress = HextoDec(instruction.substr(2, 4)) + 2;
        Load(memoryaddress, Registernumber);
    } else if (instruction[0] == '2') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        std::string value = instruction.substr(2, 4);
        Load(value, Registernumber);
    } else if (instruction[0] == '3') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        int memoryaddress = HextoDec(instruction.substr(2, 4)) + 2;
        Store(memoryaddress, Registernumber);
    } else if (instruction[0] == '4') {
        int RegisternumberR = HextoDec(instruction.substr(2, 1));
        int RegisternumberS = HextoDec(instruction.substr(3, 1));
        Move(RegisternumberR, RegisternumberS);
    } else if (instruction[0] == 'A') {
        // Handle operation for instruction 'A'
    } else if (instruction[0] == 'B') {
        int Registernumber = HextoDec(instruction.substr(1, 1));
        int memoryaddress = HextoDec(instruction.substr(2, 4)) + 2;
        Jump(memoryaddress, Registernumber);
    }
}
