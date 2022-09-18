///////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 4 Project B - Creating a class template
// NAME:    Mark Darling
// PURPOSE: redesign our class myArray from Module 4 Project A to use class
//			templates so the class myArray can be used in any application
//			that requires arrays of any data type to process data.
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PREPROCESSOR DIRECTIVES/////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>				// absolute value function : abs()
#include "myTemplate.h"
//#include <string>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// BEGIN MAIN LINEAR DRIVER PROGRAM ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
	///////////////////////////////////////////////////////////////////////////
	// PART A - INTEGERS //////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	cout << "\n\n ~~~~~~~~~~~~ DRIVER PROGRAM USING INTEGERS ~~~~~~~~~~~~\n\n";

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
	myArray<int> list1(start_1, end_1);
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
	myArray<int> list2(length_2);
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
	cout << " myArray list3 = list2;			// EQUIVALENT: myArray list3(list2)\n";
	myArray<int> list3 = list2;					// EQUIVALENT: myArray list3(list2)

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



	///////////////////////////////////////////////////////////////////////////
	// PART B - DOUBLES / FLOATS (list4, list5, list6) ////////////////////////
	///////////////////////////////////////////////////////////////////////////
	cout << "\n\n\n\n\n ~~~~~~~~~~~~~ DRIVER PROGRAM USING DOUBLES ~~~~~~~~~~~~~\n\n";

	// DEFINE VARIABLES LOCAL TO main()
	int start_4, end_4, length_4, start_5, end_5, length_5;
	//bool result;

	// TAKE INPUT FROM USER FOR ARRAY 4
	cout << " Enter the starting position of ARRAY_4: ";
	cin >> start_4;
	cout << " Enter the ending position of ARRAY_4: ";
	cin >> end_4;

	length_4 = abs(end_4 - start_4) + 1;	// take the absolute value for negative cases
	cout << " The length of ARRAY_4 is: " << length_4 << " \n";
	cout << " ARRAY_4 spans from:  0 to " << (length_4 - 1) << "\n";

	// CREATE CLASS OBJECT
	cout << " CREATING CLASS OBJECT...\n";
	myArray<double> list4(start_4, end_4);
	cout << " SUCCESS! - CLASS OBJECT CREATED!\n";

	// TAKE INPUT FROM USER FOR ARRAY 5
	cout << "\n Enter the starting position of ARRAY_5: ";
	cin >> start_5;
	cout << " Enter the ending position of ARRAY_5: ";
	cin >> end_5;

	length_5 = abs(end_5 - start_5) + 1;	// take the absolute value for negative cases
	cout << " The length of ARRAY_5 is: " << length_5 << " \n";
	cout << " ARRAY_5 spans from:  0 to " << (length_5 - 1) << "\n";

	// CREATE CLASS OBJECT
	cout << " CREATING CLASS OBJECT...\n";
	myArray<double> list5(length_5);
	cout << " SUCCESS! - CLASS OBJECTS CREATED!\n";

	// PRINT CLASS OBJECTS
	cout << "\n PRINTING CLASS OBJECTS...\n";
	cout << "\nlist4.printClassObject():\n";
	list4.printClassObject();
	cout << "\nlist5.printClassObject():\n";
	list5.printClassObject();

	// INVOKE ASSIGNMENT OPERATOR
	cout << " INVOKING ASSIGNMENT OPERATOR...\n";
	cout << " list5 = list4;				// EQUIVALENT: list5.operator=(list4)\n";
	list5 = list4;							// EQUIVALENT: list5.operator=(list4)
	cout << endl;

	// PRINT CLASS OBJECTS
	cout << " PRINTING CLASS OBJECTS...\n";
	cout << "\nlist4.printClassObject():\n";
	list4.printClassObject();
	cout << "\nlist5.printClassObject():\n";
	list5.printClassObject();

	// INVOKE COPY CONSTRUCTOR
	cout << " INVOKING COPY CONSTRUCTOR...\n";
	cout << " myArray list6 = list5;			// EQUIVALENT: myArray list6(list5)\n";
	myArray<double> list6 = list5;				// EQUIVALENT: myArray list6(list5)

	// TEST OVERLOADED RELATIONAL OPERATORS
	cout << "\n TESTING OVERLOADED RELATIONAL OPERATORS...\n";
	cout << " list4 == list5: ";
	result = list4 == list5;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	cout << " list4 != list5: ";
	result = list4 != list5;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	// PRINT CLASS OBJECTS
	cout << " PRINTING CLASS OBJECTS...\n";
	cout << "\nlist4.printClassObject():\n";
	list4.printClassObject();
	cout << "\nlist5.printClassObject():\n";
	list5.printClassObject();
	cout << "\nlist6.printClassObject():\n";
	list6.printClassObject();

	// TEST OVERLOADED SUBSCRIPT OPERATOR
	cout << " TESTING OVERLOADED SUBSCRIPT OPERATOR...\n";
	cout << " list4[0] = 4.0;			// does this use overloaded assignment operator?\n";
	list4[0] = 4.0;						// does this use overloaded assignment operator?
	cout << " list5[2] = list4[0];\n";
	list5[2] = list4[0];
	cout << endl;

	// PRINT CLASS OBJECTS
	cout << " PRINTING CLASS OBJECTS...\n";
	cout << "\nlist4.printClassObject():\n";
	list4.printClassObject();
	cout << "\nlist5.printClassObject():\n";
	list5.printClassObject();
	cout << "\nlist6.printClassObject():\n";
	list6.printClassObject();

	// TEST OVERLOADED RELATIONAL OPERATORS
	cout << " TESTING OVERLOADED RELATIONAL OPERATORS...\n";
	cout << " list4 == list5: ";
	result = list4 == list5;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	cout << " list4 != list5: ";
	result = list4 != list5;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;



	///////////////////////////////////////////////////////////////////////////
	// PART D - CHARS (list7, list8, list9) ///////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	cout << "\n\n\n\n\n ~~~~~~~~~~~~~~ DRIVER PROGRAM USING CHARS ~~~~~~~~~~~~~~\n\n";

	// DEFINE VARIABLES LOCAL TO main()
	int start_7, end_7, length_7, start_8, end_8, length_8;
	//bool result;

	// TAKE INPUT FROM USER FOR ARRAY 7
	cout << " Enter the starting position of ARRAY_7: ";
	cin >> start_7;
	cout << " Enter the ending position of ARRAY_7: ";
	cin >> end_7;

	length_7 = abs(end_7 - start_7) + 1;	// take the absolute value for negative cases
	cout << " The length of ARRAY_7 is: " << length_7 << " \n";
	cout << " ARRAY_7 spans from:  0 to " << (length_7 - 1) << "\n";

	// CREATE CLASS OBJECT
	cout << " CREATING CLASS OBJECT...\n";
	myArray<char> list7(start_7, end_7);
	cout << " SUCCESS! - CLASS OBJECT CREATED!\n";

	// TAKE INPUT FROM USER FOR ARRAY 8
	cout << "\n Enter the starting position of ARRAY_8: ";
	cin >> start_8;
	cout << " Enter the ending position of ARRAY_8: ";
	cin >> end_8;

	length_8 = abs(end_8 - start_8) + 1;	// take the absolute value for negative cases
	cout << " The length of ARRAY_8 is: " << length_8 << " \n";
	cout << " ARRAY_8 spans from:  0 to " << (length_8 - 1) << "\n";

	// CREATE CLASS OBJECT
	cout << " CREATING CLASS OBJECT...\n";
	myArray<char> list8(length_8);
	cout << " SUCCESS! - CLASS OBJECTS CREATED!\n";

	// PRINT CLASS OBJECTS
	cout << "\n PRINTING CLASS OBJECTS...\n";
	cout << "\nlist7.printClassObject():\n";
	list7.printClassObject();
	cout << "\nlist8.printClassObject():\n";
	list8.printClassObject();

	// INVOKE ASSIGNMENT OPERATOR
	cout << " INVOKING ASSIGNMENT OPERATOR...\n";
	cout << " list8 = list7;				// EQUIVALENT: list8.operator=(list7)\n";
	list8 = list7;							// EQUIVALENT: list8.operator=(list7)
	cout << endl;

	// PRINT CLASS OBJECTS
	cout << " PRINTING CLASS OBJECTS...\n";
	cout << "\nlist7.printClassObject():\n";
	list7.printClassObject();
	cout << "\nlist8.printClassObject():\n";
	list8.printClassObject();

	// INVOKE COPY CONSTRUCTOR
	cout << " INVOKING COPY CONSTRUCTOR...\n";
	cout << " myArray list9 = list8;			// EQUIVALENT: myArray list9(list8)\n";
	myArray<char> list9 = list8;				// EQUIVALENT: myArray list9(list8)

	// TEST OVERLOADED RELATIONAL OPERATORS
	cout << "\n TESTING OVERLOADED RELATIONAL OPERATORS...\n";
	cout << " list7 == list8: ";
	result = list7 == list8;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	cout << " list7 != list8: ";
	result = list7 != list8;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	// PRINT CLASS OBJECTS
	cout << " PRINTING CLASS OBJECTS...\n";
	cout << "\nlist7.printClassObject():\n";
	list7.printClassObject();
	cout << "\nlist8.printClassObject():\n";
	list8.printClassObject();
	cout << "\nlist9.printClassObject():\n";
	list9.printClassObject();

	// TEST OVERLOADED SUBSCRIPT OPERATOR
	cout << " TESTING OVERLOADED SUBSCRIPT OPERATOR...\n";
	cout << " list7[0] = Z; 			// does this use overloaded assignment operator?\n";
	list7[0] = 'Z';						// does this use overloaded assignment operator?
	cout << " list8[2] = list7[0];\n";
	list8[2] = list7[0];
	cout << endl;

	// PRINT CLASS OBJECTS
	cout << " PRINTING CLASS OBJECTS...\n";
	cout << "\nlist7.printClassObject():\n";
	list7.printClassObject();
	cout << "\nlist8.printClassObject():\n";
	list8.printClassObject();
	cout << "\nlist9.printClassObject():\n";
	list9.printClassObject();

	// TEST OVERLOADED RELATIONAL OPERATORS
	cout << " TESTING OVERLOADED RELATIONAL OPERATORS...\n";
	cout << " list7 == list8: ";
	result = list7 == list8;
	if (result == true)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	cout << " list7 != list8: ";
	result = list7 != list8;
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