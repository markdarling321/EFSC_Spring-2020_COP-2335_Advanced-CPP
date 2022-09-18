///////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 5 Project - Using exception handling
// NAME:    Mark Darling
// PURPOSE: Continue practicing overloading operators such as the arithmetic
//			and relational operators as well as the stream insertion and
//			stream extraction operators (for easier input and output).
//			Additionally, our program should handle exceptions such as
//			"division by zero" and "invalid input".
//			
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PRE-PROCESSOR DIRECTIVES ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifndef H_fractionType
#define H_fractionType

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
// CLASS DEFINITION ///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class fractionType
{

///////////////////////////////////////////////////////////////////////////////
// PUBLIC MEMBER FUNCTIONS ////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
public:

	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED ARITHMETIC OPERATOR '+' /////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	fractionType operator+(const fractionType&) const;
						// PRECONDITION:  both objects being added must be of
						//				  same class/object type.
						// POSTCONDITION: adds right fraction to left
						//				  fraction.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED ARITHMETIC OPERATOR '-' /////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	fractionType operator-(const fractionType&) const;
						// PRECONDITION:  both objects being subtracted must be
						//				  of same class/object type.
						// POSTCONDITION: subtracts right fraction from left
						//				  fraction.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED ARITHMETIC OPERATOR '*' /////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	fractionType operator*(const fractionType&) const;
						// PRECONDITION:  both objects being multiplied must be
						//				  of same class/object type.
						// POSTCONDITION: multiplies left fraction by right
						//				  fraction.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED ARITHMETIC OPERATOR '/' /////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	fractionType operator/(const fractionType&) const;
						// PRECONDITION:  both objects being divided must be of
						//				  same class/object type. neither
						//				  denominator can be zero.
						// POSTCONDITION: divides left fraction by right
						//				  fraction.
	

	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED RELATIONAL OPERATOR '<' /////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	bool operator<(const fractionType&) const;
						// PRECONDITION:  both objects being compared must be
						//				  of same class/object type and
						//				  already be initialized.
						// POSTCONDITION: returns true if left fraction is
						//				  less than right fraction being
						//				  compared. returns false otherwise.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED RELATIONAL OPERATOR '>' /////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	bool operator>(const fractionType&) const;
						// PRECONDITION:  both objects being compared must be
						//				  of same class/object type and
						//				  already be initialized.
						// POSTCONDITION: returns true if left fraction is
						//				  greater than right fraction being
						//				  compared. returns false otherwise.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED RELATIONAL OPERATOR '==' ////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	bool operator==(const fractionType&) const;
						// PRECONDITION:  both objects being compared must be
						//				  of same class/object type and
						//				  already be initialized.
						// POSTCONDITION: returns true if both member variables
						//				  numerator and denominator are equal
						//				  to the other member variables of same
						//				  type and name (but different object)
						//				  being compared. returns false
						//				  otherwise.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED RELATIONAL OPERATOR '!=' ////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	bool operator!=(const fractionType&) const;
						// PRECONDITION:  both objects being compared must be
						//				  of same class/object type and
						//				  already be initialized.
						//				  
						// POSTCONDITION: returns true if either member
						//				  variable numerator or denominator
						//				  are not equal to the other member
						//				  variables of same type and name (but
						//				  different object) being compared.
						//				  returns false otherwise.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED STREAM INSERTION OPERATOR '<<' (output) /////////////////////
	///////////////////////////////////////////////////////////////////////////
	friend ostream& operator<<(ostream&, const fractionType&);
						// PRECONDITION:  none.
						// POSTCONDITION: prints member variables numerator
						//				  and denominator to screen using
						//				  common output.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED STREAM EXTRACTION OPERATOR '>>' (input) /////////////////////
	///////////////////////////////////////////////////////////////////////////
	friend istream& operator>>(istream&, fractionType&);
						// PRECONDITION:  object receiving values passed into
						//				  it must be of type fractionType and
						//				  already exist and be initialized.
						//				  values passed must be of valid data
						//				  types and values to prevent illegal
						//				  logic and/or mathematic operations.
						// POSTCONDITION: member variables numerator and
						//				  denominator of current class object
						//				  being inserted into will be
						//				  overwritten with values specified by
						//				  user at time of member function call.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED ASSIGNMENT OPERATOR '=' /////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	const fractionType& operator=(const fractionType&);
						// PRECONDITION:  both left and right objects must
						//				  be of same class type and already
						//				  created and initialized.
						// POSTCONDITION: set right object's private member
						//				  variables of same class type equal
						//				  to left object's member variables
						//				  of same class type.


	///////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR  --  with TWO parameters ///////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	fractionType(int, int);
						// PRECONDITION:  none.
						// POSTCONDITION: creates a class object of type
						//				  fractionType with numerator equal
						//				  to left parameter and denominator
						//				  equal to right parameter.


	///////////////////////////////////////////////////////////////////////////
	// DEFAULT CONSTRUCTOR (without parameters) ///////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	fractionType();
						// PRECONDITION:  none.
						// POSTCONDITION: creates a class object of type
						//				  fractionType when called without
						//				  parameters.


///////////////////////////////////////////////////////////////////////////////
// PRIVATE MEMBER VARIABLES ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
protected:
	int numer, denom;	// numerator, denominator
};
///////////////////////////////////////////////////////////////////////////////
#endif
///////////////////////////////////////////////////////////////////////////////