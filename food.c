#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "snake.h"
int food_flag = 0;
//okok,想想food怎么写哎，要实现一个food消失，再随机出来一个食物
//先随机生成横纵坐标,停停停，不对，不能生成到蛇身上;
int usedfood[20][20] = {0};
SHOW food(void)//ok呀
{
	int x, y;
	SHOW temp;//食物
	SLIST  a1;
	a1 = LISTHEAD;
	//先把蛇那几个坐标用了
	while (a1 != NULL)
	{
		usedfood[a1->show.x][a1->show.y]=1;
		a1 = a1->next;
	}
	//找到不重复坐标
	do {
	 x = rand() % 19 + 1;
	 y = rand() % 19 + 1;
	} while (usedfood[x][y]);
	usedfood[x][y] = 1;//现在x,y是生成新食物的坐标
	temp.x = x;
	temp.y = y;
	strcpy(temp.a, FOOD);
	return temp;
}
void black(SHOW q)
{
	strcpy(q.a, BG);
}