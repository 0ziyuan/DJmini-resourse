#include "GifArea.h"

GifArea::GifArea(int x, int y, int width, int height,int num, int* Zhen, int* Dt, int Id)
        :Area(x,y, width,height)
{
	this->gifnum=num;
	this->zhen = Zhen;
	this->dt = Dt;
	this->id = Id;
}

void GifArea::drawArea()
{
	if (gifindex <= gifnum)
	{
		w1++;
		if (w1 == 10)
		{
			w1 = 0;
			w2++;
		}
		if (w2 == 10)
		{
			w2 = 0;
			w3++;
		}
		if ((w3 * 100 + w2 * 10 + w1) == zhen[gifindex])
		{
			w3 = 0;
			w2 = 0;
			w1 = 1;
		}
		imgname[0] = (id / 10) + '0';
		imgname[1] = id % 10 + '0';
		imgname[6] = w3 + '0';
		imgname[7] = w2 + '0';
		imgname[8] = w1 + '0';
		loadImage(imgname, &img);
		putImageScale(&img, x, y, width, height);
	}
}

void GifArea::next()
{
	w3 = 0;
	w2 = 0;
	w1 = 0;
	if (gifindex <= gifnum)
	{
		gifindex++;
		v1++;
		if (v1 == 10)
		{
			v1 = 0;
			v2++;
		}
		imgname[3] = v2 + '0';
		imgname[4] = v1 + '0';
	}
}