#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RegisterFile {
private:
    vector<string> registers; 
public:
    RegisterFile(); 
    string getRegister(int index);
    void setRegister(int index, string value);
    void clear();
};