//////////////////////////////////////////////////////////////////////////////
//
//  DATE:     2/11/20
//  COURSE:   COP 2335-70B  --  Module 2 Project A  -  Extending Classes
//  NAME:     Mark Darling
//  PURPOSE:  Create a class and extend it to include additional information
//
//////////////////////////////////////////////////////////////////////////////

// HEADER GUARD TO PREVENT CODE BLOAT ////////////////////////////////////////
#ifndef CheckingAccount_H
#define CheckingAccount_H

// PREPROCESSOR DIRECTIVES ///////////////////////////////////////////////////
#include <string>			// using string data types
#include<iomanip>			// output formatting of decimals
#include "BankAccount.h"	// parent class definition
using namespace std;		// using standard scope unless otherwise specified
//////////////////////////////////////////////////////////////////////////////

// CHILD CLASS DEFINITION ////////////////////////////////////////////////////
class checkingAccount : public bankAccount	// derived (child) class definition:
											// class "checkingAccount" inherits
											// all of class "bankAccount"'s
											// public member functions and
											// protected member variables
											//
											// the inherited public member functions
											// remain public and the inherited
											// protected member variables become
											// new private member variables of
											// class "checkingAccount"
{
public:
	void setInterestRate(double);			// PRECONDITION:  double variable passed must be
											//				  non-negative value and between
											//				  0.00 and 100.00
											// POSTCONDITION: sets derived class
											//				  "checkingAccount" protected member
											//				  variable "checkingInterestRate"
											//				  equal to value passed to function as
											//				  a double

	double getInterestRate() const;			// PRECONDITION:  none
											// POSTCONDITION: returns private member variable
											//				  "checkingInterestRate" as a double

	void setMinBalanace(double);			// PRECONDITION:  double variable value passed must
											//				  be non-negative
											// POSTCONDITION: sets derived class
											//				  "checkingAccount" protected member
											//				  variable "checkingMinimumBalance"
											//				  equal to value passed to function as
											//				  a double

	double getMinBalance() const;			// PRECONDITION:  none
											// POSTCONDITION: returns protected member variable
											//				  "checkingMinimumBalance" as a double

	void setServiceCharges(double);			// PRECONDITION:  double variable passed must be
											//				  non-negative value
											// POSTCONDITION: sets protected member variable
											//				  "checkingServiceCharges" equal to
											//				  value passed as a double

	double getServiceCharges() const;		// PRECONDITION:  none
											// POSTCONDITION: returns protected member variable
											//				  "checkingServiceCharges" as a double

	void postInterest();					// PRECONDITION:  none
											// POSTCONDITION: adjusts derived class "checkingAccount"
											//				  protected member variable
											//				  "accountBalance" to reflect accrued
											//				  interest accumulated

	bool isBalanceLessThanMinBal();			// PRECONDITION:  none
											// POSTCONDITION: returns true if protected member variable
											//				  "accountBalance" is less than protected
											//				  member variable "checkingMinimumBalance"
											//				  and returns false if otherwise

	void writeCheck(double);				// PRECONDITION:  double variable passed must be
											//				  non-negative value and less than
											//				  or equal to current value of
											//				  protected member variable
											//				  "accountBalance"
											// POSTCONDITION: value passed as double is subtracted
											//				  from protected member variable
											//				  "accountBalance"

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
											//				  of class "checkingAccount" and their
											//				  corresponding values to common output
											//				  along with identifying labels and
											//				  value types ($, %, etc.)

	checkingAccount();						// DEFAULT CONSTRUCTOR

											
	checkingAccount(string, int, double, double, double, double);
											// CONSTRUCTOR WITH PARAMETERS
											//				INHERITED:  string -> customerName
											//				INHERITED:  int    -> checkingAccountNumber
											//				INHERITED:  double -> checkingBalance
											//							double -> checkingInterestRate
											//							double -> checkingMinimumBalance
											//							double -> checkingServiceCharges
protected:
	//string customerName;					// INHERITED FROM CLASS: bankAccount
	//int checkingAccountNumber;			// INHERITED FROM CLASS: bankAccount
	//double checkingBalance;				// INHERITED FROM CLASS: bankAccount
	double checkingInterestRate;			// new unique protected member variable
	double checkingMinimumBalance;			// new unique protected member variable
	double checkingServiceCharges;			// new unique protected member variable
};
//////////////////////////////////////////////////////////////////////////////

#endif
//////////////////////////////////////////////////////////////////////////////