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
	if (this->value > 1 && this->value < 11) {
		output << this->type << " : " << this->value << endl;
	}
	else if (this->value == 11) {
		output << this->type << " : JACK"<< endl;
	}
	else if (this->value == 12) {
		output << this->type << " : QUEEN" << endl;
	}
	else if (this->value == 13) {
		output << this->type << " : KING" << endl;
	}
	else {
		output << this->type << " : ACE" << endl;
	}

	return output.str();
}