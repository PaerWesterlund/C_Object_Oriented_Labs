/*	Filename:	CashRegister.h
	Author:		Per Westerlund
	Date:		2021-06-28
	Summary:	Public interface for class CashRegister.
				Handles purchases made during ONE day and
				saves to permanent text file.			*/

using namespace std;
#include <fstream>

class CashRegister {
public:
	CashRegister(const char* fileName, int nrOfCategories);		// constructor
	~CashRegister();		// destructor
	bool registerItem(int category, const char* articleName, double amount);
	double batchTotal() {	// inline
		double total = _batchTotal;
		_batchTotal = 0;	// batchTotal() is expected to reset _batchTotal;
		return total;
	}
private:
	ofstream _file;			// Here will registered items be saved
	int _nrOfCategories;	// Products are organized in categories
	double* _categorySums;	// The vector will contain respective sum of each
							// category sold during the day
	double _batchTotal;		// Sold since the last summation
};