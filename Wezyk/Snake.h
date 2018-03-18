#pragma once
#include "Point.h"

enum direction { dleft, dright, dup, ddown };


class Snake
{
  public:
    Snake();
    void direction_change(direction new_direction);
	void snake_move() const;
	void snake_enlarge();
	direction direction_get() const { return snake_dirrection_; }

    Point *snake_element_get() const { return snake_elements_; }
	int snake_lenght_get() const { return snake_length_; }

    ~Snake();

private:
    direction snake_dirrection_;
    int snake_length_;
	Point *snake_elements_;
};
