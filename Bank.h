#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>
#include <string>
#include <limits>

class Bank {
private:
    std::vector<Account> accounts;
    const std::string DATA_FILE = "accounts.dat";
    int nextAccountNumber;

    int findAccount(int accNo) const {
        for (int i = 0; i < (int)accounts.size(); i++)
            if (accounts[i].getAccountNumber() == accNo)
                return i;
        return -1;
    }

public:
    Bank() : nextAccountNumber(1001) {}

    // Create a new account
    void createAccount() {
        std::string name, type;
        double initialDeposit;

        std::cout << "\n--- Create New Account ---\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter account holder name: ";
        std::getline(std::cin, name);

        std::cout << "Account type (Savings/Current): ";
        std::getline(std::cin, type);

        if (type != "Savings" && type != "Current") {
            std::cout << "Invalid type. Defaulting to Savings.\n";
            type = "Savings";
        }

        std::cout << "Enter initial deposit amount (Rs.): ";
        std::cin >> initialDeposit;

        if (initialDeposit < 500) {
            std::cout << "Minimum initial deposit is Rs.500. Account not created.\n";
            return;
        }

        Account acc(nextAccountNumber++, name, type, initialDeposit);
        accounts.push_back(acc);
        std::cout << "\nAccount created successfully!\n";
        std::cout << "Your Account Number: " << acc.getAccountNumber() << "\n";
        saveToFile();
    }

    // Deposit into account
    void deposit() {
        int accNo; double amount;
        std::cout << "\n--- Deposit ---\n";
        std::cout << "Enter account number: "; std::cin >> accNo;

        int idx = findAccount(accNo);
        if (idx == -1) { std::cout << "Account not found.\n"; return; }

        std::cout << "Enter deposit amount (Rs.): "; std::cin >> amount;
        if (accounts[idx].deposit(amount)) saveToFile();
    }

    // Withdraw from account
    void withdraw() {
        int accNo; double amount;
        std::cout << "\n--- Withdraw ---\n";
        std::cout << "Enter account number: "; std::cin >> accNo;

        int idx = findAccount(accNo);
        if (idx == -1) { std::cout << "Account not found.\n"; return; }

        std::cout << "Enter withdrawal amount (Rs.): "; std::cin >> amount;
        if (accounts[idx].withdraw(amount)) saveToFile();
    }

    // Check balance
    void checkBalance() {
        int accNo;
        std::cout << "\n--- Balance Inquiry ---\n";
        std::cout << "Enter account number: "; std::cin >> accNo;

        int idx = findAccount(accNo);
        if (idx == -1) { std::cout << "Account not found.\n"; return; }

        std::cout << "\nAccount Holder : " << accounts[idx].getHolderName() << "\n";
        std::cout << "Account Number : " << accounts[idx].getAccountNumber() << "\n";
        std::cout << "Account Type   : " << accounts[idx].getAccountType() << "\n";
        std::cout << "Balance        : Rs." << std::fixed << std::setprecision(2)
                  << accounts[idx].getBalance() << "\n";
    }

    // Display all accounts
    void displayAll() {
        std::cout << "\n--- All Accounts ---\n";
        if (accounts.empty()) { std::cout << "No accounts found.\n"; return; }

        std::cout << std::left
                  << std::setw(12) << "Acc No."
                  << std::setw(25) << "Holder Name"
                  << std::setw(12) << "Type"
                  << "Balance\n";
        std::cout << std::string(60, '-') << "\n";
        for (const auto& acc : accounts) acc.display();
    }

    // Delete an account
    void deleteAccount() {
        int accNo;
        std::cout << "\n--- Delete Account ---\n";
        std::cout << "Enter account number to delete: "; std::cin >> accNo;

        int idx = findAccount(accNo);
        if (idx == -1) { std::cout << "Account not found.\n"; return; }

        std::cout << "Are you sure? (y/n): ";
        char confirm; std::cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            accounts.erase(accounts.begin() + idx);
            std::cout << "Account deleted successfully.\n";
            saveToFile();
        } else {
            std::cout << "Deletion cancelled.\n";
        }
    }

    // Save all accounts to file
    void saveToFile() const {
        std::ofstream out(DATA_FILE);
        if (!out) { std::cerr << "Error saving data.\n"; return; }
        out << nextAccountNumber << "\n" << accounts.size() << "\n";
        for (const auto& acc : accounts) acc.writeToFile(out);
        out.close();
    }

    // Load all accounts from file
    void loadFromFile() {
        std::ifstream in(DATA_FILE);
        if (!in) return;
        in >> nextAccountNumber;
        int count; in >> count; in.ignore();
        accounts.clear();
        for (int i = 0; i < count; i++) {
            Account acc;
            if (acc.readFromFile(in)) accounts.push_back(acc);
        }
        in.close();
    }
};

#endif
