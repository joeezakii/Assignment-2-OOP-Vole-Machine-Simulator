#include "CPU.h"
#include "Instruction.h"
#include "Memory.h"
#include <sstream>
#include <iomanip>

CPU::CPU() : programCounter(0), instructionRegister("0000"){}//object


void CPU::setPC(int pc){
    programCounter = pc;
}
int CPU::getPC() const{
    return programCounter;
}



void CPU::setIR(const std::string& ir){
    instructionRegister = ir;
}
std::string CPU::getIR() const{
    return instructionRegister;
}

void CPU::fetch(Memory& memory){
    std::stringstream ss1;
    ss1 << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << programCounter;

    std::string hexAddr1 = ss1.str();

    std::stringstream ss2;
    ss2 << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << (programCounter+1);

    std::string hexAddr2 = ss2.str();


    std::string byte1 = memory.getCell(hexAddr1);
    std::string byte2 = memory.getCell(hexAddr2);

    instructionRegister = byte1 + byte2;
    programCounter += 2;
}



void CPU::halt() {
    halted = true;
}

bool CPU::isHalted() const {
    return halted;
}

void CPU::reset() {
    programCounter = 0;
    instructionRegister = "0000";
    halted = false;
}

bool CPU::step(RegisterFile& regFile, Memory& memory, Screen& screen) {
    if (halted) return false;

    fetch(memory);

   
    
    return !halted;
}