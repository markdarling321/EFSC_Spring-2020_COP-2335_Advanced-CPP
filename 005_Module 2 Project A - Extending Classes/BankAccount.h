//////////////////////////////////////////////////////////////////////////////
//
//  DATE:     2/11/20
//  COURSE:   COP 2335-70B  --  Module 2 Project A  -  Extending Classes
//  NAME:     Mark Darling
//  PURPOSE:  Create a class and extend it to include additional information
//
//////////////////////////////////////////////////////////////////////////////

// HEADER GUARD TO PREVENT CODE BLOAT ////////////////////////////////////////
#ifndef BankAccount_H
#define BankAccount_H

// PREPROCESSOR DIRECTIVES ///////////////////////////////////////////////////
#include<string>		// using string data types
#include<iomanip>		// output formatting of decimals
using namespace std;	// using standard scope unless otherwise specified
//////////////////////////////////////////////////////////////////////////////

// PARENT CLASS DEFINITION ///////////////////////////////////////////////////
class bankAccount						// base (parent) class definition
{
public:
	void setCustomerName(string);		// PRECONDITION:  none
										// POSTCONDITION: sets protected member variable
										//				  "customerName" equal to string
										//				  entered by user

	string getCustomerName() const;		// PRECONDITION:  none
										// POSTCONDITION: returns protected member variable
										//				  "customerName" as a string

	void setAccountNumber(int);			// PRECONDITION:  none
										// POSTCONDITION: sets protected member variable
										//				  "accountNumber" equal to integer
										//				  entered by user

	int getAccountNumber() const;		// PRECONDITION:  none
										// POSTCONDITION: returns protected member variable
										//				  "accountNumber" as an integer

	double getBalance() const;			// PRECONDITION:  none
										// POSTCONDITION: returns protected member variable
										//				  "accountBalance" as a double

	void depositMoney(double);			// PRECONDITION:  double variable submitted by user
										//				  must be greater than or equal to
										//				  zero
										// POSTCONDITION: protected member variable
										//				  "accountBalance" is increased by
										//				  the amount of money passed to this
										//				  function as a double

	void withdrawMoney(double);			// PRECONDITION:  double variable submitted by user
										//				  must be greater than or equal to
										//				  zero and less than or equal to
										//				  value of "accountBalance"
										// POSTCONDITION: protected member variable
										//				  "accountBalance" is decreased by
										//				  the amount of money passed to this
										//				  function as a double
	
	void printAccountInfo() const;		// PRECONDITION:  none 
										// POSTCONDITION: prints all protected member variables
										//				  of class "bankAccount" and their
										//				  corresponding values to common output
										//				  along with identifying labels and
										//				  value types ($, %, etc.)

	bankAccount();						// DEFAULT CONSTRUCTOR

	bankAccount(string, int, double);	// CONSTRUCTOR WITH PARAMETERS
										//				string -> customerName
										//				int    -> accountNumber
										//				double -> accountBalance
protected:
	string customerName;				// new unique protected member variable
	int accountNumber;					// new unique protected member variable
	double accountBalance;				// new unique protected member variable
};
//////////////////////////////////////////////////////////////////////////////

#endif
//////////////////////////////////////////////////////////////////////////////