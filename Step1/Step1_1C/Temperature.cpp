/*	Filename:	Temperature.cpp
	Author:		P�r Westerlund
	Date:		2021-04-10
	Summary:	Class with constructors that reads temperature values from a textfile into a vector.
				Functions calculate and retrieve temperature values, min/max and average.
*/
#include "Temperature.h"
#include <fstream>	//file handling
#include <iostream>
#include <iomanip>	//setprecision, setw
using namespace std;

Temperature::Temperature(string logFileName, int numberOfValues)	//Constructor with filename containing temperature values and number of values.
{
	fileName = logFileName;
	noOfValues = numberOfValues;
	minMaxCalc = false;
	averageCalc = false;
	max = 0, min = 0;
	average = 0;
}

Temperature::Temperature()	//Constructor using deafult text file and number of values.
{
	fileName = "templog.txt";	//Default file name
	noOfValues = 24;			//Default number of values
	minMaxCalc = false;
	averageCalc = false;
	max = 0, min = 0;
	average = 0;
}

Temperature::~Temperature()	//Destructor
{}

bool Temperature::initObject()	//Reads temperature values from text file and puts in temp vector. Returns false upon error.
{
	fstream fil;
	double	tempValue;
	int i;

	fil.open(fileName);

	if (fil.fail())	//Failed to open file
	{
		cerr << "\nUnable to open log file";
		cout << "\nPress Enter to quit";
		cin.ignore(10000, '\n');
		return false;
	}

	for (i = 0; i < noOfValues && !fil.eof(); i++)	//Read values to vector
	{
		fil >> tempValue;
		temp.push_back(tempValue);	//Assign to vector
	}

	noOfValues = i;
	fil.close();
	return true;
}

void Temperature::displayValues()	//Displays temperatures
{
	cout << "\nDisplaying the latest " << temp.size() << " temperature values:\n\n";

	for (int i = 0; i < temp.size(); i++)
	{
		if (i % 6 == 0)
			cout << endl;
		cout << endl << fixed << setprecision(2) << setw(8) << temp.at(i);
	}
}

void Temperature::displayMinMax()	//Displays min & max temp. Calculate if not done.
{
	if (!minMaxCalc)
		calcMinMax();	//Calculate if it's not
	
	cout << "\nMaximum temperature: " << fixed << setprecision(2) << max << " degrees Celcius\n";
	cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
}

void Temperature::displayAverage()	//Displays average temp. Calculate if not done.
{
	if (!averageCalc)
		calcAverage();	//Calculate if it's not

	cout << "\nAverage temperature: ";
	cout << fixed << setprecision(2) << average << " degrees Celcius\n";
}

void Temperature::calcMinMax()		//Calculates min and max temperature
{
	max = min = temp.at(0);

	for (int i = 1; i < temp.size(); i++)
	{
		if (temp.at(i) > max)
			max = temp.at(i);
		if (temp.at(i) < min)
			min = temp.at(i);
	}
}
void Temperature::calcAverage()		//Calculates average temperature
{
	double tempSum = 0.0;

	for (int i = 0; i < temp.size(); i++)
	{
		tempSum += temp.at(i);
	}

	average = tempSum / temp.size();
}