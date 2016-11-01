#include "functions.h"

void start() {
	Game game;
	playerInfo(game);
	dealing(game);

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

void dealing(Game &game){
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		game.dealCard(i + 1);
		game.dealCard(i + 1);
	}
	showPCards(game);
	for (int i = 0; i < game.getnrOfPlayer(); i++) {

	}
}

void showPCards(Game &game) {
	system("cls");
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		cout << "[" << game.showPlayerName(i + 1) << "]" << endl;
		cout << game.showCards(i + 1); 
		cout << "[Points] " << game.TotPoints(i + 1) << endl;
	}
}
