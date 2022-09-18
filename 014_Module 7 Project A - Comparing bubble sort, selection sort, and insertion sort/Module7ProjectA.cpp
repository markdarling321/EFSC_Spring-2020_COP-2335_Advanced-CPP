///////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 7 Project A - Comparing bubble sort, selection
//                                        sort, and insertion sort
// NAME:    Mark Darling
// PURPOSE: Write a program that creates three identical vectors of integers:
//			list1, list2, and list3 of 5,000 elements each. The program then
//			sorts list1 using bubble sort, list2 using selection sort, and
//			list3 using insertion sort and outputs the number of comparisons
//			and item assignments made by each sorting algorithm.
//			
//			Populate a list using random numbers between 1 and 2000 then copy
//			the list values into the other lists.
//
//			When your program counts each item assignment make sure to include
//			assignments to variables that store the values temporarily. For
//			example, the following counts as 3 assignments:
//
//			temp = list[index];
//			list[index] = list[index + 1];
//			list[index + 1] = temp;
//
// NOTE:	FOLLOWING THE ABOVE INSTRUCTIONS LEADS TO BUBBLE SORT'S ASSIGNMENT
//			COUNT BEING ABOUT 3x HIGHER THAN OUR BOOK'S TEXT SUGGESTS ON
//			PAGE 1075, ALTHOUGH IT CAN BE REDUCED IF WE IMPLEMENT THE
//			EFFICIENCY IMPROVEMENT SUGGESTED IN THE TEXT
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PREPROCESSOR DIRECTIVES ////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>			// string type
#include <limits>			// numeric_limits<streamsize>::max()
#include <sstream>          // cin.setstate(std::ios_base::failbit)
#include <cmath>            // abs()
#include <vector>			// vector type
#include <cstdlib>			// rand() , srand()
#include <ctime>			// time()
#include <random>			// for random number generator from StackOverflow

using namespace std;


///////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES ////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//int assCount();
//int compCount();
void printLists(const vector<int>& list1, const vector<int>& list2, const vector<int>& list3, const vector<int>& list4);


