///////////////////////////////////////////////////////////////////////////////
//
// COP 2335-70B  --  Module 7 Project B - Programming a recursive binary search
//
// NAME:    Mark Darling
// PURPOSE: Write a recursive version of the binary search algorithm that can
//			be used to search an integer vector object. Also, write a program
//			to test your algorithm.
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
int randomNumber(int low, int high);
void bubbleSort(vector<int>& list, int& bubbleCompCount, int& bubbleAssCount);
void selectionSort(vector<int>& list, int& selectCompCount, int& selectAssCount);
void insertionSort(vector<int>& list, int& insertCompCount, int& insertAssCount);
void printLists(const vector<int>& list1, const vector<int>& list2,
	const vector<int>& list3, const vector<int>& list4);
void printStats(const vector<int>& list1, const vector<int>& list2,
	const vector<int>& list3, const vector<int>& list4,
	int bubbleCompCount, int selectCompCount, int insertCompCount,
	int bubbleAssCount, int selectAssCount, int insertAssCount);
int binarySearch1(const vector<int>& list, int searchItem, int& binary1CompCount);
bool binarySearch2(const vector<int>& list, int searchItem, int& binary2CompCount,
	vector<int>& rList1);
int recursiveBinarySearch1(const vector<int>& list, int searchItem, int first,
	int last, int& recBinaryCompCount1);
bool recursiveBinarySearch2(const vector<int>& list, int searchItem, int first,
	int last, int& recBinaryCompCount2, vector<int>& rList2);


