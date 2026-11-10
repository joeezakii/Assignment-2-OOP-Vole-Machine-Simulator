#include "CPU.h"
#include "Screen.h"
#include "Instruction.h"
#include "RegisterFile.h"
#include "Memory.h"
#include "ALU.h"
#include <sstream>
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
    
    std::stringstream ss;
    ss << std::uppercase << std::hex << (sum & 0xFF);
    std::string resultHex = ss.str();
    if (resultHex.length() < 2) {
        resultHex = "0" + resultHex;
    }

    regFile.setRegister(destReg, resultHex);
}

AddFloat::AddFloat(int dest, int r1, int r2) {
    destReg = dest;
    reg1 = r1;
    reg2 = r2;
}

void AddFloat::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    std::string val1Str = regFile.getRegister(reg1);
    std::string val2Str = regFile.getRegister(reg2);

    ALU alu;

    std::string resultHex = alu.addFloatingPoint(val1Str, val2Str);

    regFile.setRegister(destReg, resultHex);
}

LoadImm::LoadImm(int r, const std::string& val) {
    reg = r;
    value = val;
}

void LoadImm::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    regFile.setRegister(reg, value);
} 

StoreMem::StoreMem(int r, int addr) {
    reg = r;
    memAddress = addr;
}

void StoreMem::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    std::string regValue = regFile.getRegister(reg);
    std::stringstream ss;
    ss << std::uppercase << std::hex << memAddress;
    std::string memAddressHex = ss.str();
    if(memAddressHex == "FF") {
        screen.write(regValue); 
    }
    memory.setCell(memAddressHex, regValue);
} 

Move::Move(int dest, int src) {
    destReg = dest;
    srcReg = src;
}

void Move::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    std::string srcValue = regFile.getRegister(srcReg);
    regFile.setRegister(destReg, srcValue); 
}

Or::Or(int dest, int r1, int r2) {
    destReg = dest;
    reg1 = r1;
    reg2 = r2;
    
}
And::And(int dest, int r1, int r2) {
    destReg = dest;
    reg1 = r1;
    reg2 = r2;
}

Xor::Xor(int dest, int r1, int r2) {
    destReg = dest;
    reg1 = r1;
    reg2 = r2;
}   

Rotate::Rotate(int r,int s) {
    reg = r;
    steps = s;
}

Jump::Jump(int r, int addr) {
    reg = r;
    memAddress = addr;
}

void Halt::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    cpu.halt();
}

void Or::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    std::string val1Str = regFile.getRegister(reg1);
    std::string val2Str = regFile.getRegister(reg2);

    int num1 = std::stoi(val1Str, nullptr, 16);
    int num2 = std::stoi(val2Str, nullptr, 16);
    int result = num1 | num2;
    std::stringstream ss;
    ss << std::hex << result;
    std::string resultHex = ss.str();

    regFile.setRegister(destReg, resultHex);
}

void And::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    std::string val1Str = regFile.getRegister(reg1);
    std::string val2Str = regFile.getRegister(reg2);

    int num1 = std::stoi(val1Str, nullptr, 16);
    int num2 = std::stoi(val2Str, nullptr, 16);
    int result = num1 & num2;
    std::stringstream ss;
    ss << std::hex << result;
    std::string resultHex = ss.str();

    regFile.setRegister(destReg, resultHex);
}

void Xor::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    std::string val1Str = regFile.getRegister(reg1);
    std::string val2Str = regFile.getRegister(reg2);

    int num1 = std::stoi(val1Str, nullptr, 16);
    int num2 = std::stoi(val2Str, nullptr, 16);
    int result = num1 ^ num2;
    std::stringstream ss;
    ss << std::hex << result;
    std::string resultHex = ss.str();

    regFile.setRegister(destReg, resultHex);
}

void Rotate::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    std::string regValueStr = regFile.getRegister(reg);
    int regValue = std::stoi(regValueStr, nullptr, 16);
    for(int i = 0; i < steps; ++i) {
        int least_significant_bit = regValue & 1;
        regValue >>= 1; // also this aswell
        if(least_significant_bit) {
            regValue |= 0x80; 
        }
    }
    std::stringstream ss;
    ss << std::hex << regValue;
    std::string resultHex = ss.str();
    if(resultHex.length() < 2) {
        resultHex = "0" + resultHex;
    }
    regFile.setRegister(reg, resultHex);
}

void Jump::execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) {
    std::string regValueStr = regFile.getRegister(reg);
    std::string regValueofI0 = regFile.getRegister(0);
    if(regValueStr == regValueofI0) {
        cpu.setPC(memAddress);
    }
}



