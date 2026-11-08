#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <string>

class CPU;
class Memory;
class RegisterFile;
class Screen;

class Instruction{
public:
    virtual void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) = 0;
    virtual ~Instruction() = default;
};

//Load Immediate
class LoadImm :public Instruction{
    private:
        int reg;
        std::string value;
    
    
    public:
        LoadImm(int r, const std::string& val);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//Load Mem
class LoadMem :public Instruction{

    private:
        int reg;
        int memAddress;


    public:
        LoadMem(int r, int addr);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//Store Mem
class StoreMem : public Instruction {
    
    private:
        int reg;
        int memAddress;
    
    
    
    public:
        StoreMem(int r, int addr);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//Move
class Move :public Instruction{
    
    
    private:
        int destReg;
        int srcReg;

    public:
        Move(int dest, int src);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//Add
class Add :public Instruction{
   
   
    private:
        int destReg;
        int reg1;
        int reg2;
   
   
    public:
        Add(int dest, int r1, int r2);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//Add Float
class AddFloat :public Instruction{


    private:
        int destReg;
        int reg1;
        int reg2;


    public:
        AddFloat(int dest, int r1, int r2);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//OR
class Or :public Instruction{
    
    
    private:
        int destReg;
        int reg1;
        int reg2;
    
    
    
    public:
        Or(int dest, int r1, int r2);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//AND
class And :public Instruction{
    
    
    private:
        int destReg;
        int reg1;
        int reg2;
    
    
    public:
        And(int dest, int r1, int r2);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//XOR
class Xor :public Instruction{


    private:
        int destReg;
        int reg1;
        int reg2;


    public:
        Xor(int dest, int r1, int r2);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//Rotate
class Rotate :public Instruction{


    private:
        int reg;
        int steps;


    public:
        Rotate(int r, int s);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//Jump
class Jump :public Instruction{
    

    private:
        int reg;
        int memAddress;
    
    
    public:
        Jump(int r, int addr);
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

//Halt
class Halt :public Instruction{
    
    
    public:
        void execute(CPU& cpu, Memory& memory, RegisterFile& regFile, Screen& screen) override;
};

#endif
