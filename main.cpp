#include <iostream>
#include "Bank.h"

int main() {
    Bank bank;
    bank.loadFromFile();

    int choice;
    do {
        std::cout << "\n=============================\n";
        std::cout << "   BANK MANAGEMENT SYSTEM    \n";
        std::cout << "=============================\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Check Balance\n";
        std::cout << "5. Display All Accounts\n";
        std::cout << "6. Delete Account\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.deposit();       break;
            case 3: bank.withdraw();      break;
            case 4: bank.checkBalance();  break;
            case 5: bank.displayAll();    break;
            case 6: bank.deleteAccount(); break;
            case 0: std::cout << "Thank you for banking with us!\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
