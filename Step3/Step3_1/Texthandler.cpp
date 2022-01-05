/*	Filename:	TextHandler.cpp
	Author:		Per Westerlund
	Date:		2021-05-14
	Summary:	Class TextHandler.
				Reads several texts from one text file and saves them in an object.
				The individual texts can then be retrieved.	*/

using namespace std;

#include "TextHandler.h"
#include <string>
#include <fstream>	
#include <iostream>

const int INPUT_BUFFER_SIZE = 10000;

Texthandler::Texthandler(string fileName, int nrOfTexts)		// Constructor
{
	maxNoOfTexts = nrOfTexts;	// Set class variable
	fstream file;

	file.open(fileName);

	if (file.fail())	//Failed to open file
	{
		cerr << "\nUnable to open file";
		throw "File open error";
	}

	textsP = new char* [maxNoOfTexts];		// Define array for text pointers

	for (int i = 0; i < maxNoOfTexts; i++)	
		textsP[i] = NULL;					// Initialize pointers

	char* readArray = new char[INPUT_BUFFER_SIZE];	// Define char array for text to be read
	int textInputIndex = 0;							// Index where next line should be appended
	string textLine;								// Line of text read by getline()

	while (getline(file, textLine))		// Read line of text
	{
		if (textLine == "%%%%%")	// Separator line
		{
			if (noOfTexts == 0 && textInputIndex == 0)	// First occurence of 5% signs
				continue;	// Skip line
			else if (noOfTexts == maxNoOfTexts)			// Max nr of texts read
				break;
			else
			{	// Complete story read
				char* text = new char[textInputIndex];	// Create text array with precise length
				readArray[textInputIndex] = '\0';		// Put NULL char at end
				strcpy(text, readArray);				// Copy readArray to text. strcpy stops at null char.
				noOfTexts++;
				textsP[noOfTexts - 1] = text;			// Save text pointer
				textInputIndex = 0;
			}

		}
		else   // NOT end of text. Add read line to array.
		{
			if (textInputIndex + textLine.length() >= INPUT_BUFFER_SIZE)
			{
				cerr << "Input read buffer exceeds limit of 10000 characters!";
				throw "read buffer overflow";
			}

			strcpy(readArray + textInputIndex, textLine.c_str());	// Convert to c string then append to previous characters
			textInputIndex += textLine.length();					// Update index
			readArray[textInputIndex++] = '\n';						// Add new line char
		}
	}

	textLine.clear();	// Erase string contents
	delete [] readArray;	// Delete input read array
	file.close();
}

Texthandler::~Texthandler()				// Destructor
{
	for (int i = 0; i < noOfTexts; i++)
		delete [] textsP[i];			// Delete saved text arrays
	delete [] textsP;					// Delete saved text pointers
}

int Texthandler::maxNrOfTexts()			// Returns max number of texts
{
	return maxNoOfTexts;
}

int Texthandler::nrOfTexts()			// Returns number of texts loaded in object
{
	return noOfTexts;
}

const char* Texthandler::text(int i) const	// Returns pointer to text indexed by argument
{
	if (i >= 0 && i < maxNoOfTexts)
		return textsP[i];
	else return NULL;
}
