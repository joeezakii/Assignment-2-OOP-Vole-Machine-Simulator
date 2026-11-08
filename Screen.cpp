#include "Screen.h"
#include <iostream>
#include <string>
void Screen::write(std::string& value) {
    Screen::displayBuffer += value;
};
std::string Screen::getOutput() {
    return Screen::displayBuffer;
}
void Screen::clear() {
    displayBuffer.clear();
}
