# DJmini

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201120213405.png)

## 项目描述

音乐游戏，大二C++结课作业，依赖于acllib库实现，仅支持Windows环境下运行。

DJmini是一款音乐游戏，提供了流畅的节奏游戏体验，目前仅包含一个曲目及相应的音乐背景。创作灵感来源于室友最近在玩的一款音乐游戏— [DJMAX RESPECT V](https://store.steampowered.com/app/960170/DJMAX_RESPECT_V/)，游戏名“DJmini”正是为了致敬该游戏，而“mini”意在表明这只是一个卑微学习者的练手项目，十分简陋😅

## 软件说明

###   游戏使用说明

#### 下载及运行

1. [下载压缩包：](https://gitee.com/wanli-0ziyuan/DJmini-release)

   ![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207140113.png)

2. 下载完成并解压后，双击DJmini文件夹中的“DJmini.exe”文件运行游戏：

   ![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207141028.png)

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207141048.png)

#### 玩法说明

##### 音轨

即下落轨道数，共四个。对应键位有左手区和右手区之分，字母键均为大写，故需将键盘大写锁定：

左手区：A﹑S﹑D﹑F		

右手区：J﹑K﹑L﹑; 

##### 音符（Note）

有样式之分，蓝色音符的音轨对应左手区键位，粉色音符的音轨对应右手区键位。击中时附有音效，随即消失。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207142827.png)

##### 判定

1. 敲击音符所在音轨对应键位击打。蓝色音符的音轨对应左手区键位，粉色音符的音轨对应右手区键位。
2. 音符刚到达判定线，到其完全从窗口底部消失的这段时间，击打相应键位，视为击中。其他时刻（如音符还未到达判定线﹑音符已消失等）击打，视为击打无效。

##### 计分与评级

###### 计分

不显示具体得分，只实时显示命中率🙃。

命中率=击中音符数/已生成音符数*100%

###### 评级

| 命中率 |  小于60%  | 60%~70%  |  70%~80%  |  80%~90%   | 90%~100% |
| :----: | :-------: | :------: | :-------: | :--------: | :------: |
|  评级  | Cheer up! | Not bad! | Nice job! | Excellent! | Perfect! |

##### 完整过程

1. 5秒倒计时，倒计时结束，游戏开始；

   ![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207142402.png)

2. 音符下落，玩家按键击打。同时游戏区右上角实时显示命中率和游戏进度；

3. 游戏进度到达100%，游戏结束。片刻后在动画播放区显示评级。

   ![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207150329.png)

### 源码编译说明

#### 示例环境

Windows10家庭版中文版，系统类型为64位，选用Visual Studio 2019 Community 作为开发环境。

#### 所需文件下载

[下载压缩包](https://gitee.com/wanli-0ziyuan/DJmini-resourse)

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207151526.png)

#### 创建项目

##### Step1

打开Visual Studio 2019，点击创建新项目。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207154836.png)

##### Step2

选择windows桌面向导，然后选择下一步。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155000.png)

##### Step3

填写名称，选择项目创建位置。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155215.png)

##### Step4

###### 应用程序类型

桌面应用程序（.exe）

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155404.png)

###### 其他选项

空项目，然后创建。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155731.png)

#### 拷贝文件

##### Step1

根据创建项目的位置找到项目文件夹

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155745.png)

##### Step2

将下载的压缩包解压，然后把.cpp文件,.h文件和资源文件三个文件夹下的所有文件拷贝到刚才的项目文件夹中。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207155915.png)

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207160411.png)

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207160428.png)

#### 添加文件

##### 头文件

右键单击头文件，选择“添加”->“现有项”

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207160513.png)

选中项目文件夹下所有的.h文件，然后点击添加。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201207160749.png)

##### 源文件和资源文件

添加步骤同头文件，源文件为所有的.cpp文件，资源文件为所有Jpg文件以及两个wav文件，一个Mp3文件。

#### 编译运行

1.*项目 ->* *配置属性**->C/C++->**代码生成**->**运行库* *:选择* *多线程调试（**/MT**）。*

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201213143117.jpg)

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201213143132.png)

2.*编译时，在下拉框中选择的是**Release**，*X86，然后生成解决方案。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201213144705.png)

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201213143618.jpg)

3.在项目文件夹下找到“Release”文件夹，进入。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201213143811.png)

4.在“Release”文件夹下找到生成的.exe文件，拷贝到最初下载解压得到的文件夹中的“资源文件”下，双击.exe文件即可运行游戏。“资源文件”文件夹即为最终游戏包，可压缩打包发送给他人游玩。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201213143934.png)

## 系统设计

### Note类

#### 成员

##### 变量

###### 公有

音符左上角、右下角坐标：int nTopRect=0,nBottomRect=25;int nLeftRect, nRightRect;

音符样式(颜色)：int style;

###### 保护

