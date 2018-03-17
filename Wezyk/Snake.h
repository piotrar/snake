#pragma once

enum direction { dleft, dright, dup, ddown };

class point
{
  public:
    point() { x_ = 0; y_ = 0; }
	point(const int x, const int y) { this->x_ = x; this->y_ = y; }
	void set(const int x, const int y)
	{
		this->x_ = x;
		this->y_ = y;
	}
	int getx() const { return x_;  }
	int gety() const { return y_; }
private:
    int x_, y_;
};

class snake
{
  public:
    snake();
    void direction_change(direction new_direction);
    void snake_move() const;

    point *snake_element_get() const { return snake_elements_; }
    int snake_lenght_get() const { return snake_length_; }

    ~snake();    

  private:
    direction snake_dirrection_;
    point *snake_elements_;
    int snake_length_;
};
