/*	Filename:	CatalogApplication.cpp
	Author:		Per Westerlund
	Date:		2021-09-12
	Summary:	Application class for catalog with items
				derived from BaseCollectionItem
*/

using namespace std;

#include <Menu.h>
#include <CollectionRegistry.h>
#include <iostream>

class CatalogApplication
{
public:
	CatalogApplication();		
	~CatalogApplication();		
	void run();			

private:						
	Menu menuObj;
	CollectionRegistry collectionReg;
};

CatalogApplication::CatalogApplication()
{}

CatalogApplication::~CatalogApplication()
{}

void CatalogApplication::run()
{
	char menuChoice = 'X';
	string	itemType, title, author, genre, latinTitle, family;
	unsigned itemID, releaseYear, nrOfPages;
	SubCollectionItem1* pItem1;
	SubCollectionItem2* pItem2;
	SubCollectionItem3* pItem3;

	while (menuChoice != 'q')				//Until Quit is chosen
	{
		menuObj.showMainMenu();				//Show menu
		menuChoice = menuObj.getChoice();	//Get valid menu choice
		
		switch (menuChoice)
		{ 
		case '0':	// Add item
			menuObj.showAddItemMenu();
			menuChoice = menuObj.getChoice();

			if (menuChoice < '1' || menuChoice > '3')	// Invalid choice
				break;

			if (menuChoice == '1')	// Music
			{
				itemType = "Music";
				cout << "\nInput title: ";
				getline(cin, title);
				releaseYear = menuObj.getReleaseYear();
				cout << "Input author: ";
				getline(cin, author);
				cout << "Input genre: ";
				getline(cin, genre);
				pItem1 = new SubCollectionItem1(title, author, genre, releaseYear);

				if (collectionReg.addItem(pItem1))
				{
					cout << "Item added!";
					break;
				}
			}
			else if (menuChoice == '2')	// Book
			{
				itemType = "Book";
				cout << "\nInput title: ";
				getline(cin, title);
				cout << "Input author: ";
				getline(cin, author);
				cout << "Input nr of pages: ";
				nrOfPages = menuObj.getPosValue();
				releaseYear = menuObj.getReleaseYear();
				pItem2 = new SubCollectionItem2(title, author, nrOfPages, releaseYear);

				if (collectionReg.addItem(pItem2))
				{
					cout << "Item added!";
					break;
				}
			}
			else if (menuChoice == '3')	// Plant
			{
				itemType = "Plant";
				cout << "\nInput title: ";
				getline(cin, title);
				cout << "Input latin title: ";
				getline(cin, latinTitle);
				cout << "Input family: ";
				getline(cin, family);
				pItem3 = new SubCollectionItem3(title, latinTitle, family);

				if (collectionReg.addItem(pItem3))
				{
					cout << "Item added!";
					break;
				}
			}
			break;
		case '1':	// Remove item
			cout << "\nRemove item\n-----------\n\nInput item ID: ";
			itemID = menuObj.getPosValue();

			if (!collectionReg.removeItem(itemID))
				cout << "\nItem ID does not exist!";
			else cout << "\nItem removed!";
			break;
		case '2':	// Find item
			cout << "\nFind item\n-----------\n\nInput field value: ";
			getline(cin, title);
			collectionReg.findItem(title);
			break;
		case '3':	// Display item
			cout << "\nDisplay item\n-----------\n\nInput item ID: ";
			itemID = menuObj.getPosValue();

			if (!collectionReg.showItem(itemID))
				cout << "\nItem ID does not exist!";
			break;
		case '4':	// Display all items in registry
			cout << "\nDisplaying all items in registry\n---------------------------\n";

			if (!collectionReg.showAllItems())
				cout << "\nNo items in registry!";
			break;
		case '5':	// Display a collection
			cout << "\nDisplay a collection\n--------------------\n\n";
			cout << "1. Music\n2. Books\n3. Plants\nq. Quit program\nOther number => Quit submenu\n";
			menuChoice = menuObj.getChoice();

			if (menuChoice < '1' || menuChoice > '3')	// Invalid choice
				break;
			if (menuChoice == '1')		// Music
				collectionReg.showCollection("Music");
			else if (menuChoice == '2')	// Books
				collectionReg.showCollection("Book");
			else if (menuChoice == '3')	// Plants
				collectionReg.showCollection("Plant");
			break;
		case '6':	// Sort register
			cout << "\nSort register\n-------------\n\n";
			cout << "1. Ascending order\n2. Descending order\nq. Quit program\nOther number => Quit submenu\n";
			menuChoice = menuObj.getChoice();

			if (menuChoice < '1' || menuChoice > '2')	// Invalid choice
				break;
			if (menuChoice == '1')		// Ascending order
				collectionReg.sort(true);
			else if (menuChoice == '2')	// Descending order
				collectionReg.sort(false);			
			break;
		case '7':	// Empty register
			collectionReg.emptyReg();
			cout << "\nREGISTER EMPTY!";
			break;
		case '8':	// Save register
			collectionReg.saveReg();
			break;
		case '9':	// Load register
			collectionReg.loadReg();
			break;
		}
		cout << "\n\nPress Enter to continue:";
		cin.ignore(10000, '\n');
	}
}

int main()
{
	CatalogApplication app;

	app.run();
	return 0;	//Normal exit code
}
