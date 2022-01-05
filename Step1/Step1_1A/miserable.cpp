/*
Filename:	miserable.cpp
Date:		2021-04-08
Summary:	This is a menu based program used to read logged temperature values from templog.txt
			and display statistical calculations based on these values
*/

#include <iostream>
#include <fstream>
#include <iomanip>	//setprecision, setw
#include <vector>	//vectors
using std::ifstream;
using std::string;
using std::endl;
using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::setprecision;
using std::setw;
using std::fixed;

void displayValues(vector<double>);		//Read temperature values and display them
void minMaxTemp(vector<double>);		//Calculate min and max temperature and display them
void AverageTemp(vector<double>);		//Calculate average temperature

int main()
{
	int runProg = 1;
	const int NO_OF_VALUES = 24;
	double temp;
	char menuChoice, enterKey;
	ifstream fil;
	string fileName = "templog.txt"; 
	vector<double> temperature;

	cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
	cin.ignore(10000, '\n');	//Ignores characters before ENTER
	fil.open(fileName);

	if (fil.fail())	//Failed to open file
	{	
		cerr << "\nUnable to open log file";
		cout << "\nPress Enter to quit";
		cin.ignore(10000, '\n');
		return -1;
	}

	for (int i = 0; i < NO_OF_VALUES && !fil.eof(); i++)	//Read values to vector
	{
		fil >> temp;
		temperature.push_back(temp);	//Assign to vector
	}

	while (runProg)
	{
		system("cls");	//Clear screen
		cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";
		cin.get(menuChoice);		
		cin.get(enterKey);

		if (enterKey != '\n') {			//Second character is NOT ENTER
			cin.ignore(10000, '\n');	//Ignores the rest until ENTER
			menuChoice = '5';			//Incorrect menu choice
		}

		if (menuChoice == '1')	//Display temperature values
		{
			cout << "\nDisplaying the latest " << temperature.size() << " temperature values:\n\n";
			displayValues(temperature);
		}

		else if (menuChoice == '2')	//View maximum and minimum temperatures
		{
			cout << "\nCalculating the maximum and minimum temperature...\n";
			minMaxTemp(temperature);
		}

		else if (menuChoice == '3')	//View average temperature
		{
			cout << "\nCalculating average temperature...\n";
			AverageTemp(temperature);
		}

		else if (menuChoice == '4') //Quit
		{
			runProg=0;
			cout << "\n\nTerminating the program.";
		}

		else {	//Incorrect input
			cout << "\nIncorrect menu choice!";
		}
		cout<<"\n\nPress Enter to continue:";
		cin.ignore(10000, '\n');
	}
	fil.close();
	return 0;
}

void displayValues(vector<double> temp)	//Read temperature values and display them
{

	for (int i = 0; i < temp.size(); i++)
	{
		if (i % 6 == 0)
			cout << endl;
		cout << endl << fixed << setprecision(2) << setw(8) << temp.at(i);
	}
}

void minMaxTemp(vector<double> temp)	//Calculate min and max temperature and display them
{
	double max = 0, min = 0;
	max = min = temp.at(0);	

	for (int i = 1; i < temp.size(); i++)
	{
		if (temp.at(i) > max)
			max = temp.at(i);
		if (temp.at(i) < min)
			min = temp.at(i);
	}
	cout << "\nMaximum temperature: " << fixed << setprecision(2) << max << " degrees Celcius\n";
	cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
}

void AverageTemp(vector<double> temp)		//Calculate average temperature
{
	double tempAverage, tempSum = 0.0;

	for (int i = 0; i < temp.size(); i++)
	{
		tempSum += temp.at(i);
	}
	tempAverage = tempSum / temp.size();
	cout << "\nAverage temperature: ";
	cout << fixed << setprecision(2) << tempAverage << " degrees Celcius\n";

}