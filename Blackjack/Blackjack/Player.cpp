#include "Player.h"

Player::Player() {
	this->name = "Unknown";
	this->nrOfCards = 0;
	this->currentMoney = 0;
	this->hand = new int[5];
}

Player::Player(const string &name, const int currentMoney) {
	this->name = name;
	this->nrOfCards = 0;
	this->currentMoney = currentMoney;
	this->hand = new int[5];
}

Player::~Player() {
	delete this->hand;
}

void Player::setName(const string &name) {
	this->name = name;
}

void Player::setNOC(const int nrOfCards) {
	this->nrOfCards = nrOfCards;
}

void Player::setCM(const int currentMoney) {
	this->currentMoney = currentMoney;
}

void Player::setHand(const int card) {
	if (this->nrOfCards < 5) {
		this->hand[nrOfCards++] = card;
	}
}

string Player::getName() const {
	return this->name;
}

int Player::getNOC() const {
	return this->nrOfCards;
}

int Player::getCM() const {
	return this->currentMoney;
}

int* Player::getHand() const {
	return this->hand;
}
