#include "Playarea.h"
#include<stdio.h>

Playarea::Playarea(int x, int y, int width, int height)
    :Area(x, y, width, height)
{}

void Playarea::createData()
{
	note[nowNum] = new Note;
	note[nowNum]->initNote();
	nowNum++;
}
void Playarea::move()
{
	for (int i = 0; i < nowNum; ++i)
		if (note[i])
		{
			note[i]->movedown();
			if (note[i]->nTopRect>=700)
			{
				delete(note[i]);
				note[i] = NULL;
			}
		}
}
void Playarea::judge(int key)
{
	ACL_Sound hit;
	loadSound("敲击.wav", &hit);//加载敲击音乐
	switch (key)
	{
	case 'A':
		for (int i = 0; i < nowNum; ++i)
			if (note[i]&& note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 0&& note[i]->style == 0)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//播放敲击声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
				}
			}
		break;
	case 'S':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 150 && note[i]->style == 0)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//播放敲击声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
				}
			}
		break;
	case 'D':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 300 && note[i]->style == 0)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//播放敲击声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
				}
			}
		break;
	case 'F':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 450 && note[i]->style == 0)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//播放敲击声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
				}
			}
		break;
	case 'J':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 0 && note[i]->style == 1)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//播放敲击声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
				}
			}
		break;
	case 'K':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 150 && note[i]->style == 1)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//播放敲击声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
				}
			}
		break;
	case 'L':
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 300 && note[i]->style == 1)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//播放敲击声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
				}
			}
		break;
	case VK_OEM_1:
		for (int i = 0; i < nowNum; ++i)
			if (note[i] && note[i]->nBottomRect >= 600)
			{
				if (note[i]->nLeftRect == 450 && note[i]->style == 1)
				{
					score++;
					delete(note[i]);
					note[i] = NULL;
					playSound(hit, 0);//播放敲击声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
				}
			}
		break;
	}
}
void Playarea::drawArea()
{
	loadImage("毛玻璃背景.jpg", &img);
	putImageScale(&img, x, y, width, height);
	//定义画笔画刷为橘棕色
	setPenColor(RGB(255, 218, 185));
	setBrushColor(RGB(255, 218, 185));
	line(0, 600, 600, 600);
	for (int i = 0; i < nowNum; ++i)
	{
		if (note[i])
		{
			note[i]->drawNote();
		}
	}
	//定义前景为橘色
	setTextBkColor(RGB(238, 229, 222));
	setTextColor(RGB(255, 127, 0));
	setTextFont("微软雅黑");
	char txt1[16];
	rightrate = score / (nowNum+0.00001)*100;
	sprintf_s(txt1,"命中率:%0.2f%%", rightrate);
	setTextSize(25);
	paintText(450, 20, txt1);
	//定义前景为棕色
	setTextColor(RGB(139, 87, 66));
	char txt2[15];
	sprintf_s(txt2, "进度:%d%%", percent);
	setTextSize(25);
	paintText(450, 50, txt2);
}