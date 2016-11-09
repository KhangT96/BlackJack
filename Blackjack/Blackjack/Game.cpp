#include "Game.h"

Game::Game() {
	this->shuffleDeck = new int[52];
	this->P = new Player*[2];
	this->nrOfDealedCards = 0;
	this->nrOfplayers = 0;
	for (int i = 0; i < 2; i++) {
		this->P[i] = new Player();
	}
	shuffleCards();
}

Game::~Game() {
	delete this->shuffleDeck;
	for (int i = 0; i < this->nrOfplayers; i++) {
		delete this->P[i];
	}
	delete this->P;
}

void Game::onePlayer() {
	delete this->P[1];
}

void Game::setPlayerInfo(const int player, const string &name)
{
	this->P[player]->setName(name);
}

void Game::setnrOfPlayer(const int NOP){
	this->nrOfplayers = NOP;
}

void Game::setplayerMoney(const int player, const int money) {
	this->P[player]->setCM(money);
}

int Game::getnrOfPlayer() const {
	return this->nrOfplayers;
}

int Game::getPlayerNOC(const int player) const {
	return 	this->P[player]->getNOC();;
}

int Game::getPlayerMoney(const int player) const {
	return 	this->P[player]->getCM();
}

int Game::getDealerNOC() const {
	return this->Dealer.getNOC();
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
	int *holder = this->P[player]->getHand();
	for (int i = 0; i < this->P[player]->getNOC(); i++) {
		output << this->gameDeck.toString(this->shuffleDeck[holder[i]]);
	}
	return output.str();
}

string Game::showPlayerName(const int player) const {
	return this->P[player]->getName();
}

string Game::showDealer() const {
	stringstream output;
	int *holder = this->Dealer.getHand();
	for (int i = 0; i < this->Dealer.getNOC(); i++) {
		output << this->gameDeck.toString(this->shuffleDeck[holder[i]]);
	}
	return output.str();
}

void Game::dealCard(const int player) {
	this->P[player]->setHand(nrOfDealedCards++);
}

void Game::dealDealer() {
	this->Dealer.setHand(nrOfDealedCards++);
}

void Game::resetGame() {
	for (int i = 0; i < 2; i++) {
		this->P[i]->setNOC(0);
	}
	this->Dealer.setNOC(0);
	this->nrOfDealedCards = 0;
	shuffleCards();
}

int Game::TotPoints(const int player){
	int totPoints = 0;
	int *holder = this->P[player]->getHand();
	for (int i = 0; i < this->P[player]->getNOC(); i++) {
		totPoints = caculatePoints(totPoints, this->gameDeck.getValue(this->shuffleDeck[holder[i]]));
	}
	return totPoints;
}

int Game::DeaPoints() {
	int totPoints = 0;
	int *holder = this->Dealer.getHand();
	for (int i = 0; i < this->Dealer.getNOC(); i++) {
		totPoints = caculatePoints(totPoints, this->gameDeck.getValue(this->shuffleDeck[holder[i]]));
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

void Game::checkPlayerLose() {
	if (this->nrOfplayers == 2) {
		if (this->P[0]->getCM() < 0) {
			delete this->P[0];
			this->P[0] = this->P[1];
			this->nrOfplayers--;
		}
		if (this->P[1]->getCM() < 0) {
			delete this->P[1];
			this->nrOfplayers--;
		}
	}
	else {
		if (this->P[0]->getCM() < 0) {
			delete this->P[0];
			this->nrOfplayers--;
		}
	}
	resetGame();
}
