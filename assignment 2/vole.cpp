#include <iostream>
#include <string>
#include <vector>
using namespace std;




@startuml
class Memory {
    - cells: vector<string>
    + string getcell(string address)
    + void setCell(string address, string value)
    + void clear()
}

class RegisterFile {
    - registers: vector<string>
    + string getRegister(int index)
    +  void setRegister(int indes, string value)
}

class cpu{
    - int PC
    - string IR
    + fetch(memory: Memory): void
    + void decodeAndExecute(alu: ALU, regFile: RegisterFile, memory: Memory)
}

class VoleMachine {
    - memory: Memory
    - registers: RegisterFile
    - controlUnit: ControlUnit
    + void loadProgram(string filename)
    + void runStepByStep()
    + void runAtOnce()
}

VoleMachine --> Memory
VoleMachine --> RegisterFile
VoleMachine --> cpu

@enduml
