#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RegisterFile {
    vector<string> registers;
public:
    string getRegister(int index);
    void setRegister(int index, string value);
    void clear();
};
