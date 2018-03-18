#pragma once

#include "Snake.h"
#include "Map.h"
#include "Food.h"

#define STATE_GAME	1
#define STATE_END	2

class Game
{
  public:
    Game();
    void tick();
    void direction_set(direction k) const;
	direction direction_get() const { return snake_->direction_get(); }
	Map* map_get() const { return game_map_;  }
	Snake* snake_get() const { return snake_; }
	int state_game_get() const { return game_state_; }
	unsigned points_get() const { return points_; }

	~Game();
  private:
	  unsigned int points_{0};
	int game_state_{STATE_GAME};
    Map* game_map_;
	Snake* snake_{new Snake()};
	Food* food_{nullptr};
};

