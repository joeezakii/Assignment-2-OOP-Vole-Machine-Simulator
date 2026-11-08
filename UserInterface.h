#pragma once
#include "VoleMachine.h"
#include <iostream>
#include <string>
class ConsoleView {
    public:
    void displayMemory(Memory& memory);
    void displayRegisters(RegisterFile& regFile);
    void displayCPUState(int pc, std::string ir);
    void displayScreen(Screen& screen);
    void displayMachine(VoleMachine& machine);
    void displayMessage(std::string text);
    std::string readInput(std::string prompt);
};

class MainMenu {
private:
    VoleMachine machine;
    ConsoleView view;
    void displayMenu();
    void handleLoadProgram();
    void handleRunStepByStep();
    void handleRunAtOnce();
    void handleEditRegister();
    void handleEditMemoryCell();
    bool askExitOrLoadAnother(int nextChoice_param);

public:
    void run();      
};