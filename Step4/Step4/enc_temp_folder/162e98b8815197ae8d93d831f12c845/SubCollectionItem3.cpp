/*	Filename:	SubCollectionItem3.cpp
	Author:		Per Westerlund
	Date:		2021-09-10
	Summary:	Class SubCollectionItem3.
				Derived class for Plant records.
*/

#include "SubCollectionItem3.h"

SubCollectionItem3::SubCollectionItem3(string title, string latinTitle, string family)
	: BaseCollectionItem()
{
	_itemType = "Plant";
	_title = title;
	_latinTitle = latinTitle;
	_family = family;
}

string SubCollectionItem3::show()
{
	string info;

	info = "\nItem type: " + _itemType;
	info += "\nItem ID: " + to_string(_itemId);
	info += "\nTitle: " + _title;
	info += "\nLatin title: " + _latinTitle;
	info += "\nFamily: " + _family;

	return (info);
}

string SubCollectionItem3::info()
{
	return (_title + ' ' + _latinTitle + ' ' + _family);
}

string SubCollectionItem3::fileData()
{
	return (_itemType + '\n' + to_string(_itemId) + '\n' + info());
}