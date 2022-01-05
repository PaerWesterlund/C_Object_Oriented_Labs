/*	Filename:	Compare.h
	Author:		Per Westerlund
	Date:		2021-04-22
	Summary:	Public interface for class Compare
				Compares input string with alphabet string	*/

const int MAX_NO_CHARS = 26;	//Max no of characters

class Compare
{
public:
	Compare();	//Default constructor
	~Compare();	//Destructor
	bool equal(const char*, const char*) const;		//Compares two char arrays. Returns true if equal.
	char* getAlphabet();							//Returns alphabet as char array.
private:
	char alphabet[MAX_NO_CHARS + 1];	//Alphabet char array
};

