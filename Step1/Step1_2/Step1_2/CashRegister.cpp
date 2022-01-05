/*	Filename:	CashRegister.cpp
	Author:		Per Westerlund
	Date:		2021-06-28
	Summary:	Public interface for class CashRegister.
				Handles purchases made during ONE day and
				saves to permanent text file.			*/

using namespace std;
#include "CashRegister.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

CashRegister::CashRegister(const char* fileName, int nrOfCategories)
{
	_nrOfCategories = nrOfCategories;
	_batchTotal = 0;
	_categorySums = new double[nrOfCategories];

	for (int i = 1; i <= nrOfCategories; i++)	// Reset category sums
		_categorySums[i] = 0;

	_file.open(fileName, ios::app);	// Open in append mode

	if (_file.fail())	// Failed to open file
	{
		cerr << "\nError when creating/opening file";
		cout << "\nPress Enter";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		exit(EXIT_FAILURE);
	}
	_file << "----- REGISTER OPENED -----" << endl;
}

CashRegister::~CashRegister()
{
	double totalSales = 0;

	_file << "----- REGISTER CLOSED -----\n";
	_file << "Category totals for last opening period:\n";
	_file << "----------------------------------------\n";

	for (int i = 1; i <= _nrOfCategories; i++)
	{
		_file << "Category " << setw(3) << i << " : " << setw(9) << _categorySums[i] << endl;
		totalSales += _categorySums[i];
	}
	_file << "Total sales within all categories: " << totalSales << endl;
	_file << "==========================================================================" << endl;
	delete [] _categorySums;
	_file.close();
}

bool CashRegister::registerItem(int category, const char* articleName, double amount)
{
	if (category > _nrOfCategories  || category < 1)	// Invalid category
		return false;

	_file << "Cat." << setw(3) << category << " : " << setw(12) << fixed;
	_file.precision(2);
	_file << amount << " Kr. [ " << articleName << " ]" << endl;
	_batchTotal += amount;
	_categorySums[category] += amount;
	return true;
}
