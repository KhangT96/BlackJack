#include "functions.h"

void start() {
	Game game;
	playerInfo(game);
	do {
		playing(game);
		system("pause");
	} while (game.getnrOfPlayer() > 0);
}

void playing(Game & game) {
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
	game.dealDealer();
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
	for (int k = game.getDealerNOC(); k < 5; k++) {
		if (game.DeaPoints() < 16) {
			cout << "[Dealer]" << endl;
			game.dealDealer();
			showPCards(game);
			system("pause");
		}
	}
	system("pause");
}

void showPCards(Game &game) {
	system("cls");
	cout << "[Dealer]" << endl;
	cout << game.showDealer();
	cout << "[Points] " << game.DeaPoints() << endl << endl;
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		cout << "[" << game.showPlayerName(i) << "]" << endl;
		cout << game.showCards(i); 
		cout << "[Points] " << game.TotPoints(i) << endl << endl;
	}
}

void detectLoseWin(Game &game) {
	system("cls");
	int dp = game.DeaPoints();
	for (int i = 0; i < game.getnrOfPlayer(); i++) {
		int points = game.TotPoints(i);
		if (dp < 22 && points > 15 && points < 21 && points > dp) {
			game.setplayerMoney(i, game.getPlayerMoney(i) + 200);
		}
		else if (points == 21) {
			game.setplayerMoney(i, game.getPlayerMoney(i) + 400);
		}
		else {
			game.setplayerMoney(i, game.getPlayerMoney(i) - 200);
		}
		cout << "[" << game.showPlayerName(i) << "] ";
		cout << game.getPlayerMoney(i) << "$ ";
		cout << "[Points] " << game.TotPoints(i) << endl << endl;
	}
	cout << "[Points] " << game.DeaPoints() << endl << endl;
	game.checkPlayerLose();
}
