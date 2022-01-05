/*	Filename:	Temperature.h
	Author:		Pär Westerlund
	Date:		2021-04-10	
	Summary:	Public interface for class Temperature
				Functions calculate/retireve temperature values, min/max and average	*/
#include <string>
#include <vector>
using namespace std;

class Temperature
{
public:
	Temperature();						//Constructor using deafult text file and number of values.
	Temperature(string, int);			//Constructor with filename containing temperature values and number of values.
	~Temperature();						//Destructor
	bool initObject();					//Reads temperature values from text file and puts in temp vector. Return false upon error.
	void displayValues();				//Displays temperatures
	void displayMinMax();				//Displays min & max temp. Calculate if not done.
	void displayAverage();				//Displays average temp. Calculate if not done.
	vector<double> getTemperatures();	//Returns temperature values
	double getMin();					//Returns min temperature. Calculate if it's not.
	double getMax();					//Returns max temperature. Calculate if it's not.
	double getAverage();				//Returns average temperature. Calculate if it's not.
private:
	void calcMinMax();					//Calculates min and max temperature
	void calcAverage();					//Calculates average temperature
	string fileName;					//File name of textfile with temperatures
	int	noOfValues;						//Number of temperature values input to constructor
	vector<double> temp;				//Temperature values
	double min;							//Min temp
	double max;							//Max temp
	double average;						//Average temp
	bool minMaxCalc;					//Min & max temp calculated
	bool averageCalc;					//Average temp calculated
};

