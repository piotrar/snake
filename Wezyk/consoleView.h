#pragma once
#include "Game.h"
#include "View.h"


class ConsoleView : public View
{
public:
	explicit ConsoleView(Game *game);
	void show() override;
private:
	void map_draw() const;
	void points_draw() const;
	Game* game_;
};


