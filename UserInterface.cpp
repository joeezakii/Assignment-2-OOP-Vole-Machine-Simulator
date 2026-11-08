#include "VoleMachine.h"
#include "CPU.h"
#include "UserInterface.h"
#include "Memory.h"
#include "Screen.h"
#include <iostream>
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
}
};


