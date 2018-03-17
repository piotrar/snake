#pragma once
#include "Game.h"


class consoleView
{
public:
	explicit consoleView(game *game);
	void show() const;
private:
	void map_draw() const;
	game *game_;
};


