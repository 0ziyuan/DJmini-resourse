#pragma once

#include "acllib.h"

class Area
{
protected:
	int x, y;
	int width, height;
	ACL_Image img;
public:
	Area(int x, int y, int width, int height);
	Area(Area& area);
	~Area();
	virtual void drawArea() = 0;
};