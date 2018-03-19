#pragma once

class Point
{
public:
	Point() { x_ = 0; y_ = 0; }
	Point(const int x, const int y) { this->x_ = x; this->y_ = y; }
	void set(const int x, const int y)
	{
		this->x_ = x;
		this->y_ = y;
	}
	int getx() const { return x_; }
	int gety() const { return y_; }
private:
	int x_, y_;
};