///////////////////////////////////////////////////////////////////////////////
// MAIN PROGRAM BEGINS HERE ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
	// DEFINE VARIABLES LOCAL TO main()
	int bubbleAssCount = 0, bubbleCompCount = 0;			// BUBBLE COUNTERS
	int selectAssCount = 0, selectCompCount = 0;			// SELECTION COUNTERS
	int insertAssCount = 0, insertCompCount = 0;			// INSERTION COUNTERS
	int binary1CompCount = 0, binary2CompCount = 0;			// BINARY COUNTERS
	int recBinaryCompCount1 = 0, recBinaryCompCount2 = 0;	// RECURSIVE BINARY COUNTERS
	int listLength, low, high, randNum, searchItem;

	// DEFINE DYNAMIC LISTS OF INTEGERS VIA VECTORS
	vector<int> list1;	// BUBBLE SORT
	vector<int> list2;	// SELECTION SORT
	vector<int> list3;	// INSERTION SORT
	vector<int> list4;	// CONTROL LIST
	vector<int> rList1;	// RESULTS LIST 1
	vector<int> rList2;	// RESULTS LIST 2

	// TAKE USER INPUT
	cout << " How many random numbers would you like to generate?\n ";
	cin >> listLength;
	cout << " What range should the randomly generated numbers fall within? [LOW,HIGH]\n";
	cout << " LOW: ";
	cin >> low;
	cout << " HIGH: ";
	cin >> high;

	// FILL ALL VECTORS WITH THE SAME SET OF RANDOM INTEGERS
	for (int i = 0; i < listLength; i++)
	{
		// GENERATE A RANDOM NUMBER
		randNum = randomNumber(low, high);

		// ADD RANDOMLY GENERATED NUMBER TO BUBBLE LIST
		list1.push_back(randNum);

		// ADD RANDOMLY GENERATED NUMBER TO SELECTION LIST
		list2.push_back(randNum);

		// ADD RANDOMLY GENERATED NUMBER TO INSERTION LIST
		list3.push_back(randNum);

		// ADD RANDOMLY GENERATED NUMBER TO CONTROL LIST
		list4.push_back(randNum);
	}

	// PRINT OUT LISTS TO VERIFY RANDOMLY-GENERATED CONTENTS ARE USABLE
	// AND ALL 3 LISTS CONTAIN THE SAME SET OF RANDOM NUMBERS
	//printLists(list1, list2, list3, list4);

	// SORT LISTS
	bubbleSort(list1, bubbleCompCount, bubbleAssCount);
	selectionSort(list2, selectCompCount, selectAssCount);
	insertionSort(list3, insertCompCount, insertAssCount);

	// PRINT SORTED LISTS
	printLists(list1, list2, list3, list4);

	// PRINT SORTING PERFORMANCE STATS
	printStats(list1, list2, list3, list4,
		bubbleCompCount, selectCompCount, insertCompCount,
		bubbleAssCount, selectAssCount, insertAssCount);

	///////////////////////////////////////////////////////////////////////////

	// USE BINARY SEARCH FUNCTIONS
	cout << " ========== Let's test our binarySearch() function... ==========\n";

	cout << " Enter an integer [" << low << "," << high << "] you would like to"
		" search for in the sorted lists: ";
	cin >> searchItem;

	cout << "\n\n\n\n ========== SEARCHING LISTS USING binarySearch1() ... ==========\n";
	if (binarySearch1(list1, searchItem, binary1CompCount) != -1)
	{
		cout << "\n " << list1[binarySearch1(list1, searchItem, binary1CompCount)] << " FOUND AT"
			" INDEX [" << binarySearch1(list1, searchItem, binary1CompCount) << "]!\n";
	}
	else
	{
		cout << " NOT FOUND!\n";
	}

	///////////////////////////////////////////////////////////////////////////

	cout << "\n\n\n\n ========== SEARCHING LISTS USING binarySearch2() ... ==========\n\n";
	if (binarySearch2(list2, searchItem, binary2CompCount, rList1) != false)
	{
		insertionSort(rList1, insertCompCount, insertAssCount);
		cout << "\n binarySearch2() returned the following results:\n\n";
		cout << " (RESULT #) \t [INDEX] \t RESULT\n";
		for (int i = 0; i < rList1.size(); i++)
		{
			cout << " \t(" << i + 1 << ") \t" << " [" << rList1[i] << "] \t\t " << list2[rList1[i]] << endl;
		}
	}
	else
	{
		cout << " NOT FOUND!\n";
	}

	///////////////////////////////////////////////////////////////////////////

	cout << "\n\n\n\n ========== SEARCHING LISTS USING recursiveBinarySearch1() ... ==========\n";
	if (recursiveBinarySearch1(list3, searchItem, 0, list3.size() - 1, recBinaryCompCount1) != -1)
	{
		cout << "\n " << list3[recursiveBinarySearch1(list3, searchItem, 0, list3.size() - 1,
			recBinaryCompCount1)] << " FOUND AT INDEX [" << recursiveBinarySearch1(list3,
				searchItem, 0, list3.size() - 1, recBinaryCompCount1) << "]!\n";
	}
	else
	{
		cout << " NOT FOUND!\n";
	}

	///////////////////////////////////////////////////////////////////////////

	cout << "\n\n\n\n ========== SEARCHING LISTS USING recursiveBinarySearch2() ... ==========\n";
	if (recursiveBinarySearch2(list3, searchItem, 0, list3.size() - 1, recBinaryCompCount2, rList2)
		!= false)
	{
		insertionSort(rList2, insertCompCount, insertAssCount);
		cout << "\n recursiveBinarySearch2() returned the following results:\n\n";
		cout << " (RESULT #) \t [INDEX] \t RESULT\n";
		for (int i = 0; i < rList2.size(); i++)
		{
			cout << " \t(" << i + 1 << ") \t" << " [" << rList2[i] << "] \t\t " << list3[rList2[i]] << endl;
		}
	}
	else
	{
		cout << " NOT FOUND!\n";
	}

	///////////////////////////////////////////////////////////////////////////

	cout << endl << endl << endl << endl;

	// MAIN PROGRAM ENDS HERE
	return 0;

} // end main()


///////////////////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS ///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int randomNumber(int low, int high)
{
	///////////////////////////////////////////////////////////////////////
	// FROM STACK OVERFLOW ////////////////////////////////////////////////
	// https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
	///////////////////////////////////////////////////////////////////////
	// ESTABLISH RANDOM NUMBER GENERATOR WITH OUTPUT IN RANGE: [low,high]
	std::random_device randDev;
	std::mt19937 randomNumGen(randDev());
	std::uniform_int_distribution<std::mt19937::result_type> range(low, high);
	// GENERATE RANDOM NUMBER USING GENERATOR
	return range(randomNumGen);
} // end randomNumber()