音符为圆角矩形，圆角部分的宽、高：int nWidth=10, nHeight=10;

##### 函数

###### 公有

初始化音符信息

音符下落

绘制音符

### Area类

#### 成员

##### 变量

###### 保护

区域左上角坐标：int x, y;

区域宽高：int width, height;

背景图片：ACL_Image img;

##### 函数

###### 公有

构造函数
拷贝构造函数
析构函数
区域绘制函数，声明为纯虚函数。

### GifArea类

#### 成员

##### 变量

###### 保护

GIF数量：int gifnum;
帧数数组：int* zhen=new int(gifnum + 1);
GifArea的编号：int id;
Gif相应的图片名：char imgname[14] = "00-01-000.jpg";
gif图片名序列：int v2 = 0, v1 = 1, w3 = 0, w2 = 0, w1 = 0;

GifArea的编号和gif图片名序列用于加载图片前更改文件名，以实现动画效果。

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201209181026.png)

###### 公有

帧间隔数组，存储每个GIF动画的帧间隔时间：int* dt = new int(gifnum + 1);
记录播放到第几个GIF动画：int gifindex = 1;

##### 函数

###### 公有

构造函数
实现从父类Area类继承的纯虚函数，区域绘制函数
播放下一个GIF动画

### Playarea类

#### 成员

##### 变量

###### 公有

音符命中率：float rightrate;
游戏进度：int percent = 0;

###### 保护

音符命中数：int score = 0;
音符数组，存储生成的音符：Note* note[500] = { 0 };
已生成音符数：int nowNum = 0;

##### 函数

###### 公有

构造函数
生成音符
窗体中所有音符下移
判定是否命中音符
实现从父类Area类继承的纯虚函数，区域绘制函数

### 类间关系

![](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201209193743.png)

### 主体

#### 各区域规划

