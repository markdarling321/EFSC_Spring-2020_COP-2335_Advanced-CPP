//////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 3 Project A - Making your ADT dynamic
// NAME:    Mark Darling
// PURPOSE: make our ADT dynamic by implementing dynamic arrays, adding a copy
//          constructor, adding a destructor, and overloading the assignment
//          operator
//
//////////////////////////////////////////////////////////////////////////////

// PRE-PROCESSOR DIRECTIVES //////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <array>
#include "bookType.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////

// CLASS MEMBER FUNCTION DEFINITIONS /////////////////////////////////////////
// BOOK TITLE
void bookType::printTitle() const               // prints title to screen
{
	cout << "\n TITLE: \t" << title;
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
			cout << "\n AUTHOR [" << (i + 1) << "]: \t" << author[i];
		}
		else
		{
			cout << "\n AUTHOR [" << (i + 1) << "]: \t" << author[i];
		}
	}
		/*
		if (i != (num_authors - 1))
		{
		    cout << "\n AUTHOR [" << (i + 1) << "]: \t" << author[i] << endl;
		}
		else
		{
		    cout << "\n AUTHOR [" << (i + 1) << "]: \t" << author[i];
		}
		*/
}
void bookType::setAuthor(string usrAuthor[], int n_authors)
{
	if (num_authors != n_authors)
	{
		delete[] author;
		author = nullptr;
		author = new string[n_authors];
	}
	num_authors = n_authors;
	for (int i = 0; i < n_authors; i++)
	{
		author[i] = usrAuthor[i];
	}
}
void bookType::updateAuthor(string usrAuthor[], int n_authors)
{
	if (num_authors != n_authors)
	{
		delete[] author;
		author = nullptr;
		author = new string[n_authors];
	}
	num_authors = n_authors;
	for (int i = 0; i < n_authors; i++)
	{
		author[i] = usrAuthor[i];
	}
}
string* bookType::getAuthor() const                  // returns author array containing authors of book as strings
{
	return author;
}
bool bookType::compareAuthor(string usrAuthor)      // returns true if authors match (first match)
{
	for (int i = 0; i < num_authors; i++)
	{
		if (usrAuthor == author[i])
			return true;
	}
	return false;
}
int bookType::getAuthorCount() const
{
	return num_authors;
}


// PUBLISHER
void bookType::printPublisher() const                // prints publisher to screen
{
	cout << "\n PUBLISHER: \t" << publisher;
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
	cout << "\n ISBN: \t\t" << isbn;
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
	cout << "\n PRICE:       $ " << price;
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
	cout << "\n STOCK: \t" << stock;
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
	cout << "\n YEAR: \t\t" << year;
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

// OVERLOADED ASSIGNMENT OPERATOR
const bookType& bookType::operator=(const bookType& bookObj)
{
	// local declaration, if any

	if (this != &bookObj)	// avoid self-assignment
	{
		// algorithm to copy bookObj into this object
		delete[] author;						// destroy existing author array
		title = bookObj.title;					// overwrite current with object to be copied
		publisher = bookObj.publisher;			// overwrite current with object to be copied
		isbn = bookObj.isbn;					// overwrite current with object to be copied
		price = bookObj.price;					// overwrite current with object to be copied
		stock = bookObj.stock;					// overwrite current with object to be copied
		year = bookObj.year;					// overwrite current with object to be copied
		num_authors = bookObj.num_authors;		// overwrite current with object to be copied

		author = new string[num_authors];		// dynamically allocate a new author array
		for (int i = 0; i < num_authors; i++)	// copy authors into new array
		{
			author[i] = bookObj.author[i];
		}
	}

	// return the object assigned
	return *this;
}

//  CONSTRUCTORS

// ~~~~~~~~~~~~~~~~~~~~  OLD FUNCTION CODE  ~~~~~~~~~~~~~~~~~~~~
//bookType::bookType(string title, string author[], string publisher, string isbn, double price, int stock, int year, int num_authors, int index)
//{
//    setTitle(title);
//    for (int i = 0; i < num_authors; i++)
//    {
//        setAuthor(author[i]);
//    }
//    setPublisher(publisher);
//    setISBN(isbn);
//    setPrice(price);
//    setStock(stock);
//    setYear(year);
//}
// ~~~~~~~~~~~~~~~~~~~~  OLD FUNCTION CODE  ~~~~~~~~~~~~~~~~~~~~


bookType::bookType()                // DEFAULT CONSTRUCTOR (without parameters)
{
	title = "";
	author = new string[1]{""};     // the default case is 1 author of value ""
	
	// ~~~~~~~~~~~~~~~~~~~~  OLD FUNCTION CODE  ~~~~~~~~~~~~~~~~~~~~
	//for (int i = 0; i < 4; i++)
	//{
	//    author[i] = "";
	//}
	// ~~~~~~~~~~~~~~~~~~~~  OLD FUNCTION CODE  ~~~~~~~~~~~~~~~~~~~~

	publisher = "";
	isbn = "";
	price = 0.00;
	stock = 0;
	year = 0;
	num_authors = 1;
}


// DESTRUCTOR
bookType::~bookType()
{
	title = "";
	delete[] author;
	*author = nullptr;              //  THE BOOK SAYS TO DO THIS FOR GOOD MEASURE IN ORDER TO
									//  PREVENT DANGLING POINTERS AFTER DEALLOCATION
	
	// ~~~~~~~~~~~~~~~~~~~~  OLD FUNCTION CODE  ~~~~~~~~~~~~~~~~~~~~
	//for (int i = 0; i < 4; i++)
	//{
	//    author[i] = "";
	//}
	// ~~~~~~~~~~~~~~~~~~~~  OLD FUNCTION CODE  ~~~~~~~~~~~~~~~~~~~~
	
	publisher = "";
	isbn = "";
	price = 0.00;
	stock = 0;
	year = 0;
	num_authors = 0;
}