///////////////////////////////////////////////////////////////////////////////


void bubbleSort(vector<int>& list, int& bubbleCompCount, int& bubbleAssCount)
{
	// RESET PERFORMANCE COUNTER VARIABLES
	bubbleCompCount = 0, bubbleAssCount = 0;

	// CREATE LOCAL VARIABLES REQUIRED FOR THIS FUNCTION
	int temp;

	///////////////////////////////////////////////////////////////////////////
	// SORT LIST USING BUBBLE SORT ALGORITHM (pg 1073) ////////////////////////
	///////////////////////////////////////////////////////////////////////////
	// CONTINUE PASSING OVER LIST WITH SORTING ALGORITHM FOR A MAXIMUM NUMBER
	// OF ITERATIONS AS THE LIST HAS NUMBER OF ELEMENTS (this is the worst case
	// for efficiency of this algorithm).
	for (int iteration = 1; iteration < list.size(); iteration++)
	{
		// GO THROUGH EACH ELEMENT IN THE LIST AND COMPARE WITH NEXT ELEMENT
		for (int index = 0; index < (list.size() - iteration); index++)
		{
			// IF LEFT ELEMENT IS GREATER THAN RIGHT ELEMENT,
			// MOVE IT ONE POSITION FURTHER TOWARDS THE BOTTOM
			// OF THE LIST BY SWAPPING THE TWO ELEMENTS' POSITIONS
			if (list[index] > list[index + 1])
			{
				temp = list[index];				// ASSIGNMENT += 1
				bubbleAssCount += 1;

				list[index] = list[index + 1];	// ASSIGNMENT += 1
				bubbleAssCount += 1;

				list[index + 1] = temp;			// ASSIGNMENT += 1
				bubbleAssCount += 1;
			}
			bubbleCompCount += 1;
		}
	} // end bubble sort
}


///////////////////////////////////////////////////////////////////////////////


void selectionSort(vector<int>& list, int& selectCompCount, int& selectAssCount)
{
	// RESET PEFORMANCE COUNTER VARIABLES
	selectCompCount = 0, selectAssCount = 0;

	// CREATE LOCAL VARIABLES REQUIRED FOR THIS FUNCTION
	int smallestIndex, location, temp;

	///////////////////////////////////////////////////////////////////////////
	// SORT LIST USING SELECTION SORT ALGORITHM (pg 550) //////////////////////
	///////////////////////////////////////////////////////////////////////////
	// STARTING AT TOP OF LIST AND WORKING TOWARDS THE BOTTOM
	for (int index = 0; index < list.size(); index++)
	{
		// ASSUME THIS ITERATION'S INDEX IS THE SMALLEST INDEX SO FAR
		// SET smallestIndex VARIABLE EQUAL TO index'S VALUE DURING THIS ITERATION
		smallestIndex = index;

		// SET LOCATION WE ARE EXAMINING THE LIST FROM EQUAL TO 1 INDEX GREATER
		// THAN OUR CURRENT ITERATION'S INDEX, SO LONG AS WE WILL NOT GO PAST
		// THE END OF OUR LIST
		for (location = index + 1; location < list.size(); location++) // COMPARISON += 1
		{
			selectCompCount += 1;
			// IF NEXT INDEX'S VALUE BEING COMPARED IS SMALLER THAN smallestIndex'S
			// VALUE DURING THIS ITERATION, UPDATE smallestIndex TO location'S INDEX
			// POSITION
			if (list[location] < list[smallestIndex])	// COMPARISON += 1
			{
				selectCompCount += 1;
				smallestIndex = location;
			}
		} // AFTER DETERMINING smallestIndex'S FINAL POSITION IN THE LIST,
		  // SWAP VALUES AROUND ACCORDINGLY
		temp = list[smallestIndex];					// ASSIGNMENT += 1
		selectAssCount += 1;
		list[smallestIndex] = list[index];			// ASSIGNMENT += 1
		selectAssCount += 1;
		list[index] = temp;							// ASSIGNMENT += 1
		selectAssCount += 1;
	}
} // end selection sort


