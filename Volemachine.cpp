#include "VoleMachine.h"
#include "CPU.h"
#include "Memory.h"
#include "RegisterFile.h"
#include <string>
#include <vector>


using namespace std;

 bool VoleMachine::loadProgram(string filename, string startAddress) {
    std::vector<std::string> program = loader.readProgramFile(filename);
    return loader.loadIntoMemory(program, startAddress, memory);
    }
  void VoleMachine::setRegister(int index, string value) {
        registers.setRegister(index, value);
    }
     void VoleMachine::setMemoryCell(string address, string value) {
        memory.setCell(address, value);
    }
    bool VoleMachine::step() {
        return cpu.step(registers, memory, screen);
    }
    void VoleMachine::runAtOnce() {
        while (!cpu.isHalted()) { 
            step(); 
        }
    }
     bool VoleMachine::isHalted() {
        return cpu.isHalted();
    }
    void VoleMachine::reset() {
        memory.clear();
        registers.clear();
        screen.clear();
        cpu.reset();
    }
    Memory& VoleMachine::getMemory()  {
        return memory;
    } 
    RegisterFile& VoleMachine::getRegisterFile() {
        return registers;
    }
    Screen& VoleMachine::getScreen() {
        return screen;
    }
    int VoleMachine::getPC()  {
        return cpu.getPC();
    }
    string VoleMachine::getIR() {
    return cpu.getIR();
}