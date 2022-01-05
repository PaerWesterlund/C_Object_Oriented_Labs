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

	if (file.fail())	// Failed to open file
	{
		cerr << "\nError when creating/opening file: " << _FILE_NAME;
		cout << "\nPress Enter";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		//exit(EXIT_FAILURE);
		return;
	}

	for (it = allItemsList.begin(); it != allItemsList.end() && !file.fail(); it++)
		file << "\n%%%%%\n" << (*it)->fileData();	// 5% signs between items

	if (file.fail())	// File error
	{
		cerr << "\nError when writing to file: " << _FILE_NAME;
		cout << "\nPress Enter";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		file.close();
	}
	else 
	{
		file.close();
		cout << "\nRegister saved!";
	}
}

void CollectionRegistry::loadReg()
{
	fstream file;
	string	itemType, title, author, genre, latinTitle, family;
	unsigned itemID, releaseYear, nrOfPages;
	SubCollectionItem1* pItem1;
	SubCollectionItem2* pItem2;
	SubCollectionItem3* pItem3;
	// TEST ITEMS
/*	pItem1 = new SubCollectionItem1("Love story", "Indila", "Pop", 2010);
	addItem(pItem1);
	pItem2 = new SubCollectionItem2("C++", "Bill Gates", 1000, 1998);
	addItem(pItem2);
	pItem3 = new SubCollectionItem3("Brudorkide", "Phaleonopsis", "Orchidae");
	addItem(pItem3);*/

	file.open(_FILE_NAME, ios::in);	// Open in read mode

	if (file.fail())	// Failed to open file
	{
		cerr << "\nError when opening file: " << _FILE_NAME;
		cout << "\nPress Enter";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		//exit(EXIT_FAILURE);
		return;
	}

	emptyReg();	// Clear register

	string textLine;	// Line of text read by getline()

	while (!file.eof())	// Not EOF or fail
	{
		getline(file, textLine);

		if (textLine == "%%%%%")	// Item separator line
		{
			getline(file, itemType);
			getline(file, textLine);	// Skip Item ID
			getline(file, title);

			if (itemType == "Music")
			{
				getline(file, author);
				getline(file, genre);
				getline(file, textLine);
				releaseYear = stoul(textLine, NULL, 10);
				pItem1 = new SubCollectionItem1(title, author, genre, releaseYear);
				addItem(pItem1);
			}
			else if (itemType == "Book")
			{
				getline(file, author);
				getline(file, textLine);
				nrOfPages = stoul(textLine, NULL, 10);
				getline(file, textLine);
				releaseYear = stoul(textLine, NULL, 10);
				pItem2 = new SubCollectionItem2(title, author, nrOfPages, releaseYear);
				addItem(pItem2);
			}
			else if (itemType == "Plant")
			{
				getline(file, latinTitle);
				getline(file, family);
				pItem3 = new SubCollectionItem3(title, latinTitle, family);
				addItem(pItem3);
			}
		}
	}

	if (file.fail())	// Failed reading file
	{
		cerr << "\nError when reading file: " << _FILE_NAME;
		cout << "\nPress Enter";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		//exit(EXIT_FAILURE);
		return;
	}
	else cout << "\nRegister loaded!";
}
