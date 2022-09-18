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
#ifndef H_myArray
#define H_myArray

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// CLASS TEMPLATE DEFINITION //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <class elemType>
class myArray
{
	///////////////////////////////////////////////////////////////////////////////
	// PUBLIC MEMBER FUNCTIONS ////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
public:
	// MEMBER FUNCTION SIGNATURES				// (not going to implement most of these)
	void growHead(int);							// (+) : appends x additional NULL elements to head


	void shrinkHead(int);						// (-) : removes x number of elements starting
												//		 from head going towards tail


	void growTail(int);							// (+) : appends x additional NULL elements to tail


	void shrinkTail(int);						// (-) : removes x number of elements starting
												//		 from tail going towards head


	void insertHead(elemType);					// insert 1 new element at head of array


	void insertTail(elemType);					// insert 1 new element at tail of array


	void insertBody(elemType, int);				// insert 1 new element in middle of array
												//			elemType : value to insert
												//				 int : index position to insert at


	void printArray() const;					// PRECONDITION:  none
												// POSTCONDITION: print object array's indexes
												//				  and each respective value


	void printClassObject() const;				// PRECONDITION:  none
												// POSTCONDITION: print class object's private
												//				  member variable names and their
												//				  values before printing its array's
												//				  indexes and their values


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED ASSIGNMENT OPERATOR /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	const myArray& operator=(const myArray&);
												// PRECONDITION:  both left and right objects must
												//				  be of same class type and already 
												//				  created and initialized
												// POSTCONDITION: set right object's private member
												//				  variables of same class type equal
												//				  to left object's member variables
												//				  of same class type


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED SUBSCRIPT / ARRAY INDEX OPERATOR ////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	elemType& operator[](int);					// PRECONDITION:  object array's index being manipulated
												//				  must be within array's bounds
												// POSTCONDITION: returns value of object's array value
												//				  stored at specified index


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED RELATIONAL OPERATOR /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	bool operator==(const myArray&) const;		// PRECONDITION:  both objects being compared must
												//				  be of same type and already
												//				  initialized containing a minimum
												//				  of 1 array element each
												// POSTCONDITION: returns true if two object's
												//				  arrays of same type are equal.
												//				  returns false otherwise.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED RELATIONAL OPERATOR /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	bool operator!=(const myArray&) const;		// PRECONDITION:  both objects being compared must
												//				  be of same type and already
												//				  initialized containing a minumum
												//				  of 1 array element each
												// POSTCONDITION: returns true if two object's
												//				  arrays of same type are not equal.
												//				  returns false otherwise


	///////////////////////////////////////////////////////////////////////////
	// COPY CONSTRUCTOR ///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	myArray(const myArray& arrayObj);			// PRECONDITION:  must be enough free system memory
												//				  to create new copy of object
												// POSTCONDITION: creates and initializes new object
												//				  instance using existing object's
												//				  (of same type) private member
												//				  variable values


	///////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR WITH TWO PARAMETERS ////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	myArray(int, int);							// PRECONDITION:  none
												// POSTCONDITION: creates dynamic array using user-
												//				  specified integers (negative or
												//				  positive) as lower and upper bounds
												//	  LEFT  int : user's starting index (inclusive)
												//	  RIGHT int : user's ending index   (inclusive)


	///////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR WITH ONE PARAMETER /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	myArray(int);								// PRECONDITION:  none
												// POSTCONDITION: creates dynamic array using integer
												//				  value passed as the length of
												//				  desired array. generated array's
												//				  indexes span from [0, length-1]
												//			int : length of array


	///////////////////////////////////////////////////////////////////////////
	// DEFAULT CONSTRUCTOR WITHOUT PARAMETERS /////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	myArray();									// PRECONDITION:  none
												// POSTCONDITION: creates a dynamic array containing
												//				  a single NULL element


	///////////////////////////////////////////////////////////////////////////
	// DESTRUCTOR /////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	~myArray();									// PRECONDITION:  object instance that contains
												//				  dynamically allocated memory must
												//				  already exist and go out of scope
												// POSTCONDITION: deletes dynamically allocated memory
												//				  after it is no longer needed


///////////////////////////////////////////////////////////////////////////////
// PRIVATE MEMBER VARIABLES ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
protected:
	elemType *array;			// pointer to hold dynamic array address of array
								// (array only valid for int, double, float, char)

	int usrStart;				// stores +/- integer index of user's starting element
	int usrEnd;					// stores +/- integer index of user's ending element
	int usrNext;				// stores +/- integer index of user's next element (usrEnd +- 1)
								// ..................depends if (start < end) or (start > end)

	int length;					// stores total number of elements in array ( abs(end-start) + 1 )
	int offset;					// stores number of elements from 0 to usrStart (0 + start)
	int direction;				// either (+1) or (-1) to indicate number line direction of array

	int iStart;					// stores true index of array start................(0)
	int iEnd;					// stores true index of array end..................(length - 1)
	int iNext;					// stores next true array index to be written to...(length)
};
///////////////////////////////////////////////////////////////////////////////
#endif
///////////////////////////////////////////////////////////////////////////////