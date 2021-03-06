#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {

private:

	int size;
	Card **deck;

public:
	Deck();
	~Deck();
	int getValue(const int posistion) const;
	string toString(const int position) const;

};

#endif // !DECK_H
