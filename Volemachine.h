#include <string>
using namespace std;
class VoleMachine {
private:
    Memory memory;
    RegisterFile register;
    CPU cpu;
    Screen screen;
    ProgramLoader loader;
public:

    bool loadProgram(string filename, string startAddress) {
    return loader.loadIntoMemory(filename, startAddress, memory);
    }

    void setRegister(int index, string value) {
        register.setRegister(index, value);
    }

    void setMemoryCell(address, value) {
    memory.setCell(address, value);
    }
    bool step() {
        return cpu.step(register, memory, screen);
    }
    void runAtOnce() {
        while (!cpu.isHalted()) { 
            step(); 
        }
    }
    bool isHalted() {
        return cpu.isHalted();
    }
    void reset() {
        memory.clear();
        register.clear();
        screen.clear();
        cpu.reset();
    }









};