///////////////////////////////////////////////////////////////////////////////
// MAIN PROGRAM BEGINS HERE ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
	// DEFINE VARIABLES
	int bubbleAssCount = 0, bubbleCompCount = 0;	// BUBBLE COUNTERS
	int selectAssCount = 0, selectCompCount = 0;	// SELECTION COUNTERS
	int insertAssCount = 0, insertCompCount = 0;	// INSERTION COUNTERS
	int i, index, iteration, randNum, temp, smallestIndex, location, firstOutOfOrder;
	bool notEqual = false;

	// DEFINE DYNAMIC LISTS VIA VECTORS
	vector<int> list1;	// BUBBLE SORT
	vector<int> list2;	// SELECTION SORT
	vector<int> list3;	// INSERTION SORT
	vector<int> list4;	// CONTROL LIST

	// FILL A VECTOR WITH 5000 RANDOM INTEGERS
	for (i = 0; i < 1000; i++)
	{
		///////////////////////////////////////////////////////////////////////
		// FROM GADDIS' BOOK (does not work well) /////////////////////////////
		///////////////////////////////////////////////////////////////////////
		//// GET THE SYSTEM TIME
		//unsigned seed = time(0);
		//
		// SEED THE RANDOM NUMBER GENERATOR
		//srand(seed);
		//
		//// DEFINE RANGE OF RANDOM NUMBER GENERATOR
		//const int MIN_VALUE = 1;
		//const int MAX_VALUE = 2000;
		//
		//// GENERATE RANDOM NUMBER TO BE INSERTED INTO OUR LISTS FOR SORTING
		//randNum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		//
		//list1.push_back(randNum);	// FILL BUBBLE LIST WITH RANDOM NUMBER
		//
		//list2.push_back(randNum);	// FILL SELECTION LIST WITH RANDOM NUMBER
		//
		//list3.push_back(randNum);	// FILL INSERTION LIST WITH RANDOM NUMBER
		///////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////
		// FROM STACK OVERFLOW ////////////////////////////////////////////////
		// https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
		///////////////////////////////////////////////////////////////////////
		// ESTABLISH RANDOM NUMBER GENERATOR WITH OUTPUT IN RANGE: [1,2000]
		std::random_device dev;
		std::mt19937 randomNumGen(dev());
		std::uniform_int_distribution<std::mt19937::result_type> range(1, 2000);
		// GENERATE RANDOM NUMBER USING GENERATOR
		randNum = range(randomNumGen);

		// FILL BUBBLE LIST WITH RANDOM NUMBER
		list1.push_back(randNum);

		// FILL SELECTION LIST WITH RANDOM NUMBER
		list2.push_back(randNum);

		// FILL INSERTION LIST WITH RANDOM NUMBER
		list3.push_back(randNum);

		// FILL CONTROL LIST WITH RANDOM NUMBER
		list4.push_back(randNum);
		///////////////////////////////////////////////////////////////////////
	}

	// PRINT OUT LISTS TO VERIFY RANDOMLY-GENERATED CONTENTS ARE USABLE
	// AND ALL 3 LISTS CONTAIN THE SAME SET OF RANDOM NUMBERS
	//printLists(list1, list2, list3);

	///////////////////////////////////////////////////////////////////////////
	// SORT LIST1 USING BUBBLE SORT ALGORITHM (pg 1073) ///////////////////////
	///////////////////////////////////////////////////////////////////////////
	// CONTINUE PASSING OVER LIST WITH SORTING ALGORITHM FOR A MAXIMUM NUMBER
	// OF ITERATIONS AS THE LIST HAS NUMBER OF ELEMENTS (this is the worst case
	// for efficiency of this algorithm).
	for (iteration = 1; iteration < list1.size(); iteration++)
	{
		// GO THROUGH EACH ELEMENT IN THE LIST AND COMPARE WITH NEXT ELEMENT
		for (index = 0; index < (list1.size() - iteration); index++)
		{
			// IF LEFT ELEMENT IS GREATER THAN RIGHT ELEMENT,
			// MOVE IT ONE POSITION FURTHER TOWARDS THE BOTTOM
			// OF THE LIST BY SWAPPING THE TWO ELEMENTS' POSITIONS
			if (list1[index] > list1[index + 1])
			{
				temp = list1[index];				// ASSIGNMENT += 1
				bubbleAssCount += 1;

				list1[index] = list1[index + 1];	// ASSIGNMENT += 1
				bubbleAssCount += 1;

				list1[index + 1] = temp;			// ASSIGNMENT += 1
				bubbleAssCount += 1;
			}
			bubbleCompCount += 1;
		}
	} // end bubble sort
	///////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////////
	// SORT LIST2 USING SELECTION SORT ALGORITHM (pg 550) /////////////////////
	///////////////////////////////////////////////////////////////////////////
	// STARTING AT TOP OF LIST AND WORKING TOWARDS THE BOTTOM
	for (index = 0; index < list2.size(); index++)
	{
		// ASSUME THIS ITERATION'S INDEX IS THE SMALLEST INDEX SO FAR
		// SET smallestIndex VARIABLE EQUAL TO index'S VALUE DURING THIS ITERATION
		smallestIndex = index;

		// SET LOCATION WE ARE EXAMINING THE LIST FROM EQUAL TO 1 INDEX GREATER
		// THAN OUR CURRENT ITERATION'S INDEX, SO LONG AS WE WILL NOT GO PAST
		// THE END OF OUR LIST
		for (location = index + 1; location < list2.size(); location++) // COMPARISON += 1
		{
			selectCompCount += 1;
			// IF NEXT INDEX'S VALUE BEING COMPARED IS SMALLER THAN smallestIndex'S
			// VALUE DURING THIS ITERATION, UPDATE smallestIndex TO location'S INDEX
			// POSITION
			if (list2[location] < list2[smallestIndex])	// COMPARISON += 1
			{
				selectCompCount += 1;
				smallestIndex = location;
			}
		} // AFTER DETERMINING smallestIndex'S FINAL POSITION IN THE LIST,
		  // SWAP VALUES AROUND ACCORDINGLY
		temp = list2[smallestIndex];					// ASSIGNMENT += 1
		selectAssCount += 1;
		list2[smallestIndex] = list2[index];			// ASSIGNMENT += 1
		selectAssCount += 1;
		list2[index] = temp;							// ASSIGNMENT += 1
		selectAssCount += 1;
	} // end selection sort

	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// SORT LIST3 USING INSERTION SORT ALGORITHM (pg 1078) ////////////////////
	///////////////////////////////////////////////////////////////////////////
	// STARTING AT THE 2ND INDEX POSITION AND MOVING TOWARDS END OF LIST
	for (firstOutOfOrder = 1; firstOutOfOrder < list3.size(); firstOutOfOrder++)
	{
		// IF HIGHER INDEX VALUE IS LESS THAN LOWER INDEX VALUE
		if (list3[firstOutOfOrder] < list3[firstOutOfOrder - 1])	// COMPARISON += 1
		{
			insertCompCount += 1;
			// ASSIGN HIGHER INDEX VALUE TO TEMPORARY STORAGE VARIABLE
			temp = list3[firstOutOfOrder];							// ASSIGNMENT += 1
			insertAssCount += 1;
			// RECORD INDEX POSITION OF FIRST NUMERIC COMPARISON DETERMINED TO BE OUT OF ORDER
			location = firstOutOfOrder;

			do	// ALLOW OUT OF ORDER VALUE TO BE MOVED AS MANY TIMES AS NECESSARY
				// PER LOGICAL LIST ITERATION
			{
				// SET firstOutOfOrder INDEX LOCATION EQUAL TO VALUE AT 1 INDEX POSITION LOWER
				// BY MOVING THE LOWER VALUE TOWARDS TOP OF LIST 1 OR MORE POSITIONS, SO LONG
				// AS WE HAVE NOTE YET REACHED INDEX 0 (THE FIRST / TOPMOST ELEMENT) OF OUR
				// LIST AND ALSO SO LONG AS THE VALUE AT 1 INDEX POSITION LOWER IS ALSO
				// STILL GREATER THAN THE firstOutOfOrder INDEX POSITION'S ORIGINAL VALUE.
				list3[location] = list3[location - 1];				// ASSIGNMENT += 1
				insertAssCount += 1;
				location--;
				insertCompCount += 1;
			} while ((location > 0) && ((list3[location - 1]) > temp));	// COMPARISON += 1

			// RELOCATE firstOutOfOrder VALUE FOR THIS ITERATION OF OUR LIST AFTER
			// DETERMINING ITS FINAL INDEX POSITION FOR THIS ITERATION.
			list3[location] = temp;									// ASSIGNMENT += 1
			insertAssCount += 1;
		}
	} // end insertion sort
	///////////////////////////////////////////////////////////////////////////


	// PRINT SORTED LISTS
	printLists(list1, list2, list3, list4);

	// PRINT ALGORITHM STATS
	for (i = 0; (i < list1.size()) && (i < list2.size()) && (i < list3.size()); i++)
	{
		if ((list1[i] != list2[i]) || (list2[i] != list3[i]) || (list3[i] != list1[i]))
		{
			notEqual = true;
		}
	}
	cout << "\n\n\n\n  INDEX \t BUBBLE \t SELECTION \t INSERTION \t CONTROL \t ALL \n";
	cout << " [#####] \t COMPARISONS \t COMPARISONS \t COMPARISONS \t LIST \t\t EQUAL \n\n";
	cout << " \t\t " << bubbleCompCount << "\t\t " << selectCompCount << "\t\t " << insertCompCount;

	if (notEqual == false)
	{
		cout << "\t\t\t\t YES\n\n";
	}
	else
	{
		cout << "\t\t\t\t NO\n\n";
	}

	cout << "\n\n  INDEX \t BUBBLE \t SELECTION \t INSERTION \t CONTROL \t ALL \n";
	cout << " [#####] \t ASSIGNMENTS \t ASSIGNMENTS \t ASSIGNMENTS \t LIST \t\t EQUAL \n\n";
	cout << " \t\t " << bubbleAssCount << "\t\t " << selectAssCount << "\t\t " << insertAssCount;
	
	if (notEqual == false)
	{
		cout << "\t\t\t\t YES\n\n\n";
	}
	else
	{
		cout << "\t\t\t\t NO\n\n\n";
	}
	// MAIN PROGRAM ENDS HERE
	return 0;
}


