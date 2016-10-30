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
	Player Pone;
	Player Ptwo;

public:

	Game();
	~Game();
	int* shuffleCards(const int size);
	bool duplicate(const int* Deck, const int size, const int nrTCheck) const;
	string getCard(const int position) const;

};

#endif // !GAME_H

