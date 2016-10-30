#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Player {

private:

	string name;
	int nrOfCards;
	int currentMoney;
	int* hand;

public:

	Player();
	Player(const string &name, const int currentMoney);
	virtual ~Player();

	void setName(const string &name);
	void setNOC(const int nrOfCards);
	void setCM(const int currentMoney);
	void setHand(const int card);

	string getName() const;
	int getNOC() const;
	int getCM() const;
	int* getHand() const;

};


#endif // !PLAYER_H
