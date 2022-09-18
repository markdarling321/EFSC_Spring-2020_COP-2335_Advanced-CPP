///////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 6 Project B - Programming recursive functions (2)
// NAME:    Mark Darling
// PURPOSE: Write a recursive function, (Greatest Common Divisor) that takes
//          two integers X and Y as parameters and returns the greatest common
//          divisor of the numbers. Ensure the correct inputs are entered. Also
//			write a program to test your function.
//
// NOTE 1:    gcd{ a , b } = gcd{ |a| , b } = gcd{ a , |b| } = gcd{ |a| , |b| }
// NOTE 2:    gcd{ a , b } = gcd{ −a  , b } = gcd{ a , −b  } = gcd{ −a  , −b  }
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PREPROCESSOR DIRECTIVES ////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <limits>			// numeric_limits<streamsize>::max()
#include <sstream>          // cin.setstate(std::ios_base::failbit)
#include <cmath>            // abs()

using namespace std;


///////////////////////////////////////////////////////////////////////////////
// RECURSIVE FUNCTION PROTOTYPE ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int gcd(long long int x, long long int y);


///////////////////////////////////////////////////////////////////////////////
// MAIN PROGRAM BEGINS HERE ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
    // DEFINE INTEGER VARIABLE
    long long int xVal, yVal;

    // TAKE INITIAL USER INPUT
    cout << " Enter an integer between -9223372036854775807";
    cout << " and 9223372036854775807 for X: ";
    cin >> xVal;
    if (!cin.fail() && (cin.get() == '\n'))    // HANDLES CONTINUING GRACEFULLY
                                               // AFTER FAILED xVal ENTRY
    {
        cout << " Enter an integer between -9223372036854775807";
        cout << " and 9223372036854775807 for Y: ";
        cin >> yVal;
    }


    // REPEAT TAKING USER INPUT IF BAD INPUT WAS GIVEN INITIALLY
    while ((!(cin.good())) || (cin.get() != '\n')) // RIGHT SIDE HANDLES FLOATS
                                                   // THAT CAN BREAK CIN STREAM
                                                   // FILTERING
    {
        cin.clear();                          // CLEAR FAIL BIT OF CIN IOSTREAM
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // DISCARD REMAINDER
                                                             // OF GARBAGE INPUT
        cout << " ERROR - input must be an integer!\n\n";    // INFORM USER
        cout << " RETRY : \n";
        cout << " Enter an integer between -9223372036854775807";
        cout << " and 9223372036854775807 for X: ";                // TRY AGAIN
        cin >> xVal;                                   // TAKE USER INPUT AGAIN
        if (!cin.fail() && (cin.get() == '\n'))     // RIGHT SIDE HANDLES FLOAT
                                                    // INPUT GRACEFULLY
        {
            cout << " Enter an integer between -9223372036854775807";
            cout << " and 9223372036854775807 for Y: ";            // TRY AGAIN
            cin >> yVal;                               // TAKE USER INPUT AGAIN
        }        
    }

    // ECHO INPUT GIVEN BY USER AND OUTPUT RESULT
    cout << " The GCD of (" << xVal << "," << yVal << ") is: ";
    cout << gcd(abs(xVal),abs(yVal)) << endl;   // MAKE RECURSIVE FUNCTION CALL

    // MAIN PROGRAM ENDS HERE
    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// RECURSIVE FUNCTION DEFINITION //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int gcd(long long int x, long long int y)
{
    // BASE CASE
    if (y == 0)
        return x;

    // RECURRING CASE
    return ( gcd(y, x % y) );
}


///////////////////////////////////////////////////////////////////////////////
// SAMPLE RUN OF RECURSIVE FUNCTION USING TEST CASE ///////////////////////////
///////////////////////////////////////////////////////////////////////////////
// TEST CASE:   (x,y):          (4,6)
//
// 1ST PASS:    CALL:           gcd(4,6)
//              BASE CASE?:     y = 0           FALSE      
//              RECURSIVE CASE: x = y       ==  6
//              RECURSIVE CASE: y = x % y   ==  4
//              RETURN:         gcd(6,4)
//
// 2ND PASS:    CALL:           gcd(6,4)
//              BASE CASE?:     y = 0           FALSE      
//              RECURSIVE CASE: x = y       ==  4
//              RECURSIVE CASE: y = x % y   ==  2
//              RETURN:         gcd(4,2)
//
// 3RD PASS:    CALL:           gcd(4,2)
//              BASE CASE?:     y = 0           FALSE      
//              RECURSIVE CASE: x = y       ==  2
//              RECURSIVE CASE: y = x % y   ==  0
//              RETURN:         gcd(2,0)
//
// 4TH PASS:    CALL:           gcd(2,0)
//              BASE CASE?:     y = 0           TRUE      
//              RECURSIVE CASE: N/A
//              RECURSIVE CASE: N/A
//              RETURN:         x           ==  2
// UNWINDING:   4TH -> 3RD -> 2ND -> 1ST
//               2  ->  2  ->  2  ->  2     =   2
//
// FINAL RESULT:            2