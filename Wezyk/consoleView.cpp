#include "ConsoleView.h"
#include <Windows.h>

ConsoleView::ConsoleView(Game* game) : game_(game)
{
}

void ConsoleView::map_draw() const
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
		{
			const auto c = map->box_get(x, y);
			if (c == SNAKE)
				SetConsoleTextAttribute(std_out, 10);
			else
				SetConsoleTextAttribute(std_out, 15);
			cout << c;
			
		}

		cout << endl;
	}
}

void ConsoleView::points_draw() const
{

	const auto map = game_->map_get();
	const auto std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coords;
	coords.X = 0;
	coords.Y = map->height_get();
	SetConsoleCursorPosition(std_out, coords);

 	cout << endl << "Points:" << game_->points_get() << endl;
}

void ConsoleView::show()
{
	map_draw();
	points_draw();
}

ConsoleView::~ConsoleView()
{
	if(game_ != nullptr)
	{
		delete game_;
		game_ = nullptr;
	}
}
