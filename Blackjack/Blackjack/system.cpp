#include "Deck.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Deck spelkort;
	for (int i = 0; i < 52; i++) {
		cout << spelkort.toString(i);
	}
	system("pause");
	return 0;
}