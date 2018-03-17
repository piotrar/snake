#include "consoleView.h"
#include <Windows.h>

consoleView::consoleView(game* game)
{
	this->game_ = game;
}

void consoleView::map_draw() const
{
	const auto std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coords;
	coords.X = 0;
	coords.Y = 0;
	SetConsoleCursorPosition(std_out, coords);

	const auto map = game_->map_get();

	const auto height = map->height_get();
	const auto width = map->width_get();

	for (auto y = 0; y < height; y++)
	{
		for (auto x = 0; x < width; x++)
			cout << map->box_get(x, y);

		cout << endl;
	}
}

void consoleView::show() const
{
	if (game_->state_game_get() == STATE_END)
	{
		cout << "Game Over!";
	}
	else
	{
		map_draw();
	}
}
