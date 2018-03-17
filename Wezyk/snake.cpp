#include "Snake.h"

snake::snake()
{
  snake_length_ = 4;
  snake_elements_ = new point[snake_length_];
  snake_elements_[0].set(1, 1);
  snake_elements_[1].set(1, 2);
  snake_elements_[2].set(1, 3);
  snake_elements_[3].set(1, 4);

  snake_dirrection_ = ddown;
}

void snake::snake_move() const
{
	auto next_point = snake_elements_[snake_length_-1];
  if (snake_dirrection_ == ddown)
      next_point.set(next_point.getx(), next_point.gety() + 1);
  if (snake_dirrection_ == dup)
	  next_point.set(next_point.getx(), next_point.gety() - 1);
  if (snake_dirrection_ == dleft)
      next_point.set(next_point.getx() - 1, next_point.gety());
  if (snake_dirrection_ == dright)
	  next_point.set(next_point.getx() + 1, next_point.gety());

  // przesun elementy weza w tablicy - ostatnie miejsce pomijamy (juz tam nie ma weza)
  for (auto i=1; i<snake_length_; i++)
    snake_elements_[i-1] = snake_elements_[i];

  snake_elements_[snake_length_-1] = next_point;

}


void snake::direction_change(const direction new_direction)
{
  snake_dirrection_ = new_direction;
}

snake::~snake()
{
  delete []snake_elements_;
}



