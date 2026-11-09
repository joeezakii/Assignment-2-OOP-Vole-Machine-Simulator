#include "CPU.h"
#include "Instruction.h"
#include "Memory.h"
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
    std::string byte1 = memory.getInstruction(programCounter);
    std::string byte2 = memory.getInstruction(programCounter + 1);
    instructionRegister = byte1 + byte2;
    programCounter += 2;
}