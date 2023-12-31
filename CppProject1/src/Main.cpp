#include <iostream>
#include "Headers/BankSystem.h"


int main() {
    BankSystem bank;

    std::string userinformationFile = "Userinformation.txt";
    std::string BalanceFile = "Balance.txt";

    std::string ReadBuffer;

    std::string username;
    std::string password;

    std::cout << "Welcome to the Bank\nPlease type the number (1 or 2) to process\n";
    std::cout << "By pressing 1 you're entering a already existing account\nBy pressing 2 you're entering a new account\n";

    int choose;
    int amount;
    int money;

    int balance = bank.GetBalance(BalanceFile);

    std::cin >> choose;

    switch (choose) {
    case 1:

        if (bank.checkLogin(userinformationFile, username, password)) {
            std::cout << "Login succeed \n";
            int choose;
            std::cout << "(1)Balance\n(2)Depoist\n(3)Withdraw\n";
            std::cin >> choose;

            switch (choose) {
            case 1:
                bank.Balance(BalanceFile);
                break;
            case 2:
                bank.DepoistMoney(BalanceFile);
                break;
            case 3:

                std::cout << "Enter the amount to withdraw: ";
                std::cin >> amount;
                balance = bank.WithdrawMoney(BalanceFile, balance, amount);

                bank.WriteBalance(BalanceFile, balance);

                std::cout << "Current balance: ";
                bank.Balance(BalanceFile);
                break;
            default:
                std::cout << "Please enter a valid number 1 to 3\n";
                std::cin >> choose;
                break;
            }

        }
        else std::cout << "Please type the username and password correctly\n";
        break;
    case 2:
        bank.LoginInformation(userinformationFile, username, password);
        break;
    default:
        std::cout << "Please enter a valid number 1 or 2\n";
        break;
    }
    system("Pause\r\n");
}