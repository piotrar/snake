#pragma once

#include "Snake.h"
#include <stdlib.h>
#include <iostream>

#define EMPTY	' '
#define WALL  '#'
#define SNAKE	's'

using namespace std;

class map
{
  public:
    map();
    map(int height, int width);
    map(const map &p);

    void init(int height, int width);
    void set_snake_on_map(snake &snake) const;
    bool is_map(point p) const;

	int height_get() const { return height_;  }
	int width_get() const { return width_; }
	char box_get(const int x, const int y) const { return box_[y][x]; }

    ~map();
  private:
    int height_{};
    int width_{};
    
    void box_create();
    void box_delete();

    char **box_{};

};

