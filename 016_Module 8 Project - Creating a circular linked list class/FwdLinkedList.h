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

#ifndef FWDLINKEDLIST_H
#define FWDLINKEDLIST_H

class FwdLinkedList
{

private:
	struct ListNode						// DECLARE SELF-REFERENTIAL DATA
										// STRUCTURE FOR LINKED LIST
	{
		int value;						// DATA TO BE STORED GOES HERE
		struct ListNode* next;			// POINTER TO NEXT NODE IN LINKED LIST
	};

	ListNode* head;						// POINTER TO HEAD OF LINKED LIST

public:
	FwdLinkedList();					// DEFAULT CONSTRUCTOR
	~FwdLinkedList();					// DESTRUCTOR

	// LINKED LIST OPERATIONS
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void displayList() const;
};
#endif