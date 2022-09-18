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
// PRE-PROCESSOR DIRECTIVES ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cassert>		// assert function : assert()
#include <cmath>		// absolute value function : abs()
#include "myArray.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// CLASS MEMBER FUNCTION DEFINITIONS //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void myArray::growHead(int growBy)
{
	cout << " CALLING: void myArray::growHead(int growBy)\n";
}
void myArray::shrinkHead(int shrinkBy)
{
	cout << " CALLING: void myArray::shrinkHead(int shrinkBy)\n";
}
void myArray::growTail(int growBy)
{
	cout << " CALLING: void myArray::growTail(int growBy)\n";
}
void myArray::shrinkTail(int shrinkBy)
{
	cout << " CALLING: void myArray::shrinkTail(int shrinkBy)\n";
}
void myArray::insertHead(int insertValue)
{
	cout << " CALLING: void myArray::insertHead(int insertValue)\n";
}
void myArray::insertTail(int insertValue)
{
	cout << " CALLING: void myArray::insertTail(int insertValue)\n";
}
void myArray::insertBody(int insertValue, int index)
{
	cout << " CALLING: void myArray::insertBody(int insertValue, int index)\n";
}
void myArray::printArray() const
{
	cout << "\n  CALLING: void myArray::printArray() const\n";
	// PRINT INTEGER ARRAY
	for (int i = 0; i < length; i++)
	{
		cout << " \t\tarray[" << i << "] = " << array[i] << "\n";
	}
	cout << endl;
}
void myArray::printClassObject() const
{
	cout << "\n  CALLING: void myArray::printClassObject() const\n";
	// PRINT PRIVATE MEMBER VARIABLES AND THEIR VALUES
	cout << " \t\tusrStart:  " << usrStart << endl;
	cout << " \t\tusrEnd:    " << usrEnd << endl;
	cout << " \t\tusrNext:   " << usrNext << endl;
	cout << endl;
	cout << " \t\tlength:    " << length << endl;
	cout << " \t\toffset:    " << offset << endl;
	cout << " \t\tdirection: " << direction << endl;
	cout << endl;
	cout << " \t\tiStart:    " << iStart << endl;
	cout << " \t\tiEnd:      " << iEnd << endl;
	cout << " \t\tiNext:     " << iNext << endl;

	// PRINT OBJECT INTEGER ARRAY
	printArray();
}

///////////////////////////////////////////////////////////////////////////////
// OVERLOADED ASSIGNMENT OPERATOR /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
const myArray& myArray::operator=(const myArray &arrayObj)
{
	cout << " CALLING: OVERLOADED ASSIGNMENT OPERATOR\n";
	// CLASS OBJECT COPY ALGORITHM
	if (this != &arrayObj)						// avoid self-assignment
	{
		// COPY PRIVATE MEMBER VARIABLES
		usrStart = arrayObj.usrStart;
		usrEnd = arrayObj.usrEnd;
		usrNext = arrayObj.usrNext;

		length = arrayObj.length;
		offset = arrayObj.offset;
		direction = arrayObj.direction;

		iStart = arrayObj.iStart;
		iEnd = arrayObj.iEnd;
		iNext = arrayObj.iNext;

		// DYNAMIC ARRAY COPY ALGORITHM
		delete[] array;						// destroy existing integer array
		array = new int[length];			// dynamically allocate a new integer array
		for (int i = 0; i < length; i++)	// copy elements into new array
		{
			array[i] = arrayObj.array[i];
		}
	}

	// RETURN OBJECT
	return *this;
}
///////////////////////////////////////////////////////////////////////////////
// OVERLOADED SUBSCRIPT / ARRAY INDEX OPERATOR ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int& myArray::operator[](int index)
{
	// CHECK TO MAKE SURE INDEX PROVIDED IS WITHIN EXISTING ARRAY BOUNDS
	assert(0 <= index && index < length);
	// RETURN VALUE REQUESTED FROM SPECIFIED INDEX
	return array[index];
}

///////////////////////////////////////////////////////////////////////////////
// OVERLOADED RELATIONAL OPERATORS ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool myArray::operator==(const myArray& arrayObj) const
{
	if (length == arrayObj.length)			// only proceed checking every index for
											// equivalence if the two arrays in question
											// are of equal length. otherwise return false.
	{
		for (int i = 0; i < length; i++)		// iterate through every element
		{
			if (array[i] != arrayObj.array[i])	// if a single comparison fails
				return false;					// return false
		}
		return true;							// otherwise, return true
	}
	return false;							// automatically return false if arrays being
											// compared are of different lengths
}

bool myArray::operator!=(const myArray& arrayObj) const
{
	if (length != arrayObj.length)			// if array lengths of both arrays being
											// compared do not match they are guaranteed
		return true;						// to not be equivalent, return true.

	else				// if array lengths of both arrays being compared are equal
						// proceed with further checks to determine overall equivalency
	{
		for (int i = 0; i < length; i++)	   // iterate through every element
		{
			if (array[i] != arrayObj.array[i]) // if any single pair of elements
			{								   // do not match, we know the two
				return true;				   // arrays are not equal, return true.
			}
		}
		return false;					   	   // otherwise, return false
	}
}

