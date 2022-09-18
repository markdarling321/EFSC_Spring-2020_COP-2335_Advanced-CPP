//////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Project Review 2 - Updating clockType class to an ADT
// NAME:    Mark Darling
// PURPOSE: add constructors to clockType and upgrade it to an ADT
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
    //   PRECONDITION:  None.
    //   POSTCONDITION: Sets private member variables representing time equal
    //                  to "hours", "minutes", and "seconds" respectively
    //                  after checking to make sure the integers passed all
    //                  fall within valid ranges for each member variable.
    void setTime(int, int, int);
    


    //   PRECONDITION:  None.
    //   POSTCONDITION: Retrieves the integer value stored in each private
    //                  member variable representing their respective
    //                  component of time and updates the addresses of
    //                  the variables passed to getTime() to reflect
    //                  the current value of the equivalent private
    //                  member variable.
    void getTime(int&, int&, int&) const;
    


    //   PRECONDITION:  None.
    //   POSTCONDITION: Prints the time represented by private member
    //                  variables "hr", "min", and "sec" in the format
    //                  HH:MM:SS.
    void printTime() const;



    //   PRECONDITION:  None.
    //   POSTCONDITION: Increases the private member variable that
    //                  represents seconds by 1 second. If the value
    //                  representing seconds is 59 prior to incrementing
    //                  then seconds gets set to 0 and incrementMinutes()
    //                  is called to yield the logical result of increasing
    //                  minutes by 1 minute.
    void incrementSeconds();



    //   PRECONDITION:  None.
    //   POSTCONDITION: Increases the private member variable that
    //                  represents minutes by 1 minute. If the value
    //                  representing minutes is 59 prior to incrementing
    //                  then minutes gets set to 0 and incrementHours()
    //                  is called to yield the logical result of increasing
    //                  hours by 1 hour.
    void incrementMinutes();



    //   PRECONDITION:  None.
    //   POSTCONDITION: Increases the private member variable that
    //                  represents hours by 1 hour. If the value
    //                  representing hours is 23 prior to incrementing
    //                  then hours gets set to 0.
    void incrementHours();



    //   PRECONDITION:  None.
    //   POSTCONDITION: Returns true if time passed to function equals
    //                  current time represented by provate member
    //                  variables and false if the two times do not
    //                  equal each other.
    bool equalTime(const clockType&) const;



    //   PRECONDITION:  None.
    //   POSTCONDITION: Initializes clockType's private member variables
    //                  to the respective integer values passed as
    //                  parameters to equalTime() in the form
    //                  MM:HH:SS.
    clockType(int, int, int);   // CONSTRUCTOR WITH PARAMETERS



    //   PRECONDITION:  None.
    //   POSTCONDITION: Initializes clockType's private member variables
    //                  representing hours, minutes, and seconds to 0 in
    //                  the format HH:MM:SS.
    clockType();                // CONSTRUCTOR WITHOUT PARAMETERS

private:
    int hr;
    int min;
    int sec;
};
//////////////////////////////////////////////////////////////////////////////
#endif