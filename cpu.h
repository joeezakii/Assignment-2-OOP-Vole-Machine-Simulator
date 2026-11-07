#ifndef CPU_H
#define CPU_H

#include <string>
#include "Memory.h"
#include "RegisterFile.h"
using namespace std;

class CPU {
private:
    int memory_place;
    string instructions;

public:

CPU(); //installer

//loader
    void setPC(int pc);
    void setIR(const string& ir);
    int getPC() const;
    string getIR() const;
//loader
    void fetch(Memory& memory); //graper
};

#endif
