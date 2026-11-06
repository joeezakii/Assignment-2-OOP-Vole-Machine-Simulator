#pragma once
#include "CPU.h"
#include "Memory.h"
#include "RegisterFile.h"
#include <string>
using namespace std;
class VoleMachine {
private:
    Memory memory;
    RegisterFile  registers;
    CPU cpu;
    Screen screen;
    ProgramLoader loader;
public:

    bool loadProgram(string filename, string startAddress);

    void setRegister(int index, string value);

    void setMemoryCell(string address, string value);

    bool step();
    
    void runAtOnce();

    bool isHalted();

    void reset();

};