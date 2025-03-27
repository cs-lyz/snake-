#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "snake.h"
#include "food.h"
#include "cursor.h"
#include "keyboard.h"
#include "timer.h"

void background(void);//显示背景方格格跟提示
void showbuffer(void);//显示蛇
bool update(void);
bool _error(int x, int y);
void _clear(void);
void showfood(void);


//还得有个缓冲区哎，建一个缓冲区,蛇跟食物都在这
SHOW buffer[100];
int BIndex;//缓冲区索引,头开始是0
enum Status {welcome,gaming,die,pause};
enum Status status;
int main(void)
{
	SLIST temp;
	setCursorPosition(1, 21);
	printf("Enter any key to start:");
	/*status = welcome,die*/
	while (getchar()!='q')//默认输完以后蛇开始移动，这个循环，死亡的话直接break就好了,
		//嘿嘿，可以键盘控制了
	{
		status = gaming;
		srand(time(NULL)); //在程序开始时调用一次
		background();
		//okok,现在初始化蛇,食物
		init_snake(4);
		SHOW food1 = food();
		buffer[0] = food1;
		showfood();
        BIndex=1;
		temp = LISTHEAD;
		while (temp != NULL)//然后把初始蛇也存储进去
		{
			buffer[BIndex++] = temp->show;
			temp = temp->next;
		}//现在buffer最大值就是BIndex-1
		showbuffer();//显示缓存区里蛇，好，等下一回显示时候得清空一下
		//okok,已经显示初始化了
	    timer(update, 1);//update如果等于false,这个程序结束
        setCursorPosition(1,21);
		printf("Enter any key to start:");
	}
	//想想啊，这个蛇不增加时候，蛇头蛇尾都需要换，然后只需要叫蛇头蛇尾坐标增加一下
	//当蛇增加时候，好，蛇尾不变，蛇头新增加，之前的蛇头换背景，还有食物要重新生成
	//感觉要把缓存区重新写入，读取一下
    
	
	return 0;
}
void background(void)
{
	int i, j;
	setCursorPosition(0, 0);
	for (i =0 ;i <= 19;i++)
	{
		for (j = 0;j <= 19;j++)
		{
			printf("■");//至少占两个字符
		}
		printf("\n");
	}
	printf("enter ENTER(or 1~9) to start.\n");
	printf("enter ESC to quit.\n");
}
//显示缓存区蛇
void showbuffer(void)
{
	for (int i = 1;i < BIndex;i++)
	{
		setCursorPosition(buffer[i].x, buffer[i].y);
		printf("%s", buffer[i].a);
	}
	BIndex = 1;
}

bool  update(void)
{
	_clear();//除了食物全变背景
	BIndex = 1;
	getkeyboard();
	SHOW temp = { 0,0,'a' };
	if (_ESC == true)//如果按了esc键
	{
		_ESC = false;
		return false;
	}
	//先把将来坐标整出来
	switch (dir) {
	case DIR_UP:
		temp.x = LISTTAIL->show.x;
		temp.y = LISTTAIL->show.y - 1;  // y减小（向上）
		break;
	case DIR_DOWN:
		temp.x = LISTTAIL->show.x;
		temp.y = LISTTAIL->show.y + 1;  // y增加（向下）
		break;
	case DIR_LEFT:
		temp.x = LISTTAIL->show.x - 1;  // x减小（向左）
		temp.y = LISTTAIL->show.y;
		break;
	case DIR_RIGHT:
		temp.x = LISTTAIL->show.x + 1;  // x增加（向右）
		temp.y = LISTTAIL->show.y;
		break;
	}
	if (_error(temp.x, temp.y) == false)
		return false;
	//现在temp是将来头的坐标了
	//变之前头为身体
    strcpy(LISTTAIL->show.a, BODY);
	strcpy(temp.a, HEAD);
	Addshow(temp);
	if (temp.x == buffer[0].x && temp.y == buffer[0].y)
	{
		//如果吃到食物 buffer[0]作为food存储区，更新一下食物，把之前食物显示变背景
		strcpy(buffer[0].a, BG);
		SHOW food1 = food();
		buffer[0] = food1;
		showfood();
	}
	else {	
		Deltail();//改蛇链表里面显示，没显示到屏幕上，感觉要马上显示，
	}
	//再把食物跟蛇显示一遍
	SLIST temp1;
	temp1 = LISTHEAD;//BIndex是1
	while (temp1 != NULL)
	{
		buffer[BIndex++] = temp1->show;
		temp1 = temp1->next;
	}
	showbuffer();
	return true;
}
bool _error(int x, int y)//判断将来的坐标是不是会跟自己或者超过墙
{
	SNODE* temp;
	temp = LISTHEAD;
	if ((x< 0) || (x >19) || (y < 0) || (y > 19))
		return false;
	while (temp->next != NULL)
	{
		if (temp->show.x == x && temp->show.y == y)
			return false;
		temp = temp->next;
	}
	return true;
}

void _clear(void)
{
	for (int i = 1; i <BIndex; i++) {//坐标什么的无所谓，重置蛇，食物再说
		strcpy(buffer[i].a , BG);
	}
	//再重新显示一下背景，
	showbuffer();
}

void showfood(void)//显示buffer[0]里面东西
{
	setCursorPosition(buffer[0].x, buffer[0].y);
	printf("%s", FOOD);
}