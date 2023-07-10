#include "Headers/BankSystem.h"

#include <sstream>

void BankSystem::LoginInformation(std::string filename, std::string username, std::string password) {
   
    std::ofstream file(filename);
    
    std::cout << "Please type the username and password\n";
    std::cout << "Username: ";

    std::cin >> username;
    std::cout << "Password: ";

    std::cin >> password;
    std::cout << "New account created!";
      
    file << username;
    file << "\n";
    file << password;
    

    file.close();
}

bool BankSystem::checkLogin(std::string filename, std::string username, std::string password) {
   
    std::ifstream file(filename);

    std::cout << "Please type the username and password\n";

    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Password: ";
    std::cin >> password;


    std::string un, pw;

    std::getline(file, un);
    std::getline(file, pw);

    if (un == username && pw == password) 
        return true;
    else 
        return false;
    
    return 0;
    file.close();
}

void BankSystem::Balance(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        std::cout << line;
    }
    file.close();
}

void BankSystem::DepoistMoney(std::string filename) {
    std::ofstream file(filename);
    int money;
    std::cout << "How much money would you like to depoist?\n";
    std::cin >> money;

    file << money;
    file.close();
}

int BankSystem::WithdrawMoney(std::string filename, int balance, int amount) {
    std::ifstream file(filename);

        if (amount > balance) {
            std::cout << "Insufficient balance!\n";
            return balance;
        }
        balance -= amount;
    
   
    return balance;
    
}

int BankSystem::GetBalance(std::string filename) {
    std::ifstream file(filename);
    int balance;
    file >> balance;
    return balance;
}

void BankSystem::WriteBalance(std::string filename, int balance) {
    std::ofstream file(filename);
    file << balance;
}