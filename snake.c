#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "snake.h"
#include "cursor.h"
SLIST LISTHEAD=NULL;
SLIST LISTTAIL = NULL;
//确认蛇初始长度，创建蛇链表
void  init_snake(int len)
{
	//首先，确认蛇的初始长度，怎么显示呢，
	// 先把蛇的各个坐标配好，然后送入到缓冲区里面
	//首先初始化链表
	SLIST temp,temp1;
	if ((temp = (SNODE*)malloc(sizeof(SNODE))) == NULL)
		exit(EXIT_FAILURE);
	temp->show.x = 0;
	temp->show.y = 1;
    strcpy(temp->show.a ,BODY);
	temp->next = NULL;
	LISTHEAD = temp;//链表头创建好了，实际是尾巴
	for (int i = 1;i < len;i++)
	{
		if ((temp1 = (SNODE*)malloc(sizeof(SNODE))) == NULL)
			exit(EXIT_FAILURE);
		temp1->show.x = i;
		temp1->show.y = 1;
		strcpy(temp1->show.a, BODY);
		temp1->next = NULL;//temp1配置好
		temp->next = temp1;
		temp = temp1;//ok,这个蛇的身体也创建好了，temp1就是蛇头
		if (i == len - 1)
		{
			strcpy(temp1->show.a, HEAD);
			LISTTAIL = temp1;
		}
	}
}
//释放蛇内存
void free_snake(void)
{
	SLIST temp;
	while (LISTHEAD != NULL)
	{
		temp = LISTHEAD->next;
		free(LISTHEAD);
		LISTHEAD = temp;
	}
}
//在链表尾添加节点
void Addshow(SHOW  w)
{
	SLIST temp;
	if ((temp = (SNODE*)malloc(sizeof(SNODE))) == NULL)
		exit(EXIT_FAILURE);
	temp->show = w;
	temp->next = NULL;
	LISTTAIL->next = temp;
	LISTTAIL = temp;
}

void Deltail(void)//删除链表头,蛇尾，而且要把蛇尾恢复成背景
{
	SLIST temp;

	//strcpy(LISTHEAD->show.a, BG);//只是在缓存区里面更新了，
	setCursorPosition(LISTHEAD->show.x, LISTHEAD->show.y);
	printf("%s", BG);
	temp = LISTHEAD->next;
	free(LISTHEAD);
	LISTHEAD = temp;
}