/**********************************************************************/
// File:	TextTest-en.cpp
// Summary:	Test file for Lab 1, Step 3
//          The program will test functionality for class Texthandler, 
//			which is aimed to read a number of stories from a textfile,
//			in order to present them on the console screen.
// Version: Version 1.1 - 2013-05-02
// Author:	Christer Lundberg
// ------------------------------------------
// Log:		2003-09-25	Created the file. Christer
//			2013-05-02	Uppdate  Version 1.1 by Anne. 
//						Converted to English and VS 2012
//			2015-03-10	Revised by Anne. Converted to VS 2013
//			2018-04-05  Code tested for VS 2017, by Anne
/**********************************************************************/

#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Texthandler.h"

// FOR DEBUGGING MEM LEAKS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class App {
public:
	int run();
};

int App::run()
{
	int maximalNumberOfTexts = 20;
	int check[] = {6, 207, 424, 113, 148, 84, 105};			// For test purpose

	try {
		Texthandler th("Stories.txt", maximalNumberOfTexts); // Assumes the text file in the project folder

		if (th.nrOfTexts() != check[0]) {
			cout << "Number of saved stories is " << th.nrOfTexts()
				<< " but should be " << check[0] << "!" << endl;
			cout << "Program cancelled!" << endl;
			return -1;
		}

		if (th.maxNrOfTexts() != maximalNumberOfTexts) {
			cout << "Number of stories that can be saved into the texthandler is " << th.maxNrOfTexts()
				<< " but should be " << maximalNumberOfTexts << "!" << endl;
			cout << "Program cancelled!" << endl;
			return -1;
		}

		int currentNrOfTexts = th.nrOfTexts();
		int nrOfChars;

		for (int i = 0; i < currentNrOfTexts; ++i) {
			nrOfChars = (int)strlen(th.text(i));
			cout << "Text nr " << i + 1 << " contains " << nrOfChars << " characters.\n";

			if (nrOfChars != check[i+1]) {
				cout << "ERROR: Length of text should have been " << check[i+1]
				<< "!" << endl;
			}
			cout << "----------------------------------------------------\n";
			cout << th.text(i) << endl << endl;
		}

		if (th.text(6) != 0) 
			cout << "ERROR: You should return NULL when trying to retrieve a text that does not exist!" << endl;
		cout << "Press Enter to quit the program";

		char buf[20];
		cin.getline(buf, 20);
	}
	catch (...){
		// Catches all... If any exception thrown in TextHandler class, it will be caught here.
		cout << "An error occured during program execution. Program ended!" << endl;
		return 1;		
	}
	return 0;
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	App app;
	return app.run();
}