#include "VoleMachineHeader.h"
// ALU class methods
ALU::ALU(Memory& memory, InstructionRegister& instruReg, Register& register_16, string& instruction2)
        : mainmemory(memory), instruRegister(instruReg), Register_16(register_16), instruction(instruction2) {
    // Constructor implementation
    cout << "ALU successfully initiated" << endl;
}

string ALU::floating_point_sum(string num1, string num2) {
    // Floating-point addition implementation
    string bin1 = HextoBin(num1);
    string bin2 = HextoBin(num2);
    double num1_dec = BintoDec(bin1);
    double num2_dec = BintoDec(bin2);
    double sum = num1_dec + num2_dec;
    string bin_sum = DectoBin(sum);
    return BintoHex(bin_sum);
}

string ALU::twosComplements_sum(string num1, string num2) {
    // Two's complement addition implementation
    string bin1 = HextoBin(num1);
    string bin2 = HextoBin(num2);
    int8_t operand1 = static_cast<int8_t>(bitset<8>(bin1).to_ulong());
    int8_t operand2 = static_cast<int8_t>(bitset<8>(bin2).to_ulong());

    // Perform addition
    int8_t sum = operand1 + operand2;

    // Convert the result to an 8-bit binary string
    return BintoHex(bitset<8>(sum).to_string());
}

void ALU::Add2complement(int R, int S, int T) {
    // Perform two's complement addition on specified registers
    Register_16.SetRegisterSingle(R, twosComplements_sum(Register_16.GetRegisterValue(S), Register_16.GetRegisterValue(T)));
}

void ALU::AddFloat(int R, int S, int T) {
    // Perform floating-point addition on specified registers
    Register_16.SetRegisterSingle(R, floating_point_sum(Register_16.GetRegisterValue(S), Register_16.GetRegisterValue(T)));
}

void ALU::bitwiseOR(int R, int S, int T) {
    // Perform bitwise OR operation on specified registers
    Register_16.SetRegisterSingle(R,DectoHex((HextoDec(Register_16.GetRegisterValue(S)) | HextoDec(Register_16.GetRegisterValue(T)))));
}

void ALU::bitwiseAND(int R, int S, int T) {
    // Perform bitwise AND operation on specified registers
    Register_16.SetRegisterSingle(R,DectoHex((HextoDec(Register_16.GetRegisterValue(S)) & HextoDec(Register_16.GetRegisterValue(T)))));
}

void ALU::bitwiseXOR(int R, int S, int T) {
    // Perform bitwise XOR operation on specified registers
    Register_16.SetRegisterSingle(R,DectoHex((HextoDec(Register_16.GetRegisterValue(S)) ^ HextoDec(Register_16.GetRegisterValue(T)))));
}

void ALU::SetInstruction(string instru) {
    // Set the instruction for the ALU to process
    instruction = instru;
}

void ALU::Decode() {
    // Decode the instruction for ALU processing
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
