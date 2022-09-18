//////////////////////////////////////////////////////////////////////////////
//
//  DATE:     2/11/20
//  COURSE:   COP 2335-70B  --  Module 2 Project A  -  Extending Classes
//  NAME:     Mark Darling
//  PURPOSE:  Create a class and extend it to include additional information
//
//////////////////////////////////////////////////////////////////////////////

// HEADER GUARD TO PREVENT CODE BLOAT ////////////////////////////////////////
#ifndef SavingsAccount_H
#define SavingsAccount_H

// PREPROCESSOR DIRECTIVES ///////////////////////////////////////////////////
#include<string>			// using string data types
#include<iomanip>			// output formatting of decimals
#include "BankAccount.h"	// parent class definition
using namespace std;		// using standard scope unless otherwise specified
//////////////////////////////////////////////////////////////////////////////

// CHILD CLASS DEFINITION ////////////////////////////////////////////////////
class savingsAccount : public bankAccount	// derived (child) class definition:
											// class "savingsAccount" inherits
											// all of class "bankAccount"'s
											// public member functions and
											// protected member variables
											// 
											// the inherited public member functions
											// remain public and the inherited
											// protected member variables become
											// new private member variables of
											// class "savingsAccount"
{
public:
	void setInterestRate(double);			// PRECONDITION:  double variable passed must be
											//				  non-negative value and between
											//				  0.00 and 100.00
											// POSTCONDITION: sets derived class
											//				  "savingsAccount" protected member
											//				  variable "savingsInterestRate"
											//				  equal to value passed to function as
											//				  a double

	double getInterestRate() const;			// PRECONDITION:  none
											// POSTCONDITION: returns private member variable
											//				  "savingsInterestRate" as a double

	void postInterest();					// PRECONDITION:  none
											// POSTCONDITION: adjusts derived class "savingsAccount"
											//				  protected member variable
											//				  "accountBalance" to reflect accrued
											//				  interest accumulated

	void withdrawMoney(double);				// PRECONDITION:  double variable passed must be
											//				  non-negative value and less than
											//				  or equal to current value of
											//				  protected member variable
											//				  "accountBalance"
											// POSTCONDITION: value passed as double is subtracted
											//				  from protected member variable
											//				  "accountBalance"

	void printAccountInfo() const;			// PRECONDITION:  none
											// POSTCONDITION: prints all protected member variables
											//				  of class "savingsAccount" and their
											//				  corresponding values to common output
											//				  along with identifying labels and
											//				  value types ($, %, etc.)

	savingsAccount();						// DEFAULT CONSTRUCTOR

	savingsAccount(string, int, double, double);
											// CONSTRUCTOR WITH PARAMETERS
											//				INHERITED:  string -> customerName
											//				INHERITED:  int    -> savingsAccountNumber
											//				INHERITED:  double -> savingsBalance
											//							double -> savingsInterestRate
protected:
	//string customerName;					// INHERITED FROM CLASS: bankAccount
	//int savingsAccountNumber;				// INHERITED FROM CLASS: bankAccount
	//double savingsBalance;				// INHERITED FROM CLASS: bankAccount
	double savingsInterestRate;				// new unique protected member variable
};
//////////////////////////////////////////////////////////////////////////////

#endif
//////////////////////////////////////////////////////////////////////////////