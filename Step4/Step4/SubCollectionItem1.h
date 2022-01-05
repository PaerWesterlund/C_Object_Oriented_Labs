/*	Filename:	SubCollectionItem1.h
	Author:		Per Westerlund
	Date:		2021-09-12
	Summary:	Public interface for class SubCollectionItem1.
				Derived class for Music records.
	Changelog:	05-25 First ver created 
				09-09 Added _releaseYear, changed constructor
*/

using namespace std;

#pragma once
#include "BaseCollectionItem.h"
#include <string>
//#include "String.h"

class SubCollectionItem1 :
    public BaseCollectionItem
{
public:
	SubCollectionItem1(string title, string author, string genre, unsigned releaseYear);
	string show();		// Display item
	string info();		// Item field info in a string
	string fileData();	// Data to save in file
private:
	string _author;
	string _genre;
	unsigned _releaseYear;
};

