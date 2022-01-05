/*	Filename:	RoulettePlayer.cpp
	Author:		Per Westerlund
	Date:		2021-09-08
	Summary:	Class RoulettePlayer
				Implements Roulette player	*/

#include "RoulettePlayer.h"
#include <iostream>
#include <string>

using namespace std;

bool RoulettePlayer::setGame(IGame* gamep)	// Sets the specific game for this player to play
{
	if (gamep->getID() != ROULETTE_ID)
		return false;				// If the game specified is other than Roulette - return error

	if (_gamep != NULL && _gamep != gamep)
		delete _gamep;				// If occupied by other game and not equal - delete it

	_gamep = gamep;
	return true;
}


bool RoulettePlayer::play(int numberOfTimes)	// Play given nr of rounds. Return false if bet > money left.
{
	int betSize;				// Bet size
	char* bet = new char[20];	// Bet Code 
	const char* betStr;			// const needed for conversion function
	char* pEnd;					// End of strtol conversion
	int betNr, betNr2, betNr3;	// Numbers betted on
	bool validInput = false;

	while (!validInput) {
		cout << "\nEnter Bet Code: ";
		cin.get(bet, 20);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl

		if (cin.fail())		// Error in input
		{
			cin.clear();	// Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		}

		// Single letter Bet Code
		if (bet[0] == 'L' || bet[0] == 'H' || bet[0] == 'O' || bet[0] == 'E')
		{
			if (bet[1] == '\0')	
				validInput = true;
		}	

		betStr = bet;
		// Check that bet numbers are in valid range
		switch (bet[0])
		{
		case 'D':	// Pair
			betNr = strtol(++betStr, &pEnd, 10);
			betNr2 = strtol(pEnd, &pEnd, 10);

			if (*pEnd == '\0' && betNr >= 1 && betNr <= 36 && betNr2 >= 1 && betNr2 <= 36)
				validInput = true;
			break;
		case 'T':	// Triple
			betNr = strtol(++betStr, &pEnd, 10);
			betNr2 = strtol(pEnd, &pEnd, 10);
			betNr3 = strtol(pEnd, &pEnd, 10);

			if (*pEnd == '\0' && betNr >= 1 && betNr <= 36 && betNr2 >= 1 && betNr2 <= 36 && betNr3 >= 1 && betNr3 <= 36)
				validInput = true;
			break;
		case 'R':	// Row (Street)
			betNr = strtol(++betStr, &pEnd, 10);

			if (*pEnd == '\0' && betNr >= 1 && betNr <= 12)
				validInput = true;
			break;
		default:	// Single nr
			betNr = strtol(betStr, &pEnd, 10);

			if (*pEnd == '\0' && betNr >= 1 && betNr <= 36)
				validInput = true;
			break;
		}
		if (!validInput)
			cout << "Invalid bet code!";
	}

	validInput = false;

	while (!validInput)
	{
		cout << "\nEnter Bet Size: ";
		cin.get(bet, 10);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl

		if (cin.fail())		// Error in input
		{
			cin.clear();	// Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Ignores characters including first endl
		}
		else
		{
			betSize = strtol(bet, &pEnd, 10);	// Max 10 chars

			if (*pEnd == '\0')
				validInput = true;
		}
		if (!validInput)
			cout << "Invalid input!";
	}

	for (int count = 1; count <= numberOfTimes; ++count) {

		if (_money - betSize < 0)	// Bet > money
			return false;

		_money += _gamep->play(bet, betSize) - betSize;	// Place bet, play and calculate money after game
		++_betCount;
	}
	return true;
}