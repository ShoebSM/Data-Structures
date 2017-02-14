/*--------------------------------------------------------------
Shoeb Mohammed - CSCI 340 - Assignment 8
Manage an item inventory using a hash table

NOTE-Couldn't get to compile but believe I got very close.
Was getting error from the main?? Oviously unsure what the 
iasue was.
---------------------------------------------------------------*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "assignment8.h"
using namespace std;

// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
/***************************************************************
Parses input to create new entry
****************************************************************/
Entry* get_entry(const string & line)
{
	Entry * entry = new Entry();

	entry->key = line.substr(2,3);
	entry->description = line.substr(6,(line.length()-6));

	return entry;
}

/******************************************************************
Parses input line to return item key
*******************************************************************/
string get_key(const string & line)
{
	string key = line.substr(2,3);
	return key;
}

/*------------------------------------------------------------------
HT:HT(int size)

Initializes data to default value
-----------------------------------------------------------------*/
HT::HT(int size)
{
	table_size = size;
	item_count = 0;
	hTable = new vector<Entry>(size);
}
/*--------------------------------------------------------------------
HT::~HT()

Destroys the table
----------------------------------------------------------------------*/
HT::~HT()
{
	delete hTable;
}
/*------------------------------------------------------------------------
HT::search
Computes and searches for hash value of key. 
-------------------------------------------------------------------------*/
int HT::search(const string & key)
{
	int hash_val = hashing(key);
	int i = 0;

	while(i < table_size)
	{
		if((*hTable)[hash_val + i].key == key)
		{
			i++;
			return hash_val + i;
		}
		else if((*hTable)[hash_val + i].key == "---")
		{
			return -1;
		}
		else
		i++;
	}
	return -1;
}

/*-----------------------------------------------------------------------
HT::insert
Inserts if key is empty, otherwise uses linear probing
------------------------------------------------------------------------*/
bool HT::insert(const Entry & e)
{
	if(search(e.key)== -1)
	{
		cout << "Item's key already exists"<<endl;
	}

	else if(table_size == item_count)
	{
		cout << "Hash table is full."<<endl;
	}
	else
	{
		for(int i=0;i < table_size; i++)
		{
			int hash = (hashing(e.key)+i)%table_size;
			if((*hTable)[hash].key == "---" || (*hTable)[hash].key == "+++")
			{
				(*hTable)[hash] = e;
				item_count++;	
				return true;
			}
		}
	}return false;
}
/*-----------------------------------------------------------------------
HT::remove
Removes item with given key
--------------------------------------------------------------------------*/
bool HT::remove(const string & s)
{
	int found = search(s);

	if(found == -1)
	{
		return false;
	}
	else
	{
		(*hTable)[found].key = "+++";
		item_count--;
		return true;
	}
}

/*----------------------------------------------------------------------
HT::print
Prints hash table
------------------------------------------------------------------------*/
void HT::print()
{
	cout << "---Hash Table---" << endl;
	for(int i=0; i < table_size; i++)
	{
		if((*hTable)[i].key != "---" && (*hTable)[i].key != "+++")
		{
			cout << setw(2) << i << "; " << (*hTable)[i].key << ": " << (*hTable)[i].description<<endl;
		}
	}
	cout <<"----------------" << endl;
}
//

int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}
