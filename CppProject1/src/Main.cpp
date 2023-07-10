#include <iostream>
#include "Headers/FileSystem.h"
#include "Headers/BankSystem.h"


int main() {
    FileSystem file;
    BankSystem system;
   
    std::string userinformationFile = "Userinformation.txt";
    std::string BalanceFile = "Balance.txt";

    std::string ReadBuffer;

    char username[25] = "";
    char password[16] = " \r\n ";

    std::cout << "Welcome to the Bank\nPlease type the number (1 or 2) to process\n";
    std::cout << "By pressing 1 you're entering a already existing account\nBy pressing 2 you're entering a new account\n";

    int choose = 0;
    int amount;
    int money = {};
    int balance = system.GetBalance(BalanceFile);
    std::cin >> choose;

        switch (choose) {
        case 1:
           
            if (system.checkLogin(userinformationFile, username, password)) {
                std::cout << "Login succeed \n";
                int choose = 0;
                std::cout << "(1)Balance\n(2)Depoist\n(3)Withdraw\n";
                std::cin >> choose;
               
                switch (choose){
                case 1:
                    system.Balance(BalanceFile);
                    break;
                case 2:
                    system.DepoistMoney(BalanceFile);
                    break;
                case 3:
                    
                    std::cout << "Enter the amount to withdraw: ";
                    std::cin >> amount;
                    balance = system.WithdrawMoney(BalanceFile,balance, amount);

                    system.WriteBalance(BalanceFile,balance);

                    std::cout << "Current balance:";
                    system.Balance(BalanceFile);
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
            system.LoginInformation(userinformationFile, username, password);
            break;
        default:
            std::cout << "Please enter a valid number 1 or 2\n";
            std::cin >> choose;
            break;
        }
}
