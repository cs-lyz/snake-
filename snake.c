#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "snake.h"
#include "cursor.h"
SLIST LISTHEAD=NULL;
SLIST LISTTAIL = NULL;
//ȷ���߳�ʼ���ȣ�����������
void  init_snake(int len)
{
	//���ȣ�ȷ���ߵĳ�ʼ���ȣ���ô��ʾ�أ�
	// �Ȱ��ߵĸ���������ã�Ȼ�����뵽����������
	//���ȳ�ʼ������
	SLIST temp,temp1;
	if ((temp = (SNODE*)malloc(sizeof(SNODE))) == NULL)
		exit(EXIT_FAILURE);
	temp->show.x = 0;
	temp->show.y = 1;
    strcpy(temp->show.a ,BODY);
	temp->next = NULL;
	LISTHEAD = temp;//����ͷ�������ˣ�ʵ����β��
	for (int i = 1;i < len;i++)
	{
		if ((temp1 = (SNODE*)malloc(sizeof(SNODE))) == NULL)
			exit(EXIT_FAILURE);
		temp1->show.x = i;
		temp1->show.y = 1;
		strcpy(temp1->show.a, BODY);
		temp1->next = NULL;//temp1���ú�
		temp->next = temp1;
		temp = temp1;//ok,����ߵ�����Ҳ�������ˣ�temp1������ͷ
		if (i == len - 1)
		{
			strcpy(temp1->show.a, HEAD);
			LISTTAIL = temp1;
		}
	}
}
//�ͷ����ڴ�
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
//������β��ӽڵ�
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

void Deltail(void)//ɾ������ͷ,��β������Ҫ����β�ָ��ɱ���
{
	SLIST temp;

	//strcpy(LISTHEAD->show.a, BG);//ֻ���ڻ�������������ˣ�
	setCursorPosition(LISTHEAD->show.x, LISTHEAD->show.y);
	printf("%s", BG);
	temp = LISTHEAD->next;
	free(LISTHEAD);
	LISTHEAD = temp;
}