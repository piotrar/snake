#pragma once

#include "Game.h"
#include "consoleView.h"

class keyboardController
{
public:
	keyboardController();
	void run();

private:
	game gane_;
	consoleView main_view_{}; 
};


