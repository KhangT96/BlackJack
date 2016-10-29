#include "Card.h"

Card::Card() {
	this->type = "Hearth";
	this->value = 1;
}

Card::Card(const string &type, const int value) {
	this->type = type;
	this->value = value;
}

Card::~Card() {

}

string Card::getType() const{
	return this->type;
}

int Card::getValue() const {
	return this->value;
}

string Card::toString() const {
	stringstream output;

	output <<this->type << " : "<< this->value << endl;

	return output.str();
}