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
#ifndef H_myArray
#define H_myArray

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// CLASS DEFINITION ///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class myArray
{
///////////////////////////////////////////////////////////////////////////////
// PUBLIC MEMBER FUNCTIONS ////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
public:
	// MEMBER FUNCTION SIGNATURES		 // (not going to implement most of these)
	void growHead(int);			// (+) : appends x additional elements to head
	

	void shrinkHead(int);		// (-) : removes x number of elements starting
								//		 from head going towards tail


	void growTail(int);			// (+) : appends x additional elements to tail
	

	void shrinkTail(int);		// (-) : removes x number of elements starting
								//		 from tail going towards head


	void insertHead(int);		// insert 1 new integer element at head of array
	

	void insertTail(int);		// insert 1 new integer element at tail of array
	

	void insertBody(int, int);	// insert 1 new integer element in middle of array
								//				int : value to insert
								//				int : index position to insert at
	

	void printArray() const;					// PRECONDITION:  none
												// POSTCONDITION: print object's integer array's
												//				  indexes and each respective value
	

	void printClassObject() const;				// PRECONDITION:  none
												// POSTCONDITION: print class object's private
												//				  member variable names and their
												//				  values before printing its array's
												//				  indexes and their values


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED ASSIGNMENT OPERATOR /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	const myArray& operator=(const myArray&);	// PRECONDITION:  both left and right objects must
												//				  be of same class type and already 
												//				  created and initialized
												// POSTCONDITION: set right object's private member
												//				  variables of same class type equal
												//				  to left object's member variables
												//				  of same class type


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED SUBSCRIPT / ARRAY INDEX OPERATOR ////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	int& operator[](int);						// PRECONDITION:  integer array index being manipulated
												//				  must be within array's bounds
												// POSTCONDITION: returns value of object's integer
												//				  array stored at specified index


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED RELATIONAL OPERATOR /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	bool operator==(const myArray&) const;		// PRECONDITION:  both objects being compared must
												//				  be of same type and already
												//				  initialized containing a minimum
												//				  of 1 array element each
												// POSTCONDITION: returns true if two object's
												//				  integer arrays of same type are
												//				  equal. returns false otherwise.


	///////////////////////////////////////////////////////////////////////////
	// OVERLOADED RELATIONAL OPERATOR /////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	bool operator!=(const myArray&) const;		// PRECONDITION:  both objects being compared must
												//				  be of same type and already
												//				  initialized containing a minumum
												//				  of 1 array element each
												// POSTCONDITION: returns true if two object's
												//				  integer arrays of same type
												//				  are not equal. returns false
												//				  otherwise.


	///////////////////////////////////////////////////////////////////////////
	// COPY CONSTRUCTOR ///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	myArray(const myArray &arrayObj);			// PRECONDITION:  must be enough free system memory
												//				  to create new copy of object
												// POSTCONDITION: creates and initializes new object
												//				  instance using existing object's
												//				  (of same type) private member
												//				  variable values


	///////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR WITH TWO PARAMETERS ////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	myArray(int, int);							// PRECONDITION:  none
												// POSTCONDITION: creates dynamic array using integers
												//				  (negative or positive) as lower and
												//				  upper bounds
												//	  LEFT  int : starting index (inclusive)
												//	  RIGHT int : ending index (exlusive)
	

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
private:
	int *array;					// integer pointer to hold dynamic array address

	int usrStart;				// stores +/- integer index of starting user element
	int usrEnd;					// stores +/- integer index of ending user element
	int usrNext;				// stores +/- integer index of next user element (usrEnd +- 1)
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