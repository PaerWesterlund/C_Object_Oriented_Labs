/*	Filename:	BaseCollectionItem.h
	Author:		Per Westerlund
	Date:		2021-09-12
	Summary:	Public interface for class BaseCollectionItem.
				Base class for records which collection subclasses inherits from.
*/

using namespace std;

#pragma once
#include <string>

class BaseCollectionItem
{
public:
	BaseCollectionItem();		// Used in subclass
	~BaseCollectionItem();		// Inherited in subclass
	virtual string show();		// Display item
	virtual string info();		// Item field info in a string
	virtual string fileData();	// Data to save in file
	void setTitle(string);
	void setID(unsigned);
	string getTitle();
	unsigned getID();
	string getItemType();
protected:
	unsigned _itemId;
	string _itemType;
	string _title;
};

