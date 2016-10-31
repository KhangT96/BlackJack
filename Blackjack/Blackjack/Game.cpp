#include "Game.h"

Game::Game() {
	this->shuffleDeck = new int[52];
	this->nrOfDealedCards = 0;
	this->nrOfplayers = 0;
	shuffleCards();
}

Game::~Game() {
	delete this->shuffleDeck;
}

void Game::setPlayerInfo(const int player, const string &name, const int money)
{
	if (player == 1) {
		this->Pone.setName(name);
		this->Pone.setCM(money);
	}
	else {
		this->Ptwo.setName(name);
		this->Ptwo.setCM(money);
	}
}

void Game::setnrOfPlayer(const int NOP){
	this->nrOfplayers = NOP;
}

int* Game::shuffleCards() {
	srand(time(NULL));
	int deal = 0; int runtime = 52; int nrCDealed = 0;
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

string Game::getCard(const int player) const
{
	stringstream output;
	if (player == 1) {
		int *holder = this->Pone.getHand();
		for (int i = 0; i < this->Pone.getNOC(); i++) {
			output << this->gameDeck.toString(this->shuffleDeck[holder[i]]);
		}
	}
	else {
		int *holder = this->Ptwo.getHand();
		for (int i = 0; i < this->Ptwo.getNOC(); i++) {
			output << this->gameDeck.toString(this->shuffleDeck[holder[i]]);
		}
	}
	return output.str();
}

void Game::dealCard(const int player) {
	if (nrOfDealedCards < 52) {
		if (player == 1) {
			this->Pone.setHand(nrOfDealedCards++);
		}
		else {
			this->Ptwo.setHand(nrOfDealedCards++);
		}
	}
}

void Game::resetGame() {
	this->Pone.setNOC(0);
	this->Ptwo.setNOC(0);
	this->nrOfDealedCards = 0;
	shuffleCards();
}
