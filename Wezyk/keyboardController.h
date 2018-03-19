#pragma once

#include "Game.h"
#include "ConsoleView.h"
#include "Controller.h"

class KeyboardController : public Controller
{
public:
	void run() override;
	~KeyboardController();
private:
	Game* game_{new Game()};
	View* view_{new ConsoleView(game_)}; 
};


