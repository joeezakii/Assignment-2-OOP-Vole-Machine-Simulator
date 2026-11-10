#pragma once
#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Memory {

  vector<string>* cells;
  public:
    Memory(); 
    string getCell(string address);
    void setCell(string address, string value);
    void clear();
    int size() const;

};