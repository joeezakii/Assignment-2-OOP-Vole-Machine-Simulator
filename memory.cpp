#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "memory.h"

using namespace std;

memory::memory() : cells(new vector<string>(256, "00")) {}

string memory::getcell(string address) {
    int index=stoi(address, nullptr, 16); 
    if (index < 0 || index >= 256) {
        cout << "Memory address out of bounds!" << endl;
        
    }
    return (*cells)[index];
}

void memory::setcell(string address, string value) {
    int index = stoi(address, nullptr, 16);
    if (index < 0 || index >= 256) {
        cout << "Memory address out of bounds!" << endl;
        return;
    }
    cells->at(index) = value;
}

void memory::clear() {
    fill(cells->begin(), cells->end(), "00");
}

void memory::size() {

}