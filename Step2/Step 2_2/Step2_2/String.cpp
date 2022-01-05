/*	Filename:	String.cpp
	Author:		Per Westerlund
	Date:		2021-07-09
	Summary:	Class String
				Operator overloading for strings	*/

#include "String.h"

String::String()
{
	_strPtr = new char[STRING_MAX_LENGTH];
	_strLen = 0;
	_strPtr[0] = '\0';
}

String::String(const char* s)
{
	_strPtr = new char[STRING_MAX_LENGTH];

	for (_strLen = 0; _strLen < STRING_MAX_LENGTH; _strLen++)
	{
		if (s[_strLen] != '\0')				// NOT end of string
			_strPtr[_strLen] = s[_strLen];	// Copy char
		else break;
	}
	_strPtr[_strLen] = '\0';	// _strLen does not include '\0'
}

String::String(const String& s)
{
	_strPtr = new char[STRING_MAX_LENGTH];

	for (_strLen = 0; _strLen < STRING_MAX_LENGTH; _strLen++)
	{
		if (s._strPtr[_strLen] != '\0')				// NOT end of string
			_strPtr[_strLen] = s._strPtr[_strLen];	// Copy char
		else break;
	}
	_strPtr[_strLen] = '\0';	// _strLen does not include '\0'
}

String::~String()
{
	delete [] _strPtr;
}

String& String::operator=(const char* s)
{
	int i;

	_strPtr = new char[STRING_MAX_LENGTH];

	for (i = 0; i < STRING_MAX_LENGTH; i++)
	{
		if (s[i] != '\0')		// NOT end of string
			_strPtr[i] = s[i];	// Copy char
		else break;
	}
	_strPtr[i] = '\0';
	_strLen = i;
	return *this;
}

String& String::operator=(const String& s)
{
	int i;

	for (i = 0; i < STRING_MAX_LENGTH; i++)
	{
		if (s._strPtr[i] != '\0')		// NOT end of string
			_strPtr[i] = s._strPtr[i];	// Copy char
		else break;
	}
	_strPtr[i] = '\0';
	_strLen = i;
	return *this;
}

const String String::operator+(const String& s)
{
	int i, maxChars;

	String temp(*this);	// Copy left operand
	maxChars = STRING_MAX_LENGTH - this->_strLen;

	// Append right operand to left operand
	for (i = 0; i < maxChars; i++)
	{
		if (s._strPtr[i] == '\0')	
			break;

	 temp._strPtr[temp._strLen] = s._strPtr[i];
	 temp._strLen++;
	}
 temp._strPtr[temp._strLen] = '\0';	// Final string null terminated
	return temp;
}

const String String::operator+(const char* s)
{
	int i, maxChars;
	maxChars = STRING_MAX_LENGTH - this->_strLen;

	// Append right operand to left operand
	for (i = 0; i < maxChars; i++)
	{
		if (s[i] == '\0')
			break;

		this->_strPtr[this->_strLen + i] = s[i];
	}
	this->_strLen += i;
	this->_strPtr[this->_strLen] = '\0';	// Final string null terminated
	return *this;
}

bool String::operator==(const char* s) const
{
	for (int i = 0; i < this->_strLen; i++)
		if (this->_strPtr[i] != s[i])	// Will also detect early '\0'
			return false;
	return true;
}

istream& operator >> (istream& is, String& s)
{
	is >> s._strPtr;	// Entire string saved here
	s._strLen = 0;

	for (int i = 0; i < s.STRING_MAX_LENGTH; i++)	// Calculate string length
	{
		if (s._strPtr[i] != '\0')	// NOT end of string
			s._strLen++;
		else break;
	}
	return is;
}

const char* String::toC_str() const
{
	return this->_strPtr; // String object stored as C string
}

int String::getLength() const
{
	return this->_strLen;
}
