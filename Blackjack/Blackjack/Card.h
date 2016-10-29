#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Card {

private:
	//Variabler
	string type;
	int value;

public:
	//Konstruktorn
	Card();
	Card(const string &type, const int value);
	//Destruktorn
	~Card();
	//Retur funktioner
	string getType() const;
	int getValue() const;
	string toString() const;


};

#endif // !CARD_H

