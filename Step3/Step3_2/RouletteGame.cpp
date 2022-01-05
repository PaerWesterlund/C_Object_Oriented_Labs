/*	Filename:	RouletteGame.cpp
	Author :	Per Westerlund
	Date :		2021 - 08 - 30
	Summary:	Class RouletteGame
				Implements Roulette game	*/

#include "RouletteGame.h"

#include <cstdlib>
#include <iostream>

int RouletteGame::play(char* bet, int amount)
{
	int nr = _rnd.getNumber();	// Spin wheel -> get roulette number
	const char* betStr = bet;	// const needed for conversion
	char* pEnd;					// End of strtol conversion
	int betNr, betNr2, betNr3;	// Numbers betted on

	std::cout << "\nRoulette nr: " << nr;

	switch (bet[0])
	{
		case 'L':	// Low nr (1-18)
			if (nr >= 1 && nr <= 18)
				return amount;
			break;
		case 'H':	// High nr (19-36)
			if (nr >= 19 && nr <= 36)
				return amount;
			break;
		case 'E':	// Even nr (Black), not 0
			if (nr % 2 == 0 && nr != 0)
				return amount;
			break;
		case 'O':	// Odd nr (Red)
			if (nr % 2 != 0)
				return amount;
			break;
		case 'D':	// Pair
			betNr = strtol(++betStr, &pEnd, 10);
			betNr2 = strtol(pEnd, NULL, 10);
			if (betNr == nr || betNr2 == nr)
				return 17 * amount;
			break;
		case 'T':	// Triple
			betNr = strtol(++betStr, &pEnd, 10);
			betNr2 = strtol(pEnd, &pEnd, 10);
			betNr3 = strtol(pEnd, NULL, 10);
			if (betNr == nr || betNr2 == nr || betNr3 == nr)
				return 11 * amount;
			break;
		case 'R':	// Row (Street)
			betNr = strtol(++betStr, NULL, 10);
			if (nr >= betNr * 3 - 2 && nr <= betNr * 3)
				return 5 * amount;
			break;
		default:	// Single nr
			betNr = strtol(betStr, NULL, 10);
			if (betNr == nr)
				return 35 * amount;
			break;
	}

	return 0;	// Loss!
}