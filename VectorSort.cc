//-----------------
//CSCI 340 - Fall 2015
//Shoeb Mohammed
//Assignment 1
//-----------------

#include <stdio.h>
#include <vector>
#include <cstdlib>              //std::rand,srand
#include <iostream>             //std::cout
#include <algorithm>            //std::sort
#include <iomanip>

using namespace std;

const int LOW = 1;
const int HIGH = 10000;
const int NO_ITEMS = 12;
const int ITEM_W = 5;

// void genRndNums( vector<int>& v, int vec_size, int seed);


void genRndNums( vector<int>& v, int vec_size, int seed)
{ 
	srand(seed);
        for(int i=0;i<vec_size;i++)
        {
                //v[i] = rand() % 10000 + 1; In the range of 1 to 10000
                v[i] = rand () % (HIGH - LOW + 1) + LOW;
        }
}

void printVec( const vector<int>& v, int vec_size )
{
        int counter = 0;
		for (int j=0;j<vec_size;j++)
        		{
                //v[j].reserve(5);
                cout << setw(ITEM_W);
                cout << v[j] << " ";
                counter++;
                if (counter % NO_ITEMS == 0)
                {
                        cout << endl;
                }
        }
}
int main()
{

    vector<int> v(100);
    genRndNums( v, 100, 9 );
    sort(v.begin(), v.end());
    printVec(v, 100);

    return 0;
}

