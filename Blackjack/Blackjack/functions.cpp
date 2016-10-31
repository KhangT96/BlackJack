#include "functions.h"

void start() {
	Game game;
	game.dealCard(1);
	game.dealCard(2);
	cout << game.getCard(1);
	cout << game.getCard(2);
}