///////////////////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS ///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void printLists(const vector<int>& list1, const vector<int>& list2, const vector<int>& list3, const vector<int>& list4)
{
	cout << "\n\n\n INDEX \t\t BUBBLE \t SELECTION \t INSERTION \t CONTROL \t EQUAL \n\n";
	for (int i = 0; (i < list1.size()) && (i < list2.size()) && (i < list3.size()); i++)
	{
		// PRINT COLUMN HEADINGS
		if (i % 100 == 0 && i != 0 && i < 1000)
		{
			cout << "\n INDEX \t\t BUBBLE \t SELECTION \t INSERTION \t CONTROL \t EQUAL \n\n";
		}
		else if (i % 100 == 0 && i != 0 && i >= 1000 && i < 10000)
		{
			cout << "\n INDEX \t\t BUBBLE \t SELECTION \t INSERTION \t CONTROL \t EQUAL \n\n";
		}

		// PRINT COLUMN LIST CONTENTS
		if (i < 1000)
		{
			cout << " [" << i << "] \t\t " << list1[i] << "\t\t " << list2[i] << "\t\t " << list3[i] << "\t\t " << list4[i];
			if (list1[i] == list2[i] && list1[i] == list3[i] && list2[i] == list3[i])
			{
				cout << "\t\t YES\n";
			}
			else
			{
				cout << "\t\t NO\n";
			}
		}
		else if (i >= 1000 && i < 10000)
		{
			cout << " [" << i << "] \t " << list1[i] << "\t\t " << list2[i] << "\t\t " << list3[i] << "\t\t " << list4[i];
			if (list1[i] == list2[i] && list1[i] == list3[i] && list2[i] == list3[i])
			{
				cout << "\t\t YES\n";
			}
			else
			{
				cout << "\t\t NO\n";
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////