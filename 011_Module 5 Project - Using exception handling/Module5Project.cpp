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
// PREPROCESSOR DIRECTIVES/////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "fractionType.h"
#include <string>
#include <limits>			// numeric_limits<streamsize>::max()

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// BEGIN MAIN LINEAR DRIVER PROGRAM ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
	// PROGRAM START
	cout << " BEGIN MAIN PROGRAM...\n";
	
	// CREATE CLASS OBJECTS
	// USING DEFAULT CONSTRUCTOR...
	fractionType myFrac1, myFrac2;
	
	// CREATE CLASS OBJECTS
	// USING CONSTRUCTOR WITH TWO PARAMETERS...
	fractionType myFrac3(1, 2);
	fractionType myFrac4(3, 4);

	// CREATE CLASS OBJECTS
	// USING DEFAULT CONSTRUCTOR...
	fractionType myFrac5;

	// CREATE INVALID CLASS OBJECTS
	// TO TEST CONSTRUCTOR EXCEPTION HANDLING...
	fractionType myFrac6(1, 0);
	fractionType myFrac7('a', 'b');	 // chars translate to int seamlessly
									 // must explicitly cast to char prior to
									 // throwing exception

	// CREATE CLASS OBJECTS
	// USING CONSTRUCTOR WITH TWO PARAMETERS...
	fractionType myFrac8(999999,999999);	// this breaks isalpha() checks if
											// not handled correctly via logic

	// CREATE INVALID CLASS OBJECTS
	// TO TEST CONSTRUCTOR EXCEPTION HANDLING...
	//fractionType myFrac9("C","D"); // does not compile - no matching signature
									 // any alpha strings entered during myFrac
									 // object updates are taken in as a series
									 // of chars which have corresponding integer
									 // values and do not cause an exception
	
	// PRINT EACH CLASS OBJECT TO SCREEN
	// USING OVERLOADED STREAM INSERTION OPERATOR...
	cout << "\n\n myFrac1 = \n" << myFrac1;
	cout << "\n\n myFrac2 = \n" << myFrac2;
	cout << "\n\n myFrac3 = \n" << myFrac3;
	cout << "\n\n myFrac4 = \n" << myFrac4;
	cout << "\n\n myFrac5 = \n" << myFrac5;
	cout << "\n\n myFrac6 = \n" << myFrac6;
	cout << "\n\n myFrac7 = \n" << myFrac7;
	cout << "\n\n myFrac8 = \n" << myFrac8;
	
	// COMPARE CLASS OBJECTS
	// USING OVERLOADED RELATIONAL OPERATORS...
	cout << "\n\n\n\n IS myFrac3 < myFrac4 ?\n";
	if (myFrac3 < myFrac4)
		cout << " TRUE\n";
	else
		cout << " FALSE\n";

	// COMPARE CLASS OBJECTS
	// USING OVERLOADED RELATIONAL OPERATORS...
	cout << "\n\n IS myFrac4 > myFrac3 ?\n";
	if (myFrac4 > myFrac3)
		cout << " TRUE\n";
	else
		cout << " FALSE\n";

	// COMPARE CLASS OBJECTS
	// USING OVERLOADED RELATIONAL OPERATORS...
	cout << "\n\n IS myFrac1 != myFrac2 ?\n";
	if (myFrac1 != myFrac2)
		cout << " TRUE\n";
	else
		cout << " FALSE\n";

	// COMPARE CLASS OBJECTS
	// USING OVERLOADED RELATIONAL OPERATORS...
	cout << "\n\n IS myFrac1 == myFrac2 ?\n";
	if (myFrac1 == myFrac2)
		cout << " TRUE\n";
	else
		cout << " FALSE\n";

	// ADD TWO FRACTION OBJECTS
	// USING OVERLOADED ARITHMETIC OPERATORS...
	cout << "\n\n\n\n myFrac3 + myFrac4 = \n";
	cout << myFrac3 + myFrac4;

	// SUBTRACT TWO FRACTION OBJECTS
	// USING OVERLOADED ARITHMETIC OPERATORS...
	cout << "\n\n myFrac4 - myFrac3 = \n";
	cout << myFrac4 - myFrac3;

	// MULTIPLY TWO FRACTION OBJECTS
	// USING OVERLOADED ARITHMETIC OPERATORS...
	cout << "\n\n myFrac3 * myFrac4 = \n";
	cout << myFrac3 * myFrac4;

	// DIVIDE TWO FRACTION OBJECTS
	// USING OVERLOADED ARITHMETIC OPERATORS...
	cout << "\n\n myFrac4 / myFrac3 = \n";
	cout << myFrac4 / myFrac3;

	// UPDATE FRACTION OBJECT
	// USING OVERLOADED STREAM EXTRACTION OPERATOR...
	cout << "\n\n\n\n Let's update myFrac1 to a new value...\n";
	cin >> myFrac1;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// UPDATE FRACTION OBJECT
	// USING OVERLOADED STREAM EXTRACTION OPERATOR...
	cout << "\n\n Let's update myFrac2 to a new value...\n";
	cin >> myFrac2;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// UPDATE FRACTION OBJECT
	// USING OVERLOADED STREAM EXTRACTION OPERATOR...
	cout << "\n\n\n\n Let's update myFrac3 to a new value...\n";
	cin >> myFrac3;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// UPDATE FRACTION OBJECT
	// USING OVERLOADED STREAM EXTRACTION OPERATOR...
	cout << "\n\n Let's update myFrac4 to a new value...\n";
	cin >> myFrac4;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// RE-PRINT myFrac1 AND myFrac2 CLASS OBJECTS TO SCREEN AFTER UPDATES
	// USING OVERLOADED STREAM INSERTION OPERATOR...
	cout << "\n\n\n\n myFrac1 = \n" << myFrac1;
	cout << "\n\n myFrac2 = \n" << myFrac2;
	cout << "\n\n myFrac3 = \n" << myFrac3;
	cout << "\n\n myFrac4 = \n" << myFrac4;

	// UPDATE myFrac5 FRACTION OBJECT TO NEW CALCULATED VALUE
	// USING OVERLOADED ASSIGNMENT OPERATOR...
	cout << "\n\n\n\n myFrac5 = myFrac1 + myFrac2 \n";
	myFrac5 = myFrac1 + myFrac2;

	// PRINT myFrac5 CLASS OBJECT TO SCREEN AFTER UPDATE
	// USING OVERLOADED STREAM INSERTION OPERATOR...
	cout << "\n\n myFrac5 = \n" << myFrac5;

	// END PROGRAM
	cout << "\n\n\n\n END MAIN PROGRAM...\n";
}