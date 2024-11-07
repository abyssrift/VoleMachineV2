#include "VoleMachineHeader.h"
int main(){
    string filename = "textcase.txt";
//    cout << "Please Enter the .txt File's Name: " << endl;
//    cin >> filename;
    while (filename.substr(filename.size()-4,filename.size()) != ".txt"){
        cout << "The name you entered doesn't belong to a .txt file, Enter a Valid Name: " << endl;
        cin >> filename;
    }
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
        machine.SetMainMemoryValue(i + 2, instructions[i]);
        machine.SetMainMemoryValue(i + 3, instructions[i + 1]);
    }
    machine.Start();
}