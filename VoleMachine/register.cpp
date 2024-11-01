#include "register.h"
#include "QDebug"
// Constructor
Register::Register() {
    RegisterVector.resize(16);
    qDebug() << "Register_16 successfully initiated";
}

// Sets a single register's value by index
void Register::SetRegisterSingle(int index, const string& s) {
    RegisterVector[index].SetRegisterSingle(s);
}

// Gets a RegisterSingle object at the specified index
RegisterSingle Register::GetRegister(int index) {
    return RegisterVector[index];
}

// Returns the value of the register at the specified index
string Register::GetRegisterValue(int index) {
    return RegisterVector[index].ReturnValue();
}

void Register::ResetRegisters(){
    for(int i = 0; i < RegisterVector.size(); i++){
        RegisterVector[i].SetRegisterSingle("00");
    }
}