///////////////////////////////////////////////////////////////////////////////


void insertionSort(vector<int>& list, int& insertCompCount, int& insertAssCount)
{
	// RESET PERFORMANCE COUNTER VARIABLES
	insertCompCount = 0, insertAssCount = 0;

	// CREATE LOCAL VARIABLES REQUIRED FOR THIS FUNCTION
	int temp, location;

	///////////////////////////////////////////////////////////////////////////
	// SORT LIST USING INSERTION SORT ALGORITHM (pg 1078) /////////////////////
	///////////////////////////////////////////////////////////////////////////
	// STARTING AT THE 2ND INDEX POSITION AND MOVING TOWARDS END OF LIST
	for (int firstOutOfOrder = 1; firstOutOfOrder < list.size(); firstOutOfOrder++)
	{
		// IF HIGHER INDEX VALUE IS LESS THAN LOWER INDEX VALUE
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])	// COMPARISON += 1
		{
			insertCompCount += 1;
			// ASSIGN HIGHER INDEX VALUE TO TEMPORARY STORAGE VARIABLE
			temp = list[firstOutOfOrder];							// ASSIGNMENT += 1
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
				list[location] = list[location - 1];				// ASSIGNMENT += 1
				insertAssCount += 1;
				location--;
				insertCompCount += 1;
			} while ((location > 0) && ((list[location - 1]) > temp));	// COMPARISON += 1

			// RELOCATE firstOutOfOrder VALUE FOR THIS ITERATION OF OUR LIST AFTER
			// DETERMINING ITS FINAL INDEX POSITION FOR THIS ITERATION.
			list[location] = temp;									// ASSIGNMENT += 1
			insertAssCount += 1;
		}
	}
} // end insertionSort()


///////////////////////////////////////////////////////////////////////////////


void printLists(const vector<int>& list1, const vector<int>& list2,
	const vector<int>& list3, const vector<int>& list4)
{
	// PRINT LISTS
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
			cout << " [" << i << "] \t\t " << list1[i] << "\t\t " << list2[i] << "\t\t "
				<< list3[i] << "\t\t " << list4[i];
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
			cout << " [" << i << "] \t " << list1[i] << "\t\t " << list2[i] << "\t\t "
				<< list3[i] << "\t\t " << list4[i];
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
} // end printLists()


///////////////////////////////////////////////////////////////////////////////


void printStats(const vector<int>& list1, const vector<int>& list2,
	const vector<int>& list3, const vector<int>& list4,
	int bubbleCompCount, int selectCompCount, int insertCompCount,
	int bubbleAssCount, int selectAssCount, int insertAssCount)
{
	// PRINT ALGORITHM STATS

	bool notEqual = false;

	for (int i = 0; (i < list1.size()) && (i < list2.size()) && (i < list3.size()); i++)
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
} // end printStats()


///////////////////////////////////////////////////////////////////////////////

// TRADITIONAL binarySearch() THAT REPORTS FIRST RESULT
int binarySearch1(const vector<int>& list, int searchItem, int& binary1CompCount)
{
	// DETERMINE CRITICAL POINTS OF SEARCHABLE RANGE WITHIN OUR LIST
	int first = 0;
	int last = list.size() - 1;
	int mid;

	bool found = false;

	while (first <= last && !found)			// CONTINUE ITERATING WHILE SEARCHABLE LIST RANGE
	{										// IS STILL VALID AND RESULT NOT YET FOUND

		mid = (first + last) / 2;			// DETERMINE MIDDLE POINT OF LIST RANGE DURING THIS
											// ITERATION

		if (list[mid] == searchItem)		// searchItem FOUND
		{
			binary1CompCount += 1;			// COMPARISON += 1
			found = true;
		}
		else if (list[mid] > searchItem)	// searchItem NOT FOUND - MOVE UP THE LIST
		{
			binary1CompCount += 1;			// COMPARISON += 1
			last = mid - 1;					// MOVE END OF SEARCHABLE RANGE FOR NEXT ITERATION
		}
		else								// searchItem NOT FOUND - MOVE DOWN THE LIST
		{
			binary1CompCount += 1;			// COMPARISON += 1
			first = mid + 1;				// MOVE START OF SEARCHABLE RANGE FOR NEXT ITERATION
		}
	}

	if (found)								// RETURN RESULT ONCE FOUND
		return mid;
	else									// RETURN -1 IF NO RESULT FOUND
		return -1;
} // end binary1Search()


