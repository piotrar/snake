#include <Windows.h>
#include "KeyboardController.h"

void KeyboardController::run()
{
	while (game_->state_game_get() != STATE_END)
	{
		view_->show();
		const int interval = 300 - (game_->points_get() * 10);
		Sleep(interval > 100 ? interval : 100);

		if (GetAsyncKeyState(VK_UP))
			game_->direction_set(dup);
		else if (GetAsyncKeyState(VK_LEFT))
			game_->direction_set(dleft);
		else if (GetAsyncKeyState(VK_RIGHT))
			game_->direction_set(dright);
		else if (GetAsyncKeyState(VK_DOWN))
			game_->direction_set(ddown);
		else if (GetAsyncKeyState(VK_ESCAPE))
			break;

		game_->tick();
	}
	getchar();
}


