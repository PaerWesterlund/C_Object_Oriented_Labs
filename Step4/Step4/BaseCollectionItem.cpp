/*	Filename:	BaseCollectionItem.cpp
	Author:		Per Westerlund
	Date:		2021-09-12
	Summary:	Class BaseCollectionItem.
				Base class for records which collection subclasses inherits from.
*/

using namespace std;

#include "BaseCollectionItem.h"
#include <string>

BaseCollectionItem::BaseCollectionItem()
{
	_itemType = "BaseItem";
	_itemId = 0;
	_title = "";
}

BaseCollectionItem::~BaseCollectionItem()
{}

string BaseCollectionItem::show()
{
	return string();
}

string BaseCollectionItem::info()
{
	return string();
}

string BaseCollectionItem::fileData()	// Data to save in file
{
	return string();
}

void BaseCollectionItem::setTitle(string titleStr)
{
	_title = titleStr;
}

string BaseCollectionItem::getTitle()
{
	return _title;
}

void BaseCollectionItem::setID(unsigned id)
{
	_itemId = id;
}

unsigned BaseCollectionItem::getID()
{
	return _itemId;
}

string BaseCollectionItem::getItemType()
{
	return _itemType;
}
