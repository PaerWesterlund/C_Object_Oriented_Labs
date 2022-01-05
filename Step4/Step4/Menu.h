/*	Filename:	Menu.h
	Author:		Pär Westerlund
	Date:		2021-09-12
	Summary:	Public interface for class Menu
				Functions shows Menu and handles Menu choice
				for CatalogApplication.cpp				
*/

#include <string>
using namespace std;

class Menu
{
public:
	Menu();
	~Menu();
	void showMainMenu();		//Displays menu
	void showAddItemMenu();		//Displays Add Item submenu
	char getChoice();			//Returns users menu choice
	unsigned getReleaseYear();	//Get valid release year from cin
	unsigned getPosValue();		//Get valid unsigned from cin
};

