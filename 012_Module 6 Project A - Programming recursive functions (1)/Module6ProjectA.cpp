///////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 6 Project A - Programming recursive functions (1)
// NAME:    Mark Darling
// PURPOSE: Write a recursive function, sumDigits, that takes an integer as a
//          parameter and returns the sum of the digits of the integer. Ensure
//          the correct input is entered. Also, write a program to test your
//          function.
//			
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PREPROCESSOR DIRECTIVES ////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <limits>			// numeric_limits<streamsize>::max()
#include <sstream>          //cin.setstate(std::ios_base::failbit)

using namespace std;


///////////////////////////////////////////////////////////////////////////////
// RECURSIVE FUNCTION PROTOTYPE ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int sumDigits(long long int num);


///////////////////////////////////////////////////////////////////////////////
// MAIN PROGRAM BEGINS HERE ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
    // DEFINE INTEGER VARIABLE
    long long int number;

    // TAKE INITIAL USER INPUT
    cout << " Enter an integer between 0 and 9223372036854775807: ";
    cin >> number;

    if (number < 0)               // MANUALLY SET CIN STREAM STATE TO FAILED IF
        cin.setstate(std::ios_base::badbit);      // NEGATIVE INPUT IS DETECTED

    // REPEAT TAKING USER INPUT IF BAD INPUT WAS GIVEN INITIALLY
    while ((!(cin.good())) || (cin.get() != '\n')) // RIGHT SIDE HANDLES FLOATS
                                                   // THAT CAN BREAK CIN STREAM
                                                   // STATE CHECKS
    {
        cin.clear(); // CLEAR FAIL BIT OF CIN IOSTREAM
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // DISCARD REMAINDER
                                                             // OF GARBAGE INPUT
        cout << " ERROR - input must be an integer!\n\n"; // INFORM USER
        cout << " RETRY - Enter an integer: "; // TRY AGAIN
        cin >> number; // STORE INPUT USING CIN IOSTREAM

        if (number < 0)           // MANUALLY SET CIN STREAM STATE TO FAILED IF
            cin.setstate(std::ios_base::badbit);  // NEGATIVE INPUT IS DETECTED
    }

    // ECHO INPUT GIVEN BY USER AND OUTPUT RESULT
    cout << " The sum of the digits in " << number << " is ";
    cout << sumDigits(number) << endl; // MAKE RECURSIVE FUNCTION CALL

    // MAIN PROGRAM ENDS HERE
    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// RECURSIVE FUNCTION DEFINITION //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int sumDigits(long long int num)
{
    // BASE CASE
    if (num == 0)
        return 0;

    // RECURRING CASE
    return (num % 10 + sumDigits(num / 10)); // MOD BY 10 STRIPS 1 DIGIT AT A
                                             // TIME THEN CALLS ITSELF AGAIN
                                             // PASSING IT THE REMAINING DIGITS
}


///////////////////////////////////////////////////////////////////////////////
// SAMPLE RUN OF RECURSIVE FUNCTION USING TEST CASE ///////////////////////////
///////////////////////////////////////////////////////////////////////////////
// TEST CASE:   number = 123
// 1ST PASS:    CALL:       sumDigits(123)
//              FUNC:       123 % 10 = 3
//              FUNC:       123 / 10 = 12
//              RETURN:     3 + sumDigits(12)
// 2ND PASS:    CALL:       sumDigits(12)
//              FUNC:       12 % 10 = 2
//              FUNC:       12 / 10 = 1
//              RETURN:     2 + sumDigits(1)
// 3RD PASS:    CALL:       sumDigits(1)
//              FUNC:       1 % 10 = 1
//              FUNC:       1 / 10 = 0
//              RETURN:     1 + sumDigits(0)
// 4TH PASS:    CALL:       sumDigits(0)
//              FUNC:       BASE CASE == TRUE
//              RETURN:     0
// UNWINDING:   4TH + 3RD + 2ND + 1ST
//               0  +  1  +  2  +  3    =   6
// FINAL RESULT:            6