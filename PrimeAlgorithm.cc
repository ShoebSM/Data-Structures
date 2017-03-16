/*******************************************************
  PROGRAM: Assignment3
  AUTHOR: Shoeb Mohammed
  LOGON ID: z1700231
  DUE DATE: 9/21/2015

  FUNCTION: Finds and prints all prime numbers using 
  the algorithm known as Sieve of Eratosthenes

  INPUT: N/A

  OUTPUT: All the prime numbers between 2 and 1000.
*******************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <set>

using namespace std;

const int NO_ITEMS = 10;	//Constants for displaying output
const int ITEM_W = 5;

/*******************************************************
sieve(s,1000)

Fills the set with the values from 2-1000. Then
proceeds to eliminate all non prime values from set. 
*******************************************************/
void sieve( set<int>& s, int n) {
	for(int i=2;i<=n;i++)		//fills set 2-1000
	  s.insert(i);

	for(int m=2; m<=n; m++){	

		for(int k=m; k<=n; k++)
		  s.erase(m*k);		//eliminates non prime values.
	}
}
/********************************************************
print_primes(s);

Prints the set, outputs new line after 10 values.
********************************************************/
void print_primes( const set<int>& s) {
	int counter = 0;

	set<int>::const_iterator it;

	for(it=s.begin();it!=s.end();it++){
		cout << setw(ITEM_W);
		cout << *it << " ";
		counter++;
		if (counter % NO_ITEMS ==0)
			cout << endl;
	}
	
	cout << "\nThere are" << counter << "prime numbers\n";
}

int main() {
    set<int> s;
    sieve(s, 1000);
    print_primes(s);
    return 0;
}
