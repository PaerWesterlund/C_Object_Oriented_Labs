/*	Filename:	Menu.h
	Author:		Pär Westerlund
	Date:		2021-04-10
	Summary:	Public interface for class Menu
				Functions shows Menu and handles Menu choice	*/
#include <string>
using namespace std;

class Menu
{
public:
	Menu();
	~Menu();
	void showMenu();	//Displays menu
	char getChoice();	//Returns users menu choice
};

