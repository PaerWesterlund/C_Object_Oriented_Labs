/*	Filename:	App.cpp
	Author :	Per Westerlund
	Date :		2021 - 09 - 07
	Summary:	Application class implementing a
				Roulette game						*/

using namespace std;

#include <iostream>
#include "RouletteGame.h"
#include "RoulettePlayer.h"
#include "Menu.h"

class App {
public:
	App() : _player(NULL), _game(NULL), _nrOfTimes(0) {}
	int run();
	void setParams(IPlayer* player, IGame* game, int playNrOfTimes); 
	void setNumberOfTimes(int);	
private:
	IPlayer* _player;
	IGame* _game;
	int	_nrOfTimes = 0;		// Nr of times to play game
};

void App::setParams(IPlayer* player, IGame* game, int playNrOfTimes)
{
	_player = player;
	_game = game;
	_nrOfTimes = playNrOfTimes;
}

void App::setNumberOfTimes(int playNrOfTimes)	// Set number of rounds
{
	_nrOfTimes = playNrOfTimes;
}

int App::run() {
	if (!_player->setGame(_game))
	{
		cerr << "\nGame needs to be set to Roulette for a roulette player!";
		return -1;
	}
	else if (!_player->play(_nrOfTimes))	// Money run out
	{
		cerr << "\nBet is higher than money left!";
			return -1;
	}
	cout << "\nAfter " << _player->getBetCount() << " number of rounds, the player has " << _player->getMoney() << " SEK left!" << endl;
	return 0;
}

int main() {
	Menu menuObj;
	RouletteGame game;
	App app;
	bool objInit = false;		// App object initialized?
	char menuChoice = '0';
	int startAmount = 0;		// Initial amount of money
	int nrOfTimes = 0;			// Number of times to play game

	while (menuChoice != '4')				//Until Quit is chosen
	{
		menuObj.showMenu();					//Show menu
		menuChoice = menuObj.getChoice();	//Get valid menu choice

		switch (menuChoice)
		{
		case '1':
			if (startAmount == 0)
				startAmount = menuObj.getPosValue();
			else cout << "\nALREADY SET!";
			break;
		case '2':
				nrOfTimes = menuObj.getPosValue();
			break;
		case '3':
			if (startAmount == 0)
				cout << "\nInitial amount of money NOT SET!";
			else if (nrOfTimes == 0)
				cout << "\nNumber of times to play game is NOT SET!";
			else if (!objInit)
			{
				RoulettePlayer player(startAmount);
				app.setParams(&player, &game, nrOfTimes);
				objInit = true;
				app.run();
			}
			else
			{
				app.setNumberOfTimes(nrOfTimes);
				app.run();
			}
			break;
		}
		cout << "\nPress Enter to continue:";
		cin.ignore(10000, '\n');
	}

	return 0;	// QUIT
}