#include "alu.h"
#include "QDebug"

ALU::ALU(Memory& memory, InstructionRegister& instruReg, Register& register_162, string& instruction2)
    : mainmemory(memory), instruRegister(instruReg), Register_16(register_162), instruction(instruction2) {
    qDebug() << "ALU successfully initiated";
}

int ALU::HextoDec(string hex) {
    return stoi(hex, nullptr, 16);
}

string ALU::DectoHex(int dec) {
    stringstream ss;
    ss << hex << dec;
    string hex_num = ss.str();
    transform(hex_num.begin(), hex_num.end(), hex_num.begin(), ::toupper);
    return hex_num;
}

string ALU::HextoBin(string hex) {
    int dec = stoi(hex, nullptr, 16);
    bitset<8> bin(dec);
    return bin.to_string();
}

string ALU::BintoHex(string bin) {
    int dec = stoi(bin, nullptr, 2);
    stringstream ss;
    ss << hex << dec;
    string hex = ss.str();
    transform(hex.begin(), hex.end(), hex.begin(), ::toupper);
    return hex;
}

double ALU::BintoDec(string bin) {
    char sign = bin[0];
    string base = bin.substr(1, 3);
    int base_int = stoi(base, nullptr, 2);
    string mantissa = bin.substr(4, 7);
    int mantissa_int = stoi(mantissa, nullptr, 2);
    double dec = ((mantissa_int / 16.0) + 1) * pow(2, (base_int - 3));
    return (sign == '0') ? dec : dec * -1;
}

string ALU::DectoBin(double dec) {
    double fraction = abs(dec - static_cast<int>(dec));
    int counter = 0, j = 0;
    char sign;
    bitset<8> base_bin = abs(static_cast<int>(dec));
    string base, exponent, mantissa, fraction_bin, bin;
    base = base_bin.to_string();
    sign = (dec >= 0) ? '0' : '1';

    for (int i = 0; i < 8; ++i) {
        fraction *= 2;
        fraction_bin += (static_cast<int>(fraction) == 1) ? '1' : '0';
        fraction -= static_cast<int>(fraction);
    }

    string full_bin = base + '.' + fraction_bin;
    if (static_cast<int>(dec) == 0) {
        counter--;
        while (full_bin[9 + j] == '0') {
            counter--;
            j++;
        }
        j = 0;
        for (int i = 10 + (-counter); i < full_bin.size(); ++i) {
            if (mantissa.size() == 4) break;
            if (full_bin[i] == '.') continue;
            mantissa += full_bin[i];
        }
    } else {
        while (full_bin[j] == '0') {
            counter++;
            j++;
        }
        counter = 7 - counter;
        j = 0;
        for (int i = 8 + (-counter); i < full_bin.size(); ++i) {
            if (mantissa.size() == 4) break;
            if (full_bin[i] == '.') continue;
            mantissa += full_bin[i];
        }
    }

    if ((3 + counter) >= 0) {
        bitset<3> exponent_bin(3 + counter);
        exponent = exponent_bin.to_string();
    } else {
        bitset<3> exponent_bin((3 + counter) * -1);
        exponent = exponent_bin.to_string();
    }

    bin = sign + exponent + mantissa;
    return bin;
}

string ALU::floating_point_sum(string num1, string num2) {
    string bin1 = HextoBin(num1);
    string bin2 = HextoBin(num2);
    double num1_dec = BintoDec(bin1);
    double num2_dec = BintoDec(bin2);
    double sum = num1_dec + num2_dec;
    string bin_sum = DectoBin(sum);
    return BintoHex(bin_sum);
}

string ALU::twosComplements_sum(string num1, string num2) {
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
    Register_16.SetRegisterSingle(R, twosComplements_sum(Register_16.GetRegisterValue(S), Register_16.GetRegisterValue(T)));
}

void ALU::AddFloat(int RegisternumberR, int RegisternumberS, int RegisternumberT) {
    Register_16.SetRegisterSingle(RegisternumberR, floating_point_sum(Register_16.GetRegisterValue(RegisternumberS), Register_16.GetRegisterValue(RegisternumberT)));
}

void ALU::bitwiseOR(int R, int S, int T) {
    Register_16.SetRegisterSingle(R, DectoHex((HextoDec(Register_16.GetRegisterValue(S)) | HextoDec(Register_16.GetRegisterValue(T)))));
}

void ALU::bitwiseAND(int R, int S, int T) {
    Register_16.SetRegisterSingle(R, DectoHex((HextoDec(Register_16.GetRegisterValue(S)) & HextoDec(Register_16.GetRegisterValue(T)))));
}

void ALU::bitwiseXOR(int R, int S, int T) {
    Register_16.SetRegisterSingle(R, DectoHex((HextoDec(Register_16.GetRegisterValue(S)) ^ HextoDec(Register_16.GetRegisterValue(T)))));
}

void ALU::SetInstruction(string instru) {
    instruction = instru;
}

void ALU::Decode() {
    if (instruction[0] == '5') {
        int R = HextoDec(instruction.substr(1, 1));
        int S = HextoDec(instruction.substr(2, 1));
        int T = HextoDec(instruction.substr(3, 1));
        Add2complement(R, S, T);
    } else if (instruction[0] == '6') {
        int R = HextoDec(instruction.substr(1, 1));
        int S = HextoDec(instruction.substr(2, 1));
        int T = HextoDec(instruction.substr(3, 1));
        AddFloat(R, S, T);
    }
}
