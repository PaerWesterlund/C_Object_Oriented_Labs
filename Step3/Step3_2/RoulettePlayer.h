/*	Filename:	RoulettePlayer.h
	Author:		Per Westerlund
	Date:		2021-08-30
	Summary:	Public interface for class RoulettePlayer
				Implements Roulette player settings		*/

#include <cstdlib>

#include "IPlayer.h"
#include "IGame.h"

// Code below partly from CrapPlayer.h included in Lab files
class RoulettePlayer : public IPlayer {
public:
	RoulettePlayer(int money) : _gamep(NULL), _money(money), _betCount(0), ROULETTE_ID(111222) {}
	virtual bool setGame(IGame* game);		// Gives the player a game object to use
	virtual bool play(int numberOfTimes);	// Tells player to play the game numberOfTimes times

	virtual int	getMoney() const {				// Returns the amount of money still available for game
		return _money;
	}

	virtual int getBetCount() const {			// Returns the total number of bets placed during object life time
		return _betCount;
	}

private:
	IGame* _gamep;								// Points out the game to use (should be a Roulette Game)
	int	_money;									// Shows the current amount of money available for playing
	int	_betCount;								// Shows the number of bets placed so far
	const int ROULETTE_ID;						// ID assigned to the Roulette game
};


