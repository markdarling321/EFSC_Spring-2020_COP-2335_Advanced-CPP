//////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 1 Project B - Creating Your Own ADT
// NAME:    Mark Darling
// PURPOSE: create our own abstract data type
//
//////////////////////////////////////////////////////////////////////////////

// PREPROCESSOR DIRECTIVES////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <iomanip>
#include "bookType.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////

// MAIN PROGRAM FUNCTION PROTOTYPES //////////////////////////////////////////
void mainMenu(const int MAX_BOOKS, bookType myBook[]);
int booksInLibrary(const int MAX_BOOKS, bookType myBook[]);
int searchBook(const int MAX_BOOKS, bookType myBook[]); // returns index of book
void checkInBook(const int MAX_BOOKS, bookType myBook[]);
void checkOutBook(const int MAX_BOOKS, bookType myBook[]);
void updateBookInfo(const int MAX_BOOKS, bookType myBook[]);
void displayBookInfo(const int MAX_BOOKS, bookType myBook[], int index);
//////////////////////////////////////////////////////////////////////////////


// BEGIN MAIN PROGRAM ////////////////////////////////////////////////////////
int main()
{
    // DEFINE GLOBAL CONSTANTS
    const int MAX_BOOKS = 100, MAX_AUTHORS = 4;

    // DEFINE VARIABLES
    string title, author[4], publisher, isbn;
    double price;
    int usr_input, stock, year, num_authors = 0;

    // DEFINE CLASS OBJECTS
    bookType myBook[MAX_BOOKS];               // creates an array of 100 empty books

    // TEST CLASS MEMBER FUNCTIONS HERE
    mainMenu(MAX_BOOKS, myBook);



    return 0;
} ////////////////////////////////////////////////////////////////////////////


// MAIN PROGRAM FUNCTIONS ////////////////////////////////////////////////////
void mainMenu(const int MAX_BOOKS, bookType myBook[])
{
    // DEFINE VARIABLES LOCAL TO THIS FUNCTION
    const int NUM_CHOICES = 6;
    int usrInput = 0;

    // CREATE MENU AND WAIT FOR VALID INPUT FROM USER
    do
    {
        cout << endl;
        cout << "*********************************************************\n";
        cout << "*\tWelcome to Mark Darling's Library!              *\n";
        cout << "*\tWe can store up to " << MAX_BOOKS << " books.\t                *\n";
        cout << "*********************************************************\n";

        cout << "Please choose from the following options:" << endl;
        cout << "\t[1.] LIST NUMBER OF BOOKS IN LIBRARY\n";
        cout << "\t[2.] SEARCH FOR A BOOK\n";
        cout << "\t[3.] CHECK IN A BOOK\n";
        cout << "\t[4.] CHECK OUT A BOOK\n";
        cout << "\t[5.] UPDATE A BOOK\n";
        cout << "\t[6.] LEAVE LIBRARY\n\n";
        cout << "Enter your selection: ";
        cin >> usrInput;
        cout << "*********************************************************\n";
    } while (usrInput <= 0 || usrInput > NUM_CHOICES);

    // DIRECT PROGRAM TO CORRECT FUNCTION BASED ON USER INPUT
    if (usrInput == 1)
    {
        int booksInLib = booksInLibrary(MAX_BOOKS, myBook);
        cout << "We currently have " << booksInLib << " books to choose from.\n\n";
        mainMenu(MAX_BOOKS, myBook);
    }
    else if (usrInput == 2)
    {
        cin.ignore(128, '\n');
        searchBook(MAX_BOOKS, myBook);
        mainMenu(MAX_BOOKS, myBook);
    }
    else if (usrInput == 3)
    {
        cin.ignore(128, '\n');
        checkInBook(MAX_BOOKS, myBook);
        mainMenu(MAX_BOOKS, myBook);
    }
    else if (usrInput == 4)
    {
        cin.ignore(128, '\n');
        checkOutBook(MAX_BOOKS, myBook);
        mainMenu(MAX_BOOKS, myBook);
    }
    else if (usrInput == 5)
    {
        cin.ignore(128, '\n');
        updateBookInfo(MAX_BOOKS, myBook);
        mainMenu(MAX_BOOKS, myBook);
    }
    else if (usrInput == 6)
    {
        cin.ignore(128, '\n');
        cout << "Thank you for visiting my library. Goodbye!\n\n\n";
    }
    else
    {
        cin.ignore(128, '\n');
        cout << "ERROR:\t\tPlease make a valid selection.\n";
    }
}

