#include "functions.h"

void start() {
	Game game;
	playerInfo(game);
	dealing(game);
	detectLoseWin(game);

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
	string answer = "";
	bool stop = false;
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		game.dealCard(i + 1);
		game.dealCard(i + 1);
	}
	showPCards(game);
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		stop = false;
		for (int j = game.getPlayerNOC(i + 1); j < 5 && stop == false; j++) {
			if (game.TotPoints(i + 1) < 21) {
				cout << "[" << game.showPlayerName(i + 1) << "]";
				cout << " Do you want to get another card?[Y or N]\n";
				cin >> answer;
				if (answer == "N") {
					stop = true;
				}
				else {
					game.dealCard(i + 1);
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
		cout << "[" << game.showPlayerName(i + 1) << "]" << endl;
		cout << game.showCards(i + 1); 
		cout << "[Points] " << game.TotPoints(i + 1) << endl;
	}
}

void detectLoseWin(Game &game) {
	system("cls");
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		int points = game.TotPoints(i + 1);
		if (points > 15 && points < 21) {
			game.setplayerMoney(i + 1, game.getPlayerMoney(i + 1) + 100);
		}
		else if (points == 21) {
			game.setplayerMoney(i + 1, game.getPlayerMoney(i + 1) + 300);
		}
		else {
			game.setplayerMoney(i + 1, game.getPlayerMoney(i + 1) - 100);
		}
		cout << "[" << game.showPlayerName(i + 1) << "] ";
		cout << game.getPlayerMoney(i + 1) << "$\n";
	}
}
