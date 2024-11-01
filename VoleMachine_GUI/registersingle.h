#ifndef REGISTERSINGLE_H
#define REGISTERSINGLE_H

#include <string>
using namespace std;

class RegisterSingle {
public:
    RegisterSingle();  // Constructor

    void SetRegisterSingle(string s);
    void SetRegisterSingle(int n, char s);
    string ReturnValue();

protected:
    string value;
};

#endif // REGISTERSINGLE_H
