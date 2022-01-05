/*	Filename:	SubCollectionItem2.h
	Author:		Per Westerlund
	Date:		2021-09-10
	Summary:	Public interface for class SubCollectionItem2.
				Derived class for Book records.
*/

using namespace std;

#pragma once
#include "BaseCollectionItem.h"
#include <string>

class SubCollectionItem2 :
	public BaseCollectionItem
{
public:
	SubCollectionItem2(string title, string author, unsigned nrOfPages, unsigned releaseYear);
	string show();		// Display item
	string info();		// Item field info in a string
	string fileData();	// Data to save in file
private:
	string _author;
	unsigned _nrOfPages;
	unsigned _releaseYear;
};

