#include "Map.h"
#include "Point.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Game.h"

Map::Map()
{
	init(height_, width_);
}

Map::Map(string name)
{
	string line;
	ifstream mapfile(name);


	this->height_ = 20;
	this->width_ = 30;

	box_create();
	auto h = 0;
	if (mapfile.is_open())
	{
		while (getline(mapfile, line))
		{
			strcpy(box_[h], line.c_str());
			h++;
		}
		mapfile.close();
	}
	else cout << "Unable to open file";
	
}



Map::Map(const int height, const int width)
{
  box_ = nullptr;
  init(height, width);
}

Map::Map(const Map &p)
{
  init(p.height_, p.width_);

  for (auto x=0; x<width_; x++)
    for (auto y=0; y<height_; y++)
      box_[y][x] = p.box_[y][x];
}

void Map::init(const int height, const int width)
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

bool Map::is_map(Point p) const
{
	return box_[p.gety()][p.getx()] == WALL;
}


void Map::set_snake_on_map(Snake *snake) const
{
	const auto snake_length = snake->snake_lenght_get();
	const auto snake_elements = snake->snake_element_get();

   // najpierw usun poprzednia pozycje weza
   for (auto x=0; x<width_; x++)
     for (auto y=0; y<height_; y++)
       if (box_[y][x]==SNAKE) box_[y][x] = EMPTY;

   for (auto i=0; i<snake_length; i++)
	   box_[snake_elements[i].gety()][snake_elements[i].getx()] = SNAKE;
}


void Map::box_delete()
{
  if (box_!= nullptr)
  {
    for (auto y=0; y<height_; y++)
      delete []box_[y];
    delete []box_;

    box_ = nullptr;
  }
}

void Map::box_create()
{
  if (box_!= nullptr) box_delete();

  box_ = new char*[height_];
  for (auto i=0; i<height_; i++)
    box_[i] = new char[width_];
}



Map::~Map()
{
  box_delete();
}

void Map::set_food_on_map(Food* food) const
{
		box_[food->get_pos().gety()][food->get_pos().getx()] = FOOD;
}

bool Map::is_empty(Point p) const
{
	return box_[p.gety()][p.getx()] == EMPTY;
}

bool Map::is_food(Point p) const
{
	return box_[p.gety()][p.getx()] == FOOD;
}


