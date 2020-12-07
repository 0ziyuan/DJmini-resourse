#pragma once

#include "Area.h"
#include "Note.h"

class Playarea :public Area
{
public:
	float rightrate;
	int percent = 0;
protected:
	int score = 0;
	Note* note[500] = { 0 };
	int nowNum = 0;
public:
	Playarea(int x, int y, int width, int height);
	void createData();
	void move();
	void judge(int key);
	void drawArea();
};