![规划图](https://gitee.com/wanli-0ziyuan/gitee-graph-bed/raw/master/img/20201208222331.png)

#### 重要环节

##### GIF动画

加载各个GIF动画帧数，数组存储

加载各个GIF动画每帧间隔时间，数组存储

##### 背景音乐

加载并播放背景音乐

#### 注册事件

##### 定时器

###### 定时器0

根据当前GIF动画每帧间隔时间进行中断，调用区域绘制函数重绘动画播放区，实现单个GIF动画播放。

###### 定时器1

控制每个GIF动画播放时长，触发后播放下一个GIF动画。

###### 定时器2

根据倒计时动画每帧间隔时间进行中断，调用区域绘制函数重绘玩家操作区，实现动画播放。

###### 定时器3

控制倒计时结束时间，触发后将一个全局布尔变量置真，意为开始游戏。

###### 定时器4

控制生成音符时间，触发一次，利用随机数和Playarea类生成音符函数，随机生成0，1或2个音符，然后调用区域绘制函数重绘玩家操作区。

###### 定时器5

每触发一次游戏进度+1，然后调用区域绘制函数重绘玩家操作区，从而实时显示游戏进度。

###### 定时器6

每触发一次调用Playarea类窗体中所有音符下移的函数，然后调用区域绘制函数重绘玩家操作区，实现音符下落效果。

###### 定时器7

游戏结束，停止动画播放，根据命中率，在动画播放区显示玩家最终评级。

##### 键盘

如果发生的事件为按下，则调用Playarea类中判定是否命中音符的函数。

## 程序实现

#### Note类

##### 初始化音符信息

###### 函数原型

void initNote();

###### 函数实现

通过rand生成随机数，mod2以后赋给style
通过rand生成随机数，mod4*音符宽度以后赋给nLeftRect
nLeftRect加上音符宽度赋给nLeftRect

##### 音符下落

###### 函数原型

void movedown();

###### 函数实现

nTopRect和nBottomRect均增加一定值，值越大，下落越快。

##### 绘制音符

###### 函数原型

void drawNote();

###### 函数实现

1. 判断style的值。如果为0，则通过setPenColor和setBrushColor函数定义画笔画刷为蓝色；否则定义画笔画刷为紫色。
2. 通过绘制圆角矩形的函数roundrect(nLeftRect,nTopRect,nRightRect,nBottomRect,nWidth,nHeight);绘制音符。

#### Area类

##### 构造函数

###### 函数原型

Area(int x, int y, int width, int height);

###### 函数实现

将传入的x, y, width, height分别赋给this指针指向的x, y, width, height。

##### 拷贝构造函数

函数原型

Area(Area& area);

函数实现

将作为引用的area的x, y, width, height分别赋给x, y, width, height。

##### 析构函数

函数原型

~Area();

函数实现

函数体为空。

##### 区域绘制函数

###### 函数原型

virtual void drawArea() = 0;

###### 函数实现

声明为纯虚函数,函数体为空。

#### GifArea类

##### 构造函数

###### 函数原型

GifArea(int x, int y, int width, int height,int num,int* Zhen,int* Dt, int Id);

###### 函数实现

将传入的x, y, width, height通过参数表传给从父类Area继承的成员变量x, y, width, height。

将传入的num, Zhen, Dt, Id分别赋给this指针指向的gifnum, zhen, dt, id。

##### 区域绘制函数

###### 函数原型

void drawArea();//从父类Area类继承的纯虚函数

###### 函数实现

1. 如果gifindex <= gifnum，即GIF未播放完，则进行下一步；否则函数执行结束；
2. gif图片名序列中的w1自增；
3. 判断w1是否等于10，是则w1归0，w2+1;
4. 判断w2是否等于10，是则w2归0，w3+1;
5. 判断当前GIF是否播放完最后一帧，即w3 * 100 + w2 * 10 + w1是否等于zhen[gifindex]，是则w3和w2归0，w1置1;
6. 将(id / 10) + '0'赋给imgname[0]，将id % 10 + '0'赋给imgname[1]，将w3 + '0'赋给imgname[6]，将w2 + '0'赋给imgname[7]，将w1 + '0'赋给imgname[8]；
7. 利用新的图片名数组，通过loadImage(imgname, &img);加载下一帧图片；
8. 通过putImageScale(&img, x, y, width, height);进行图片绘制；
9. 函数执行结束。

##### 播放下一个GIF动画

###### 函数原型

void next();

###### 函数实现

1. 将gif图片名序列中的w3,w2,w1置0；
2. 如果gifindex <= gifnum，即GIF未播放完，则进行下一步；否则函数执行结束；
3. 当前gif图片序号gifindex自增，gif图片名序列中的v1自增；
4. 判断v1是否等于10，是则v1归0，v2+1;
5. 将v2 + '0'赋给imgname[3]，将v1 + '0'赋给imgname[4]；
6. 函数执行结束。

#### Playarea类

##### 构造函数

###### 函数原型

Playarea(int x, int y, int width, int height);

###### 函数实现

###### 

##### 生成音符

###### 函数原型

void createNote();

###### 函数实现



##### 所有音符下移

###### 函数原型

void move();

###### 函数实现



##### 判定是否命中音符

###### 函数原型

void judge(int key);

###### 函数实现



##### 区域绘制函数

###### 函数原型

void drawArea();//从父类Area类继承的纯虚函数

###### 函数实现



#### 全局函数

##### 加载各个GIF动画帧数

```c++
void loadzhen(int* zhen);
```

传入一个整型数组的地址，将各个GIF动画帧数存放进该数组。

##### 加载各个GIF动画每帧间隔时间

```c++
void loaddt(int* dt);
```

传入一个整型数组的地址，将各个GIF动画每帧间隔时间存放进该数组。

#### 窗体

生成程序窗体，title : 窗口标题。left : 窗口左上角横坐标，若不希望指定窗口位置，可传入 DEFAULT。 top : 窗口左上角纵坐标，若不希望指定窗口位置，可传入 DEFAULT。 width : 窗口可绘制区域的宽度。 height : 窗口可绘制区域的高度。

```c++
initWindow(const char title[], int left, int top, int width, int height);
```

#### 背景音乐

##### 加载

从文件中加载声音文件，第一个参数为文件名，第二个参数为指向一个ACL_Sound结构的指针。

```c++
loadSound("FirstKiss.mp3", &winsound);
```

##### 播放

第二个参数非零时，音乐将循环播放。否则只播放一遍

```c++
playSound(winsound, 0);
```

#### 定时器

##### 注册定时器中断

```c++
registerTimerEvent(timerEvent);
```

##### 开启定时器

```c++
startTimer(int timerID, int timeinterval);
```

1. 定时器时间间隔单位为毫秒。设置定时器后，每经过 timeinterval 毫秒时间，便会触发 timer 事件。
2. 可以使用多个 timer，ID 建议使用从 0 开始的整数。 
3. 当 timeinterval 设置为 0 时，定时器会在程序空闲时（没有键盘、鼠标输入，且上次 timer 事件已经处理）触发。 
4. timer 的时间精度在 10ms数量级，当设置的时间间隔小于 10ms 时，实际间隔会在 10ms 以上。

##### 定时器事件

```c++
void timerEvent(int id) {}
```

通过switch 语句对id进行判断，从而得知是第几个定时器触发 timer 事件，进而执行相应语句，时序性地实现各项功能。

#### 键盘

##### 注册键盘中断

```c++
registerKeyboardEvent(keyEvent);
```

##### 键盘事件

第一个参数为按键的虚拟键码（注意：不是 ASCII 码）。第二个参数为发生的事件（按下或弹起）。

```c++
void keyEvent(int key, int event){}
```

通过对象调用Playarea类的judge(key);函数，判定是否命中音符。

## 测试报告

### 测试方法

### 测试过程

### 测试结果

未完待续。。。