///////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 8 Project - Creating a circular linked list class
//
// NAME:    Mark Darling
// PURPOSE: Design a class to implement a sorted circular linked list. Include
//			the following operations:
//			1.) Initialize the list (to an empty state)
//			2.) Determine if the list is empty
//			3.) Destroy the list
//			4.) Print the list
//			5.) Find the length of the list.
//			6.) Search the list for a given item.
//			7.) Insert an item in the list.
//			8.) Delete an item from the list.
//			9.) Copy the list.
//
//			Write the definitions of the class circularLinkedList and its
//			member functions (Your may assume that the elemtns of the circular
//			linked list are in ascending order). Also, write a program to test
//			the operations of your circularLinkedList class.
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PREPROCESSOR DIRECTIVES ////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <cmath>            // abs()
#include <cstdlib>			// rand() , srand()
#include <ctime>			// time()
#include <iostream>
#include <limits>			// numeric_limits<streamsize>::max()
#include <random>			// for random number generator from StackOverflow
#include <string>			// string type
#include <sstream>          // cin.setstate(std::ios_base::failbit)
#include <vector>			// vector type

#include "FwdLinkedList.h"
//#include "circularLinkedList.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES ////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// MAIN PROGRAM BEGINS HERE ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
	// DEFINE OBJECTS
	FwdLinkedList fwdList;

	// BUILD LINKED LIST
	fwdList.appendNode(13);
	fwdList.appendNode(19);
	fwdList.appendNode(12);
	fwdList.appendNode(11);
	fwdList.appendNode(17);
	fwdList.appendNode(10);
	fwdList.appendNode(14);
	fwdList.appendNode(15);
	fwdList.appendNode(16);
	fwdList.appendNode(18);

	// DISPLAY LIST
	fwdList.displayList();

	// MAIN PROGRAM ENDS HERE
	return 0;
}


///////////////////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS ///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////