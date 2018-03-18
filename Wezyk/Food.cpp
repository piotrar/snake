#include "Food.h"
#include <cstdlib>


Food::Food(const int max_width, const int max_height)
{
	random_set_pos(max_width, max_height);
}

void Food::random_set_pos(const int max_width, const int max_height)
{
	const auto x = rand() % max_width;
	const auto y = rand() % max_height;
	this->pos_.set(x, y);
}
