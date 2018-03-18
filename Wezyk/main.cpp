#include <tchar.h>
#include <ctime>
#include "KeyboardController.h"

int _tmain(int argc, _TCHAR *argv[])
{
	srand(unsigned(time(nullptr)));
	Controller* controller = new KeyboardController; 
	controller->run();
	delete controller;
    return 0;
}

