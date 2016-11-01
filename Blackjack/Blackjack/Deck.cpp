#include "Deck.h"

Deck::Deck() {
	string type = "00";
	int current = 0;
	this->size = 52;
	this->deck = new Card*[this->size];
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				type = "Spades";
			}
			else if (j == 1) {
				type = "Clubs";
			}
			else if (j == 2) {
				type = "Diamonds";
			}
			else {
				type = "Heart";
			}
			this->deck[current++] = new Card(type, i + 1);
		}
	}
}

Deck::~Deck() {
	for (int i = 0; i < this->size; i++) {
		delete this->deck[i];
	}
	delete this->deck;
}

int Deck::getValue(const int position) const{
	return this->deck[position]->getValue();
}

string Deck::toString(const int position) const{
	return this->deck[position]->toString();
}