int booksInLibrary(const int MAX_BOOKS, bookType myBook[])
{
    int booksAvailable = 0;

    for (int i = 0; i < MAX_BOOKS; i++)
    {
        if (myBook[i].getTitle() != "")
            booksAvailable++;
    }

    return booksAvailable;
}

int searchBook(const int MAX_BOOKS, bookType myBook[]) // returns first matching index
{                                                      // or -1 if no match found
    const int NUM_CHOICES = 8;
    int usrChoice = 0, searchYear;
    string findThisBook, searchTitle, searchAuthor, searchPublisher, searchISBN;
    bool searchResult = false;

    do
    {
        cout << "\n*********************************************************\n";
        cout << "*\tWhich field would you like to search by?\t*\n";
        cout << "*********************************************************\n";
        cout << "\t[1.] TITLE\n";
        cout << "\t[2.] AUTHOR\n";
        cout << "\t[3.] PUBLISHER\n";
        cout << "\t[4.] ISBN\n";
        cout << "\t[5.] YEAR\n";
        cout << "\t[6.] PRICE\n";
        cout << "\t[7.] STOCK\n";
        cout << "\t[8.] GO BACK TO PREVIOUS MENU\n\n";
        cout << "Enter your selection: ";
        cin >> usrChoice;
        cout << "*********************************************************\n";

        if (usrChoice == 1)         // SEARCH BY TITLE
        {
            cin.ignore(128, '\n');
            cout << "\n\nEnter a TITLE to search for: ";
            getline(cin, searchTitle);
            for (int i = 0; i < MAX_BOOKS; i++)
            {
                searchResult = myBook[i].compareTitle(searchTitle);
                if (searchResult == true)
                {
                    cout << "BOOK FOUND!\n";
                    cout << "A book containing the TITLE you are looking for is currently available to check out!\n";
                    displayBookInfo(MAX_BOOKS, myBook, i);
                    return i;
                    //break;
                }
            }
            if (searchResult == false)
            {
                cout << "BOOK NOT FOUND!\n";
                cout << "Sorry, we do not have any books containing the TITLE you are searching for available to check out.\n";
                return -1;
            }
        }
        else if (usrChoice == 2)    // SEARCH BY AUTHOR
        {
            cin.ignore(128, '\n');
            cout << "\n\nEnter an AUTHOR to search for: ";
            getline(cin, searchAuthor);
            for (int i = 0; i < MAX_BOOKS; i++)
            {
                searchResult = myBook[i].compareAuthor(searchAuthor);
                if (searchResult == true)
                {
                    cout << "AUTHOR FOUND!\n";
                    cout << "We have at least 1 book by the AUTHOR you are searching for currently available to check out!\n";
                    displayBookInfo(MAX_BOOKS, myBook, i);
                    return i;
                    //break;
                }
            }
            if (searchResult == false)
            {
                cout << "AUTHOR NOT FOUND!\n";
                cout << "Sorry, we do not have any books by the AUTHOR you are searching for available to check out.\n";
                return -1;
            }
        }
        else if (usrChoice == 3)    // SEARCH BY PUBLISHER
        {
            cin.ignore(128, '\n');
            cout << "\n\nEnter a PUBLISHER to search for: ";
            getline(cin, searchPublisher);
            for (int i = 0; i < MAX_BOOKS; i++)
            {
                searchResult = myBook[i].comparePublisher(searchPublisher);
                if (searchResult == true)
                {
                    cout << "PUBLISHER FOUND!\n";
                    cout << "We currently have at least 1 book by that PUBLISHER available to check out!\n";
                    displayBookInfo(MAX_BOOKS, myBook, i);
                    return i;
                    //break;
                }
            }
            if (searchResult == false)
            {
                cout << "PUBLISHER NOT FOUND!\n";
                cout << "Sorry, we do not have any books by the PUBLISHER you are searching for.\n";
                return -1;
            }
        }
        else if (usrChoice == 4)    // SEARCH BY ISBN
        {
            cin.ignore(128, '\n');
            cout << "\n\nEnter an ISBN to search for: ";
            getline(cin, searchISBN);
            for (int i = 0; i < MAX_BOOKS; i++)
            {
                searchResult = myBook[i].compareISBN(searchISBN);
                if (searchResult == true)
                {
                    cout << "ISBN FOUND!\n";
                    cout << "We currently have at least 1 book with the ISBN you searched for available to check out!\n";
                    displayBookInfo(MAX_BOOKS, myBook, i);
                    return i;
                    //break;
                }
            }
            if (searchResult == false)
            {
                cout << "ISBN NOT FOUND!\n";
                cout << "Sorry, we do not have any books with the ISBN you are searching for.\n";
                return -1;
            }
        }
        else if (usrChoice == 5)    // SEARCH BY YEAR
        {
            bool bookFound = false;

            cin.ignore(128, '\n');
            cout << "\n\nEnter a YEAR to search for: ";
            cin >> searchYear;

            for (int i = 0; i < MAX_BOOKS; i++)
            {
                searchResult = myBook[i].compareYear(searchYear);
                if (searchResult == true)
                {
                    cout << "MATCH FOUND!\n";
                    bookFound = true;
                    cout << "We currently have at least 1 book published in the YEAR you searched for available to check out!\n";
                    displayBookInfo(MAX_BOOKS, myBook, i);
                    return i;
                    //break;
                }
            }
            if (searchResult == false && bookFound == false)
            {
                cout << "NO MATCH FOUND!\n";
                cout << "Sorry, we do not have any books available that were published in the YEAR you searched for.\n";
                return -1;
            }
        }
        else if (usrChoice == 6)    // SEARCH BY STOCK
        {
            cin.ignore(128, '\n');
            cout << "Sorry, we have not finished setting this feature up yet.";
            return -1;
        }
        else if (usrChoice == 7)    // SEARCH BY PRICE
        {
            cin.ignore(128, '\n');
            cout << "Sorry, we have not finished setting this feature up yet.";
            return -1;
        }
        else if (usrChoice == 8)    // GO BACK
        {
            cin.ignore(128, '\n');
            cout << "Taking you back to previous menu...\n";
        }
        else                        // ERROR
        {
            cin.ignore(128, '\n');
            cout << "ERROR:\t\tPlease make a valid selection.\n";
        }
    } while (usrChoice <= 0 || usrChoice > NUM_CHOICES);
    cout << endl;
}

