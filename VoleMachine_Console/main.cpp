#include "VoleMachineHeader.h"
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