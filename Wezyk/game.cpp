#include "Game.h"

game::game()
{
  init();
}

void game::init()
{
   game_map_.set_snake_on_map(snake_);
   game_state_ = STATE_GAME;
}


void game::move()
{
  if (game_state_==STATE_END) return;

	const auto snake_length = snake_.snake_lenght_get();
	const auto snake_elements = snake_.snake_element_get();

  snake_.snake_move();

  // sprawdzamy czy snake nie wyladowal na scianie!
  if (game_map_.is_map(snake_elements[snake_length - 1]))
  {
    cout << "Koniec gry!" << endl;
    game_state_ = STATE_END;
  }

  game_map_.set_snake_on_map(snake_);
}

void game::direction_set(const direction k)
{
  snake_.direction_change(k);
}