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

// Handling division by zero exception.

#include <iostream>
using namespace std;

int main()
{
    int dividend, divisor, quotient;
    
    try
    {
        cout << "Line 8: Enter the dividend: ";
        cin >> dividend;
        
        cout << endl;
        
        cout << "Line 11: Enter the divisor: ";
        cin >> divisor;
        
        cout << endl;
        
        if (divisor == 0)
            throw 0;

        quotient = dividend / divisor;

        cout << "Line 17: Quotient = " << quotient << endl;
    }

    catch (int)
    {
        cout << "Line 21: Division by 0." << endl;
    }

    return 0;
}