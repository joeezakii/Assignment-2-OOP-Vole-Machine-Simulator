#ifndef CPU_H
#define CPU_H

#include <string>
#include "Memory.h"
#include "Screen.h"
#include "RegisterFile.h"
using namespace std;

class CPU {
private:
    int programCounter;
    string instructionRegister;
    bool halted;

public:

CPU(); //installer

//loader
    void setPC(int address);
    void setIR(const string& ir);
    int getPC() const;
    string getIR() const;
//loader
    void fetch(Memory& memory); //grabber
    bool step(RegisterFile& registers, Memory& memory, Screen& screen); //stepper
    void halt(); //halting
    bool isHalted() const; //halt checker
    void reset(); //resetter
};

#endif