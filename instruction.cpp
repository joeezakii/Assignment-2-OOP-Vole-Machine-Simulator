#include "Instruction.h"
#include "RegisterFile.h"
#include "Memory.h"
#include <string>


Add::Add(int dest, int r1, int r2){
    destReg = dest;
    reg1 = r1;
    reg2 = r2;
}

//Execute Fun
void Add::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen){

    std::string val1Str = regFile.getRegister(reg1);
    std::string val2Str = regFile.getRegister(reg2);

    int num1 = std::stoi(val1Str, nullptr, 16);
    int num2 = std::stoi(val2Str, nullptr, 16);
    int sum = num1 + num2;
    std::string resultHex =;


    regFile.setRegister(destReg, resultHex);
}
