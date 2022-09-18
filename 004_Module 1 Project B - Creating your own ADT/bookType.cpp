//////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 1 Project B - Creating Your Own ADT
// NAME:    Mark Darling
// PURPOSE: create our own abstract data type
//
//////////////////////////////////////////////////////////////////////////////

// PRE-PROCESSOR DIRECTIVES //////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "bookType.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////

// CLASS MEMBER FUNCTION DEFINITIONS /////////////////////////////////////////
// BOOK TITLE
void bookType::printTitle() const               // prints title to screen
{
    cout << "TITLE: \t\t" << title;
}
void bookType::setTitle(string usrTitle)
{
    title = usrTitle;
}
void bookType::updateTitle(string usrTitle)
{
    title = usrTitle;
}
string bookType::getTitle() const               // returns title of book as a string
{
    return title;
}
bool bookType::compareTitle(string usrTitle)    // returns true if book titles match
{
    if (usrTitle == title)
        return true;
    else
        return false;
}


// AUTHOR
void bookType::printAuthor() const                  // prints author to screen
{
    for (int i = 0; i < num_authors; i++)
    {
        if (i != (num_authors - 1))
        {
            cout << "AUTHOR [" << (i + 1) << "]: \t" << author[i] << endl;
        }
        else
        {
            cout << "AUTHOR [" << (i + 1) << "]: \t" << author[i];
        }
    }
}
void bookType::setAuthor(string usrAuthor[], int n_authors)
{
    num_authors = n_authors;
    for (int i = 0; i < n_authors; i++)
    {
        author[i] = usrAuthor[i];
    }
}
void bookType::updateAuthor(string usrAuthor[], int n_authors)
{
    num_authors = n_authors;
    for (int i = 0; i < n_authors; i++)
    {
        author[i] = usrAuthor[i];
    }
}
string bookType::getAuthor() const                  // returns author array containing authors of book as strings
{
    return *author;
}
bool bookType::compareAuthor(string usrAuthor)      // returns true if authors match
{
    for (int i = 0; i < num_authors; i++)
    {
        if (usrAuthor == author[i])
            return true;
    }
    return false;
}


// PUBLISHER
void bookType::printPublisher() const                // prints publisher to screen
{
    cout << "PUBLISHER: \t" << publisher;
}
void bookType::setPublisher(string usrPublisher)
{
    publisher = usrPublisher;
}
void bookType::updatePublisher(string usrPublisher)
{
    publisher = usrPublisher;
}
string bookType::getPublisher() const                // returns publisher of book as a string
{
    return publisher;
}
bool bookType::comparePublisher(string usrPublisher) // returns true if publishers match
{
    if (usrPublisher == publisher)
        return true;
    else
        return false;
}


// ISBN
void bookType::printISBN() const              // prints ISBN to screen
{
    cout << "ISBN: \t\t" << isbn;
}
void bookType::setISBN(string usrISBN)
{
    isbn = usrISBN;
}
void bookType::updateISBN(string usrISBN)
{
    isbn = usrISBN;
}
string bookType::getISBN() const              // returns ISBN of book as an int
{
    return isbn;
}
bool bookType::compareISBN(string usrISBN)    // returns true if ISBNs match
{
    if (usrISBN == isbn)
        return true;
    else
        return false;
}


// PRICE
void bookType::printPrice() const             // prints price to screen
{
    cout << "PRICE: \t\t$" << price;
}
void bookType::setPrice(double usrPrice)
{
    price = usrPrice;
}
void bookType::updatePrice(double usrPrice)
{
    price = usrPrice;
}
double bookType::getPrice() const             // returns price of book as a double
{
    return price;
}
bool bookType::comparePrice(double usrPrice)  // returns true if prices match
{
    if (usrPrice == price)
        return true;
    else
        return false;
}


// STOCK
void bookType::printStock() const        // prints stock quantity to screen
{
    cout << "STOCK: \t\t" << stock;
}
void bookType::setStock(int usrStock)
{
    stock = usrStock;
}
void bookType::updateStock(int usrStock)
{
    stock = usrStock;
}
int bookType::getStock() const           // returns quantity in stock as an int
{
    return stock;
}


// YEAR
void bookType::printYear() const          // prints year of publication to screen
{
    cout << "YEAR: \t\t" << year;
}
void bookType::setYear(int usrYear)
{
    year = usrYear;
}
void bookType::updateYear(int usrYear)
{
    year = usrYear;
}
int bookType::getYear() const             // returs year of publication as an int
{
    return year;
}
bool bookType::compareYear(int usrYear)
{
    if (usrYear == year)
        return true;
    else
        return false;
}


//  CONSTRUCTORS
/*
bookType::bookType(string title, string author[], string publisher, string isbn, double price, int stock, int year, int num_authors, int index)
{
    setTitle(title);
    for (int i = 0; i < num_authors; i++)
    {
        setAuthor(author[i]);
    }
    setPublisher(publisher);
    setISBN(isbn);
    setPrice(price);
    setStock(stock);
    setYear(year);
}
*/
bookType::bookType()
{
    title = "";
    for (int i = 0; i < 4; i++)
    {
        author[i] = "";
    }
    publisher = "";
    isbn = "";
    price = 0.00;
    stock = 0;
    year = 0;
    num_authors = 0;
}


// DESTRUCTOR
/*
bookType::~bookType()
{
    title = "";
    for (int i = 0; i < 4; i++)
    {
        author[i] = "";
    }
    publisher = "";
    isbn = "";
    price = 0.00;
    stock = 0;
    year = 0;
    num_authors = 0;
}
*/