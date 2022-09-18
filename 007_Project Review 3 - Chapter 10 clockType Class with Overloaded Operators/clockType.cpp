//////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Project Review 3 - Chapter 10's clockType Class with
//                                      Overloaded Operators
// NAME:    Mark Darling
// PURPOSE: update our clockType ADT to include overloaded operators
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
	cout << sec;
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
	setTime(0,0,0);
	//hr = 0;
	//min = 0;
	//sec = 0;
}

// OVERLOADED EQUALITY OPERATOR
bool clockType::operator==(const clockType& otherClock) const
{
	return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

// OVERLOADED PRE-INCREMENT OPERATOR
clockType clockType::operator++()
{
	sec++;

	if (sec > 59)
	{
		sec = 0;
		min++;

		if (min > 59)
		{
			min = 0;
			hr++;

			if (hr > 23)
			{
				hr = 0;
			}
		}
	}

	return *this;
}

// OVERLOADED NOT-EQUAL OPERATOR
bool clockType::operator!=(const clockType& otherClock) const
{
	return (hr != otherClock.hr || min != otherClock.min || sec != otherClock.sec);
}

// OVERLOADED LESS-THAN-OR-EQUAL-TO OPERATOR
bool clockType::operator<=(const clockType& otherClock) const
{
	return ((hr <= otherClock.hr) ||
		(hr == otherClock.hr && min < otherClock.min) ||
		(hr == otherClock.hr && min == otherClock.min && sec <= otherClock.sec));
}

// OVERLOADED LESS-THAN OPERATOR
bool clockType::operator<(const clockType& otherClock) const
{
	return ((hr < otherClock.hr) ||
			(hr == otherClock.hr && min < otherClock.min) ||
			(hr == otherClock.hr && min == otherClock.min && sec < otherClock.sec));
}

// OVERLOADED GREATER-THAN-OR-EQUAL-TO OPERATOR
bool clockType::operator>=(const clockType& otherClock) const
{
	return ((hr > otherClock.hr) ||
		(hr == otherClock.hr && min > otherClock.min) ||
		(hr == otherClock.hr && min == otherClock.min && sec >= otherClock.sec));
}

// OVERLOADED GREATER-THAN OPERATOR
bool clockType::operator>(const clockType& otherClock) const
{
	return ((hr > otherClock.hr) ||
		(hr == otherClock.hr && min > otherClock.min) ||
		(hr == otherClock.hr && min == otherClock.min && sec > otherClock.sec));
}

// OVERLOADED ASSIGNMENT OPERATOR
const clockType& clockType::operator=(const clockType& clockObj)
{
	// local declaration, if any

	if (this != &clockObj)		// avoid self-assignment
	{
		// algorithm to copy clockObj into this object
		hr = clockObj.hr;
		min = clockObj.min;
		sec = clockObj.sec;
		//setTime(clockObj.hr, clockObj.min, clockObj.sec);
	}

	// return the object assigned
	return *this;
}

//////////////////////////////////////////////////////////////////////////////