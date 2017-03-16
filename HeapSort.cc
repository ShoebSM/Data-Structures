#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

/*------L-----------------------------------------------------------
Programmer: Shoeb Mohammed   zID:z1700231

CSCI340 - Assignment7
Write a program to sort numbers using the Heap Sort tecnique.
-------------------------------------------------------------------*/

void build_heap(vector<int>&v, int heap_size, bool(*compar)(int,int));
void heapify(vector<int>&v, int heap_size, int r, bool(*compar)(int, int));
bool less_than (int e1, int e2);
bool greater_than (int e1, int e2);
void heap_sort(vector<int>&v, int heap_size, bool(*compar) (int, int));
int extract_heap(vector<int>&v, int& heap_size, bool(*compar) (int,int));

/*-------------------------------------------------------------------
Function: build_heap
Ensures that the element begins at position 1 and not 0,
calls heapify
---------------------------------------------------------------------*/
void build_heap(vector<int>&v, int heap_size, bool(*compar)(int,int)){
	//Constructs heap with heap_size elements in vector v
	for(int i=heap_size;i>0;i--)
	{
		heapify(v,heap_size,i,compar);
	}

}
/*---------------------------------------------------------------------
Function: heapify
Finds the largest value in the heap and arranges the heap.
-----------------------------------------------------------------------*/
void heapify(vector<int>&v, int heap_size, int r, bool(*compar)(int, int)){
	//"Heapifies" a tree at the root position r
	int Left = 2*r;
	int Right = 2*r+1;
	int largest;
	if (Left <= heap_size && compar(v[Left],v[r]))
	{
		 largest = Left;
	} else largest = r;

	if (Right <= heap_size && compar(v[Right],v[largest]))
	{
		 largest = Right;
	}
	if(largest != r)
	{
		int temp;
		temp = v[r];
		v[r]=v[largest];
		v[largest]=temp;
		heapify(v,heap_size,largest,compar);
	}
}
/*-----------------------------------------------------------
bool(less_than)
Compares two values, returns true if value1 is less than value2
-------------------------------------------------------------*/
bool less_than (int e1, int e2){
	if(e1 < e2)
	{
		return true;
	}else return false;
}
/*-------------------------------------------------------------
greater_than
Compares two values, returns true if value1 is greater than value 2
--------------------------------------------------------------*/
bool greater_than (int e1, int e2){
	if(e1 > e2)
	{
		return true;
	}else return false;
}
/*----------------------------------------------------------------
heap_sort
Sends to extract heap, then reverses the heap
-------------------------------------------------------------------*/
void heap_sort(vector<int>&v, int heap_size, bool(*compar) (int, int)){
	
	for(int i=heap_size;i>1;i--)
	{
		v[i]=extract_heap(v,heap_size,compar);
	}
	reverse(v.begin() + 1,v.end());
}

/*---------------------------------------------------------------------
extract_heap
Switches the first value of the vector with the last value of the vector.
Removes the end part of the heap
----------------------------------------------------------------------*/
int extract_heap(vector<int>&v, int& heap_size, bool(*compar) (int,int)){
	if(heap_size < 1)
		cout << "error heap underflow";
	int max;
	max = v[1];
	v[1] = v[heap_size];
	heap_size = heap_size-1;
	heapify(v,heap_size,1,compar);
	return max;

}
/*--------------------------------------------------
prints the vector contents
------------------------------------------------------*/
void print_vector(vector<int>&v, int pos, int size){
	int counter = 0;
	for (int i= pos;i<=size;i++)
	{

		cout << setw(4);
		cout << v[i] << " ";
		counter++;
		if (counter % 10 == 0)
		{
			cout << endl;
		}
	}
	cout <<endl;

}

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    int heap_size = 24;
    for (int i=1; i<=heap_size; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+heap_size+1 );
    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, heap_size, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, heap_size );
    
    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, heap_size, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, heap_size );
                        
    return 0;
}
