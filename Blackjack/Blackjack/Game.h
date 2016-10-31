#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>  

class Game {

private:

	Deck gameDeck;
	int *shuffleDeck;
	int nrOfDealedCards;
	Player Pone;
	Player Ptwo;
	int* shuffleCards();
	bool duplicate(const int* Deck, const int size, const int nrTCheck) const;

public:

	Game();
	~Game();
	string getCard(const int player) const;
	void dealCard(const int player);
	void resetGame();

};

#endif // !GAME_H

