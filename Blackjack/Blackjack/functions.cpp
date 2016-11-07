#include "functions.h"

void start() {
	Game game;
	playerInfo(game);
	dealing(game);
	detectLoseWin(game);

}

void playerInfo(Game &game) {
	int nrOfPlayers = 0;string name = "";
	cout << "How many player?[1 or 2]\n";
	cin >> nrOfPlayers; game.setnrOfPlayer(nrOfPlayers);
	cin.ignore();
	for (int i = 0; i < nrOfPlayers; i++) {
		system("cls");
		cout << "Player " << i + 1 << " name?\n";
		getline(cin, name);
		game.setPlayerInfo(i, name);
	}
	system("pause");
}

void dealing(Game &game){
	string answer = "";
	bool stop = false;
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		game.dealCard(i);
		game.dealCard(i);
	}
	showPCards(game);
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		stop = false;
		for (int j = game.getPlayerNOC(i); j < 5 && stop == false; j++) {
			if (game.TotPoints(i) < 21) {
				cout << "[" << game.showPlayerName(i) << "]";
				cout << " Do you want to get another card?[Y or N]\n";
				cin >> answer;
				if (answer == "N") {
					stop = true;
				}
				else {
					game.dealCard(i);
				}
			}
			showPCards(game);
		}
	}
	system("pause");
}

void showPCards(Game &game) {
	system("cls");
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		cout << "[" << game.showPlayerName(i) << "]" << endl;
		cout << game.showCards(i); 
		cout << "[Points] " << game.TotPoints(i) << endl;
	}
}

void detectLoseWin(Game &game) {
	system("cls");
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		int points = game.TotPoints(i);
		if (points > 15 && points < 21) {
			game.setplayerMoney(i, game.getPlayerMoney(i) + 100);
		}
		else if (points == 21) {
			game.setplayerMoney(i, game.getPlayerMoney(i) + 300);
		}
		else {
			game.setplayerMoney(i, game.getPlayerMoney(i) - 100);
		}
		cout << "[" << game.showPlayerName(i) << "] ";
		cout << game.getPlayerMoney(i) << "$\n";
	}
}
