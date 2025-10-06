# proiect-: Detailed Documentation

## Overview

This project is a C++ console application designed to manipulate and operate on hexadecimal numbers. It provides an interactive menu for users to perform arithmetic operations (addition, subtraction, multiplication, division) on hexadecimal values, all managed through a custom `HexInt` class. The program includes password authentication, logs operation results to a file, and demonstrates object-oriented and operator overloading concepts in C++.

---

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Main Components](#main-components)
  - [HexInt Class](#hexint-class)
  - [Menu System](#menu-system)
  - [Arithmetic Operations](#arithmetic-operations)
  - [File Logging](#file-logging)
  - [Authentication](#authentication)
- [File Structure](#file-structure)
- [Code Walkthrough](#code-walkthrough)
- [Extensibility Suggestions](#extensibility-suggestions)

---

## Features

- Handles hexadecimal numbers using a custom class.
- Supports addition, subtraction, multiplication, and division.
- Operator overloading for arithmetic and comparison.
- Input/output in hexadecimal format for clarity.
- Logs each operation and result to a file.
- Password protection for access control.
- Simple, menu-driven interface.

---

## Usage

1. **Run the Program:** Compile and execute `main.cpp`.
2. **Login:** Enter the password (`parola_secreta`) when prompted.
3. **Select Operations:** 
   - Choose from the menu: description/help, add, subtract, multiply, divide, exit.
   - Enter two hexadecimal numbers for operations (e.g., `0x1A`, `0xFF`).
4. **Results and Logging:** View results in the console and check `results.txt` for a log of all operations.

---

## Main Components

### HexInt Class

The `HexInt` class encapsulates hexadecimal integers and provides:

- **Constructors:** From `long long` or hexadecimal string (with/without `0x` prefix).
- **Conversion Methods:** Convert to and from hexadecimal string representation.
- **Operator Overloads:** 
  - Arithmetic: `+`, `-`, `*`, `/`
  - Assignment: `=`
  - Comparison: `==`, `!=`, `<`, `<=`, `>`, `>=`
  - Casts: To `long long` and `std::string` (hex representation)

#### Example

```cpp
HexInt a("0x1A");
HexInt b("0x05");
HexInt c = a + b;
std::cout << c.toHexString(); // Outputs: 0x1f
```

### Menu System

- **showMenu:** Prints available options to the user.
- **description:** Displays a brief description of the program.

### Arithmetic Operations

For each operation (addition, subtraction, multiplication, division):

- Prompts for two hexadecimal numbers.
- Converts input to `HexInt`.
- Performs the operation using overloaded operators.
- Prints and logs the result.

**Example:**

```cpp
void performAddition() {
    std::string hex1, hex2;
    std::cin >> hex1 >> hex2;
    HexInt num1(hex1), num2(hex2);
    HexInt result = num1 + num2;
    std::cout << result.toHexString();
    writeToFile("Adunare", hex1, hex2, result.toHexString());
}
```

### File Logging

- **writeToFile:** Appends each operation, operands, and result to `results.txt`.
- Format:
  ```
  Operatie: Adunare
  Primul numar: 0x1A
  Al doilea numar: 0x05
  Rezultatul: 0x1f
  --------------------------
  ```

### Authentication

- **authenticate:** Asks the user for a password before allowing access to the menu.
- Password is checked against a hardcoded string: `"parola_secreta"`.

---

## File Structure

- `main.cpp` — Main application source code, including all classes and functions.
- `results.txt` — Output file for operation logs (created at runtime).
- `README.md` — Basic project overview.

---

## Code Walkthrough

### main.cpp Structure

- **Includes:** Standard libraries for I/O, string manipulation, file handling.
- **Class Definition:** `HexInt` class for hexadecimal integer encapsulation.
- **Menu Functions:** For user interaction.
- **Arithmetic Functions:** For each operation type.
- **Authentication:** Simple password check.
- **Main Loop:** 
  - Authenticate user.
  - Show menu and handle user input.
  - Call corresponding function based on choice.
  - Loop until exit.

### Notable Implementations

- **Hexadecimal Input/Output:** User can enter numbers with or without `0x` prefix.
- **Operator Overloading:** Allows intuitive use of arithmetic and comparison operators.
- **Log File Handling:** Uses `std::ofstream` in append mode, checks file open status.
- **Password Security:** Password is currently hardcoded and visible in code.

---

## Extensibility Suggestions

- **Improve Security:** Store password more securely (hash, environment variable, etc.).
- **Input Validation:** Add error handling for invalid hexadecimal strings or division by zero.
- **Modularization:** Split the code into multiple files (e.g., class definition in a header/source file).
- **Unit Tests:** Add tests for the `HexInt` class and arithmetic functions.
- **GUI:** Optionally add a graphical user interface for ease of use.

---

## Example Output

```
Introduceti parola: parola_secreta
1. Descriere program (help)
2. Adunare
3. Scadere
4. Inmultire
5. Impartire
6. Iesire
Alegeti o optiune: 2
Introduceti primul numar hexazecimal: 0x1A
Introduceti al doilea numar hexazecimal: 0x05
Rezultatul adunarii este: 0x1f
```

---

## Authors and License

- Author: [octa332](https://github.com/octa332)
- License: Not explicitly specified in the code.

---

## See Also

- [README.md](https://github.com/octa332/proiect-/blob/cf5034dea5b1a64663181a9e88904c17a7489243/README.md)
- `results.txt` (runtime generated)

---
