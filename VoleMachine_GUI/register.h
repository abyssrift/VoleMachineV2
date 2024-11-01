#ifndef REGISTER_H
#define REGISTER_H

#include "registersingle.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Register {
public:
    Register();  // Constructor

    void SetRegisterSingle(int index, const string& s);
    void ResetRegisters();
    RegisterSingle GetRegister(int index);
    string GetRegisterValue(int index);

private:
    vector<RegisterSingle> RegisterVector;
};

#endif // REGISTER_H
