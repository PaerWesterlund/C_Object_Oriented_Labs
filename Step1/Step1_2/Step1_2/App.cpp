/*	Filename:	App.cpp
	Author:		Per Westerlund
	Date:		2021-06-30
	Summary:	Application class that handles user interaction with class CashRegister.
*/

using namespace std;
#include <CashRegister.h>
#include <iostream>
#include <string>
#include <sstream>

class Application
{
public:
	Application();		// Constructor
	~Application();		// Destructor

	void run();
private:
	void showMainMenu();
	void showSubMenu();
	char getChoice();
	void addItem(CashRegister* cashReg);
};

Application::Application()
{}

Application::~Application()
{}

void Application::showMainMenu()		//Displays main  menu
{
	system("cls");	//Clear screen
	cout << "\n\nMENU\n----\n\n1. New purchase\n2. Close register\n\nMake your choice: ";
}

void Application::showSubMenu()		//Displays sub menu
{
	system("cls");	//Clear screen
	cout << "\n\nMENU\n----\n\n1. Register item\n2. Finish purchase\n\nMake your choice: ";
}

char Application::getChoice()		//Returns menu choice
{
	char menuChoice = '0';

	cin.get(menuChoice);	//First character

	if (menuChoice > '2' || menuChoice < '1')	// Invalid choice
		menuChoice = '0';			

	return menuChoice;
}

void Application::addItem(CashRegister* cashReg)
{
	int category;
	string itemName, mystr;
	double price;
	bool regComplete = false;

	while (true)
	{
		cout << "Enter category number: ";
		cin >> category;

		if (cin.fail())		// Error in input
		{
			cin.clear();	// Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		}
		cout << "Enter item name: ";
		cin >> itemName;
		cout << "Enter price: ";
		cin >> price;

		if (cin.fail())		// Error in input
		{
			cin.clear();	// Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		}
		regComplete = cashReg->registerItem(category, itemName.c_str(), price);

		if (!regComplete)
			cout << "Invalid input(s) in item registration. Please try again." << endl;
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores endl in cin after input
			break;
		}
	}
}

void Application::run()
{
	char mainMenuChoice = '0';
	char subMenuChoice = '0';
	const int NO_OF_CATEGORIES = 5;	// No of categories in register

	CashRegister cashReg("Register.txt", NO_OF_CATEGORIES);	// Create cash register

	while (mainMenuChoice != '2')		//Until Quit is chosen
	{
		showMainMenu();					//Show main menu
		mainMenuChoice = getChoice();	//Get main menu choice
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores endl in cin after input

		if (mainMenuChoice == '1')		//New purchase
		{
			while (true)	//Until finished purchase
			{
				showSubMenu();					
				subMenuChoice = getChoice();	

				if (subMenuChoice == '1')		// Add item
					addItem(&cashReg);
				else if (subMenuChoice == '2')	// Finish purchase
				{
					cout << "Batch total: ";
					cout.precision(2);
					cout << fixed << cashReg.batchTotal() << " Kr";
					cout << "\n\nPress Enter to continue";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
					break;
				}
			}

		}
	}
	cout << "\nPress Enter to close register";
	cin.ignore(10000, '\n');
}

int main()
{
	Application app;

	app.run();
	return 0;	//Normal exit code
}