#include "Game.h"

Game::Game() {
	this->shuffleDeck = shuffleCards(52);
}

Game::~Game() {
	delete this->shuffleDeck;
}

int* Game::shuffleCards(const int size) {
	srand(time(NULL));
	int *shuffleDeck = new int[size];
	int deal = 0; int runtime = size; int nrCDealed = 0;
	for (int i = 0; i < runtime; i++) {
		deal = rand() % 52;
		if (duplicate(shuffleDeck, nrCDealed, deal)) {
			runtime++;
		}
		else {
			shuffleDeck[nrCDealed++] = deal;
		}
	}
	return shuffleDeck;
}

bool Game::duplicate(const int * Deck, const int size, const int nrTCheck) const
{
	bool duplicated = false;
	for (int i = 0; i < size && duplicated == false; i++) {
		if (nrTCheck == Deck[i]) {
			duplicated = true;
		}
	}
	return duplicated;
}

string Game::getCard(const int position) const
{
	return this->gameDeck.toString(shuffleDeck[position]);
}
