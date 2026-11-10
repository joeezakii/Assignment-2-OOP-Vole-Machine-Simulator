#include "CPU.h"
#include "Instruction.h"
#include "Memory.h"
#include "RegisterFile.h"
#include "Screen.h"
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

    if (programCounter >= 256) {
        halted = true;
        return false;
    }

    std::string ir = getIR();
    if (ir.length() < 4) return !halted;

    // 2. Decode instruction opcode and operands
    int opcode = std::stoi(ir.substr(0, 1), nullptr, 16);
    int r = std::stoi(ir.substr(1, 1), nullptr, 16);
    int x = std::stoi(ir.substr(2, 1), nullptr, 16);
    int y = std::stoi(ir.substr(3, 1), nullptr, 16);
    int xy = std::stoi(ir.substr(2, 2), nullptr, 16);

    Instruction* currentInstruction = nullptr;

    switch (opcode) {
        case 1: 
            currentInstruction = new LoadImm(r, memory.getCell(ir.substr(2, 2)));
            break;
        case 2: 
            currentInstruction = new LoadImm(r, ir.substr(2, 2));
            break;
        case 3: 
            currentInstruction = new StoreMem(r, xy);
            break;
        case 4: 
            currentInstruction = new Move(x, y);
            break;
        case 5: 
            currentInstruction = new Add(r, x, y);
            break;
        case 6: 
            currentInstruction = new AddFloat(r, x, y); 
            break;
        case 7: 
            currentInstruction = new Or(r, x, y);
            break;
        case 8: 
            currentInstruction = new And(r, x, y);
            break;
        case 9: 
            currentInstruction = new Xor(r, x, y);
            break;
        case 0xA: 
            currentInstruction = new Rotate(r, y);
            break;
        case 0xB: 
            currentInstruction = new Jump(r, xy);
            break;
        case 0xC: 
            currentInstruction = new Halt();
            break;
        default:
            break;
    }

    
    if (currentInstruction != nullptr) {
        currentInstruction->execute(*this, memory, regFile, screen);
        delete currentInstruction;
    }
   
    
    return !halted;
}