///////////////////////////////////////////////////////////////////////////////

// MODIFIED binarySearch2() THAT REPORTS ALL RESULTS
bool binarySearch2(const vector<int>& list, int searchItem, int& binary2CompCount,
	vector<int>& rList1)
{
	int first = 0;
	int last = list.size() - 1;
	int mid;
	int temp;

	bool found = false, complete = false;

	while (first <= last && !found && !complete)
	{
		mid = (first + last) / 2;

		if (list[mid] == searchItem)		// UPON searchItem HIT, LOOK LEFT, THEN LOOK RIGHT
											// TO FIND FULL RANGE OF RESULTS IN THE EVENT THERE
											// IS MORE THAN 1 RESULT
		{
			binary2CompCount += 1;			// COMPARISON += 1;
			rList1.push_back(mid);			// ADD INDEX OF FOUND RESULT TO RESULTS LIST
			cout << " FIRST HIT AT [INDEX] " << mid << " PUSHED TO rList1!\n\n\n";
			found = true;
			///////////////////////////////////////////////////////////////////
			cout << " LOOKING TO THE LEFT FOR ADDITIONAL RESULTS...\n\n";
			temp = mid;
			while (found == true && temp > 0)		// LOOK LEFT
			{
				cout << " (found == true && temp > 0)\n";
				temp--;								// STEP 1 ELEMENT TO THE LEFT
				if (list[temp] == searchItem)			// CHECK TO SEE IF IT MATCHES searchItem
				{
					cout << " list[" << temp << "] == searchItem\n";
					binary2CompCount += 1;				// COMPARISON += 1
					rList1.push_back(temp);	// ADD INDEX OF FOUND RESULT TO RESULTS LIST
					cout << " [INDEX] " << temp << " PUSHED TO rList1!\n\n";
				}
				else if (list[temp] != searchItem)		// LEFT BOUND OF RESULTS RANGE FOUND
				{
					cout << " list[" << temp << "] == searchItem\n";
					binary2CompCount += 1;				// COMPARISON += 1
					found = false;
					cout << "\n LEFT BOUND OF RESULTS RANGE FOUND!\n\n";
				}
			}
			///////////////////////////////////////////////////////////////////
			cout << " LOOKING TO THE RIGHT FOR ADDITIONAL RESULTS...\n\n";
			found = true;
			temp = mid;
			while (found == true && temp < list.size() - 1)		// LOOK RIGHT
			{
				cout << " (found == true && temp < list.size() - 1)\n";
				temp++;									// STEP 1 ELEMENT TO THE RIGHT
				//if (temp == list.size())	// fixed this using list.size()-1 in while loop above
				//{
				//	cout << " BREAK - PREVENT OUT OF BOUND ARRAY INDEX!\n";
				//	break;
				//}
				if (list[temp] == searchItem)			// CHECK TO SEE IF IT MATCHES searchItem
				{
					cout << " list[" << temp << "] == searchItem\n";
					binary2CompCount += 1;				// COMPARISON += 1
					rList1.push_back(temp);	// ADD INDEX OF FOUND RESULT TO RESULTS LIST
					cout << " [INDEX] " << temp << " PUSHED TO rList1!\n\n";
				}
				else if (list[temp] != searchItem)		// RIGHT BOUND OF RESULTS RANGE FOUND
				{
					cout << " list[" << temp << "] == searchItem\n";
					binary2CompCount += 1;				// COMPARISON += 1
					found = false;
					cout << "\n RIGHT BOUND OF RESULTS RANGE FOUND!\n\n";
				}
			}
			complete = true;				// FINISHED LOOKING LEFT AND RIGHT FROM FIRST RESULT
			///////////////////////////////////////////////////////////////////
		}
		else if (list[mid] > searchItem&& complete == false)
		{
			binary2CompCount += 1;
			last = mid - 1;
		}
		else if (list[mid] < searchItem && complete == false)
		{
			binary2CompCount += 1;
			first = mid + 1;
		}
	}

	if (complete)
		return true;
	else
		return false;
} // end binary2Search()