///////////////////////////////////////////////////////////////////////////////
// COPY CONSTRUCTOR ///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
myArray::myArray(const myArray &arrayObj)
{
	cout << " CALLING: COPY CONSTRUCTOR\n";
	// COPY PRIVATE MEMBER VARIABLES
	usrStart = arrayObj.usrStart;
	usrEnd = arrayObj.usrEnd;
	usrNext = arrayObj.usrNext;

	length = arrayObj.length;
	offset = arrayObj.offset;
	direction = arrayObj.direction;

	iStart = arrayObj.iStart;
	iEnd = arrayObj.iEnd;
	iNext = arrayObj.iNext;

	// DYNAMIC ARRAY COPY ALGORITHM
	array = new int[length];

	for (int i = 0; i < length; i++)
	{
		array[i] = arrayObj.array[i];
	}
}


///////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR  --  with TWO parameters ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
myArray::myArray(int start, int end)
{
	cout << " CALLING: 2 PARAMETER CONSTRUCTOR\n";
	// HANDLE END VALUE DIFFERENTLY DEPENDING WHETHER IT IS POINTING LEFT/RIGHT ON NUMBER LINE
	if (start > end)					// CASE:   (end < start]	AKA: (end <--- start]
	{
		usrStart = start;
		usrEnd = end;
		usrNext = end - 1;

		length = (abs(end - start) + 1);		// will ALWAYS be a positive integer
		offset = (0 + usrStart);				// not required, retains +/- value
		direction = -1;

		iStart = 0;								// array index will ALWAYS start at 0
		iEnd = length - 1;						// array index will ALWAYS end at (length - 1)
		iNext = length;							// array index will ALWAYS advance in (+) direction
	}
	else if (start < end)				// CASE:   [start < end)	AKA: [start ---> end)
	{
		usrStart = start;
		usrEnd = end;
		usrNext = end + 1;

		length = (abs(end - start) + 1);		// will ALWAYS be a positive integer
		offset = (0 + usrStart);				// not required, retains +/- value
		direction = 1;

		iStart = 0;								// array index will ALWAYS start at 0
		iEnd = length - 1;						// array index will ALWAYS end at (length - 1)
		iNext = length;							// array index will ALWAYS advance in (+) direction
	}
	else if (start == end && start == 0)// CASE:   [start == end]
	{
		// ALWAYS advance in (+) direction regardless of starting position
		// since we are unable to determine the direction of a 1 element array
		usrStart = start;
		usrEnd = end;
		usrNext = end + 1;
		
		length = 1;								// will ALWAYS be a positive integer
		offset = (0 + usrStart);				// not required, retains +/- value
		direction = 1;

		iStart = 0;								// array of length 1 will ALWAYS start at 0
		iEnd = 0;								// array of length 1 will ALWAYS end at 0
		iNext = 1;								// array index will ALWAYS advance in (+) direction
	}
	
	array = new int[length];					// generate new dynamic array
	for (int i = 0; i < length; i++)
	{
		array[i] = NULL;						// initialize all values of array to NULL
	}
}

///////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR  --  with ONE parameter ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
myArray::myArray(int length)
{
	cout << " CALLING: 1 PARAMETER CONSTRUCTOR\n";
	// UPDATE MEMBER VARIABLES
	usrStart = 1;
	usrEnd = length;
	usrNext = length + 1;

	this->length = length;
	offset = 1;
	direction = 1;

	iStart = 0;
	iEnd = length - 1;
	iNext = length;

	// GENERATE DYNAMIC ARRAY BASED ON PARAMETERS PASSED
	array = new int[length];					// generate new dynamic array
	for (int i = 0; i < length; i++)
	{
		array[i] = NULL;						// initialize all values of array to NULL
	}
}

///////////////////////////////////////////////////////////////////////////////
// DEFAULT CONSTRUCTOR (without parameters) ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
myArray::myArray()
{
	cout << " CALLING: 0 PARAMETER CONSTRUCTOR\n";
	// UPDATE MEMBER VARIABLES
	usrStart = 1;
	usrEnd = 1;
	usrNext = 2;

	length = 1;
	offset = 1;
	direction = 1;
	
	iStart = 0;
	iEnd = 0;
	iNext = 1;

	// THIS ARRAY WILL NEED TO BE RESIZED PRIOR TO USE IF CALLED FROM DEFAULT CONSTRUCTOR
	array = new int[1];			// create a new dynamic array containing a single element
	array[0] = NULL;			// initialize element value to NULL
}

///////////////////////////////////////////////////////////////////////////////
// DESTRUCTOR /////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
myArray::~myArray()
{
	cout << " CALLING: DESTRUCTOR\n";
	delete[] array;			// destroy dynamic array
	array = nullptr;		// prevent dangling pointers after deallocation
}
///////////////////////////////////////////////////////////////////////////////