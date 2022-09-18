/******************************************************************************
COP 2335-70B  //  Project Review 1: Chapter 10 clockType Class // Mark Darling
******************************************************************************/

#include <iostream>
using namespace std;
//#include "clockType.h"

// CLASS DEFINITION
class clockType
{
public:
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType&) const;
    clockType(int, int, int);   // CONSTRUCTOR WITH PARAMETERS
    clockType();                // CONSTRUCTOR WITHOUT PARAMETERS

private:
    int hr;
    int min;
    int sec;
};


//  BEGIN MAIN PROGRAM
int main()
{
    // DEFINE CLASS OBJECTS
    clockType myClock;
    clockType yourClock;
    
    // DEFINE VARIABLES
    int hours;
    int minutes;
    int seconds;

    // SET THE TIME OF myClock
    myClock.setTime(5, 4, 30);

    // PRINT THE TIME OF myClock
    cout << "myClock: ";
    myClock.printTime();
    cout << endl;

    // PRINT THE TIME OF yourClock
    cout << "yourClock: ";
    yourClock.printTime();
    cout << endl;

    // SET THE TIME OF yourClock
    yourClock.setTime(5, 45, 16);

    // PRINT THE TIME OF yourClock AFTER SETTING IT
    cout << "After setting, yourClock: ";
    yourClock.printTime();
    cout << endl;

    // COMPARE myClock AND yourClock
    if (myClock.equalTime(yourClock))
        cout << "Both times are equal." << endl;
    else
        cout << "The two times are not equal." << endl;

    // TAKE USER INPUT TO BE USED FOR SETTING THE TIME
    cout << "Enter the hours, minute, and seconds: ";
    cin >> hours >> minutes >> seconds;
    cout << endl;

    // SET THE TIME OF myClock USING THE VALUE OF THE VARIALBES TAKEN FROM USER ABOVE
    myClock.setTime(hours, minutes, seconds);

    // PRINT THE TIME OF myClock AFTER CHANGING ITS TIME
    myClock.printTime();
    cout << endl;

    // INCREMENT THE TIME OF myClock BY ONE SECOND
    myClock.incrementSeconds();

    // PRINT THE TIME OF myClock AFTER INCREMENTING IT BY 1 SECOND
    myClock.printTime();
    cout << endl;

    // RETRIEVE THE HOURS, MINUTES, AND SECONDS OF THE OBJECT myClock
    myClock.getTime(hours, minutes, seconds);

    // OUTPUT THE VALUE OF HOURS, MINUTES, AND SECONDS
    cout << "hours = " << hours
         << ", minutes = " << minutes
         << ", seconds = " << seconds
         << endl;
    
    return 0;
}   // END MAIN



// MEMBER FUNCTION DEFINITIONS
void clockType::setTime(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else
        min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
        sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::printTime() const
{
    if (hr < 10)
        cout << "0";
    cout << hr << ":";

    if (min < 10)
        cout << "0";
    cout << min << ":";

    if (sec < 10)
        cout << "0";
    cout << sec << ":";
}

void clockType::incrementSeconds()
{
    sec++;

    if (sec > 59)
    {
        sec = 0;
        incrementMinutes();
    }
}

void clockType::incrementMinutes()
{
    min++;
    if (min > 59)
    {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementHours()
{
    hr++;
    if (hr > 23)
        hr = 0;
}

bool clockType::equalTime(const clockType& otherclock) const
{
    return (hr == otherclock.hr
        && min == otherclock.min
        && sec == otherclock.sec);
}

clockType::clockType(int hours, int minutes, int seconds)
{
    setTime(hours, minutes, seconds);
}

clockType::clockType()  // DEFAULT CONSTRUCTOR
{
    hr = 0;
    min = 0;
    sec = 0;
}
