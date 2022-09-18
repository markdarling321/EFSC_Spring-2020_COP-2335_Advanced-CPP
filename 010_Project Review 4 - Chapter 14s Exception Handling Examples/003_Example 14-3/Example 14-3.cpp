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

// Division by zero and the assert function.

#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    int dividend, divisor, quotient;
   
    cout << "Line 7: Enter the dividend: ";
    cin >> dividend;
    
    cout << endl;
    
    cout << "Line 10: Enter the divisor: ";
    cin >> divisor;
    
    cout << endl;
    
    assert(divisor != 0);
    
    quotient = dividend / divisor;
    
    cout << "Line 15: Quotient = " << quotient << endl;
    
    return 0;
}