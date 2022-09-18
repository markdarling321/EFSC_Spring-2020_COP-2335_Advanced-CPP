//////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Project Review 3 - Chapter 10's clockType Class with
//                                      Overloaded Operators
// NAME:    Mark Darling
// PURPOSE: update our clockType ADT to include overloaded operators
//
//////////////////////////////////////////////////////////////////////////////

// PRE-PROCESSOR DIRECTIVES ///////////////////////////////////////////////////
#ifndef H_clockType
#define H_clockType

using namespace std;
//////////////////////////////////////////////////////////////////////////////

// CLASS DEFINITION //////////////////////////////////////////////////////////
class clockType
{
public:
	void setTime(int, int, int);
	//   PRECONDITION:  None.
	//   POSTCONDITION: Sets private member variables representing time equal
	//                  to "hours", "minutes", and "seconds" respectively
	//                  after checking to make sure the integers passed all
	//                  fall within valid ranges for each member variable.


	
	void getTime(int&, int&, int&) const;
	//   PRECONDITION:  None.
	//   POSTCONDITION: Retrieves the integer value stored in each private
	//                  member variable representing their respective
	//                  component of time and updates the addresses of
	//                  the variables passed to getTime() to reflect
	//                  the current value of the equivalent private
	//                  member variable.


	
	void printTime() const;
	//   PRECONDITION:  None.
	//   POSTCONDITION: Prints the time represented by private member
	//                  variables "hr", "min", and "sec" in the format
	//                  HH:MM:SS.


	
	void incrementSeconds();
	//   PRECONDITION:  None.
	//   POSTCONDITION: Increases the private member variable that
	//                  represents seconds by 1 second. If the value
	//                  representing seconds is 59 prior to incrementing
	//                  then seconds gets set to 0 and incrementMinutes()
	//                  is called to yield the logical result of increasing
	//                  minutes by 1 minute.


	
	void incrementMinutes();
	//   PRECONDITION:  None.
	//   POSTCONDITION: Increases the private member variable that
	//                  represents minutes by 1 minute. If the value
	//                  representing minutes is 59 prior to incrementing
	//                  then minutes gets set to 0 and incrementHours()
	//                  is called to yield the logical result of increasing
	//                  hours by 1 hour.


	
	void incrementHours();
	//   PRECONDITION:  None.
	//   POSTCONDITION: Increases the private member variable that
	//                  represents hours by 1 hour. If the value
	//                  representing hours is 23 prior to incrementing
	//                  then hours gets set to 0.


	
	bool equalTime(const clockType&) const;
	//   PRECONDITION:  None.
	//   POSTCONDITION: Returns true if time passed to function equals
	//                  current time represented by provate member
	//                  variables and false if the two times do not
	//                  equal each other.


	
	clockType(int, int, int);   // CONSTRUCTOR WITH PARAMETERS
	//   PRECONDITION:  None.
	//   POSTCONDITION: Initializes clockType's private member variables
	//                  to the respective integer values passed as
	//                  parameters to equalTime() in the form
	//                  MM:HH:SS.


	
	clockType();                // CONSTRUCTOR WITHOUT PARAMETERS
	//   PRECONDITION:  None.
	//   POSTCONDITION: Initializes clockType's private member variables
	//                  representing hours, minutes, and seconds to 0 in
	//                  the format HH:MM:SS.


	
	bool operator==(const clockType& otherClock) const;		// OVERLOADED EQUALITY OPERATOR
	//   PRECONDITION:  Parameter passed to overloaded function is an object of type clockType.
	//   POSTCONDITION: Returns TRUE if all values of both objects (ie. times) are equal
	//					to their respective comparator value (hr == hr, min == min, sec == sec).
	//					Returns FALSE otherwise.


	
	clockType operator++();									// OVERLOADED PRE-INCREMENT OPERATOR
	//   PRECONDITION:  Object being incremented is an object of type clockType.
	//   POSTCONDITION: Increases time of object by 1 second, rolling over seconds, minutes, and
	//					hours accordingly if they go beyond their logical values (ie. > 59 || > 24)


	
	bool operator!=(const clockType& otherClock) const;		// OVERLOADED NOT-EQUAL OPERATOR
	//   PRECONDITION:  Parameter passed to overloaded function is an object of type clockType.
	//   POSTCONDITION: Returns TRUE if any one of the three components of the two times being
	//					compared are not equal to one another. Returns FALSE otherwise.


	
	bool operator<=(const clockType& otherClock) const;		// OVERLOADED LESS-THAN-OR-EQUAL-TO OPERATOR
	//   PRECONDITION:  Parameter passed to overloaded function is an object of type clockType.
	//   POSTCONDITION: Returns TRUE if (hr < objHr) || ((hr == objHr) && (min < objMin)) ||
	//					((hr == objHr) && (min == objMin) && (sec <= objSec)).
	//					Returns FALSE otherwise.


	
	bool operator<(const clockType& otherClock) const;		// OVERLOADED LESS-THAN OPERATOR
	//   PRECONDITION:  Parameter passed to overloaded function is an object of type clockType.
	//   POSTCONDITION: Returns TRUE if (hr < objHr) || ((hr == objHr) && (min < objMin)) ||
	//					((hr == objHr) && (min == objMin) && (sec < objSec)).
	//					Returns FALSE otherwise.


	
	bool operator>=(const clockType& otherClock) const;		// OVERLOADED GREATER-THAN-OR-EQUAL-TO OPERATOR
	//   PRECONDITION:  Parameter passed to overloaded function is an object of type clockType.
	//   POSTCONDITION: Returns TRUE if (hr > objHr) || ((hr == objHr) && (min > objMin)) ||
	//					((hr == objHr) && (min == objMin) && (sec >= objSec)).
	//					Returns FALSE otherwise.


	
	bool operator>(const clockType& otherClock) const;		// OVERLOADED GREATER-THAN OPERATOR
	//   PRECONDITION:  Parameter passed to overloaded function is an object of type clockType.
	//   POSTCONDITION: Returns TRUE if (hr > objHr) || ((hr == objHr) && (min > objMin)) ||
	//					((hr == objHr) && (min == objMin) && (sec > objSec)).
	//					Returns FALSE otherwise.


	
	const clockType& operator=(const clockType&);			// OVERLOADED ASSIGNMENT OPERATOR
	//   PRECONDITION:  Parameter passed to overloaded function is an object of type clockType.
	//   POSTCONDITION: Copies object of same type (clockType) passed to function into the
	//					originally called object.



private:
	int hr;
	int min;
	int sec;
};
//////////////////////////////////////////////////////////////////////////////
#endif