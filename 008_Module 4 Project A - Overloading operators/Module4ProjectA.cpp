///////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 4 Project A - Overloading operators
// NAME:    Mark Darling
// PURPOSE: design and implement the class myArray that solves the array index
//			out of bounds problem and also allows the user to begin the array
//			index starting at any integer, positive or negative. Every object
//			of type myArray is an array of type int. During execution, when
//			accessing an array component, if the index is out of bounds, the
//			program must terminate with an appropriate error message.
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PREPROCESSOR DIRECTIVES/////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include "myArray.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// BEGIN MAIN LINEAR DRIVER PROGRAM ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
	// DEFINE VARIABLES LOCAL TO main()
	int start_1, end_1, length_1, start_2, end_2, length_2;
	bool result;

	// TAKE INPUT FROM USER FOR ARRAY 1
	cout << " Enter the starting position of ARRAY_1: ";
	cin >> start_1;
	cout << " Enter the ending position of ARRAY_1: ";
	cin >> end_1;
	
	length_1 = abs(end_1 - start_1) + 1;	// take the absolute value for negative cases
	cout << " The length of ARRAY_1 is: " << length_1 << " \n";
	cout << " ARRAY_1 spans from:  0 to " << (length_1 - 1) << "\n";

	// CREATE CLASS OBJECT
	cout << " CREATING CLASS OBJECT...\n";
	myArray list1(start_1, end_1);
	cout << " SUCCESS! - CLASS OBJECT CREATED!\n";

	// TAKE INPUT FROM USER FOR ARRAY 2
	cout << "\n Enter the starting position of ARRAY_2: ";
	cin >> start_2;
	cout << " Enter the ending position of ARRAY_2: ";
	cin >> end_2;

	length_2 = abs(end_2 - start_2) + 1;	// take the absolute value for negative cases
	cout << " The length of ARRAY_2 is: " << length_2 << " \n";
	cout << " ARRAY_2 spans from:  0 to " << (length_2 - 1) << "\n";

	// CREATE CLASS OBJECT
	cout << " CREATING CLASS OBJECT...\n";
	myArray list2(length_2);
	cout << " SUCCESS! - CLASS OBJECTS CREATED!\n";

	// PRINT CLASS OBJECTS
	cout << "\n PRINTING CLASS OBJECTS...\n";
	cout << "\nlist1.printClassObject():\n";
	list1.printClassObject();
	cout << "\nlist2.printClassObject():\n";
	list2.printClassObject();

	// INVOKE ASSIGNMENT OPERATOR
	cout << " INVOKING ASSIGNMENT OPERATOR...\n";
	cout << " list2 = list1;				// EQUIVALENT: list2.operator=(list1)\n";
	list2 = list1;							// EQUIVALENT: list2.operator=(list1)
	cout << endl;

	// PRINT CLASS OBJECTS
	cout << " PRINTING CLASS OBJECTS...\n";
	cout << "\nlist1.printClassObject():\n";
	list1.printClassObject();
	cout << "\nlist2.printClassObject():\n";
	list2.printClassObject();

	// INVOKE COPY CONSTRUCTOR
	cout << " INVOKING COPY CONSTRUCTOR...\n";
	cout << " myArray list3 = list2;			// EQUIVALENT: myArray list3(list1)\n";
	myArray list3 = list2;						// EQUIVALENT: myArray list3(list1)

	// TEST OVERLOADED RELATIONAL OPERATORS
	cout << "\n TESTING OVERLOADED RELATIONAL OPERATORS...\n";
	cout << " list1 == list2: ";
	result = list1 == list2;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	cout << " list1 != list2: ";
	result = list1 != list2;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	// PRINT CLASS OBJECTS
	cout << " PRINTING CLASS OBJECTS...\n";
	cout << "\nlist1.printClassObject():\n";
	list1.printClassObject();
	cout << "\nlist2.printClassObject():\n";
	list2.printClassObject();
	cout << "\nlist3.printClassObject():\n";
	list3.printClassObject();

	// TEST OVERLOADED SUBSCRIPT OPERATOR
	cout << " TESTING OVERLOADED SUBSCRIPT OPERATOR...\n";
	cout << " list1[0] = 4;				// does this use overloaded assignment operator?\n";
	list1[0] = 4;						// does this use overloaded assignment operator?
	cout << " list2[2] = list1[0];\n";
	list2[2] = list1[0];
	cout << endl;

	// PRINT CLASS OBJECTS
	cout << " PRINTING CLASS OBJECTS...\n";
	cout << "\nlist1.printClassObject():\n";
	list1.printClassObject();
	cout << "\nlist2.printClassObject():\n";
	list2.printClassObject();
	cout << "\nlist3.printClassObject():\n";
	list3.printClassObject();

	// TEST OVERLOADED RELATIONAL OPERATORS
	cout << " TESTING OVERLOADED RELATIONAL OPERATORS...\n";
	cout << " list1 == list2: ";
	result = list1 == list2;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	cout << " list1 != list2: ";
	result = list1 != list2;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;

	// END MAIN PROGRAM
	cout << "\n END OF PROGRAM!\n";
	return 0;
}
///////////////////////////////////////////////////////////////////////////////