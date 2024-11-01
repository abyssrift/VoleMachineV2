#include "VoleMachineHeader.h"

// Utility functions
int HextoDec(string hex) {
    // Implementation for hexadecimal to decimal conversion
    int dec;
    dec = stoi(hex, nullptr,16);
    return dec;
}

string DectoHex(int dec) {
    // Implementation for decimal to hexadecimal conversion
    stringstream ss;
    ss << hex << dec;
    string hex_num = ss.str();
    transform(hex_num.begin(),hex_num.end(),hex_num.begin(),::toupper);
    return hex_num;
}

string HextoBin(string hex) {
    // Implementation for hexadecimal to binary conversion
    int dec;
    dec = stoi(hex, nullptr,16);
    bitset<8> bin(dec);
    return bin.to_string();
}

string BintoHex(string bin) {
    // Implementation for binary to hexadecimal conversion
    int dec;
    stringstream ss;
    dec = stoi(bin, nullptr,2);
    ss << hex << dec;
    string hex = ss.str();
    transform(hex.begin(),hex.end(),hex.begin(),::toupper);
    return hex;
}

double BintoDec(string bin) {
    char sign = bin[0];
    string base = bin.substr(1,3);
    int base_int = stoi(base, nullptr,2);
    string mantissa = bin.substr(4,7);
    int mantissa_int = stoi(mantissa, nullptr,2);
    double dec = ((mantissa_int / 16.0) + 1) * pow(2,(base_int-3));
    if (sign == '0') return dec;
    else return dec * -1;
}

string DectoBin(double dec) {
    // Implementation for decimal to binary conversion
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
