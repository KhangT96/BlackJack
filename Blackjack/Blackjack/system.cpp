#include "Game.h"
#include <stdlib.h>
#include <time.h>  

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Game one;
	for (int i = 0; i < 52; i++) {
		cout << one.getCard(i);
	}
	system("pause");
	return 0;
}