#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "snake.h"
int food_flag = 0;
//okok,����food��ôд����Ҫʵ��һ��food��ʧ�����������һ��ʳ��
//��������ɺ�������,ͣͣͣ�����ԣ��������ɵ�������;
int usedfood[20][20] = {0};
SHOW food(void)//okѽ
{
	int x, y;
	SHOW temp;//ʳ��
	SLIST  a1;
	a1 = LISTHEAD;
	//�Ȱ����Ǽ�����������
	while (a1 != NULL)
	{
		usedfood[a1->show.x][a1->show.y]=1;
		a1 = a1->next;
	}
	//�ҵ����ظ�����
	do {
	 x = rand() % 19 + 1;
	 y = rand() % 19 + 1;
	} while (usedfood[x][y]);
	usedfood[x][y] = 1;//����x,y��������ʳ�������
	temp.x = x;
	temp.y = y;
	strcpy(temp.a, FOOD);
	return temp;
}
void black(SHOW q)
{
	strcpy(q.a, BG);
}