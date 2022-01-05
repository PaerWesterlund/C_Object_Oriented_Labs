/*	Filename:	SubCollectionItem1.cpp
	Author:		Per Westerlund
	Date:		2021-09-12
	Summary:	Class SubCollectionItem1.
				Derived class for Music records.
	Changelog:	First ver created 05-25
				09-10 Changed constructor & deleted set functions
				09-11 show function
				09-12 info & fileData functions
*/

#include "SubCollectionItem1.h"

SubCollectionItem1::SubCollectionItem1(string title, string author, string genre, unsigned releaseYear)
	: BaseCollectionItem()
{
	_itemType = "Music";
	_title = title;
	_author = author;
	_genre = genre;
	_releaseYear = releaseYear;
}

string SubCollectionItem1::show()
{
	string info;

	info = "\nItem type: " + _itemType;
	info += "\nItem ID: " + to_string(_itemId);
	info += "\nTitle: " + _title;
	info += "\nAuthor: " + _author;
	info += "\nGenre: " + _genre;
	info += "\nRelease year: " + to_string(_releaseYear);

	return (info);
}

string SubCollectionItem1::info()
{
	return (_title + '\n' + _author + '\n' + _genre + '\n' + to_string(_releaseYear));
}

string SubCollectionItem1::fileData()
{
	return (_itemType + '\n' + to_string(_itemId) + '\n' + info());
}