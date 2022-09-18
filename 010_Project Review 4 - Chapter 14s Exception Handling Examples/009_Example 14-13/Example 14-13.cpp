///////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Project Review 4 - Chapter 14's Exception Handling Examples
// NAME:    Mark Darling
// PURPOSE: COPY, COMPILE, RUN, TEST, and TAKE SCREENSHOTS of the following
//          programs from our book starting on PAGE 993: 14-1, 14-2, 14-3, 14-5,
//          14-6, 14-10, 14-11, 14-12, 14-3. These examples demonstrate what
//          happens when an exception is not handled in addition to how exceptions
//          can and should be handled, using straight-forward built-in exception
//          handling methods to more complex, custom exception classes created
//          by the user.
//
///////////////////////////////////////////////////////////////////////////////

// Handling exception thrown by a function.

#include <iostream>
#include "divisionByZero.h"

using namespace std;

void doDivision();

int main()
{
    doDivision();
    return 0;
}

void doDivision()
{
    int dividend, divisor, quotient;
    
    try
    {
        cout << "Line 15: Enter the dividend: ";
        cin >> dividend;
        
        cout << endl;
        
        cout << "Line 18: Enter the divisor: ";
        cin >> divisor;
        
        cout << endl;
        
        if (divisor == 0)
            throw divisionByZero();
        
        quotient = dividend / divisor;
        
        cout << "Line 24: Quotient = " << quotient << endl;
    }
    
    catch (divisionByZero divByZeroObj)
    {
        cout << "Line 28: In the function "
             << "doDivision: "
             << divByZeroObj.what() << endl;
    }
}