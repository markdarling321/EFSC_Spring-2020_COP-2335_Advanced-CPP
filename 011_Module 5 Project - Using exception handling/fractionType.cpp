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
#include <iostream>
#include <limits>			// numeric_limits<streamsize>::max()
#include "fractionType.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// CLASS MEMBER FUNCTION IMPLEMENTATIONS //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED ARITHMETIC OPERATOR '+' /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
fractionType fractionType::operator+(const fractionType& fracObj) const
{
	cout << " CALLING OVERLOADED ARITHMETIC OPERATOR: + \n";
	int a = numer;
	int b = denom;
	int c = fracObj.numer;
	int d = fracObj.denom;

	fractionType tempFraction;

	tempFraction.numer = ((a*d) + (b*c));
	tempFraction.denom = (b*d);

	return tempFraction;
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED ARITHMETIC OPERATOR '-' /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
fractionType fractionType::operator-(const fractionType& fracObj) const
{
	cout << " CALLING OVERLOADED ARITHMETIC OPERATOR: - \n";
	int a = numer;
	int b = denom;
	int c = fracObj.numer;
	int d = fracObj.denom;

	fractionType tempFraction;

	tempFraction.numer = ((a * d) - (b * c));
	tempFraction.denom = (b * d);

	return tempFraction;
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED ARITHMETIC OPERATOR '*' /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
fractionType fractionType::operator*(const fractionType& fracObj) const
{
	cout << " CALLING OVERLOADED ARITHMETIC OPERATOR: * \n";
	int a = numer;
	int b = denom;
	int c = fracObj.numer;
	int d = fracObj.denom;

	fractionType tempFraction;

	tempFraction.numer = (a * c);
	tempFraction.denom = (b * d);

	return tempFraction;
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED ARITHMETIC OPERATOR '/' /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
fractionType fractionType::operator/(const fractionType& fracObj) const
{
	cout << " CALLING OVERLOADED ARITHMETIC OPERATOR: / \n";
	int a = numer;
	int b = denom;
	int c = fracObj.numer;
	int d = fracObj.denom;

	fractionType tempFraction;

	tempFraction.numer = (a * d);
	tempFraction.denom = (b * c);

	return tempFraction;
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED RELATIONAL OPERATOR '<' /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool fractionType::operator<(const fractionType& fracObj) const
{
	cout << " CALLING OVERLOADED RELATIONAL OPERATOR: < \n";
	int a = numer;
	int b = denom;
	int c = fracObj.numer;
	int d = fracObj.denom;

	if ((a * d) < (b * c))
		return true;
	else
		return false;
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED RELATIONAL OPERATOR '>' /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool fractionType::operator>(const fractionType& fracObj) const
{
	cout << " CALLING OVERLOADED RELATIONAL OPERATOR: > \n";
	int a = numer;
	int b = denom;
	int c = fracObj.numer;
	int d = fracObj.denom;

	if ((a * d) > (b * c))
		return true;
	else
		return false;
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED RELATIONAL OPERATOR '==' ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool fractionType::operator==(const fractionType& fracObj) const
{
	cout << " CALLING OVERLOADED RELATIONAL OPERATOR: == \n";
	if (fracObj.numer == numer && fracObj.denom == denom)
		return true;
	else
		return false;
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED RELATIONAL OPERATOR '!=' ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool fractionType::operator!=(const fractionType& fracObj) const
{
	cout << " CALLING OVERLOADED RELATIONAL OPERATOR: != \n";
	if (fracObj.numer != numer || fracObj.denom != denom)
		return true;
	else
		return false;
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED STREAM INSERTION OPERATOR '<<' (output) /////////////////////////
///////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& oStreamObj, const fractionType& fracObj)
{
/*
	cout << " CALLING OVERLOADED STREAM INSERTION OPERATOR: << \n";
	oStreamObj << " NUMERATOR:        " << fracObj.numer << "\n";
	oStreamObj << "               ----------\n";
	oStreamObj << " DENOMINATOR:      " << fracObj.denom << "\n";
	return oStreamObj;
*/
	cout << " CALLING OVERLOADED STREAM INSERTION OPERATOR: << (output) \n";
	oStreamObj << " NUMERATOR:        " << fracObj.numer << "\n";
	oStreamObj << "               ----------\n";
	oStreamObj << " DENOMINATOR:      " << fracObj.denom << "\n";
	return oStreamObj;
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED STREAM EXTRACTION OPERATOR '>>' (input) /////////////////////////
///////////////////////////////////////////////////////////////////////////////
istream& operator>>(istream& iStreamObj, fractionType& fracObj)
{


// NO EXCEPTION HANDLING //////////////////////////////////////////////////////
/*
	cout << " CALLING OVERLOADED STREAM EXTRACTION OPERATOR: >> (input) \n";
	cout << " ENTER NUMERATOR:        ";
	iStreamObj >> fracObj.numer;
	cout << "                     ----------\n";
	cout << " ENTER DENOMINATOR:      ";
	iStreamObj >> fracObj.denom;
	return iStreamObj;
*/


// ATTEMPT #1  --  BROKEN EXCEPTION HANDLING //////////////////////////////////

	cout << " CALLING OVERLOADED STREAM EXTRACTION OPERATOR: >> (input) \n";
	try
	{
		cout << " ENTER NUMERATOR:        ";
		iStreamObj >> fracObj.numer;
		cout << "                     ----------\n";
		cout << " ENTER DENOMINATOR:      ";
		iStreamObj >> fracObj.denom;

		
		if ((fracObj.numer <= 255) && (isalpha(fracObj.numer) != 0))
		{
		cout << " fracObj.numer <= 255 && isalpha(fracObj.numer) != 0\t";
		throw static_cast<char>(fracObj.numer);
		}
		else if ((fracObj.denom <= 255) && (isalpha(fracObj.denom) != 0))
		{
		cout << " fracObj.denom <= 255 && isalpha(fracObj.denom) != 0\t";
		throw static_cast<char>(fracObj.denom);
		}
		else if (fracObj.denom == 0)
		{
			cout << " fracObj.denom == 0\t";
			throw fracObj.denom;
		}
		else if (fracObj.denom < 0)
		{
			cout << " fracObj.denom < 0\t";
			throw string("Negative denominator!");
		}
		
		
		

		return iStreamObj;
	}
	catch (int err)					// WORKING
	{
		cout << " ERROR!  --  ZERO DENOMINATOR NOT ALLOWED! \n";
		fracObj.numer = NULL;
		fracObj.denom = NULL;
	}
	catch (string err)				// NOT WORKING ALL THE TIME
	{
		cout << " ERROR!  --  NEGATIVE DENOMINATOR NOT ALLOWED! \n";
		fracObj.numer = NULL;
		fracObj.denom = NULL;
	}
	catch (...)						// NOT WORKING
	{
		cout << " ERROR!  --  INVALID DATA TYPE! ONLY INTEGERS ALLOWED! \n";
		fracObj.numer = NULL;
		fracObj.denom = NULL;

		//cin.clear();													// DOES NOT WORK
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');			// DOES NOT WORK
		//iStreamObj.clear();											// DOES NOT WORK
		//iStreamObj.ignore(numeric_limits<streamsize>::max(), '\n');	// DOES NOT WORK
	}



// ATTEMPT #2  --  ALTERNATE METHOD? //////////////////////////////////////////
/*
	cout << " CALLING OVERLOADED STREAM EXTRACTION OPERATOR: >> (input) \n";
	cout << " ENTER NUMERATOR:        ";
	iStreamObj >> fracObj.numer;
	cout << "                     ----------\n";
	cout << " ENTER DENOMINATOR:      ";
	iStreamObj >> fracObj.denom;
	return fractionType(fracObj.numer, fracObj.denom);		// TRYING TO USE CONSTRUCTOR
*/
}


///////////////////////////////////////////////////////////////////////////////
// OVERLOADED ASSIGNMENT OPERATOR '=' /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
const fractionType& fractionType::operator=(const fractionType& fracObj)
{
	cout << " CALLING OVERLOADED ASSIGNMENT OPERATOR: = \n";
	// CLASS OBJECT COPY ALGORITHM
	if (this != &fracObj)	// avoid self-assignment (DOES THIS USE OVERLOADED
							// RELATIONAL OPERATOR != DEFINED BELOW?)
	{
		// COPY PRIVATE MEMBER VARIABLES
		numer = fracObj.numer;
		denom = fracObj.denom;
	}

	// RETURN OBJECT
	return *this;
}


///////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR  --  with TWO parameters ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
fractionType::fractionType(int n, int d)
{
/*
	cout << " CALLING CONSTRUCTOR (w/TWO PARAMETERS) \n";
	numer = n;
	denom = d;
*/
	cout << " CALLING CONSTRUCTOR (w/TWO PARAMETERS) \n";
	try
	{
		if (d == 0)
		{
			throw d;
		}
		else if (d < 0)
		{
			throw string("Negative denominator!");
		}
		else if (d <= 255 && isalpha(d) != 0)
		{
			throw static_cast<char>(d);
		}
		else if (n <= 255 && isalpha(n) != 0)
		{
			throw static_cast<char>(n);
		}
		//cout << isalpha(d);
		//cout << static_cast<char>(d);
		numer = n;
		denom = d;
	}
	catch (int err)
	{
		cout << " ERROR!  --  ZERO DENOMINATOR NOT ALLOWED! \n";
		numer = NULL;
		denom = NULL;
	}
	catch (string err)
	{
		cout << " ERROR!  --  NEGATIVE DENOMINATOR NOT ALLOWED! \n";
		numer = NULL;
		denom = NULL;
	}
	catch (...)
	{
		cout << " ERROR!  --  INVALID DATA TYPE! ONLY INTEGERS ALLOWED! \n";
		numer = NULL;
		denom = NULL;
	}
}


///////////////////////////////////////////////////////////////////////////////
// DEFAULT CONSTRUCTOR (without parameters) ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
fractionType::fractionType()
{
	cout << " CALLING DEFAULT CONSTRUCTOR (w/NO PARAMETERS) \n";
	numer = NULL;
	denom = NULL;
}


///////////////////////////////////////////////////////////////////////////////