/*	Filename:	Compare.cpp
	Author:		Per Westerlund
	Date:		2021-04-22
	Summary:	Class Compare
				Compares input string with alphabet string	*/

#include "Compare.h"
#include <string>

Compare::Compare()	//Default constructor
{
	strcpy(alphabet, "abcdefghijklmnopqrstuvwxyz");	//Init alphabet string	
}

Compare::~Compare()	//Destructor
{
}

bool Compare::equal(const char* str1, const char* str2) const	//Compares two char arrays. Returns true if equal.
{
	if (!strcmp(str1, str2))	//strncmp returns 0 if equal strings
		return true;
	else return false;
}

char* Compare::getAlphabet()	//Returns alphabet as char array.
{
	return Compare::alphabet;
}


