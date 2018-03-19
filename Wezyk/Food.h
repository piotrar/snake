#pragma once
#include "Point.h"

class Food
{
public:
	Food(int max_width, int max_height);
	void random_set_pos(int max_width, int max_height);
	Point get_pos() const { return pos_; }
private:
	Point  pos_;
};
