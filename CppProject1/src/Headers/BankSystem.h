#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

class BankSystem
{
private:

public:
	
	int GetBalance(std::string filename);

	bool checkLogin(std::string filename, std::string username, std::string password);

	void LoginInformation(std::string filename, std::string username, std::string password);

	void Balance(std::string filename);

	void DepoistMoney(std::string filename);

	int WithdrawMoney(std::string filename, int balance, int amount);

	void WriteBalance(std::string filename, int balance);
};
