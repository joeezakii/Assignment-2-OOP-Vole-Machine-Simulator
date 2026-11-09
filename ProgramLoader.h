#ifndef PROGRAMLOADER_H
#define PROGRAMLOADER_H

#include <string>
#include <vector>
#include "Memory.h"

class ProgramLoader {
public:
    std::vector<std::string> readProgramFile(std::string filename);
    bool isValidStartAddress(std::string address);
    bool isValidInstructionText(std::string line);
    bool loadIntoMemory(std::vector<std::string> program, std::string startAddress, Memory& memory);
};

#endif