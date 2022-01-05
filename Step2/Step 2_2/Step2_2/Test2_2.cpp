/**********************************************************************/
// File:	Test2_2.cpp
// Summary:	Test file for Lab 2, Step 2
//          The program will test functionality for class String, which
//			is aimed to handle a number of common string-operations.
//			If defined according to requirements in given specification, 
//			the result of execution is expected to present console 
//			outputs like examples suggested in comments to test code.
//			NO CHANGES of the predefined code are allowed, except those 
//			needed to handle exceptions, if solving the optional task.
// Version: Version 1.1 - 2013-04-08
// Author:	Anne Norling
// ------------------------------------------
// Log:		2007-03-14	Created the file. Anne
//			2013-04-08	Uppdate  Version 1.1 by Anne. 
//						Converted to English and VS 2012
//			2015-03-06	Revised by Anne. Converted to VS 2013
//			2018-04-05  Code tested for VS 2017, by Anne
/**********************************************************************/

#include <iostream>
#include "String.h"
using std::cout;
using std::cin;
using std::endl;

class Application
{
public:
	int run();
};

int Application::run()
{
	String str1("Hello ");
	String str2(str1);
	cout << str1 << str2 << endl;	// Shall print "Hello Hello "

	str2 = "my world!";
	cout << str1 << str2 << endl;	// Shall print "Hello my world!"

	String str3;
	cout << "Enter a name: ";
	cin >> str3;				// (... The user enters for instance "Pluto"...)
	str2 = str1 + str3;
	cout << str2 << endl;		// Shall print "Hello Pluto"
	str2 = "Goodbye " + str3;
	cout << str2 << endl;		// Shall print "Goodbye Pluto"
	cout << str1 << "and " << "Goodbye " 
			<< (str1 == "Goodbye " ? "is " : "is not ") << "the same word!\n";
								// Shall print "Hello and Goodbye is not the same word!"
	return 0;
}

int main()
{
	Application myApp;
	return myApp.run();
}