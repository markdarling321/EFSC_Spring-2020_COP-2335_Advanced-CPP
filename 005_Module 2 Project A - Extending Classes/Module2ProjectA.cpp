//////////////////////////////////////////////////////////////////////////////
//
//  DATE:     2/11/20
//  COURSE:   COP 2335-70B  --  Module 2 Project A  -  Extending Classes
//  NAME:     Mark Darling
//  PURPOSE:  Create a class and extend it to include additional information
//
//////////////////////////////////////////////////////////////////////////////

// PREPROCESSOR DIRECTIVES ///////////////////////////////////////////////////
#include <iostream>				// common input & output
#include <string>				// using string data types
#include <iomanip>				// output formatting of decimals
#include "BankAccount.h"		// parent class definition
#include "CheckingAccount.h"	// child class definition
#include "SavingsAccount.h"		// child class definition
using namespace std;			// using standard scope unless otherwise specified
//////////////////////////////////////////////////////////////////////////////

// MAIN PROGRAM FUNCTION PROTOTYPES //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

// BEGIN MAIN PROGRAM ////////////////////////////////////////////////////////
void main()
{
	// DEFINE GLOBAL CONSTANTS
	// DEFINE VARIABLES

	// DEFINE CLASS OBJECTS
	checkingAccount myCheckingAccount;	// INITIALIZE WITH DEFAULT CONSTRUCTOR
	savingsAccount mySavingsAccount;	// INITIALIZE WITH DEFAULT CONSTRUCTOR

	// TEST CLASS MEMBER FUNCTIONS HERE
	cout << "*************************************************************\n";
	cout << "***                   BEGIN MAIN PROGRAM                  ***\n";
	cout << "*************************************************************\n";
	cout << " Let's check our bank account...\n";
	myCheckingAccount.printAccountInfo();
	mySavingsAccount.printAccountInfo();
	cout << "*************************************************************\n";
	cout << " Let's set our checking account number: ";
	int checkingAccountNumber;
	cin >> checkingAccountNumber;
	myCheckingAccount.setAccountNumber(checkingAccountNumber);
	cout << "*************************************************************\n";
	cout << " What is the owner's name of the checking account?: ";
	string checkingAccountOwner;
	cin.ignore();
	getline(cin, checkingAccountOwner);
	myCheckingAccount.setCustomerName(checkingAccountOwner);
	cout << "*************************************************************\n";
	cout << " Let's deposit money into our checking account...\n";
	double moneyToDeposit;
	cout << " How much money do you want to deposit? : $ ";
	cin >> moneyToDeposit;
	myCheckingAccount.depositMoney(moneyToDeposit);
	cout << "*************************************************************\n";
	cout << " Okay, let's check our checking account's new balance...\n";
	cout << " UPDATED BALANCE: $ " << myCheckingAccount.getBalance() << endl;
	cout << "*************************************************************\n";
	cout << " Let's withdraw money from our checking account...\n";
	double moneyToWithdraw;
	cout << " How much money do you want to withdraw? : $ ";
	cin >> moneyToWithdraw;
	myCheckingAccount.withdrawMoney(moneyToWithdraw);
	cout << "*************************************************************\n";
	cout << " Okay, let's check our checking account's new balance...\n";
	cout << " UPDATED BALANCE: $ " << myCheckingAccount.getBalance() << endl;
	cout << "*************************************************************\n";
	cout << " Let's set the interest rate of our checking account...\n";
	cout << " Enter the account's interest rate (0.00 - 100.00): ";
	double interestRate;
	cin >> interestRate;
	myCheckingAccount.setInterestRate(interestRate);
	cout << "*************************************************************\n";
	cout << " Let's set the minimum balance of our checking account...\n";
	cout << " Enter the account's minimum balance amount: $ ";
	double minimumBalance;
	cin >> minimumBalance;
	myCheckingAccount.setMinBalanace(minimumBalance);
	cout << "*************************************************************\n";
	cout << " Let's set the service charges of our checking account...\n";
	cout << " Enter the account's service charges amount: $ ";
	double serviceCharges;
	cin >> serviceCharges;
	myCheckingAccount.setServiceCharges(serviceCharges);
	cout << "*************************************************************\n";
	cout << " Let's check our checking account's interest rate...\n";
	cout << " CHECKING INTEREST RATE: % " << myCheckingAccount.getInterestRate();
	cout << endl;
	cout << "*************************************************************\n";
	cout << " Let's check our checking account's minimum balance...\n";
	cout << " CHECKING MINIMUM BALANCE: $ " << myCheckingAccount.getMinBalance();
	cout << endl;
	cout << "*************************************************************\n";
	cout << " Let's check our checking account's service charges...\n";
	cout << " CHECKING SERVICE CHARGES: $ " << myCheckingAccount.getServiceCharges();
	cout << endl;
	cout << "*************************************************************\n";
	cout << " Let's post the interest to our checking account now...\n";
	myCheckingAccount.postInterest();
	cout << " UPDATED ACCOUNT BALANCE: $ " << myCheckingAccount.getBalance();
	cout << endl;
	cout << "*************************************************************\n";
	cout << " Let's check if our checking account's balance is less than the minimum balance...\n";
	bool result;
	result = myCheckingAccount.isBalanceLessThanMinBal();
	if (result == true)
		cout << " TRUE\n";
	else if (result == false)
		cout << " FALSE\n";
	cout << "*************************************************************\n";
	cout << " Let's write a check from our checking account...\n";
	cout << " Enter check amount: $ ";
	double checkAmount;
	cin >> checkAmount;
	cout << " Issuing check now...\n";
	myCheckingAccount.writeCheck(checkAmount);
	cout << "*************************************************************\n";
	cout << " Let's check if our checking account's balance is less than the minimum balance...\n";
	result = myCheckingAccount.isBalanceLessThanMinBal();
	if (result == true)
		cout << " TRUE\n";
	else if (result == false)
		cout << " FALSE\n";
	cout << "*************************************************************\n";
	cout << " Let's check our bank account...\n";
	myCheckingAccount.printAccountInfo();
	mySavingsAccount.printAccountInfo();
	cout << "*************************************************************\n";
	cout << " Let's withdraw money from our checking account...\n";
	cout << " Enter withdraw amount: $ ";
	double withdrawAmount;
	cin >> withdrawAmount;
	cout << " Withdrawing money now...\n";
	myCheckingAccount.withdrawMoney(withdrawAmount);
	cout << "*************************************************************\n";
	cout << " Okay, let's check our checking account's new balance...\n";
	cout << " UPDATED BALANCE: $ " << myCheckingAccount.getBalance() << endl;
	cout << "*************************************************************\n";
	cout << " Let's check if our checking account's balance is less than the minimum balance...\n";
	result = myCheckingAccount.isBalanceLessThanMinBal();
	if (result == true)
		cout << " TRUE\n";
	else if (result == false)
		cout << " FALSE\n";
	cout << "*************************************************************\n";
	cout << " Let's check our bank account...\n";
	myCheckingAccount.printAccountInfo();
	mySavingsAccount.printAccountInfo();
	cout << "*************************************************************\n";
	cout << " Let's set our savings account number: ";
	int savingsAccountNumber;
	cin >> savingsAccountNumber;
	mySavingsAccount.setAccountNumber(savingsAccountNumber);
	cout << "*************************************************************\n";
	cout << " What is the owner's name of the savings account?: ";
	string savingsAccountOwner;
	cin.ignore();
	getline(cin, savingsAccountOwner);
	mySavingsAccount.setCustomerName(savingsAccountOwner);
	cout << "*************************************************************\n";
	cout << " Let's deposit money into our savings account...\n";
	cout << " How much money do you want to deposit? : $ ";
	cin >> moneyToDeposit;
	mySavingsAccount.depositMoney(moneyToDeposit);
	cout << "*************************************************************\n";
	cout << " Let's set the interest for our savings account...\n";
	cout << " Enter the account's interest rate (0.00 - 100.00): ";
	cin >> interestRate;
	mySavingsAccount.setInterestRate(interestRate);
	cout << "*************************************************************\n";
	cout << " Let's check our savings account's interest rate...\n";
	cout << " SAVINGS INTEREST RATE: % " << mySavingsAccount.getInterestRate();
	cout << endl;
	cout << "*************************************************************\n";
	cout << " Let's post the interest to our savings account now...\n";
	mySavingsAccount.postInterest();
	cout << " UPDATED ACCOUNT BALANCE: $ " << mySavingsAccount.getBalance();
	cout << endl;
	cout << "*************************************************************\n";
	cout << " Let's withdraw money from our savings account...\n";
	cout << " Enter withdraw amount: $ ";
	cin >> withdrawAmount;
	cout << " Withdrawing money now...\n";
	mySavingsAccount.withdrawMoney(withdrawAmount);
	cout << "*************************************************************\n";
	cout << " Let's check our bank account...\n";
	myCheckingAccount.printAccountInfo();
	mySavingsAccount.printAccountInfo();
	cout << "*************************************************************\n";
	cout << "***                    END MAIN PROGRAM                   ***\n";
	cout << "*************************************************************\n";
}
//////////////////////////////////////////////////////////////////////////////

// MAIN PROGRAM FUNCTION DEFINITIONS /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////