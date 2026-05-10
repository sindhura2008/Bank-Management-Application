# Bank Management Application

A C++ based Bank Management Application that simulates core banking operations using **Object-Oriented Programming** and **File Handling**.

## Features
- Create Savings / Current accounts
- Deposit and Withdraw funds
- Check account balance
- Display all accounts
- Delete an account
- Persistent data storage using file handling (`accounts.dat`)

## File Structure
| File | Description |
|---|---|
| `main.cpp` | Entry point with menu-driven interface |
| `Account.h` | Account class with deposit, withdraw, file I/O |
| `Bank.h` | Bank class managing all account operations |
| `README.md` | Project documentation |

## How to Compile & Run

```bash
g++ -std=c++17 main.cpp -o bank_app
./bank_app
```

## OOP Concepts Used
- **Classes & Objects** – `Account` and `Bank` classes
- **Encapsulation** – Private data with public methods
- **Abstraction** – Clean interfaces hiding internal logic
- **File Handling** – `ifstream` / `ofstream` for persistent storage
