#include "ProgramLoader.h"
#include <fstream>
#include <sstream>
#include <regex>

std::vector<std::string> ProgramLoader::readProgramFile(std::string filename) {
    std::vector<std::string> instructions;
    std::ifstream file(filename);
    if (!file.is_open()) {
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
    if (startIndex + program.size() > 256) {
        return false;
    }
    for (size_t i = 0; i < program.size(); ++i) {
        std::stringstream addrStream;
        addrStream << std::uppercase << std::hex << (startIndex + i);
        std::string currentAddr = addrStream.str();
        if (currentAddr.length() == 1) currentAddr = "0" + currentAddr;
        memory.setCell(currentAddr, program[i]);
    }
    return true;
}