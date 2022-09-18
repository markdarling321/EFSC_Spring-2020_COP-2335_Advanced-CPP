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
// PRE-PROCESSOR DIRECTIVES ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cassert>				// assert function : assert()
#include <cmath>				// absolute value function : abs()
#include "myTemplate.h"
//#include <string>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// EXPLICIT TEMPLATE INSTANTIATION TO RETAIN INFORMATION-HIDING OF IMPLEMENTATION
// (I spent hours banging my head before I figured this out... not happy.)
/* https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file */
///////////////////////////////////////////////////////////////////////////////
template class myArray<int>;
template class myArray<double>;
template class myArray<float>;
template class myArray<char>;
//template class myArray<string>;	// still can't get this to work yet

///////////////////////////////////////////////////////////////////////////////
// CLASS MEMBER FUNCTION DEFINITIONS //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <class elemType>
void myArray<elemType>::growHead(int growBy)
{
	cout << " CALLING: void myArray::growHead(int growBy)\n";
}


template <class elemType>
void myArray<elemType>::shrinkHead(int shrinkBy)
{
	cout << " CALLING: void myArray::shrinkHead(int shrinkBy)\n";
}


template <class elemType>
void myArray<elemType>::growTail(int growBy)
{
	cout << " CALLING: void myArray::growTail(int growBy)\n";
}


template <class elemType>
void myArray<elemType>::shrinkTail(int shrinkBy)
{
	cout << " CALLING: void myArray::shrinkTail(int shrinkBy)\n";
}


template <class elemType>
void myArray<elemType>::insertHead(elemType insertValue)
{
	cout << " CALLING: void myArray::insertHead(int insertValue)\n";
}


template <class elemType>
void myArray<elemType>::insertTail(elemType insertValue)
{
	cout << " CALLING: void myArray::insertTail(int insertValue)\n";
}


template <class elemType>
void myArray<elemType>::insertBody(elemType insertValue, int index)
{
	cout << " CALLING: void myArray::insertBody(int insertValue, int index)\n";
}


template <class elemType>
void myArray<elemType>::printArray() const
{
	cout << "\n  CALLING: void myArray::printArray() const\n";
	// PRINT INTEGER ARRAY
	for (int i = 0; i < length; i++)
	{
		cout << " \t\tarray[" << i << "] = " << array[i] << "\n";
	}
	cout << endl;
}


template <class elemType>
void myArray<elemType>::printClassObject() const
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
template <class elemType>
const myArray<elemType>& myArray<elemType>::operator=(const myArray<elemType>& arrayObj)
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
		array = new elemType[length];		// dynamically allocate a new array
											// (only valid for int, double, float, char)
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
template <class elemType>
elemType& myArray<elemType>::operator[](int index)
{
	// CHECK TO MAKE SURE INDEX PROVIDED IS WITHIN EXISTING ARRAY BOUNDS
	assert(0 <= index && index < length);
	// RETURN VALUE REQUESTED FROM SPECIFIED INDEX
	return array[index];
}

///////////////////////////////////////////////////////////////////////////////
// OVERLOADED RELATIONAL OPERATORS ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <class elemType>
bool myArray<elemType>::operator==(const myArray& arrayObj) const
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

template <class elemType>
bool myArray<elemType>::operator!=(const myArray& arrayObj) const
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
template <class elemType>
myArray<elemType>::myArray(const myArray& arrayObj)
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
	array = new elemType[length];				// only valid for int, double, float, char

	for (int i = 0; i < length; i++)
	{
		array[i] = arrayObj.array[i];
	}
}


///////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR  --  with TWO parameters ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <class elemType>
myArray<elemType>::myArray(int start, int end)
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

	array = new elemType[length];				// generate new dynamic array
												// (only valid for int, double, float, char)
	for (int i = 0; i < length; i++)
	{
		array[i] = NULL;						// initialize all values of array to NULL
	}
}

///////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR  --  with ONE parameter ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <class elemType>
myArray<elemType>::myArray(int length)
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
	array = new elemType[length];				// generate new dynamic array
												// (only valid for int, double, float, char)
	for (int i = 0; i < length; i++)
	{
		array[i] = NULL;						// initialize all values of array
												// to NULL
	}
}

///////////////////////////////////////////////////////////////////////////////
// DEFAULT CONSTRUCTOR (without parameters) ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <class elemType>
myArray<elemType>::myArray()
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
	array = new elemType[1];	// create a new dynamic array containing a single element
								// (only valid for int, double, float, char)
	array[0] = NULL;			// initialize element value to NULL
}

///////////////////////////////////////////////////////////////////////////////
// DESTRUCTOR /////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <class elemType>
myArray<elemType>::~myArray()
{
	cout << " CALLING: DESTRUCTOR\n";
	delete[] array;			// destroy dynamic array
	array = nullptr;		// prevent dangling pointers after deallocation
}
///////////////////////////////////////////////////////////////////////////////