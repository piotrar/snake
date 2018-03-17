#include <Windows.h>
#include "keyboardController.h"

keyboardController::keyboardController() : main_view_(&gane_)
{  }

void keyboardController::run()
{
	while (gane_.state_game_get() != STATE_END)
	{
		main_view_.show();
		Sleep(250);

		if (GetAsyncKeyState(VK_UP))
			gane_.direction_set(dup);
		else if (GetAsyncKeyState(VK_LEFT))
			gane_.direction_set(dleft);
		else if (GetAsyncKeyState(VK_RIGHT))
			gane_.direction_set(dright);
		else if (GetAsyncKeyState(VK_DOWN))
			gane_.direction_set(ddown);
		else if (GetAsyncKeyState(VK_ESCAPE))
			break;

		gane_.move();

	}

	getchar();
}


