#include <iostream>
#include <string>
#include <vector>
#include "memory.h"

using namespace std;

memory::memory() {
    cells->resize(256, "00");}

    string memory::getcell(string address) {
        int index = stoi(address, nullptr, 16);
        if (index<0 || index>256) {
            cout<<"Invalid memory address"<<endl;
        
        }
    return (*cells)[index];
    
    }
    void memory::setcell(string address, string value) {
        
        int index = stoi(address, nullptr, 16);
        if (index<0 || index>256) {
            cout<<"Invalid memory address"<<endl;
        
        }
    (*cells)[index] = value;
    }