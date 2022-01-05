/*	Filename:	Menu.cpp
	Author:		Per Westerlund
	Date:		2021-09-09
	Summary:	Class Menu.	Functions shows Menu and returns Menu choice
*/

#include "Menu.h"
#include <string>
#include <iostream>

using namespace std;

Menu::Menu()
{}

Menu::~Menu()
{}

void Menu::showMainMenu()		//Displays main menu
{
	system("cls");	//Clear screen
	cout << "\n\nMENU\n----\n\n0. Add item\n1. Remove item\n2. Find item\n3. Display an item\n4. Display all items";
	cout << "\n5. Display a collection\n6. Sort register\n7. Empty register\n8. Save register\n9. Load register\nq. QUIT\n";
}

void Menu::showAddItemMenu()	//Displays Add Item submenu
{
	system("cls");	//Clear screen
	cout << "\nAdd item\n--------\nSpecify item type:\n1. Music\n2. Book\n3. Plant\nq. Quit program\n\nOther number => Quit submenu";
}

char Menu::getChoice()		//Returns menu choice only after getting valid input
{
	char menuChoice = 'X', enterKey;

	while (menuChoice == 'X')	//Wait until valid choice
	{
		cout << "\nChoice: ";
		cin.get(menuChoice);	//First character
		cin.get(enterKey);		//Second character

		if (((menuChoice <= '9' && menuChoice >= '0') || menuChoice == 'q') && enterKey == '\n')	// Valid choice + ENTER
			return menuChoice;
		else menuChoice = 'X';

		if (enterKey != '\n') {			//Second character is not ENTER
			cin.ignore(10000, '\n');	//Ignores the rest until ENTER
			menuChoice = 'X';			//Incorrect menu choice
		}

		cout << "\nIncorrect menu choice! Press ENTER to continue";
		cin.ignore(10000, '\n');	//Ignores the rest until ENTER
	}
}

unsigned Menu::getReleaseYear()	// Obtain unsigned from cin
{
	unsigned releaseYear;

	while (true) {
		cout << "Input release year: ";
		cin >> releaseYear;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl

		if (cin.fail())		// Error in input
		{
			cin.clear();	// Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		}
		else if (releaseYear <= 2050)
		{
			return releaseYear;	// Valid releaseYear
		}
		cout << "Invalid input!\n";
	}
}

unsigned Menu::getPosValue()	// Obtain unsigned from cin
{
	unsigned value;

	while (true) {
		cin >> value;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl

		if (cin.fail())		// Error in input
		{
			cin.clear();	// Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		}
		else 
		{
			return value;	// Valid value
		}
		cout << "Invalid input!\n";
		cout << "Enter value again: ";
	}
}
