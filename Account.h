#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Account {
private:
    int accountNumber;
    std::string holderName;
    std::string accountType;
    double balance;

public:
    Account() : accountNumber(0), holderName(""), accountType(""), balance(0.0) {}

    Account(int accNo, const std::string& name, const std::string& type, double initialDeposit)
        : accountNumber(accNo), holderName(name), accountType(type), balance(initialDeposit) {}

    // Getters
    int getAccountNumber() const { return accountNumber; }
    std::string getHolderName() const { return holderName; }
    std::string getAccountType() const { return accountType; }
    double getBalance() const { return balance; }

    // Deposit
    bool deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit amount must be positive.\n";
            return false;
        }
        balance += amount;
        std::cout << "Deposited Rs." << std::fixed << std::setprecision(2) << amount
                  << " successfully. New Balance: Rs." << balance << "\n";
        return true;
    }

    // Withdraw
    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive.\n";
            return false;
        }
        if (amount > balance) {
            std::cout << "Insufficient funds. Available balance: Rs."
                      << std::fixed << std::setprecision(2) << balance << "\n";
            return false;
        }
        balance -= amount;
        std::cout << "Withdrawn Rs." << std::fixed << std::setprecision(2) << amount
                  << " successfully. Remaining Balance: Rs." << balance << "\n";
        return true;
    }

    // Display account info
    void display() const {
        std::cout << std::left
                  << std::setw(12) << accountNumber
                  << std::setw(25) << holderName
                  << std::setw(12) << accountType
                  << "Rs." << std::fixed << std::setprecision(2) << balance << "\n";
    }

    // Write to file
    void writeToFile(std::ofstream& out) const {
        out << accountNumber << "\n"
            << holderName << "\n"
            << accountType << "\n"
            << balance << "\n";
    }

    // Read from file
    bool readFromFile(std::ifstream& in) {
        if (!(in >> accountNumber)) return false;
        in.ignore();
        std::getline(in, holderName);
        std::getline(in, accountType);
        in >> balance;
        in.ignore();
        return true;
    }
};

#endif
