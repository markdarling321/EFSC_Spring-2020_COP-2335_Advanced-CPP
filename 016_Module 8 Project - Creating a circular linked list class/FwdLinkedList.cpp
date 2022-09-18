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

#include "FwdLinkedList.h"
#include <iostream>				// cout

using namespace std;

// DEFAULT CONSTRUCTOR
FwdLinkedList::FwdLinkedList()
{
	cout << " FwdLinkedList() DEFAULT CONSTRUCTOR\n";
	head = nullptr;
}

// DESTRUCTOR
FwdLinkedList::~FwdLinkedList()
{
	cout << " FwdLinkedList() DESTRUCTOR\n";
	ListNode* nodePtr;				// CURRENT NODE POINTER FOR LIST TRAVERSAL
	ListNode* nextNode;				// NEXT NODE POINTER FOR PLACE-KEEPING

	nodePtr = head;					// START TRAVERSAL FROM HEAD OF LIST

	while (nodePtr != nullptr)		// TRAVERSE LIST UNTIL END OF LIST
	{
		nextNode = nodePtr->next;	// POINT nextNode AT NEXT LINK AFTER nodePtr
		delete nodePtr;				// DELETE NODE nodePtr CURRENTLY POINTS TO
		nodePtr = nextNode;			// UPDATE nodePtr TO POINT TO NEXT NODE
	}
}

// LINKED LIST OPERATIONS
void FwdLinkedList::appendNode(int num)
{
	cout << " appendNode(int)\n";
	ListNode* newNode;					// CREATE NEW SELF-REFERENTIAL POINTER
	ListNode* nodePtr;					// POINTER FOR TRAVERSING LIST

	// CREATE NEW NODE AND UPDATE VALUE WITH DATA
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	// IF LIST IS EMPTY AND DOES NOT CONTAIN ANY NODES
	// MAKE newNode THE FIRST NODE
	if (!head)
	{
		head = newNode;
	}
	else	// IF LIST IS NOT EMPTY, INSERT newNode AT END OF LIST
	{
		nodePtr = head;					// INITIALIZE nodePtr TO HEAD OF LIST

		while (nodePtr->next)			// FIND LAST NODE IN LIST
		{
			nodePtr = nodePtr->next;	// TRAVERSE LIST
		}

		nodePtr->next = newNode;		// INSERT newNode AT END OF LIST
	}
}

void FwdLinkedList::insertNode(int num)
{
	cout << " insertNode(int)\n";
	ListNode* newNode;					// DEFINE NEW NODE OBJECT & TYPE
	ListNode* nodePtr;					// DEFINE POINTER FOR LIST TRAVERSAL
	ListNode* previousNode = nullptr;	// DEFINE POINTER TO PREVIOUS NODE

	newNode = new ListNode;				// CREATE NEW NODE
	newNode->value = num;				// STORE DATA IN NEW NODE

	if (!head)							// IF NO LIST EXISTS YET...
	{
		head = newNode;					// MAKE newNode THE FIRST NODE IN LIST
		newNode->next = nullptr;		// MAKE newNode'S LINK THE END OF LIST
	}
	else							// IF LIST ALREADY EXISTS, INSERT NEW NODE
	{
		nodePtr = head;						// POSITION CURRENT NODE POINTER
											// TO POINT TO HEAD OF LIST

		previousNode = nullptr;				// INITIALIZE previousNode

		// SKIP ALL NODES WHOSE VALUE IS LESS THAN num
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;			// TRAVERSE LIST FORWARD
			nodePtr = nodePtr->next;		// TRAVERSE LIST FORWARD
		}

		// IF NEW NODE TO BE INSERTED IS FIRST IN LIST,
		// INSERT IT BEFORE ALL OTHER NODES
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else		// IF NEW NODE TO BE INSERTED IS NOT FIRST IN LIST,
					// INSERT NEW NODE AFTER THE PREVIOUS NODE
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void FwdLinkedList::deleteNode(int num)
{
	cout << " deleteNode(int)\n";
	ListNode* nodePtr;				// CURRENT NODE POINTER FOR LIST TRAVERSAL

	ListNode* previousNode = nullptr;			// PREVIOUS NODE POINTER FOR
												// LIST TRAVERSAL/MODIFICATION

	if (!head)						// IF LIST IS EMPTY...
	{
		return;						// DO NOTHING
	}
	if (head->value == num)			// IF LIST IS NOT EMPTY AND THE HEAD
									// IS THE VALUE TO BE DELETED...
	{
		nodePtr = head->next;	   // POINT CURRENT NODE POINTER AT HEAD'S LINK
		delete head;			   // DELETE HEAD
		head = nodePtr;			   // MAKE CURRENT NODE POINTER THE NEW HEAD
	}
	else	   // IF LIST NOT EMPTY AND VALUE TO BE DELETED IS NOT HEAD OF LIST
	{
		nodePtr = head;				// STARTING AT HEAD OF LIST...

		// WHILE NOT AT END OF LIST AND SEARCH VALUE HAS NOT YET BEEN FOUND...
		while (nodePtr != nullptr && nodePtr->value != num)	// TRAVERSE LIST
		{
			previousNode = nodePtr;			// UPDATE previousNode POINTER
			nodePtr = nodePtr->next;		// UPDATE CURRENT NODE POINTER
		}

		// IF nodePtr NOT AT END OF LIST, LINK PREVIOUS NODE
		// TO NODE AFTER nodePtr, THEN DELETE nodePtr
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;			// SKIP A LINK
			delete nodePtr;								// DELETE SKIPPED LINK
		}
	}
}

void FwdLinkedList::displayList() const
{
	cout << " displayList()\n";
	ListNode* nodePtr;					// POINTER FOR TRAVERSING LIST

	nodePtr = head;				// POSITION nodePtr TO POINT TO HEAD OF LIST

	while (nodePtr)				// WHILE nodePtr POINTS TO A NODE, TRAVERSE LIST
	{
		cout << " " << nodePtr->value << endl;	// DISPLAY VALUE IN CURRENT NODE
												// POINTED TO BY nodePtr
		nodePtr = nodePtr->next;				// MOVE TO NEXT NODE
	} // END OF LIST TRAVERSAL

} // END OF displayList()