#include "registersingle.h"

// Constructor
RegisterSingle::RegisterSingle() {
    value = "00";
}

// Sets the value of the register as a string, ensuring a 2-character format
void RegisterSingle::SetRegisterSingle(string s) {
    if (s.size() == 1) {
        s = "0" + s;
    }
    value = s;
}

// Sets a specific character in the register value at index `n`
void RegisterSingle::SetRegisterSingle(int n, char s) {
    value[n] = s;
}

// Returns the current value of the register
string RegisterSingle::ReturnValue() {
    return value;
}
