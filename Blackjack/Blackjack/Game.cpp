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

void Game::setplayerMoney(const int player, const int money) {
	if (player == 1) {
		Pone.setCM(money);
	}
	else {
		Ptwo.setCM(money);
	}
}

int Game::getnrOfPlayer() const {
	return this->nrOfplayers;
}

int Game::getPlayerNOC(const int player) const {
	int nrofCards = Ptwo.getNOC();
	if (player == 1) {
		nrofCards = Pone.getNOC();
	}
	return nrofCards;
}

int Game::getPlayerMoney(const int player) const {
	int playermoney = Ptwo.getCM();
	if (player == 1) {
		playermoney = Pone.getCM();
	}
	return playermoney;
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

string Game::showCards(const int player) const
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

string Game::showPlayerName(const int player) const {
	string name = "";
	if (player == 1) {
		name = Pone.getName();
	}
	else {
		name = Ptwo.getName();
	}
	return name;
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

int Game::TotPoints(const int player){
	int totPoints = 0;
	if (player == 1) {
		int *holder = this->Pone.getHand();
		for (int i = 0; i < this->Pone.getNOC(); i++) {
			totPoints = caculatePoints(totPoints, this->gameDeck.getValue(this->shuffleDeck[holder[i]]));
		}
	}
	else {
		int *holder = this->Ptwo.getHand();
		for (int i = 0; i < this->Ptwo.getNOC(); i++) {
			totPoints = caculatePoints(totPoints, this->gameDeck.getValue(this->shuffleDeck[holder[i]]));
		}
	}
	return totPoints;
}

int Game::caculatePoints(const int totPoints, const int currentvalue) {
	int Points = 0;
	if (currentvalue > 10) {
		Points = totPoints + 10;
	}
	else if (currentvalue > 1) {
		Points = totPoints + currentvalue;
	}
	else {
		Points = totPoints + 11;
		if (Points > 21) {
			Points = Points - 10;
		}
	}
	return Points;
}
