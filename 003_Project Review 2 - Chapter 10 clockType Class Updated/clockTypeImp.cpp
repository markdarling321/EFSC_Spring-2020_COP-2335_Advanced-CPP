//////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Project Review 2 - Updating clockType class to an ADT
// NAME:    Mark Darling
// PURPOSE: add constructors to clockType and upgrade it to an ADT
//
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "clockType.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////

// MEMBER FUNCTION DEFINITIONS ///////////////////////////////////////////////
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

// NOTE: using the address of the variables passed to getTime()
//       eliminates the need to return 3 different values
//       simultaneously since C++ can only return 1 value easily
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

// CONSTRUCTOR WITH PARAMETERS
clockType::clockType(int hours, int minutes, int seconds)
{
    setTime(hours, minutes, seconds);
}

// DEFAULT CONSTRUCTOR
clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
}
//////////////////////////////////////////////////////////////////////////////