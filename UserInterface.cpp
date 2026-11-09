#pragma once
#include "VoleMachine.h"
#include "CPU.h"
#include "UserInterface.h"
#include "Memory.h"
#include "Screen.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool MainMenu::askExitOrLoadAnother(int nextChoice_param) {
        if(nextChoice_param == 1) {
            handleLoadProgram();
        } else if(nextChoice_param == 2) {
            cout << "Exiting the simulator. Goodbye!" << '\n';
            return false;
        }
        return true;
};


void MainMenu::handleRunStepByStep() {
    while(!machine.isHalted()) {
        machine.step();
        view.displayMachine(machine);
        string userInput = view.readInput("Press Enter to continue to the next step or type 'exit' to stop: ");
        if(userInput == "exit") {
            break;
        }
    }
    if(machine.isHalted()) {
        view.displayMessage("Program has halted.");
    }
};

void MainMenu::handleRunAtOnce() {
    machine.runAtOnce();
    view.displayMachine(machine);
};

void MainMenu::handleEditRegister() {
    int regIndex = stoi(view.readInput("Enter the register index (0-15): "));
    string newValue = view.readInput("Enter the new value (in hex): ");
    machine.setRegister(regIndex, newValue);
    view.displayMessage("Register updated successfully.");
};

void MainMenu::handleEditMemoryCell() {
    string memAddress = view.readInput("Enter the memory address (in hex): ");
    string newValue = view.readInput("Enter the new value (in hex): ");
    machine.setMemoryCell(memAddress, newValue);
    view.displayMessage("Memory cell updated successfully.");
};



void MainMenu::handleLoadProgram() {
    string filename = view.readInput("Enter the program filename: ");
    string startAddress = view.readInput("Enter the start address: ");
    if(machine.loadProgram(filename, startAddress)) {
        view.displayMessage("Program loaded successfully.");
    } else {
        while(!machine.loadProgram(filename, startAddress)) {
            view.displayMessage("Failed to load program.");
            filename = view.readInput("Enter the program filename again: ");
            startAddress = view.readInput("Enter the start address again: ");
        }
    }
};



void MainMenu::run() {
bool flag = true;
int nextChoice;
int choice;
while(flag){
        cout << "Welcome to the VoleMachine Simulator!" << '\n';
        cout << "Which option would you like to choose?" << '\n';
        cout << "1. Load a program" << '\n';
        cout << "2. Run the program step by step" << '\n';
        cout << "3. Run the program at once" << '\n';
        cout << "4. Edit a register" << '\n';
        cout << "5. Edit a memory cell" << '\n';
        cout << "6. Exit" << '\n';
        cin >> choice;
            switch(choice) {
                case 1:
                    handleLoadProgram();
                    break;
                case 2:
                    handleRunStepByStep();
                    break;
                case 3:
                    handleRunAtOnce();
                    break;
                case 4:
                    handleEditRegister();
                    break;
                case 5:
                    handleEditMemoryCell();
                    break;
                case 6: {
                    flag = false;
                    cout << "Exiting the simulator. Goodbye!" << '\n';
                    break;
                }
        } 
         if(flag) {
                    cout << "Would you like to load another program or exit? (1 for load, 2 for exit): ";
                    cin >> nextChoice;
                    while(nextChoice != 1 && nextChoice != 2) {
                    cout << "Invalid choice. Please enter 1 to load another program or 2 to exit." << '\n';
                    cin >> nextChoice;
                    }
                flag = askExitOrLoadAnother(nextChoice);
                }
}
};
void ConsoleView::displayMemory(Memory memory) {
    cout << "Memory Contents:" << endl;
    for (int i = 0; i < 16; ++i) {
        for(int j = 0; j < 16; ++j) {
            int index = (i*16) + j;
            std::stringstream ss;
            ss << std::hex << index;
            string address = ss.str();
            if(address.length() < 2) {
                address = "0" + address;
            }
            string value = memory.getCell(address);
            cout << address << ": " << value << "  ";
        }
        cout << endl;
    }
}
void ConsoleView::displayRegisters(RegisterFile regFile) {
    cout << "Register Contents:" << endl;
    for (int i = 0; i < 16; ++i) {
        string value = regFile.getRegister(i);
        cout << "R" << i << ": " << value << "  ";
    }
    cout << endl;
}
void ConsoleView::displayCPUState(int pc, std::string ir) {
    cout << "CPU State:" << endl;
    cout << "PC: " << pc << ", IR: " << ir << endl;
}

void ConsoleView::displayScreen(Screen &screen) {
   cout << "Screen Output:" << endl;
   cout << screen.getOutput() << endl;
};

void ConsoleView::displayMachine(VoleMachine &machine) {
    displayCPUState(machine.getPC(), machine.getIR());
    displayRegisters(machine.getRegisterFile());
    displayMemory(machine.getMemory());
    displayScreen(machine.getScreen());
}

void ConsoleView::displayMessage(std::string text) {
    cout << text << endl;
}

std::string ConsoleView::readInput(std::string prompt) {
    std::string temp_string;
    std::cout << prompt;
    std::cin >> temp_string;
    return temp_string;
}
    

