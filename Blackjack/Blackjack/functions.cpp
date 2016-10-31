#include "functions.h"

void start() {
	Game game;
	playerInfo(game);
	game.dealCard(1);
	game.dealCard(2);
	cout << game.getCard(1);
	cout << game.getCard(2);
}

void playerInfo(Game &game) {
	int nrOfPlayers = 0; int money = 0; string name = "";
	cout << "How many player?[1 or 2]\n";
	cin >> nrOfPlayers; game.setnrOfPlayer(nrOfPlayers);
	for (int i = 0; i < nrOfPlayers; i++) {
		system("cls");
		cin.ignore();
		cout << "Player " << i + 1 << " name?\n";
		getline(cin, name);
		cout << "Player " << i + 1 << " money?\n";
		cin >> money;
		game.setPlayerInfo(i + 1, name, money);
	}
	system("pause");
}
