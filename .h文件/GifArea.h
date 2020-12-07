#pragma once

#include "Area.h"

class GifArea :public Area
{
protected:
	int gifnum;
	int* zhen=new int(gifnum + 1);
    int id;
	char imgname[14] = "00-01-000.jpg";
	int v2 = 0, v1 = 1, w3 = 0, w2 = 0, w1 = 0;//gifÍ¼Æ¬ÃûĞòÁĞ
public:
	int* dt = new int(gifnum + 1);
	int gifindex = 1;
public:
	GifArea(int x, int y, int width, int height,int num,int* Zhen,int* Dt, int Id);
	void drawArea();
	void next();
};