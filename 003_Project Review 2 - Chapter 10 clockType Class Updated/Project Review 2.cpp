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

//  BEGIN MAIN PROGRAM ///////////////////////////////////////////////////////
int main()
{
    // DEFINE CLASS OBJECTS
    clockType myClock;      // THIS IS INITIALIZED USING DEFAULT CONTRUCTOR
    clockType yourClock;    // THIS IS INITIALIZED USING DEFAULT CONSTRUCTOR

    // DEFINE VARIABLES
    int hours;
    int minutes;
    int seconds;

    // BEGIN CONSOLE OUTPUT
    cout << "CREATING CLASS OBJECTS: myClock AND yourClock...\n";
    cout << "BOTH CLASS OBJECTS SUCCESSFULLY CREATED AND INITIALIZED TO 00:00:00\n";
    cout << endl << endl << endl;

    // SET THE TIME OF myClock
    cout << "SETTING THE TIME OF myClock to 05:04:30\n";
    myClock.setTime(5, 4, 30);

    // PRINT THE TIME OF myClock
    cout << "PRINTING THE TIME OF myClock: ";
    myClock.printTime();
    cout << endl;

    // PRINT THE TIME OF yourClock
    cout << "PRINTING THE TIME OF yourClock: ";
    yourClock.printTime();
    cout << endl << endl << endl;

    // SET THE TIME OF yourClock
    cout << "SETTING THE TIME OF yourClock to 05:45:16\n";
    yourClock.setTime(5, 45, 16);

    // PRINT THE TIME OF yourClock AFTER SETTING IT
    cout << "PRINTING THE TIME OF yourClock AFTER SETTING IT: ";
    yourClock.printTime();
    cout << endl << endl << endl;

    // COMPARE myClock AND yourClock
    cout << "COMPARING myClock AND yourClock...\n";
    if (myClock.equalTime(yourClock))
        cout << "RESULT: Both times are equal." << endl << endl << endl;
    else
        cout << "RESULT: The two times are not equal." << endl << endl << endl;

    // TAKE USER INPUT TO BE USED FOR SETTING THE TIME
    cout << "TAKING USER INPUT TO SET THE TIME OF myClock...\n";
    cout << "Enter the hours, minute, and seconds: ";
    cin >> hours >> minutes >> seconds;
    cout << endl;

    // SET THE TIME OF myClock USING THE VALUE OF THE VARIALBES TAKEN FROM USER ABOVE
    cout << "SETTING myClock EQUAL TO VALUES TAKEN FROM USER...\n";
    myClock.setTime(hours, minutes, seconds);

    // PRINT THE TIME OF myClock AFTER CHANGING ITS TIME
    cout << "PRINTING TIME OF myClock AFTER CHANGING ITS TIME TO VALUES TAKEN FROM USER: ";
    myClock.printTime();
    cout << endl << endl << endl;

    // INCREMENT THE TIME OF myClock BY ONE SECOND
    cout << "INCREMENTING SECONDS...\n";
    myClock.incrementSeconds();
    cout << "SECONDS HAVE BEEN INCREMENTED BY 1!\n\n\n";

    // PRINT THE TIME OF myClock AFTER INCREMENTING IT BY 1 SECOND
    cout << "PRINTING TIME OF myClock AFTER INCREMENTING SECONDS: ";
    myClock.printTime();
    cout << endl << endl << endl;

    // RETRIEVE THE HOURS, MINUTES, AND SECONDS OF THE OBJECT myClock
    cout << "RETRIEVING myClock's CURRENT TIME...\n\n\n";
    myClock.getTime(hours, minutes, seconds);

    // OUTPUT THE VALUE OF HOURS, MINUTES, AND SECONDS
    cout << "OUTPUTTING myClock's CURRENT TIME VALUES...\n";
    cout << "hours = " << hours
         << ", minutes = " << minutes
         << ", seconds = " << seconds
         << endl;

    cout << "\n\n\nEND MAIN PROGRAM.\n\n\n";
    return 0;
}   // END MAIN
//////////////////////////////////////////////////////////////////////////////