#include "ProgramLoader.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <iostream> 

std::vector<std::string> ProgramLoader::readProgramFile(std::string filename) {
    std::vector<std::string> instructions;
    std::ifstream file(filename);
    
    
    if (!file.is_open()) {
        std::cout << "Error: Could not open " << filename << ". Check the file path!\n";
        return instructions; 
    }   
    
    std::string line;
    while (std::getline(file, line)) {
        size_t commentPos = line.find("//");
        if (commentPos != std::string::npos) {
            line = line.substr(0, commentPos);
        }
        commentPos = line.find('#');
        if (commentPos != std::string::npos) {
            line = line.substr(0, commentPos);
        }
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        if (!line.empty() && isValidInstructionText(line)) {
            instructions.push_back(line);
        }
    }
    file.close();
    return instructions;
}

bool ProgramLoader::isValidStartAddress(std::string address) {
    if (address.length() != 2) return false;
    std::regex hexRegex("^[0-9A-Fa-f]{2}$");
    return std::regex_match(address, hexRegex);
}

bool ProgramLoader::isValidInstructionText(std::string line) {
    if (line.length() != 4) return false;
    std::regex hexRegex("^[0-9A-Fa-f]{4}$");
    return std::regex_match(line, hexRegex);
}

bool ProgramLoader::loadIntoMemory(std::vector<std::string> program, std::string startAddress, Memory& memory) {
    if (!isValidStartAddress(startAddress)) {
        return false;
    }
    int startIndex = std::stoi(startAddress, nullptr, 16);
    
    if (startIndex + (program.size() * 2) > 256) {
        return false;
    }

    int currentIdx = startIndex;
    for (size_t i = 0; i < program.size(); ++i) {
        std::string inst = program[i];
        std::string byte1 = inst.substr(0, 2); 
        std::string byte2 = inst.substr(2, 2); 

        std::stringstream ss1;
        ss1 << std::uppercase << std::hex << currentIdx;
        std::string addr1 = ss1.str();
        if (addr1.length() == 1) addr1 = "0" + addr1;
        memory.setCell(addr1, byte1);

        std::stringstream ss2;
        ss2 << std::uppercase << std::hex << (currentIdx + 1);
        std::string addr2 = ss2.str();
        if (addr2.length() == 1) addr2 = "0" + addr2;
        memory.setCell(addr2, byte2);

        currentIdx += 2;
    }
    return true;
}