#include "Deck.h"
#include <stdlib.h>
#include <time.h>  

void start();
int* shuffleCards(const int size);
bool duplicate(const int* Deck, const int size, const int nrTCheck);