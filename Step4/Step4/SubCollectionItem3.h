/*	Filename:	SubCollectionItem3.h
	Author:		Per Westerlund
	Date:		2021-09-10
	Summary:	Public interface for class SubCollectionItem3.
				Derived class for Plant records.
*/

using namespace std;

#pragma once
#include "BaseCollectionItem.h"
#include <string>

class SubCollectionItem3 :
	public BaseCollectionItem
{
public:
	SubCollectionItem3(string title, string latinTitle, string family);
	string show();		// Display item
	string info();		// Item field info in a string
	string fileData();	// Data to save in file
private:
	string _latinTitle;
	string _family;
};