#include <iostream>
#include "RegisterFile.h"

RegisterFile::RegisterFile() {
    registers.resize(16, "00");
}