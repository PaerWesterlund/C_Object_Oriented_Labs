/*	Filename:	Application.cpp
	Author:		Per Westerlund
	Date:		2021-04-22
	Summary:	Application class using Compare, Clock & MyTime classes.
				It measures how fast the alphabet is typed.
*/
#include <Compare.h>
#include <Clock.h>
#include <MyTime.h>
#include <iostream>
#include <string>

using namespace std;

class Application
{
public:
	Application();		// Constructor
	~Application();		// Destructor

	void run();

private:
	Compare* compareP = 0;			//Pointers to objects created with new in run()
	Clock* clockP = 0;				//Initialized to NULL = 0
	MyTime* startTimeP = 0;
	MyTime* stopTimeP = 0;
};

Application::Application()	
{}

Application::~Application()
{}

void Application::run()
{
	string inputString;
	
	compareP = new Compare();	//Create Compare object

	system("cls");	//Clear screen
	cout << "Type the alphabet (or beginning of) in small letters as fast as possible!";
	cout << "\nThe time will be measured from first Enter. Press Enter to finish input string.";
	cout << "\nPress Enter to start!";
	cin.ignore(10000, '\n');	//Ignore characters before ENTER
	cout << "\nType alphabet: ";
	clockP = new Clock();	//Create Clock object
	startTimeP = new MyTime((clockP->give_me_the_time()));	//Set start time
	getline(cin, inputString);

	if (compareP->equal(inputString.c_str(), compareP->getAlphabet()))	//Check if input string equals alphabet
	{
		stopTimeP = new MyTime((clockP->give_me_the_time()));	//Set stop time
		cout << "\nAlphabet typed correctly!";
		cout << "\nTime elapsed: " << (*stopTimeP - *startTimeP) << " (hh:mm:ss)";
		delete stopTimeP;	//Delete MyTime object
	}
	else cout << "\nAlphabet NOT typed correctly!";
	delete startTimeP;	//Delete MyTime object
	delete clockP;		//Delete Clock object
	delete compareP;	//Delete Compare object
	cout << "\nPress Enter to end program!";
	cin.ignore(10000, '\n');	//Ignore characters before ENTER
}

int main()
{
	Application app;

	app.run();
	return 0;	//Normal exit code
}
