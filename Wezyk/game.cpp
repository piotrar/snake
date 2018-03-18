#include "Game.h"
#include <string>

Game::Game()
{
	cout << "Enter map name:"<<endl<<"(type default to load default)" << endl;
	string mapname;
	cin >> mapname;
	if (mapname != "default")
		game_map_ = new Map(mapname);
	else
		game_map_ = new Map();

	game_map_->set_snake_on_map(snake_);
}

void Game::tick()
{
  if (game_state_==STATE_END) return;

	const auto snake_elements = snake_->snake_element_get();

  snake_->snake_move();

  // sprawdzamy czy snake nie wyladowal na scianie!
  if (game_map_->is_map(snake_elements[0]))
  {
    game_state_ = STATE_END;
	cout << "Game over!" << endl;
  }

  if (game_map_->is_food(snake_elements[0]))
  {
	  points_++;
	  snake_->snake_enlarge();
	  delete food_;
	  food_ = nullptr;
  }
  else if (food_ != nullptr)
  {
	  while (!(game_map_->is_empty(food_->get_pos()) || game_map_->is_food(food_->get_pos())))
		  food_->random_set_pos(game_map_->width_get(), game_map_->height_get());
	  game_map_->set_food_on_map(food_);
  }
  else
	  food_ = new Food(game_map_->width_get(), game_map_->height_get());


  game_map_->set_snake_on_map(snake_);
}

void Game::direction_set(const direction k) const
{
  snake_->direction_change(k);
}
