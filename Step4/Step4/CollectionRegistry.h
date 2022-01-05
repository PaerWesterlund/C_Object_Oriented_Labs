/*	Filename:	CollectionRegistry.h
	Author:		Per Westerlund
	Date:		2021-09-12
	Summary:	Interface for class CollectionRegistry.
				Handles data and operations of a registry of records.
*/

using namespace std;
#include <list>
#include <BaseCollectionItem.h>
#include <SubCollectionItem1.h>
#include <SubCollectionItem2.h>
#include <SubCollectionItem3.h>

class CollectionRegistry
{
public:
	CollectionRegistry();
	~CollectionRegistry();
	bool addItem(BaseCollectionItem*);	// Add item to registry
	bool removeItem(unsigned);			// Remove item with specified Id
	bool showItem(unsigned);			// Remove item with specified Id
	bool findItemId(unsigned);			// Set iterator to item with specified Id
	void findItem(string);				// Find and display item with specified title
	bool showAllItems();				// Displays all items in registry
	void showCollection(string);		// Displays all items in specified collection
	void sort(bool);					// Sort registry
	void emptyReg();					// Empty register
	void saveReg();						// Save register
	void loadReg();						// Load register
private:
	unsigned _count = 0;	// Number of items added. Determines next item Id.
	const string _FILE_NAME = "Register.txt";	// Registry file name
	list<BaseCollectionItem*> allItemsList;		// List with pointers to item objects
	list<BaseCollectionItem*>::iterator it;		// List iterator
};

