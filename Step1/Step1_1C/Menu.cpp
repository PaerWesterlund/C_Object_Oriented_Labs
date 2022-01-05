/*	Filename:	Menu.cpp
	Author:		Per Westerlund
	Date:		2021-04-10
	Summary:	Class Menu.	Functions shows Menu and returns Menu choice
*/
#include "Menu.h"
#include <string>
#include <iostream>
#include <iomanip>	
using namespace std;

Menu::Menu()
{}

Menu::~Menu()
{}

void Menu::showMenu()		//Displays menu
{
	system("cls");	//Clear screen
	cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";
}

char Menu::getChoice()		//Returns menu choice only after getting valid input
{
	char menuChoice = '0', enterKey;

	while (menuChoice == '0')	//Wait until valid choice
	{
		cin.get(menuChoice);	//First character
		cin.get(enterKey);		//Second character

		if (menuChoice > '4' || menuChoice < '1' || menuChoice == '\n')	//First character is ENTER or invalid choice
			menuChoice = '0';			//Incorrect menu choice

		if (enterKey != '\n') {			//Second character is not ENTER
			cin.ignore(10000, '\n');	//Ignores the rest until ENTER
			menuChoice = '0';			//Incorrect menu choice
		}

		if (menuChoice != '0')			//Valid menu choice
			return menuChoice;
		else
		{
			cout << "\nIncorrect menu choice! Press ENTER to continue";
			cin.ignore(10000, '\n');	//Ignores the rest until ENTER
			Menu::showMenu();			//CLear screen and show menu again
		}
	}
	return menuChoice;
}