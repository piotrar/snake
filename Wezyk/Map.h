#pragma once

#include "Snake.h"
#include <iostream>
#include "Food.h"

#define EMPTY ' '
#define WALL '#'
#define SNAKE 's'
#define FOOD '@'

using namespace std;

class Map
{
  public:
	Map();
	explicit Map(string name);
	Map(int height, int width);
    Map(const Map &p);

    void init(int height, int width);
    void set_snake_on_map(Snake *snake) const;
	bool is_map(Point p) const;
	void set_food_on_map(Food* food) const;
	bool is_empty(Point p) const;
	bool is_food(Point p) const;

	int height_get() const { return height_;  }
	int width_get() const { return width_; }
	char box_get(const int x, const int y) const { return box_[y][x]; }

    ~Map();
private:
    int height_{20};
    int width_{30};

    void box_create();
    void box_delete();

    char **box_{nullptr};

};

