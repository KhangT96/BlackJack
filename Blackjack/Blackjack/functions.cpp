#include "functions.h"

void start() {
	Deck spelkort;
	int *shuffleDeck = shuffleCards(52);
	for (int i = 0; i < 52; i++) {
		cout << "[" << i << "]" << spelkort.toString(shuffleDeck[i]);
	}
	delete shuffleDeck;
}

int* shuffleCards(const int size) {
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

bool duplicate(const int* Deck, const int size, const int nrTCheck)
{
	bool duplicated = false;
	for (int i = 0; i < size && duplicated == false; i++) {
		if (nrTCheck == Deck[i]) {
			duplicated = true;
		}
	}
	return duplicated;
}
