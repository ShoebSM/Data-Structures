/******************************************************
PROGRAM: assignment2.cc
AUTHOR: Shoeb Mohammed
LOGON ID: z1700231
DUE DATE: 9/11/2015

FUNCTION: Implements search algorithms on randomly generated integers stored in
vectors.

INPUT: Standard input

OUTPUT: Number of successful matches
*******************************************************/

#include <iostream>     //std::cout
#include <algorithm>    //std::find
#include <vector>	//std::vector
#include <iomanip>      //Printing True or False

const int TOBE_SEARCHED = 5000;
const int HIGH = 10000;		
const int LOW = 1;

using namespace std;


/**********************************************************
getRndNums(container,10000,9)
getRndNums(tobeSearched,TOBE_SEARCHED,3)

Called twice to generate random numbers and store into
two vectors, contrainer and tobeSearched.
*******************************************************/

void genRndNums( vector<int>& v, int vec_size, int seed ) {
	srand(seed);
        for(int i=0;i<vec_size;i++)
        {
                v.push_back( rand () % (HIGH - LOW + 1) + LOW);
        }
}

/***************************************************************
int linear_search_count=search(container,tobeSearched,linearSearch)

Linear search algorithm, searches for x from the beginning of the 
vector to the end. Returns true if it finds x,else false. 
***************************************************************/
bool linearSearch( const vector<int>& v, int x) {
	vector<int>::const_iterator ls;			/*iterates through vector*/
	ls = find(v.begin(),v.end(),x);			/*searches from the beginning til the end for x*/
	if (ls != v.end())
	  return true;
	else
	  return false;
}
/*****************************************************************
int binary_search_count=search(container, tobeSearched, binarySearch)

Binary search algorithm, x is the searched item in vector v.
If found true will return, otherwise, false.
******************************************************************/
bool binarySearch( const vector<int>& v, int x) {
	if(binary_search(v.begin(),v.end(),x))
	  return true;
	else
	  return false;
}
/******************************************************************
int linear_search_count=search(container,tobeSearched,linearSearch)
int binary_search_count=search(container,tobeSearched,binarySearch)

Search algorithm. Puts pointer p in search routine, then calls 
for each match v2 has with v1. It adds to the number of successful
searches and returns that value.
*******************************************************************/
int search( const vector<int>& container, const vector<int>& searchNums,	//Looks through both vectors calls p() for each element,										// computes number of successful searches
	bool (*p)( const vector<int>&, int) ) {
	int success = 0;			/*Tracks successful searches*/
	for(vector<int>::const_iterator i=searchNums.begin();i!=searchNums.end();i++){
		if (p(container,*i))
			success++;
} 
	return success;
}
/****************************************************************
sortVec(container);

Sorts the elements of v in ascending order.
****************************************************************/
void sortVec (vector<int>& v) {
	sort(v.begin(),v.end());
}

/*****************************************************************
printStat(linear_search_count,TOBE_SEARCHED);
printStat(binary_search_count,TOBE_SEARCHED);

Prints the percentage of successful searches
******************************************************************/
void printStat (int totalSucCnt, int vec_size) {

	cout << "Successful searches...";
	double succPct =(double) totalSucCnt/vec_size;
	succPct = succPct * 100;		/*for a percent value*/
	cout << succPct << "%" << endl; 
}

int main() {
    vector<int> container, tobeSearched;
    genRndNums(container, 10000, 9);
    genRndNums(tobeSearched, TOBE_SEARCHED, 3);

    cout << "\nConducting linear search ..." << endl;
    int linear_search_count = search( container, tobeSearched, linearSearch );
    printStat ( linear_search_count, TOBE_SEARCHED );

    cout << "\nConducting binary search on unsorted container ..." << endl;
    int binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    sortVec( container );

    cout << "\nConducting binary search on sorted container ..." << endl;
    binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );
   
    return 0;
}
