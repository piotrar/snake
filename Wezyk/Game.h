#pragma once

#include "Snake.h"
#include "Map.h"

#define STATE_GAME	1
#define STATE_END	2

class game
{
  public:
    game();
    void move();
    void direction_set(direction k);
	map *map_get() { return &game_map_;  }
	snake *snake_get() { return &snake_; }
	int state_game_get() const { return game_state_; }

  private:
	void init();
	int game_state_{};
    map game_map_;
    snake snake_;
};

