/*
Filename:	miserable.cpp
Date:		2021-04-05
This is a menu based program used to read logged temperature values from templog.txt
and display statistical calculations based on these values
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	int i, runProg=1;
	double temp, tempSum, tempAverage;
	char menuChoice;

	cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
	cin.get();

	while (runProg)
	{
		system("cls");	//Clear screen
		cout<<"\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";
		cin.get(menuChoice);
		cin.get();

		if (menuChoice == '1')	//Display temperature values
		{
			cout<<"\nDisplaying the latest 24 temperature values:\n\n";
			ifstream fil("templog.txt"); 	

			for (i = 0;i < 24; i++)
			{
				if (i % 6 == 0)
					cout<<endl;
				fil>>temp;
				cout<<fixed<<setprecision(2)<<setw(8)<<temp;
			}
			fil.close();
		}

		else if (menuChoice == '2')	//View maximum and minimum temperatures
		{
			cout<<"\nCalculating the maximum and minimum temperature...\n";
			double max=0, min=0;
			ifstream fil("templog.txt");	
			fil>>temp;
			max=min=temp;

			for (i = 1; i < 24; i++)
			{
				fil>>temp;
				if (temp > max)
					max=temp;
				if (temp < min)
					min=temp;
			}
			fil.close();
			cout<<"\nMaximum temperature: "<<fixed<<setprecision(2)<<max<<" degrees Celcius\n";
			cout<<"\nMinimum temperature: "<<min<<" degrees Celcius\n";
		}

		else if (menuChoice == '3')	//View average temperature
		{
			cout<<"\nCalculating average temperature...\n";
			tempSum=0.0;
			ifstream fil("templog.txt");

			for (i = 0; i < 24; i++)
			{
				fil>>temp;
				tempSum+=temp;
			}
			fil.close();
			tempAverage=tempSum/24;
			cout<<"\nAverage temperature: ";
			cout<<fixed<<setprecision(2)<<tempAverage<<" degrees Celcius\n";
		}

		else  //Quit
		{
			runProg=0;
			cout << "\n\nTerminating the program.";
		}
		cout<<"\n\nPress Enter to continue:";
		cin.get();
	}
	return 0;
}

