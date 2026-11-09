#include <iostream>
#include <string>
#include "RegisterFile.h"

RegisterFile::RegisterFile() {
    registers.resize(16, "00");
}

std::string RegisterFile::getRegister(int index) {
    if (index < 0 || index >= 16) {
        return "00";
    }
    return registers[index];
}

void RegisterFile::setRegister(int index, std::string value) {
    if (index >= 0 && index < 16) {
        registers[index] = value;
    }
}

void RegisterFile::clear() {
    for (int i = 0; i < 16; ++i) {
        registers[i] = "00";
    }
}