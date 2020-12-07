#include "Area.h"

Area::Area(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
Area::Area(Area& area)
{
	x = area.x;
	y = area.y;
	width = area.width;
	height = area.height;
	img = area.img;
}
Area::~Area()
{}