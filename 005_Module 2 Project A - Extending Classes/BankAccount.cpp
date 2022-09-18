//////////////////////////////////////////////////////////////////////////////
//
//  DATE:     2/11/20
//  COURSE:   COP 2335-70B  --  Module 2 Project A  -  Extending Classes
//  NAME:     Mark Darling
//  PURPOSE:  Create a class and extend it to include additional information
//
//////////////////////////////////////////////////////////////////////////////

// PREPROCESSOR DIRECTIVES ///////////////////////////////////////////////////
#include<iostream>			// common input and output
#include<string>			// using string data types
#include "BankAccount.h"	// parent class definition
using namespace std;		// using standard scope unless otherwise specified
//////////////////////////////////////////////////////////////////////////////

// CLASS FUNCTIONS (implementation) //////////////////////////////////////////
void bankAccount::setCustomerName(string custName)
{
	customerName = custName;
}

string bankAccount::getCustomerName() const
{
	return customerName;
}

void bankAccount::setAccountNumber(int accntNumber)
{
	accountNumber = accntNumber;
}

int bankAccount::getAccountNumber() const
{
	return accountNumber;
}

double bankAccount::getBalance() const
{
	return accountBalance;
}

void bankAccount::depositMoney(double moneyDeposit)
{
	if (moneyDeposit >= 0)
	{
		cout << " SUCCESS! - You just deposited: $ " << moneyDeposit << endl;
		accountBalance = accountBalance + moneyDeposit;
	}
	else // do nothing
	{
		cout << " ERROR - VALUE MUST BE POSITIVE!\n";
		cout << "*************************************************************\n";
		cout << " How much would you like to deposit: $ ";
		cin >> moneyDeposit;
		depositMoney(moneyDeposit);
	}
}

void bankAccount::withdrawMoney(double moneyWithdraw)
{
	if (moneyWithdraw >= 0 && moneyWithdraw <= accountBalance)
		accountBalance = accountBalance - moneyWithdraw;
	else // do nothing
	{
		cout << " ERROR - VALUE MUST BE POSITIVE AND/OR LESS THAN OR EQUAL TO"
			" CURRENT ACCOUNT BALANCE!\n";
	}
}

void bankAccount::printAccountInfo() const
{
	cout << fixed << setprecision(2);
	cout << endl;
	cout << "*******************************************************" << endl;
	cout << "*               PRINT BANK ACCOUNT INFO               *" << endl;
	cout << "*******************************************************" << endl;
	cout << "CUSTOMER NAME:   " << customerName << endl;
	cout << "ACCOUNT NUMBER:  " << accountNumber << endl;
	cout << "ACCOUNT BALANCE: " << accountBalance << endl;
	cout << endl;
}

// DEFAULT CONSTRUCTOR
bankAccount::bankAccount()
{
	customerName = "";
	accountNumber = 0;
	accountBalance = 0.00;
}

// CONSTRUCTOR WITH PARAMETERS
bankAccount::bankAccount(string custName, int accntNumber, double accntBalance)
{
	customerName = custName;
	accountNumber = accntNumber;
	accountBalance = accntBalance;
}
//////////////////////////////////////////////////////////////////////////////