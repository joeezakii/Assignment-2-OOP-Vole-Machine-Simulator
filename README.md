# Assignment-2-OOP-Vole-Machine-Simulator
# 🚀 Vole Machine Simulator

Hey there! 👋 Welcome to my **Vole Machine Simulator** repository! 

This is an object-oriented **C++ simulator** designed to replicate the inner workings of a classic Vole Machine architecture—from executing low-level machine instructions all the way up to tracking memory grid states and register files in real time.

Whether you're stepping through assembly-like code, debugging register values, or checking screen memory outputs, this tool is built to bring hardware execution to life in a clean, interactive environment.

---

## 🛠️ System Architecture & Features

The project is built around a modular architecture that cleanly separates hardware storage, central execution, and presentation logic:

* **Hardware Component Classes:**
  * **`Memory`**: Encapsulates 256 addressable memory cells (`00` to `FF`), handling raw string-based hex conversions, read/write cell access (`getcell`/`setcell`), and system wipes.
  * **`RegisterFile`**: Simulates 16 general-purpose CPU registers (`R0` through `RF`). It strictly enforces the core architecture rule where **`R0` is hardwired to `00`** for jump comparisons and baseline arithmetic.
  * **`ALU`**: Handles low-level bitwise operations, Two's Complement conversions, floating-point logic, and numeric additions.
* **Instruction Set Execution Engine:**
  * Uses an object-oriented design pattern where individual instruction classes (e.g., `LoadImmediate`, `LoadFromMemory`, `Store`, `Move`, `AddInteger`, `AddFloatingPoint`, `Rotate`, `Jmp`) extend a base `Instruction` class to execute specific operations cleanly.
* **Central Controller & CPU:**
  * **`CPU`**: Coordinates instruction decoding, program counter (`PC`) increments, and execution loops.
  * **`ProgramLoader`**: Reads raw assembly/hex machine code directly into memory.
* **UI & Views:**
  * Modular console visualization (`ConsoleView`) that renders current memory states, register contents, and step-by-step program execution.

---

## 💻 Supported Instruction Set Architecture (ISA)

The simulator supports key Vole operations, including:

| Opcode / Format | Instruction Name | Description |
| :--- | :--- | :--- |
| **`1 R XY`** | Load from Memory | Load contents of memory cell `XY` into register `R`. |
| **`2 R VAL`** | Load Immediate | Load bit pattern `VAL` directly into register `R`. |
| **`3 R XY`** | Store | Store contents of register `R` to memory address `XY` (address `FF` acts as screen output). |
| **`4 0 R S`** | Move | Move data from register `R` to register `S`. |
| **`5 R S T`** | Add (Integer) | Add contents of registers `S` and `T`, storing result in register `R`. |
| **`6 R S T`** | Add (Float) | Add floating-point contents of registers `S` and `T` into register `R`. |
| **`7 R S T`** | OR | Bitwise OR of registers `S` and `T` into register `R`. |
| **`8 R S T`** | AND | Bitwise AND of registers `S` and `T` into register `R`. |
| **`9 R S T`** | XOR | Bitwise XOR of registers `S` and `T` into register `R` (used for bitwise inversions). |
| **`A R 0 X`** | Rotate | Rotate contents of register `R` right by `X` bits. |
| **`B R XY`** | Jump | Jump to address `XY` if contents of register `R` equal register `R0`. |
| **`C 0 0 0`** | Halt | Terminate program execution. |

---

## 🧪 Included Sample Programs

The repository includes pre-configured Vole program examples to demonstrate full execution loops:

1. **Two's Complement Subtraction:** Demonstrates loading values into registers, performing XOR inversion, executing Two's Complement math to subtract $3$ from $5$, and writing the result ($2$) to memory address `FF`.
2. **Countdown Loop with Conditional Branching:** Shows loop control by decrementing a counter from `03` down to `01`, outputting each iteration to address `FF`, and using `B10E` / `B006` conditional jumps against `R0` to halt when zero is reached.

---

## ⚙️ Building & Running

### Requirements
* Modern **C++ compiler** supporting C++17 or later (`g++`, `clang++`, or MSVC).
* Standard C++ libraries (`<iostream>`, `<string>`, `<vector>`, `<iomanip>`).

### Quick Start

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/joeezakii/Assignment-2-OOP-Vole-Machine-Simulator.git](https://github.com/joeezakii/Assignment-2-OOP-Vole-Machine-Simulator.git)
   cd Assignment-2-OOP-Vole-Machine-Simulator

1. **Compile using PowerShell or Terminal:**

Bash
g++ -std=c++17 main.cpp vole.cpp memory.cpp Resgisterfile.cpp -o vole_sim

2. **Run the executable:**

Bash
./vole.sim


🤝 Project Structure
Plaintext
├── memory.h / memory.cpp            # Memory management (256 hex cells)
├── Resgisterfile.h / Registerfile.cpp # Register file (16 registers, R0 lock)
├── CPU.h / CPU.cpp                  # Program Counter and instruction execution cycle
├── Controller.h                     # Instruction decoding logic
├── Instructions/                    # Individual instruction executors (Load, Store, Add, etc.)
├── ProgramLoader.h                  # Memory program parser
├── ConsoleView.h                    # Command-line display & UI rendering
└── main.cpp                         # Entry point & interactive execution
Feel free to star ⭐️ the repo if you find it helpful! Happy coding!

