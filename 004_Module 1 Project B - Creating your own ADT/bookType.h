//////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 1 Project B - Creating Your Own ADT
// NAME:    Mark Darling
// PURPOSE: create our own abstract data type
//
//////////////////////////////////////////////////////////////////////////////

// PRE-PROCESSOR DIRECTIVES ///////////////////////////////////////////////////
#ifndef H_bookType
#define H_bookType

#include <string>

using namespace std;
//////////////////////////////////////////////////////////////////////////////

// CLASS DEFINITION //////////////////////////////////////////////////////////
class bookType
{
public:
    // BOOK TITLE
    void printTitle() const;        // PRECONDITION:  None.
                                    // POSTCONDITION: Prints title to screen.

    void setTitle(string);          // PRECONDITION:  None.
                                    // POSTCONDITION: Sets title using a string
                                    //                as input.
    
    void updateTitle(string);       // PRECONDITION:  None.
                                    // POSTCONDITION: Updates title using a 
                                    //                string as input.
    
    string getTitle() const;        // PRECONDITION:  None.
                                    // POSTCONDIITON: Returns title of book as
                                    //                a string.
    
    bool compareTitle(string);      // PRECONDITION:  None.
                                    // POSTCONDITION: Returns true if book titles
                                    //                match.

    // AUTHOR
    void printAuthor() const;       // PRECONDITION:  None.
                                    // POSTCONDITION: Prints author to screen.

    void setAuthor(string[], int);  // PRECONDITION:  None.
                                    // POSTCONDITION: Sets author using a string
                                    //                as input.

    void updateAuthor(string[], int); // PRECONDITION:  None.
                                    // POSTCONDITION: Updates author using a
                                    //                string as input.

    string getAuthor() const;       // PRECONDITION:  None.
                                    // POSTCONDITION: Returns author of book as a
                                    //                string

    bool compareAuthor(string);     // PRECONDITION:  None.
                                    // POSTCONDITION: Returns true if authors
                                    //                match

    // PUBLISHER
    void printPublisher() const;    // PRECONDITION:  None.
                                    // POSTCONDITION: Prints publisher to screen.

    void setPublisher(string);      // PRECONDITION:  None.
                                    // POSTCONDITION: Sets publisher using a
                                    //                string as input.

    void updatePublisher(string);   // PRECONDITION:  None.
                                    // POSTCONDITION: Updates publisher using a
                                    //                string as input.

    string getPublisher() const;    // PRECONDITION:  None.
                                    // POSTCONDITION: Returns publisher of book
                                    //                as a string.

    bool comparePublisher(string);  // PRECONDITION:  None.
                                    // POSTCONDITION: Returns true if publishers
                                    //                match.

    // ISBN
    void printISBN() const;         // PRECONDITION:  None.
                                    // POSTCONDITION: Prints ISBN to screen.

    void setISBN(string);           // PRECONDITION:  None.
                                    // POSTCONDITION: Sets ISBN using a string
                                    //                as input.

    void updateISBN(string);        // PRECONDITION:  None.
                                    // POSTCONDITION: Updates ISBN using a string
                                    //                as input.

    string getISBN() const;         // PRECONDITION:  None.
                                    // POSTCONDITION: Returns ISBN of book as an
                                    //                int.

    bool compareISBN(string);       // PRECONDITION:  None.
                                    // POSTCONDITION: Returns true if ISBNs match.

    // PRICE
    void printPrice() const;        // PRECONDITION:  None.
                                    // POSTCONDITION: Prints price to screen.

    void setPrice(double);          // PRECONDITION:  None.
                                    // POSTCONDITION: Sets price using a double
                                    //                as input.

    void updatePrice(double);       // PRECONDITION:  None.
                                    // POSTCONDITION: Updates price using a
                                    //                double as input.

    double getPrice() const;        // PRECONDITION:  None.
                                    // POSTCONDITION: Returns price of book as a
                                    //                double.

    bool comparePrice(double);      // PRECONDITION:  None.
                                    // POSTCONDITION: Returns true if prices
                                    //                match.

    // STOCK
    void printStock() const;        // PRECONDITION:  None.
                                    // POSTCONDITION: Prints stock quantity to
                                    //                screen.

    void setStock(int);             // PRECONDITION:  None.
                                    // POSTCONDITION: Sets stock quantity using
                                    //                int input.

    void updateStock(int);          // PRECONDTIION:  None.
                                    // POSTCONDITION: Updates stock quantity
                                    //                using int input.

    int getStock() const;           // PRECONDTIION:  None.
                                    // POSTCONDITION: Returns quantity in stock
                                    //                as an int.

    // YEAR
    void printYear() const;         // PRECONDITION:  None.
                                    // POSTCONDITION: Prints year of publication
                                    //                to screen.

    void setYear(int);              // PRECONDITION:  None.
                                    // POSTCONDITION: Sets year of publication
                                    //                using int input.

    void updateYear(int);           // PRECONDITION:  None.
                                    // POSTCONDITION: Updates year of publication
                                    //                using int input.

    int getYear() const;            // PRECONDITION:  None.
                                    // POSTCONDITION: Returns year of publication
                                    //                as an int.

    bool compareYear(int);          // PRECONDITION:  None.
                                    // POSTCONDITION: Returns true if year passed
                                    //                as parameter matches target
                                    //                book's publication year.

    // CONSTRUCTORS
    //bookType(string, string, string, string, double, int, int, int, int); // DEFAULT COSNTRUCTOR WITH PARAMETERS
    bookType();                     // DEFAULT CONSTRUCTOR WITHOUT PARAMETERS

    // DESTRUCTOR
    //bookType::~bookType();

private:
    string title;
    string author[4];
    string publisher;
    string isbn;
    double price;
    int stock;
    int year;
    int num_authors;
};
//////////////////////////////////////////////////////////////////////////////
#endif