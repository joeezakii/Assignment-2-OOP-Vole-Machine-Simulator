#include <iostream>
#include "Registerfile.h"

RegisterFile::RegisterFile() {
    registers.resize(16, "00");
}