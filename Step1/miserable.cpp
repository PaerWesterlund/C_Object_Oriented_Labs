/*
Filename:	miserable.cpp
Date:		2021-04-05
This is a menu based program used to read logged temperature values from templog.txt
and display statistical calculations based on these values
*/

#include <iostream>
#include <fstream>
#include <iomanip>	//setprecision, setw
#include <vector>	//vectors
using namespace std;

//void resetFile(ifstream&);		//Reset file to be read from beginning
void displayValues(vector<double>, int);	//Read temperature values and display them
void minMaxTemp(vector<double>, int);		//Calculate min and max temperature and display them
void AverageTemp(vector<double>, int);		//Calculate average temperature

int main()
{
	int i, noOfValues = 24, runProg = 1;
	double temp;
	char menuChoice;
	ifstream fil;
	string fileName = "templog.txt";
	vector<double> temperature;

	cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
	cin.get();	//CHECK FOR ENTER!
	fil.open(fileName);

	if (fil.fail())	//Failed to open file
	{	
		cerr << "\nUnable to open log file";
		cout << "\nPress Enter to quit";
		cin.get();
		return -1;
	}

	/*while (!fil.eof()) 
	{
		fil >> temp;
		temperature.push_back(temp);	//Assign to vector
		noOfValues++;
	}*/

	for (i = 0; i < noOfValues && !fil.eof(); i++)
	{
		fil >> temp;
		temperature.push_back(temp);	//Assign to vector
	}
	noOfValues = i;

	for (i = 0; i < noOfValues; i++) 
	{
		cout << endl << i << fixed << ": " << setprecision(2) << setw(8) << temperature.at(i);
	}
	cin.get();

	while (runProg)
	{
		system("cls");	//Clear screen
		cout<<"\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";
		cin.get(menuChoice);
		cin.get();

		if (menuChoice == '1')	//Display temperature values
		{
			cout << "\nDisplaying the latest " << noOfValues << " temperature values:\n\n";
			displayValues(temperature, noOfValues);
		}

		else if (menuChoice == '2')	//View maximum and minimum temperatures
		{
			cout<<"\nCalculating the maximum and minimum temperature...\n";
			minMaxTemp(temperature, noOfValues);
		}

		else if (menuChoice == '3')	//View average temperature
		{
			cout<<"\nCalculating average temperature...\n";
			AverageTemp(temperature, noOfValues);
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
		cin.get();
	}
	fil.close();
	return 0;
}

/*void resetFile(ifstream& file) 
{
	file.clear();	//Clear file stream state
	file.seekg(0);	//Set file stream to beginning
}*/

void displayValues(vector<double> temp, int noOfValues)	//Read temperature values and display them
{

	for (int i = 0; i < noOfValues; i++)
	{
		if (i % 6 == 0)
			cout << endl;
		cout << endl << fixed << setprecision(2) << setw(8) << temp.at(i);
	}
}

void minMaxTemp(vector<double> temp, int noOfValues)	//Calculate min and max temperature and display them
{
	double max = 0, min = 0;
	max = min = temp.at(0);	

	for (int i = 1; i < noOfValues; i++)
	{
		if (temp.at(i) > max)
			max = temp.at(i);
		if (temp.at(i) < min)
			min = temp.at(i);
	}
	cout << "\nMaximum temperature: " << fixed << setprecision(2) << max << " degrees Celcius\n";
	cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
}

void AverageTemp(vector<double> temp, int noOfValues)		//Calculate average temperature
{
	double tempAverage, tempSum = 0.0;

	for (int i = 0; i < noOfValues; i++)
	{
		tempSum += temp.at(i);
	}
	tempAverage = tempSum / noOfValues;
	cout << "\nAverage temperature: ";
	cout << fixed << setprecision(2) << tempAverage << " degrees Celcius\n";

}