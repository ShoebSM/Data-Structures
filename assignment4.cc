/******************************************************************
PROGRAM: Assignment4
AUTHOR: Shoeb Mohammed
LOGON ID: z1700231
DUE DATEL 10/2/2015

FUNCTION: Reads in words from an input file, removes the punctuation
and returns the cleaned words and their frequencies.
******************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <ctype.h>
#include <map>

using namespace std;

const int NO_ITEMS = 3;
const int ITEM_W = 16;
/********************************************************
print_words(m);

Prints out the cleaned words and their frequencies, as
well as the number of words in the input stream and the
number of unique words.
*********************************************************/
void print_words( const map<string, int>&cleanWords ) {

	int i=0;int total=0;
	for(map<string,int>::const_iterator it=cleanWords.begin(); it!=cleanWords.end();it++)
	{
		cout <<	setw(ITEM_W) << left<< it->first<<":" << it->second<<" "<<"	";

		i++;
		total = total+it->second;
		if (i % NO_ITEMS ==0)	//Limit three words per line
		{
			cout << endl;
		}
	}
	
	cout << endl << "Number of unique words: " << cleanWords.size()<<endl;
	cout <<"Number of words in input stream: " <<total<<endl; 
}
/********************************************************************
clean_entry(inputWords,cleanedWords);

Receives string from getWords, takes the index of the first
alphanumeric character, as well as the index of the last alphanumeric
character.Uses the substr() method to create an effectively 'clean' 
version of the word.

*********************************************************************/
void clean_entry( const string& toClean, string& cleaned ) {
	unsigned int i=0; //index for first aplhanumeric char
	unsigned int j=0; //index for last aplhanumeric char
	unsigned int z=0; 
	
	//Finds first alphanumeric character
	for(z=0;z<(toClean.length())&& !isalnum(toClean[i]);z++)
	{
		i++;
	}


	j=i; //Gives i the index value of the first alphanumeric character

	//Finds last alphanumeric character
	for(z=i;z<(toClean.length())&&isalnum(toClean[j]);z++)
	{
		j++;
	}

	cleaned = toClean.substr(i,j-i); //Creates cleaned word

	unsigned int k = 0;
	while(k<=j)
	{
		cleaned[k]=tolower(cleaned[k]);	//converts to lowercase
		k++;
	}
}
/********************************************************************
get_words(m,infile);

Gets words from the input file, takes a string sends it to clean_entry.
After word is cleaned it saves it to the map.
*********************************************************************/
void get_words( map<string, int>&data, ifstream& input ) { //Gets words from input stream
	string inputWord,cleanedWords;

	while(input>>inputWord)
	{
 		clean_entry(inputWord,cleanedWords);
		if(cleanedWords.length()>0)
			data[cleanedWords]++;
	}
}


int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "command line argument: input-file-name" << endl;
        return 1;
    }

    ifstream infile(argv[1], ios::in);

    map<string, int> m;

    get_words( m, infile );

    infile.close();

    print_words( m );

    return 0;
}
