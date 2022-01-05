/*	Filename:	TextHandler.h
	Author:		Per Westerlund
	Date:		2021-05-14
	Summary:	Public interface for class TextHandler
				Reads several texts from one text file and saves them in an object.
				The individual texts can then be retrieved.	*/

using namespace std;

#include <string>

class Texthandler
{
public:
	Texthandler(string, int);	// Constructor
	~Texthandler();				// Destructor
	int maxNrOfTexts();			// Returns max number of texts
	int nrOfTexts();			// Returns number of texts loaded
	const char* text(int) const;// Returns pointer to text indexed by argument
private:
	char** textsP = NULL;		// Array of char pointers to texts
	int maxNoOfTexts = 0;		// Max no of texts that can be loaded
	int noOfTexts = 0;			// No of texts loaded
};