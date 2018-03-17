#include "Map.h"

map::map()
{
  box_ = nullptr;
  init(20, 20);
}

map::map(const int height, const int width)
{
  box_ = nullptr;
  init(height, width);
}

map::map(const map &p)
{
  init(p.height_, p.width_);

  for (auto x=0; x<width_; x++)
    for (auto y=0; y<height_; y++)
      box_[y][x] = p.box_[y][x];
}

void map::init(const int height, const int width)
{
  this->height_ = height;
  this->width_ = width;
  box_create();

  for (auto x=0; x<width; x++)
    for (auto y=0; y<height; y++)
      if (y!=0 && x!=0 && x!=(width-1) && y!=(height-1))
        box_[y][x] = EMPTY;
      else
        box_[y][x] = WALL;

}

bool map::is_map(point p) const
{
	return box_[p.gety()][p.getx()] == WALL;
}


void map::set_snake_on_map(snake &snake) const
{
	const auto snake_length = snake.snake_lenght_get();
	const auto snake_elements = snake.snake_element_get();

   // najpierw usun poprzednia pozycje weza
   for (auto x=0; x<width_; x++)
     for (auto y=0; y<height_; y++)
       if (box_[y][x]==SNAKE) box_[y][x] = EMPTY;

   for (auto i=0; i<snake_length; i++)
   {
     box_[snake_elements[i].gety()][snake_elements[i].getx()] = SNAKE;
   }
}


void map::box_delete()
{
  if (box_!= nullptr)
  {
    for (auto y=0; y<height_; y++)
      delete []box_[y];
    delete []box_;

    box_ = nullptr;
  }
}

void map::box_create()
{
  if (box_!= nullptr) box_delete();

  box_ = new char*[height_];
  for (auto i=0; i<height_; i++)
    box_[i] = new char[width_];
}



map::~map()
{
  box_delete();
}

