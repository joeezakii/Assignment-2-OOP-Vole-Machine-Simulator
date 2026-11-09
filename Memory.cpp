#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Memory.h"


using namespace std;

Memory::Memory() : cells(new vector<string>(256, "00")) {}

string Memory::getCell(string address) {
    int index=stoi(address, nullptr, 16); 
    if (index < 0 || index >= 256) {
        cout << "Memory address out of bounds!" << endl;
        
    }
    return (*cells)[index];
}

void Memory::setCell(string address, string value) {
    int index = stoi(address, nullptr, 16);
    if (index < 0 || index >= 256) {
        cout << "Memory address out of bounds!" << endl;
        return;
    }
    cells->at(index) = value;
}

void Memory::clear() {
    fill(cells->begin(), cells->end(), "00");
}

void Memory::size() {

}