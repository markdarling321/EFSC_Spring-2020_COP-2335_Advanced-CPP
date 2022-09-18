//////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 3 Project A - Making your ADT dynamic
// NAME:    Mark Darling
// PURPOSE: make our ADT dynamic by implementing dynamic arrays, adding a copy
//          constructor, adding a destructor, and overloading the assignment
//          operator
//
//////////////////////////////////////////////////////////////////////////////

// PREPROCESSOR DIRECTIVES////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <iomanip>
#include "bookType.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////

// BEGIN MAIN LINEAR DRIVER PROGRAM //////////////////////////////////////////
int main()
{
	// DEFINE VARIABLES LOCAL TO main()
	string usrTitle, usrPublisher, usrISBN, searchString;
	string* usrAuthor;
	int numAuthors, usrStock, usrYear, usrIndex, searchInt, usrIndexCopyFrom, usrIndexOverwriteTo;
	double usrPrice, searchDouble;
	bool result = false;

	// DETERMINE SIZE OF LIBRARY AT RUNTIME BY ASKING USER
	cout << "\n How many books can your library store?\n";
	int numBooks;
	cin >> numBooks;

	// CREATE DYNAMICALLY ALLOCATED ARRAY OF NEW OBJECTS BASED ON USER INPUT
	cout << "\n Making room to store " << numBooks << " book(s) in our new library...\n";
	bookType *myBook = new bookType[numBooks];	// this initializes each object using the
												// default constructor
	cout << "\n SUCCESS!\n";

	// STORE INFORMATION OF EACH BOOK BY TAKING IN THE INFO FROM USER
	// THEN STORING IT TO THE CLASS OBJECTS' ARRAY COMPONENTS
	for (int i = 0; i < numBooks; i++)
	{
		cout << "\n ################    ENTER INFO FOR BOOK # " << (i + 1) << " :    ################\n";
		cout << " #################################################################\n";
		cout << " TITLE:              ";
		cin >> usrTitle;
		cout << " How many authors? : ";
		cin >> numAuthors;
		usrAuthor = new string[numAuthors];     // dynamically allocate an array of strings
		for (int i = 0; i < numAuthors; i++)
		{
			cout << " AUTHOR [" << (i + 1) << "]:         ";
			cin >> usrAuthor[i];
		}
		cout << " PUBLISHER:          ";
		cin >> usrPublisher;
		cout << " ISBN:               ";
		cin >> usrISBN;
		cout << " PRICE:            $ ";
		cin >> usrPrice;
		cout << " STOCK:              ";
		cin >> usrStock;
		cout << " YEAR:               ";
		cin >> usrYear;
		
		// SET CLASS OBJECT ARRAY[i] VALUES EQUAL TO USER INPUT
		myBook[i].setTitle(usrTitle);
		//cout << "TITLE SET!\n";
		myBook[i].setAuthor(usrAuthor, numAuthors);
		//cout << "AUTHOR SET!\n";
		myBook[i].setPublisher(usrPublisher);
		//cout << "PUBLISHER SET!\n";
		myBook[i].setISBN(usrISBN);
		//cout << "ISBN SET!\n";
		myBook[i].setPrice(usrPrice);
		//cout << "PRICE SET!\n";
		myBook[i].setStock(usrStock);
		//cout << "STOCK SET!\n";
		myBook[i].setYear(usrYear);
		//cout << "YEAR SET!\n";
	}
	cout << "\n SUCCESS! Our library is now stocked...\n";

	// PRINT BOOKS IN LIBRARY OUT TO THE SCREEN
	cout << "\n Here are the books currently in our library...\n";
	for (int i = 0; i < numBooks; i++)
	{
		cout << "\n\n ~~~~~~~~~~~    BOOK # " << (i + 1) << " :    ~~~~~~~~~~~\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		myBook[i].printTitle();
		myBook[i].printAuthor();
		myBook[i].printPublisher();
		myBook[i].printISBN();
		myBook[i].printPrice();
		myBook[i].printStock();
		myBook[i].printYear();
	}

	// UPDATE A BOOK's INFO
	cout << "\n\n\n It looks like one of the books in the library needs to be updated...\n";
	cout << " Which book number needs to be updated? : ";
	cin >> usrIndex;

	cout << "\n Here is the info for BOOK # " << usrIndex << " BEFORE: \n";
	cout << "\n ~~~~~~~~~~~    BOOK # " << usrIndex << " :    ~~~~~~~~~~~\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// GET THE INFO FOR EACH PIECE OF BOOK INFORMATION
	string checkTitle = myBook[usrIndex - 1].getTitle();
	string* checkAuthor = myBook[usrIndex - 1].getAuthor();
	int authCount = myBook[usrIndex - 1].getAuthorCount();
	string checkPublisher = myBook[usrIndex - 1].getPublisher();
	string checkISBN = myBook[usrIndex - 1].getISBN();
	double checkPrice = myBook[usrIndex - 1].getPrice();
	int checkStock = myBook[usrIndex - 1].getStock();
	int checkYear = myBook[usrIndex - 1].getYear();

	// PRINT EACH PIECE OF INFO GOTTEN OUT TO THE SCREEN
	cout << "\n TITLE: \t" << checkTitle;
	for (int i = 0; i < authCount; i++)
	{
		cout << "\n AUTHOR [" << (i + 1) << "]: \t" << checkAuthor[i];
	}
	cout << "\n PUBLISHER: \t" << checkPublisher;
	cout << "\n ISBN: \t\t" << checkISBN;
	cout << "\n PRICE:       $ " << checkPrice;
	cout << "\n STOCK: \t" << checkStock;
	cout << "\n YEAR: \t\t" << checkYear;

	// UPDATE EACH PIECE OF INFO ACCORDINGLY
	cout << "\n\n Enter Book # " << usrIndex << " UPDATED INFORMATION: \n";
	cout << "\n TITLE:              ";
	cin >> usrTitle;
	cout << " How many authors? : ";
	cin >> numAuthors;
	usrAuthor = new string[numAuthors];     // dynamically allocate an array of strings
	for (int i = 0; i < numAuthors; i++)
	{
		cout << " AUTHOR [" << (i + 1) << "]:         ";
		cin >> usrAuthor[i];
	}
	cout << " PUBLISHER:          ";
	cin >> usrPublisher;
	cout << " ISBN:               ";
	cin >> usrISBN;
	cout << " PRICE:            $ ";
	cin >> usrPrice;
	cout << " STOCK:              ";
	cin >> usrStock;
	cout << " YEAR:               ";
	cin >> usrYear;

	// SET CLASS OBJECT ARRAY[i] VALUES EQUAL TO USER INPUT
	myBook[usrIndex - 1].setTitle(usrTitle);
	//cout << "TITLE SET!\n";
	myBook[usrIndex - 1].setAuthor(usrAuthor, numAuthors);
	//cout << "AUTHOR SET!\n";
	myBook[usrIndex - 1].setPublisher(usrPublisher);
	//cout << "PUBLISHER SET!\n";
	myBook[usrIndex - 1].setISBN(usrISBN);
	//cout << "ISBN SET!\n";
	myBook[usrIndex - 1].setPrice(usrPrice);
	//cout << "PRICE SET!\n";
	myBook[usrIndex - 1].setStock(usrStock);
	//cout << "STOCK SET!\n";
	myBook[usrIndex - 1].setYear(usrYear);
	//cout << "YEAR SET!\n";

	cout << "\n\n Here is the info for BOOK # " << usrIndex << " AFTER: \n";
	cout << "\n ~~~~~~~~~~~    BOOK # " << usrIndex << " :    ~~~~~~~~~~~\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// GET THE INFO FOR EACH PIECE OF BOOK INFORMATION
	checkTitle = myBook[usrIndex - 1].getTitle();
	checkAuthor = myBook[usrIndex - 1].getAuthor();
	authCount = myBook[usrIndex - 1].getAuthorCount();
	checkPublisher = myBook[usrIndex - 1].getPublisher();
	checkISBN = myBook[usrIndex - 1].getISBN();
	checkPrice = myBook[usrIndex - 1].getPrice();
	checkStock = myBook[usrIndex - 1].getStock();
	checkYear = myBook[usrIndex - 1].getYear();

	// PRINT EACH PIECE OF INFO GOTTEN OUT TO THE SCREEN
	cout << "\n TITLE: \t" << checkTitle;
	for (int i = 0; i < authCount; i++)
	{
		cout << "\n AUTHOR [" << (i + 1) << "]: \t" << checkAuthor[i];
	}
	cout << "\n PUBLISHER: \t" << checkPublisher;
	cout << "\n ISBN: \t\t" << checkISBN;
	cout << "\n PRICE:       $ " << checkPrice;
	cout << "\n STOCK: \t" << checkStock;
	cout << "\n YEAR: \t\t" << checkYear;

	// DEMONSTRATE THE COMPARE FUNCTIONS HERE
	// COMPARE TITLE
	result = false;
	cout << "\n\n Enter a TITLE you would like to search for: ";
	cin >> searchString;
	cout << " SEARCHING NOW...\n";
	for (int i = 0; i < numBooks; i++)
	{
		if (myBook[i].compareTitle(searchString) == true)
		{
			result = true;
			//cout << " RESULT: TITLE FOUND!\n";
		}
		//else if (myBook[i].compareTitle(searchString) == false)
		//{
		//	cout << " RESULT: TITLE NOT FOUND!\n";
		//}
	}
	if (result == true)
		cout << " RESULT: TITLE FOUND!\n";
	else
		cout << " RESULT: TITLE NOT FOUND!\n";
	

	// COMPARE AUTHOR
	result = false;
	cout << "\n Enter an AUTHOR you would like to search for: ";
	cin >> searchString;
	cout << " SEARCHING NOW...\n";
	for (int i = 0; i < numBooks; i++)
	{
		if (myBook[i].compareAuthor(searchString) == true)
		{
			result = true;
			//cout << " RESULT: AUTHOR FOUND!\n";
		}
		//else if (myBook[i].compareAuthor(searchString) == false)
		//{
		//	cout << " RESULT: AUTHOR NOT FOUND!\n";
		//}
	}
	if (result == true)
		cout << " RESULT: AUTHOR FOUND!\n";
	else
		cout << " RESULT: AUTHOR NOT FOUND!\n";


	// COMPARE PUBLISHER
	result = false;
	cout << "\n Enter a PUBLISHER you would like to search for: ";
	cin >> searchString;
	cout << " SEARCHING NOW...\n";
	for (int i = 0; i < numBooks; i++)
	{
		if (myBook[i].comparePublisher(searchString) == true)
		{
			result = true;
			//cout << " RESULT: PUBLISHER FOUND!\n";
		}
		//else if (myBook[i].comparePublisher(searchString) == false)
		//{
		//	cout << " RESULT: PUBLISHER NOT FOUND!\n";
		//}
	}
	if (result == true)
		cout << " RESULT: PUBLISHER FOUND!\n";
	else
		cout << " RESULT: PUBLISHER NOT FOUND!\n";


	// COMPARE ISBN
	result = false;
	cout << "\n Enter an ISBN you would like to search for: ";
	cin >> searchString;
	cout << " SEARCHING NOW...\n";
	for (int i = 0; i < numBooks; i++)
	{
		if (myBook[i].compareISBN(searchString) == true)
		{
			result = true;
			//cout << " RESULT: ISBN FOUND!\n";
		}
		//else if (myBook[i].compareISBN(searchString) == false)
		//{
		//	cout << " RESULT: ISBN NOT FOUND!\n";
		//}
	}
	if (result == true)
		cout << " RESULT: ISBN FOUND!\n";
	else
		cout << " RESULT: ISBN NOT FOUND!\n";


	// COMPARE PRICE
	result = false;
	cout << "\n Enter a PRICE you would like to search for: ";
	cin >> searchDouble;
	cout << " SEARCHING NOW...\n";
	for (int i = 0; i < numBooks; i++)
	{
		if (myBook[i].comparePrice(searchDouble) == true)
		{
			result = true;
			//cout << " RESULT: PRICE FOUND!\n";
		}
		//else if (myBook[i].comparePrice(searchDouble) == false)
		//{
		//	cout << " RESULT: PRICE NOT FOUND!\n";
		//}
	}
	if (result == true)
		cout << " RESULT: PRICE FOUND!\n";
	else
		cout << " RESULT: PRICE NOT FOUND!\n";

	// COMPARE STOCK (not implemented - doesn't really make sense)
	//result = false;
	//cout << "\n Enter a STOCK AMOUNT you would like to search for: ";
	//cin >> searchString;
	//cout << " SEARCHING NOW...\n";
	//for (int i = 0; i < numBooks; i++)
	//{
	//	if (myBook[i].compareStock(searchString) == true)
	//	{
	//		result = true;
	//		cout << " RESULT: STOCK AMOUNT FOUND!\n";
	//	}
	//	else if (myBook[i].compareStock(searchString) == false)
	//	{
	//		cout << " RESULT: STOCK AMOUNT NOT FOUND!\n";
	//	}
	//}
	//if (result == true)
	//	cout << " RESULT: STOCK AMOUNT FOUND!\n";
	//else
	//	cout << " RESULT: STOCK AMOUNT NOT FOUND!\n";


	// COMPARE YEAR
	result = false;
	cout << "\n Enter a YEAR you would like to search for: ";
	cin >> searchInt;
	cout << " SEARCHING NOW...\n";
	for (int i = 0; i < numBooks; i++)
	{
		if (myBook[i].compareYear(searchInt) == true)
		{
			result = true;
			//cout << " RESULT: YEAR FOUND!\n";
		}
		//else if (myBook[i].compareYear(searchInt) == false)
		//{
		//	cout << " RESULT: YEAR NOT FOUND!\n";
		//}
	}
	if (result == true)
		cout << " RESULT: YEAR FOUND!\n";
	else
		cout << " RESULT: YEAR NOT FOUND!\n";

	// DEMONSTRATE OVERLOADED ASSIGNMENT OPERATOR
	cout << "\n\n Let's use our overloaded assignment operator to copy one book's info\n to another...\n";
	cout << "\n Which book's info would you like to copy?\n";
	cout << " ENTER BOOK # TO COPY FROM: ";
	cin >> usrIndexCopyFrom;
	cout << " Which BOOK # would you like to overwrite?\n";
	cout << " ENTER BOOK # TO OVERWRITE TO: ";
	cin >> usrIndexOverwriteTo;
	cout << " Copying BOOK # " << usrIndexCopyFrom << " to BOOK # " << usrIndexOverwriteTo << " ...\n";
	myBook[usrIndexOverwriteTo - 1] = myBook[usrIndexCopyFrom - 1];
	cout << " COPY SUCCESSFUL!\n\n";
	
	// PRINT BOOKS IN LIBRARY OUT TO THE SCREEN
	cout << "\n Here are the books currently in our library...\n";
	for (int i = 0; i < numBooks; i++)
	{
		cout << "\n\n ~~~~~~~~~~~    BOOK # " << (i + 1) << " :    ~~~~~~~~~~~\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		myBook[i].printTitle();
		myBook[i].printAuthor();
		myBook[i].printPublisher();
		myBook[i].printISBN();
		myBook[i].printPrice();
		myBook[i].printStock();
		myBook[i].printYear();
	}

	// FREE DYNAMICALLY ALLOCATED MEMORY USED IN MAIN BEFORE TERMINATING PROGRAM
	delete[] usrAuthor;
	*usrAuthor = nullptr;
	cout << endl << endl;
	return 0;
} ////////////////////////////////////////////////////////////////////////////
