/*	Filename:	SubCollectionItem2.cpp
	Author:		Per Westerlund
	Date:		2021-09-10
	Summary:	Class SubCollectionItem2.
				Derived class for Book records.
*/

#include "SubCollectionItem2.h"

SubCollectionItem2::SubCollectionItem2(string title, string author, unsigned nrOfPages, unsigned releaseYear)
	: BaseCollectionItem()
{
	_itemType = "Book";
	_title = title;
	_author = author;
	_nrOfPages = nrOfPages;
	_releaseYear = releaseYear;
}

string SubCollectionItem2::show()
{
	string info;

	info = "\nItem type: " + _itemType;
	info += "\nItem ID: " + to_string(_itemId);
	info += "\nTitle: " + _title;
	info += "\nAuthor: " + _author;
	info += "\nNr of pages: " + to_string(_nrOfPages);
	info += "\nRelease year: " + to_string(_releaseYear);

	return (info);
}

string SubCollectionItem2::info()
{
	return (_title + '\n' + _author + '\n' + to_string(_nrOfPages) + '\n' + to_string(_releaseYear));
}

string SubCollectionItem2::fileData()
{
	return (_itemType + '\n' + to_string(_itemId) + '\n' + info());
}