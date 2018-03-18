#pragma once
#include "Point.h"

class Food
{
public:
	Food(int max_width, int max_height);
	void random_set_pos(int max_width, int max_height);
	bool exists() const { return exists_; }
	Point get_pos() const { return pos_; }
private:
	Point  pos_;
	bool exists_ = false;
};