void checkInBook(const int MAX_BOOKS, bookType myBook[])
{
    // DEFINE CONSTANTS LOCAL TO THIS FUNCTION
    const int MAX_AUTHORS = 4;

    // DEFINE VARIABLES LOCAL TO THIS FUNCTION
    string title, author[MAX_AUTHORS], publisher, isbn;
    double price;
    int stock, year, num_authors, booksAvailable;

    // BEGIN CHECK-IN PROCESS WITH USER
    cout << endl;
    cout << "Lets check in a book...\n\n";
    cout << "TITLE: \t\t\t";
    getline(cin, title);
    do
    {
        cout << "NUMBER OF AUTHORS: \t";
        cin >> num_authors;
        cin.ignore(128, '\n');

        if (num_authors == 1)
        {
            cout << "AUTHOR: \t\t";
            getline(cin, author[0]);
        }
        else if (num_authors > 1 && num_authors <= MAX_AUTHORS)
        {
            for (int i = 0; i < num_authors; i++)
            {
                cout << "AUTHOR[" << (i + 1) << "] :  \t\t";
                getline(cin, author[i]);
            }
        }
        else if (num_authors > MAX_AUTHORS)
        {
            cout << "Sorry, we can only store up to " << MAX_AUTHORS << " authors per book.\n";
        }
        else
        {
            cout << "ERROR: \t\t\tPlease enter a valid number of authors.\n";
        }
    } while (num_authors <= 0 || num_authors > MAX_AUTHORS);


    cout << "PUBLISHER: \t\t";
    getline(cin, publisher);
    cout << "ISBN: \t\t\t";
    getline(cin, isbn);
    cout << "PRICE: \t\t\t$";
    cin >> price;
    cout << "QTY IN STOCK: \t\t";
    cin >> stock;
    cout << "YEAR PUBLISHED: \t";
    cin >> year;

    booksAvailable = booksInLibrary(MAX_BOOKS, myBook);

    myBook[booksAvailable].setTitle(title);
    myBook[booksAvailable].setAuthor(author, num_authors);
    myBook[booksAvailable].setPublisher(publisher);
    myBook[booksAvailable].setISBN(isbn);
    myBook[booksAvailable].setPrice(price);
    myBook[booksAvailable].setStock(stock);
    myBook[booksAvailable].setYear(year);

    cout << "\nFINISHED CHECKING BOOK IN!\n\n";
}

