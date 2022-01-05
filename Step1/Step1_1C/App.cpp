/*	Filename:	App.cpp
	Author:		P�r Westerlund
	Date:		2021-04-11
	Summary:	Application class using Temperature and Menu Class to read temperature values from a textfile
				and calculate and display min, max and average.
*/
#include <Menu.h>
#include <Temperature.h>
#include <iostream>

class Application
{
public:
	Application();		// Constructor
	~Application();		// Destructor

	void run();			

private:						
	Menu		menuObj;		// These two objects are created when the Application constructor
	Temperature tempObj;		// is run in main() method
};

Application::Application()
{}

Application::~Application()
{}

void Application::run()
{
	char menuChoice = '0';

	if (!tempObj.initObject())				//If temperature values couldn't be read
		return;							

	while (menuChoice != '4')				//Until Quit is chosen
	{
		menuObj.showMenu();					//Show menu
		menuChoice = menuObj.getChoice();	//Get valid menu choice
		
		switch (menuChoice)
		{ 
		case '1':
			tempObj.displayValues();	//Displays temperatures
			break;
		case '2':
			tempObj.displayMinMax();	//Displays min & max temp
			break;
		case '3':
			tempObj.displayAverage();	//Displays average temp
			break;
		}
		cout << "\n\nPress Enter to continue:";
		cin.ignore(10000, '\n');
	}
	cout << "\n\nTerminating the program.";
	cout << "\n\nPress Enter to continue:";
	cin.ignore(10000, '\n');
}

int main()
{
	Application app;

	app.run();
	return 0;	//Normal exit code
}
