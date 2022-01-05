/*	Filename:	CollectionRegistry.cpp
	Author:		Per Westerlund
	Date:		2021-05-27
	Summary:	Class CollectionRegistry.
				Handles data and operations on a registry of records.
	Changelog:	05-27 First ver created
*/

using namespace std;

#include "CollectionRegistry.h"
#include <BaseCollectionItem.h>
#include <iostream>
#include <string>
#include <fstream>

CollectionRegistry::CollectionRegistry()
{}

CollectionRegistry::~CollectionRegistry()
{}

bool CollectionRegistry::addItem(BaseCollectionItem* pItem)	// Add item to registry
{															
	if (pItem == NULL)
		return false;
															
	string itemType = pItem->getItemType();
	pItem->setID(++_count);
	allItemsList.push_back(pItem);

	return true;
}

bool CollectionRegistry::findItemId(unsigned id)	// Set iterator to item with specified Id
{
	// https://stackoverflow.com/questions/42933943/how-to-use-lambda-for-stdfind-if
	it = find_if(allItemsList.begin(), allItemsList.end(), [id](BaseCollectionItem* item) {
		return item->getID() == id;
		});

	if (it == allItemsList.end())
		return false;	// Item not found
	else return true;	// Item found
}

bool CollectionRegistry::removeItem(unsigned id)	// Remove item with specified Id
{
	BaseCollectionItem* pBase;

	if (findItemId(id))
	{
		pBase = *it;
		allItemsList.erase(it);		// Delete item pointer in list
		delete(pBase);				// Delete object
		return true;
	}
	else return false;
}

void CollectionRegistry::findItem(string value)		// Find and display items with specified info
{
	size_t match;
	string itemInfo;

	for (it = allItemsList.begin(); it != allItemsList.end(); it++)
	{
		itemInfo = (*it)->info();
		match = itemInfo.find(value);
		if (match != string::npos)
			cout << (*it)->show() << "\n";
	}

	cout << "\n--- FOUND ITEMS END OF LIST  ---";
}

bool CollectionRegistry::showItem(unsigned id)	// Show item with specified Id
{
	if (findItemId(id))
	{
		cout << (*it)->show();
		return true;
	}
	else return false;
}

bool CollectionRegistry::showAllItems()	// Displays all items in registry
{
	if (allItemsList.size() == 0)
		return false;

	for (it = allItemsList.begin(); it != allItemsList.end(); it++)
		cout << (*it)->show() << "\n";

	return true;
}

void CollectionRegistry::showCollection(string itemType)	// Displays all items in specified collection
{
	if (allItemsList.size() == 0)
	{
		cout << "\nEMPTY REGISTER!";
		return;
	}

	for (it = allItemsList.begin(); it != allItemsList.end(); it++)
		if ((*it)->getItemType() == itemType)
			cout << (*it)->show() << "\n";
	
	cout << "\n--- COLLECTION END OF LIST  ---";
	return;
}

void CollectionRegistry::sort(bool asc)	// Sort registry
{
	if (allItemsList.size() == 0)	// Empty register
	{
		cout << "\nEMPTY REGISTER!";
		return;
	}

	// https://stackoverflow.com/questions/16507519/c-sorting-custom-objects-in-a-list
	if (asc)	// Ascending order
	{
		allItemsList.sort([](BaseCollectionItem* lhs, BaseCollectionItem* rhs) {return lhs->getTitle() < rhs->getTitle(); });
	}
	else       // Descending order
	{
		allItemsList.sort([](BaseCollectionItem* lhs, BaseCollectionItem* rhs) {return lhs->getTitle() > rhs->getTitle(); });
	}

	cout << "\nLIST SORTED!";
}

void CollectionRegistry::emptyReg()
{
	BaseCollectionItem* pBase;

	_count = 0;	// Reset itemID counter

	if (allItemsList.size() == 0)	// Empty register
		return;

	for (it = allItemsList.begin(); it != allItemsList.end();)
	{
		pBase = *it;
		it = allItemsList.erase(it);	// Delete item pointer in list. Update iterator to next item.
		delete(pBase);					// Delete object
	}
}

void CollectionRegistry::saveReg()
{
	fstream file;

	// Sort register by ascending Item ID
	allItemsList.sort([](BaseCollectionItem* lhs, BaseCollectionItem* rhs) {return lhs->getID() < rhs->getID(); });

	file.open(_FILE_NAME, ios::out);	// Open in write mode

	if (file.fail() || file.bad())	// Failed to open file
	{
		cerr << "\nError when creating/opening file: " << _FILE_NAME;
		cout << "\nPress Enter";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		//exit(EXIT_FAILURE);
		return;
	}


	for (it = allItemsList.begin(); it != allItemsList.end(); it++)
		file << (*it)->fileData() << "\n";

	file.close();
	cout << "\nRegister saved!";
}
