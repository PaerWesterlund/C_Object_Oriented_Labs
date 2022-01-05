/*	Filename:	String.h
	Author:		Per Westerlund
	Date:		2021-07-13
	Summary:	Public interface for class String
				Operator overloading for strings	*/

using namespace std;

#ifndef STRING_H // String.h
#define STRING_H
#include <iostream>	// Used in inline functions

class String
{
	friend istream& operator>>(istream& is, String& s);
public:
	// Constructors
	String();
	String(const char* s);
	String(const String& s);
	~String();
	// Operator overloading
	const String operator+(const String& s);
	const String operator+(const char* s);
	String& operator=(const char* s);
	String& operator=(const String& s);
	bool operator==(const char* s) const;
	// Additional functions
	const char* toC_str() const;
	int getLength() const;
private:
	char* _strPtr;
	int _strLen;
	const int STRING_MAX_LENGTH = 100;
};

inline ostream& operator << (ostream& os, const String& s)
{
	os << s.toC_str();
	return os;
}

inline String operator+(const char* c, const String& s)
{
	String temp(c);
	return temp + s;
}
#endif /* STRING_H */