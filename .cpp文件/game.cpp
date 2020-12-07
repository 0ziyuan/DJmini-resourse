
/*预处理指令读取头文件*/
#include <iostream>
#include "acllib.h"
#include"Playarea.h"
#include"GifArea.h"

using namespace std;

/*宏定义区*/
//游戏窗体宽度
#define WinWidth 1300
//游戏窗体高度
#define WinHeight 700
//Gif区域坐标x
#define GifX 600
//Gif区域坐标y
#define GifY 0
//Gif区域宽度
#define GifWidth 700
//Gif区域高度
#define GifHeight 700
//GIF区图片数
#define Num 35
//Play区域坐标x
#define PlayX 0
//Play区域坐标y
#define PlayY 0
//Play区域宽度
#define PlayWidth 600
//Play区域高度
#define PlayHeight 700

/*全局变量声明*/
ACL_Sound winsound;
ACL_Image backimg;
//倒计时帧数
int ZhenCountdown[2] = {25,25};
//倒计时每帧间隔时间
int DtCountdown[2] = { 200,200 };
//倒计时是否结束
bool countdown_end = FALSE;
//GIF区各张GIF帧数
int Zhen[Num + 1];
//GIF区各张GIF每帧间隔时间
int Dt[Num + 1];
//定义并初始化GifArea类对象countdown
GifArea countdown(0, 0, 600, 600,1, ZhenCountdown, DtCountdown, 0);
//定义并初始化GifArea类对象gifarea
GifArea gifarea(GifX, GifY, GifWidth, GifHeight,Num, Zhen, Dt, 1);
//定义并初始化Playarea类对象playarea
Playarea playarea(PlayX, PlayY, PlayWidth, PlayHeight);

/*函数声明*/
void loadzhen(int* zhen);
void loaddt(int* dt);
void timerEvent(int id);
void keyEvent(int key, int event);

/*主函数*/
int Setup()
{
	//srand生成随机因子
	srand((unsigned)time(NULL));
	//加载各张GIF帧数
	loadzhen(Zhen);
	//加载每帧间隔时间
	loaddt(Dt);
	//生成窗口
	initWindow("DJmini", 0, 0, WinWidth, WinHeight);
	//背景音乐
	loadSound("FirstKiss.mp3", &winsound);//加载背景音乐
	playSound(winsound, 0);//播放背景声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
	//注册定时器中断
	registerTimerEvent(timerEvent);
	//注册键盘中断
	registerKeyboardEvent(keyEvent);
	//开启定时器
	startTimer(0, gifarea.dt[gifarea.gifindex]);
	startTimer(1, 7500);
	startTimer(2, countdown.dt[countdown.gifindex]);
	startTimer(3, 5000);
	startTimer(4, 800);//生成音符
	startTimer(5, 2480);//进度+1
	startTimer(6, 10);//音符下落
	startTimer(7, 262500);//结束
	return 0;
}
//加载各张GIF帧数
void loadzhen(int* zhen)
{
	zhen[1] = 135;zhen[2] = 9;zhen[3] = 24;zhen[4] = 240;zhen[5] = 18;
	zhen[6] = 5;zhen[7] = 19;zhen[8] = 54;zhen[9] = 15;zhen[10] = 20;
    zhen[11] = 48;zhen[12] = 82;zhen[13] = 36;zhen[14] = 7;zhen[15] = 26;
	zhen[16] = 96;zhen[17] = 61;zhen[18] = 100;zhen[19] = 7;zhen[20] = 32;
	zhen[21] = 33;zhen[22] = 28;zhen[23] = 30;zhen[24] = 20;zhen[25] = 160;
	zhen[26] = 94;zhen[27] = 47;zhen[28] = 24;zhen[29] = 120;zhen[30] = 72;
	zhen[31] = 52;zhen[32] = 24;zhen[33] = 180;zhen[34] = 32;zhen[35] = 37;
}
//加载每帧间隔时间
void loaddt(int* dt)
{
	dt[1] = 40;dt[2] = 20;dt[3] = 30;dt[4] = 30;dt[5] = 30;
	dt[6] = 20;dt[7] = 80;dt[8] = 10;dt[9] = 30;dt[10] = 30;
	dt[11] = 20;dt[12] = 10;dt[13] = 30;dt[14] = 10;dt[15] = 30;
	dt[16] = 50;dt[17] = 30;dt[18] = 30;dt[19] = 10;dt[20] = 30;
	dt[21] = 10;dt[22] = 30;dt[23] = 20;dt[24] = 10;dt[25] = 30;
	dt[26] = 30;dt[27] = 40;dt[28] = 30;dt[29] = 30;dt[30] = 30;
	dt[31] = 10;dt[32] = 30;dt[33] = 30;dt[34] = 30;dt[35] = 40;
}
void timerEvent(int id) 
{
	switch (id)
	{
	case 0:
		beginPaint();
		gifarea.drawArea();
		endPaint();
		break;
	case 1:
		gifarea.next();
		break;
	case 2:
		beginPaint();
		countdown.drawArea();
		endPaint();
		break;
	case 3:
		countdown.next();
		countdown_end = TRUE;
		break;
	case 4:
		if (countdown_end == TRUE && playarea.percent < 99)
		{
			int shu= rand() % 5;
			switch (shu)
			{
			case 0:

				break;
			case 1:
			case 2:
			case 3:
                playarea.createData();
				break;
			case 4:
				playarea.createData();
				playarea.createData();
				break;
			}
			beginPaint();
			playarea.drawArea();
			endPaint();
		}
		break;
	case 5:
		if (countdown_end == TRUE && playarea.percent < 100)
		{
			playarea.percent++;
		}
		break;
	case 6:
		if (countdown_end == TRUE)
		{
			playarea.move();
			beginPaint();
			playarea.drawArea();
			endPaint();
		}
		break;
	case 7:
		ACL_Sound givesc;
		loadSound("评级.wav", &givesc);//加载敲击音乐
		playSound(givesc, 0);//播放敲击声音，第二个参数非零时，音乐将循环播放。否则只播放一遍
		beginPaint();
		//定义前景为火色
		setTextColor(RGB(139, 78, 85));
		setTextBkColor(RGB(26, 18, 33));
		char txt3[15];
		int level=playarea.rightrate / 10;
		switch (level)
		{
		case 10:
		case 9:
			sprintf_s(txt3, "Perfect!");
			break;
		case 8:
			sprintf_s(txt3, "Excellent!");
			break;
		case 7:
			sprintf_s(txt3, "Nice job!");
			break;
		case 6:
			sprintf_s(txt3, "Not bad!");
			break;
		default:
			sprintf_s(txt3, "Cheer up!");
			break;
		}
		setTextSize(50);
		paintText(860, 50, txt3);
		endPaint();
		break;//end switch
	}
}

void keyEvent(int key, int event)
{
	if (event != KEY_DOWN)return;
	playarea.judge(key);
}