///////////////////////////////////////////////////////////////////////////////

// TRADITIONAL RECURSIVE binarySearch() THAT REPORTS FIRST RESULT
int recursiveBinarySearch1(const vector<int>& list, int searchItem, int first, int last,
	int& recBinaryCompCount1)
{
	// CREATE NECESSARY LOCAL VARIABLES FOR THIS FUNCTION TO OPERATE
	int mid;

	// NO RESULT
	if (first > last)
	{
		recBinaryCompCount1 += 1;			// COMPARISON += 1
		return -1;
	}

	// RESULT
	else
	{
		// DETERMINE MIDDLE OF LIST
		mid = (first + last) / 2;


		if (list[mid] == searchItem)		// BASE CASE - CHECK MIDDLE ELEMENT FIRST
		{
			recBinaryCompCount1 += 1;			// COMPARISON += 1
			return mid;
		}
		else if (list[mid] > searchItem)		// RECURSIVE CASE - PASS LEFT HALF OF LIST
		{
			recBinaryCompCount1 += 1;			// COMPARISON += 1
			recursiveBinarySearch1(list, searchItem, first, mid - 1, recBinaryCompCount1);
		}
		else if (list[mid] < searchItem)		// RECURSIVE CASE - PASS RIGHT HALF OF LIST
		{
			recBinaryCompCount1 += 1;			// COMPARISON += 1
			recursiveBinarySearch1(list, searchItem, mid + 1, last, recBinaryCompCount1);
		}
	}

} // end recursiveBinarySearch()

///////////////////////////////////////////////////////////////////////////////

// MODIFIED RECURSIVE binarySearch() THAT REPORTS ALL RESULTS
bool recursiveBinarySearch2(const vector<int>& list, int searchItem, int first, int last,
	int& recBinaryCompCount2, vector<int>& rList2)
{
	// CREATE NECESSARY LOCAL VARIABLES FOR THIS FUNCTION TO OPERATE
	int mid;

	// NO RESULT
	if (first > last)
	{
		recBinaryCompCount2 += 1;			// COMPARISON += 1
		return false;
	}

	// RESULT
	else
	{
		// DETERMINE MIDDLE OF LIST
		mid = (first + last) / 2;


		if (list[mid] == searchItem)		// BASE CASE - CHECK MIDDLE ELEMENT FIRST
		{
			recBinaryCompCount2 += 1;			// COMPARISON += 1
			rList2.push_back(mid);			// ADD HIT TO RESULTS LIST
			// LOOK LEFT
			recursiveBinarySearch2(list, searchItem, first, mid - 1, recBinaryCompCount2, rList2);
			// LOOK RIGHT
			recursiveBinarySearch2(list, searchItem, mid + 1, last, recBinaryCompCount2, rList2);
			return true;
		}
		else if (list[mid] > searchItem)		// RECURSIVE CASE - PASS LEFT HALF OF LIST
		{
			recBinaryCompCount2 += 1;			// COMPARISON += 1
			recursiveBinarySearch2(list, searchItem, first, mid - 1, recBinaryCompCount2, rList2);
		}
		else if (list[mid] < searchItem)		// RECURSIVE CASE - PASS RIGHT HALF OF LIST
		{
			recBinaryCompCount2 += 1;			// COMPARISON += 1
			recursiveBinarySearch2(list, searchItem, mid + 1, last, recBinaryCompCount2, rList2);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////