void checkOutBook(const int MAX_BOOKS, bookType myBook[])
{
    int targetBook = -1;

    //cout << "We are not currently lending books, sorry!\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "~~~~~~~~~~     CHECK OUT A BOOK     ~~~~~~~~~~\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    targetBook = searchBook(MAX_BOOKS, myBook); // retrieve target book's index

    string title = myBook[targetBook].getTitle();
    string author = myBook[targetBook].getAuthor();
    string publisher = myBook[targetBook].getPublisher();
    string ISBN = myBook[targetBook].getISBN();
    double price = myBook[targetBook].getPrice();
    int stock = myBook[targetBook].getStock();
    int year = myBook[targetBook].getYear();

    cout << "TITLE:     " << title << endl;
    cout << "AUTHOR(S): " << author << endl;    // I know this is not correct for multiple authors
    cout << "PUBLISHER: " << publisher << endl;
    cout << "ISBN:      " << ISBN<< endl;
    cout << "PRICE:     " << price << endl;
    cout << "STOCK:     " << stock << endl;
    cout << "YEAR:      " << year << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "~~~~~~~~~~     CHECK OUT A BOOK     ~~~~~~~~~~\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    // ADD CODE TO FINISH CHECKOUT PROCESS
}

void updateBookInfo(const int MAX_BOOKS, bookType myBook[])
{
    int targetBook = -1; // value for storing library index of target book

    //cout << "UPDATE BOOK INFO FUNCTION GOES HERE.\n";
    cout << "Which book's info needs to be updated?\n";
    targetBook = searchBook(MAX_BOOKS, myBook); // index i will be set to index if target book found
    if (targetBook == -1)
    {
        cout << "SORRY, WE CANNOT FIND THAT BOOK IN THE LIBRARY TO UPDATE IT.\n";
    }
    else if (targetBook >= 0 && targetBook < MAX_BOOKS)
    {
        cout << "PLEASE ENTER THE CORRECTED INFORMATION BELOW...\n\n";

        // DEFINE CONSTANTS LOCAL TO THIS FUNCTION
        const int MAX_AUTHORS = 4;

        // DEFINE VARIABLES LOCAL TO THIS FUNCTION
        string title, author[MAX_AUTHORS], publisher, isbn;
        double price;
        int stock, year, num_authors, booksAvailable;

        // BEGIN BOOK INFO UPDATE PROCESS WITH USER
        cout << endl;
        cout << "Lets update this book's info...\n\n";
        cout << "TITLE: \t\t\t";
        getline(cin, title);
        do
        {
            cout << "NUMBER OF AUTHORS: \t";
            cin >> num_authors;
            cin.ignore(128, '\n');

            if (num_authors == 1)
            {
                cout << "AUTHOR: \t\t";
                getline(cin, author[0]);
            }
            else if (num_authors > 1 && num_authors <= MAX_AUTHORS)
            {
                for (int i = 0; i < num_authors; i++)
                {
                    cout << "AUTHOR[" << (i + 1) << "] :  \t\t";
                    getline(cin, author[i]);
                }
            }
            else if (num_authors > MAX_AUTHORS)
            {
                cout << "Sorry, we can only store up to " << MAX_AUTHORS << " authors per book.\n";
            }
            else
            {
                cout << "ERROR: \t\t\tPlease enter a valid number of authors.\n";
            }
        } while (num_authors <= 0 || num_authors > MAX_AUTHORS);


        cout << "PUBLISHER: \t\t";
        getline(cin, publisher);
        cout << "ISBN: \t\t\t";
        getline(cin, isbn);
        cout << "PRICE: \t\t\t$";
        cin >> price;
        cout << "QTY IN STOCK: \t\t";
        cin >> stock;
        cout << "YEAR PUBLISHED: \t";
        cin >> year;

        //booksAvailable = booksInLibrary(MAX_BOOKS, myBook);

        myBook[targetBook].updateTitle(title);
        myBook[targetBook].updateAuthor(author, num_authors);
        myBook[targetBook].updatePublisher(publisher);
        myBook[targetBook].updateISBN(isbn);
        myBook[targetBook].updatePrice(price);
        myBook[targetBook].updateStock(stock);
        myBook[targetBook].updateYear(year);

        cout << "\nFINISHED UPDATING BOOK INFO!\n\n";
    }
    else
    {
        cout << "ERROR :  AN UNKOWN ERROR HAS OCCURRED...\n";
    }
}

void displayBookInfo(const int MAX_BOOKS, bookType myBook[], int index)
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "~~~~~~~~~~   DISPLAYING BOOK INFO   ~~~~~~~~~~\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    myBook[index].printTitle();
    cout << endl;
    myBook[index].printAuthor();
    cout << endl;
    myBook[index].printPublisher();
    cout << endl;
    myBook[index].printISBN();
    cout << endl;
    myBook[index].printPrice();
    cout << endl;
    myBook[index].printStock();
    cout << endl;
    myBook[index].printYear();
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "~~~~~~~~~~   DISPLAYING BOOK INFO   ~~~~~~~~~~\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
//////////////////////////////////////////////////////////////////////////////