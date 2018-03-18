#pragma once

class View
{
public:
	virtual ~View() = default;

	virtual void show() = 0;
};
