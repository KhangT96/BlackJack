#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>  

class Game {

private:
	Player **P;
	Deck gameDeck;
	int *shuffleDeck;
	int nrOfDealedCards;
	int nrOfplayers;
	int* shuffleCards();
	bool duplicate(const int* Deck, const int size, const int nrTCheck) const;

public:

	Game();
	~Game();
	void setPlayerInfo(const int player, const string &name);
	void setnrOfPlayer(const int NOP);
	void setplayerMoney(const int player, const int money);
	int getnrOfPlayer() const;
	int getPlayerNOC(const int player) const;
	int getPlayerMoney(const int player) const;
	string showCards(const int player) const;
	string showPlayerName(const int player) const;
	void dealCard(const int player);
	void resetGame();
	int TotPoints(const int player);
	int caculatePoints(const int totPoints, const int currentvalue);


};

#endif // !GAME_H

