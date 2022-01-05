/*	Filename:	RouletteGame.h
	Author :	Per Westerlund
	Date :		2021 - 08 - 30
	Summary:	Public interface for class RouletteGame
				Implements Roulette game	*/

#include <cstdlib>
#include <ctime>

#include "IGame.h"

// Code below partly from CrapGame.h included in Lab files
class RouletteGame : public IGame {
public:
	RouletteGame() : _rnd(0, 36) {}
	virtual int play(char* bet, int amount);		// Place amount money on position bet and return winnings
	virtual int getID() const {
		return ROULETTE_ID;
	}
private:
	static const int ROULETTE_ID = 111222;			// This is a unique number assigned to the Roulette game

	class Randomizer {								// Inner nested class...
	public:
		Randomizer(int min, int max) : _min(min), _max(max) {
			srand((unsigned)time(NULL));
		}

		int getNumber() {
			return (rand() % (_max - _min + 1)) + _min;
		}
	private:
		int _min, _max;
	} 
	_rnd;	// Creates an object of Randomizer class (used in play() in RouletteGame.cpp)
};