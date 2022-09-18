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
#include "CheckingAccount.h"	// class definition this file implements
using namespace std;			// using standard scope unless otherwise specified
//////////////////////////////////////////////////////////////////////////////

// CLASS FUNCTIONS (implementation) //////////////////////////////////////////
void checkingAccount::setInterestRate(double intRate)
{
	if (intRate >= 0 && intRate <= 100)
	{
		checkingInterestRate = intRate;
		cout << " SUCCESS! - The interest rate has been set to: % " << intRate << endl;
	}
	else // do nothing
	{
		cout << " ERROR - VALUE MUST BE BETWEEN 0.00 and 100.00 !\n";
		cout << "*************************************************************\n";
		cout << " What would you like to set the interest rate to: % ";
		cin >> intRate;
		checkingAccount::setInterestRate(intRate);
	}
}
double checkingAccount::getInterestRate() const
{
	return checkingInterestRate;
}
void checkingAccount::setMinBalanace(double minBalance)
{
	if (minBalance >= 0)
		checkingMinimumBalance = minBalance;
	else // do nothing
	{
		cout << " ERROR - VALUE MUST BE POSITIVE!\n";
		cout << "*************************************************************\n";
		cout << " What would you like to set the minimum balance to: $ ";
		cin >> minBalance;
		checkingAccount::setMinBalanace(minBalance);
	}
}
double checkingAccount::getMinBalance() const
{
	return checkingMinimumBalance;
}
void checkingAccount::setServiceCharges(double servCharges)
{
	if (servCharges >= 0)
		checkingServiceCharges = servCharges;
	else // do nothing
	{
		cout << " ERROR - VALUE MUST BE POSITIVE!\n";
		cout << "*************************************************************\n";
		cout << " What would you like to set the service charges to: $ ";
		cin >> servCharges;
		checkingAccount::setServiceCharges(servCharges);
	}
}
double checkingAccount::getServiceCharges() const
{
	return checkingServiceCharges;
}
void checkingAccount::postInterest()
{
	double checkingInterestRate = getInterestRate();
	double newAccountBalance = (accountBalance * (1 + (checkingInterestRate / 100)));	// I KNOW THIS IS NOT THE CORRECT CALCULATION FOR ACCRUED INTEREST
	accountBalance = newAccountBalance;
}
bool checkingAccount::isBalanceLessThanMinBal()
{
	if (accountBalance < checkingMinimumBalance)
		return true;
	else if (accountBalance >= checkingMinimumBalance)
		return false;
}
void checkingAccount::writeCheck(double checkAmount)
{
	double checkingAccountBalance = getBalance();
	if (checkAmount > checkingAccountBalance && checkAmount >= 0)
	{
		cout << " INSUFFICIENT FUNDS! - Please try writing a smaller check.\n";
		cout << "*************************************************************\n";
		cout << " How much would you like to write a check for: $ ";
		cin >> checkAmount;
		checkingAccount::writeCheck(checkAmount);
	}
	else if (checkAmount <= checkingAccountBalance && checkAmount >= 0)
	{
		cout << " A CHECK FOR $" << checkAmount << " HAS BEEN ISSUED FROM YOUR ACCOUNT!\n";
		accountBalance = accountBalance - checkAmount;
	}
	else
	{
		cout << " CHECKING ERROR - Please enter valid values.\n";
		cout << "*************************************************************\n";
		cout << " How much would you like to write a check for: $ ";
		cin >> checkAmount;
		checkingAccount::writeCheck(checkAmount);
	}
}
void checkingAccount::withdrawMoney(double withdrawAmount) // OVERRIDE = SAME SIGNATURE, DIFFERENT FUNCTION
{
	double checkingAccountBalance = getBalance();
	if (withdrawAmount > checkingAccountBalance && withdrawAmount >= 0)
	{
		cout << " INSUFFICIENT FUNDS! - Please try withdrawing less money.\n";
		cout << "*************************************************************\n";
		cout << " How much would you like to withdraw from checking: $ ";
		cin >> withdrawAmount;
		checkingAccount::withdrawMoney(withdrawAmount);
	}
	else if (withdrawAmount <= checkingAccountBalance && withdrawAmount >= 0)
	{
		cout << " SUCCESS! - You just withdrew $" << withdrawAmount << " from your CHECKING account!\n";
		accountBalance = accountBalance - withdrawAmount;
	}
	else
	{
		cout << " CHECKING ERROR - Please enter valid values.\n";
		cout << "*************************************************************\n";
		cout << " How much would you like to withdraw from checking: $ ";
		cin >> withdrawAmount;
		checkingAccount::withdrawMoney(withdrawAmount);
	}
}
void checkingAccount::printAccountInfo() const // OVERRIDE = SAME SIGNATURE, DIFFERENT FUNCTION
{
	cout << fixed << setprecision(2);
	cout << endl;
	cout << "**********************************************************" << endl;
	cout << "*               PRINT CHECKING ACCOUNT INFO              *" << endl;
	cout << "**********************************************************" << endl;
	cout << "CUSTOMER NAME:              " << customerName << endl;
	cout << "CHECKING ACCOUNT NUMBER:  # " << accountNumber << endl;
	cout << "CHECKING ACCOUNT BALANCE: $ " << accountBalance << endl;
	cout << "CHECKING INTEREST RATE:     " << checkingInterestRate << " %" << endl;
	cout << "CHECKING MINIMUM BALANCE: $ " << checkingMinimumBalance << endl;
	cout << "CHECKING SERVICE CHARGES: $ " << checkingServiceCharges << endl;
	cout << endl;
}
// DEFAULT CONSTRUCTOR
checkingAccount::checkingAccount() : bankAccount()	// CALL bankAccount() DEFAULT CONSTRUCTOR FIRST!
{
	//string customerName = "";				// THIS IS INITIALIZED BY bankAccount() DEFAULT CONSTRUCTOR
	//int checkingAccountNumber = 0;		// THIS IS INITIALIZED BY bankAccount() DEFAULT CONSTRUCTOR
	//double checkingBalance = 0.00;		// THIS IS INITIALIZED BY bankAccount() DEFAULT CONSTRUCTOR
	checkingInterestRate = 0.00;
	checkingMinimumBalance = 0.00;
	checkingServiceCharges = 0.00;
}
// CONSTRUCTOR WITH PARAMETERS
checkingAccount::checkingAccount(string custName, int accntNumber, double accntBalance, double intRate, double minBalance, double svcCharges)
	: bankAccount(custName, accntNumber, accntBalance)	// PASS VARIABLES IN COMMON TO BASE CLASS CONSTRUCTOR
{
	//string customerName = custName;			// THIS IS INITIALIZED BY bankAccount() CONSTRUCTOR
	//int checkingAccountNumber = accntNumber;	// THIS IS INITIALIZED BY bankAccount() CONSTRUCTOR
	//double checkingBalance = accntBalance;	// THIS IS INITIALIZED BY bankAccount() CONSTRUCTOR
	checkingInterestRate = intRate;
	checkingMinimumBalance = minBalance;
	checkingServiceCharges = svcCharges;
}
//////////////////////////////////////////////////////////////////////////////