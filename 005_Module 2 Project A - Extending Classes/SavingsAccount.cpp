//////////////////////////////////////////////////////////////////////////////
//
//  DATE:     2/11/20
//  COURSE:   COP 2335-70B  --  Module 2 Project A  -  Extending Classes
//  NAME:     Mark Darling
//  PURPOSE:  Create a class and extend it to include additional information
//
//////////////////////////////////////////////////////////////////////////////

// PREPROCESSOR DIRECTIVES ///////////////////////////////////////////////////
#include<iostream>				// common input and output
#include<string>				// using string data types
#include<iomanip>				// output formatting of decimals
#include "SavingsAccount.h"		// class definition this file implements
using namespace std;			// using standard scope unless otherwise specified
//////////////////////////////////////////////////////////////////////////////

// CLASS FUNCTIONS (implementation)  /////////////////////////////////////////
void savingsAccount::setInterestRate(double intRate)
{
	if (intRate >= 0 && intRate <= 100)
		savingsInterestRate = intRate;
	else // do nothing
	{
		cout << " ERROR - VALUE MUST BE BETWEEN 0.00 and 100.00 !\n";
		cout << "*************************************************************\n";
		cout << " What would you like to set the interest rate to: % ";
		cin >> intRate;
		savingsAccount::setInterestRate(intRate);
	}
}
double savingsAccount::getInterestRate() const
{
	return savingsInterestRate;
}
void savingsAccount::postInterest()
{
	double savingsInterestRate = getInterestRate();
	double newAccountBalance = (accountBalance * (1 + (savingsInterestRate / 100))); // I KNOW THIS IS NOT THE CORRECT CALCULATION FOR ACCRUED INTEREST
	accountBalance = newAccountBalance;
}
void savingsAccount::withdrawMoney(double withdrawAmount) // OVERRIDE = SAME SIGNATURE, DIFFERENT FUNCTION
{
	double savingsAccountBalance = getBalance();
	if (withdrawAmount > savingsAccountBalance && withdrawAmount >= 0)
	{
		cout << " INSUFFICIENT FUNDS! - Please try withdrawing less money.\n";
		cout << "*************************************************************\n";
		cout << " How much would you like to withdraw from savings: $ ";
		cin >> withdrawAmount;
		savingsAccount::withdrawMoney(withdrawAmount);
	}
	else if (withdrawAmount <= savingsAccountBalance && withdrawAmount >= 0)
	{
		cout << " SUCCESS! - You just withdrew $" << withdrawAmount << " from your SAVINGS account!\n";
		accountBalance = accountBalance - withdrawAmount;
	}
	else
	{
		cout << " SAVINGS ERROR - Please enter valid values.\n";
		cout << "*************************************************************\n";
		cout << " How much would you like to withdraw from savings: $ ";
		cin >> withdrawAmount;
		savingsAccount::withdrawMoney(withdrawAmount);
	}
}
void savingsAccount::printAccountInfo() const	// OVERRIDE = SAME SIGNATURE, DIFFERENT FUNCTION
{
	cout << fixed << setprecision(2);
	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "*               PRINT SAVINGS ACCOUNT INFO               *" << endl;
	cout << "**********************************************************" << endl;
	cout << "CUSTOMER NAME:             " << customerName << endl;
	cout << "SAVINGS ACCOUNT NUMBER:  # " << accountNumber << endl;
	cout << "SAVINGS ACCOUNT BALANCE: $ " << accountBalance << endl;
	cout << "SAVINGS INTEREST RATE:     " << savingsInterestRate << " %" << endl;
	cout << endl;
}
// DEFAULT CONSTRUCTOR
savingsAccount::savingsAccount() : bankAccount() // CALL bankAccount() DEFAULT CONSTRUCTOR FIRST!
{
	//string customerName = "";			// THIS IS INITIALIZED BY bankAccount() DEFAULT CONSTRUCTOR
	//int savingsAccountNumber = 0;		// THIS IS INITIALIZED BY bankAccount() DEFAULT CONSTRUCTOR
	//double savingsBalance = 0.00;		// THIS IS INITIALIZED BY bankAccount() DEFAULT CONSTRUCTOR
	savingsInterestRate = 0.00;
}
// CONSTRUCTOR WITH PARAMETERS
savingsAccount::savingsAccount(string custName, int accntNumber, double accntBalance, double intRate)
	: bankAccount(custName, accntNumber, accntBalance) // PASS VARIABLES IN COMMON TO BASE CLASS CONSTRUCTOR
{
	//string customerName = custName;			// THIS IS INITIALIZED BY bankAccount() DEFAULT CONSTRUCTOR
	//int savingsAccountNumber = accntNumber;	// THIS IS INITIALIZED BY bankAccount() DEFAULT CONSTRUCTOR
	//double savingsBalance = accntBalance;		// THIS IS INITIALIZED BY bankAccount() DEFAULT CONSTRUCTOR
	savingsInterestRate = intRate;
}
//////////////////////////////////////////////////////////////////////////////