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

void background(void);//��ʾ������������ʾ
void showbuffer(void);//��ʾ��
bool update(void);
bool _error(int x, int y);
void _clear(void);
void showfood(void);


//�����и�������������һ��������,�߸�ʳ�ﶼ����
SHOW buffer[100];
int BIndex;//����������,ͷ��ʼ��0
enum Status {welcome,gaming,die,pause};
enum Status status;
int main(void)
{
	SLIST temp;
	setCursorPosition(1, 21);
	printf("Enter any key to start:");
	/*status = welcome,die*/
	while (getchar()!='q')//Ĭ�������Ժ��߿�ʼ�ƶ������ѭ���������Ļ�ֱ��break�ͺ���,
		//�ٺ٣����Լ��̿�����
	{
		status = gaming;
		srand(time(NULL)); //�ڳ���ʼʱ����һ��
		background();
		//okok,���ڳ�ʼ����,ʳ��
		init_snake(4);
		SHOW food1 = food();
		buffer[0] = food1;
		showfood();
        BIndex=1;
		temp = LISTHEAD;
		while (temp != NULL)//Ȼ��ѳ�ʼ��Ҳ�洢��ȥ
		{
			buffer[BIndex++] = temp->show;
			temp = temp->next;
		}//����buffer���ֵ����BIndex-1
		showbuffer();//��ʾ���������ߣ��ã�����һ����ʾʱ������һ��
		//okok,�Ѿ���ʾ��ʼ����
	    timer(update, 1);//update�������false,����������
        setCursorPosition(1,21);
		printf("Enter any key to start:");
	}
	//���밡������߲�����ʱ����ͷ��β����Ҫ����Ȼ��ֻ��Ҫ����ͷ��β��������һ��
	//��������ʱ�򣬺ã���β���䣬��ͷ�����ӣ�֮ǰ����ͷ������������ʳ��Ҫ��������
	//�о�Ҫ�ѻ���������д�룬��ȡһ��
    
	
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
			printf("��");//����ռ�����ַ�
		}
		printf("\n");
	}
	printf("enter ENTER(or 1~9) to start.\n");
	printf("enter ESC to quit.\n");
}
//��ʾ��������
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
	_clear();//����ʳ��ȫ�䱳��
	BIndex = 1;
	getkeyboard();
	SHOW temp = { 0,0,'a' };
	if (_ESC == true)//�������esc��
	{
		_ESC = false;
		return false;
	}
	//�Ȱѽ�������������
	switch (dir) {
	case DIR_UP:
		temp.x = LISTTAIL->show.x;
		temp.y = LISTTAIL->show.y - 1;  // y��С�����ϣ�
		break;
	case DIR_DOWN:
		temp.x = LISTTAIL->show.x;
		temp.y = LISTTAIL->show.y + 1;  // y���ӣ����£�
		break;
	case DIR_LEFT:
		temp.x = LISTTAIL->show.x - 1;  // x��С������
		temp.y = LISTTAIL->show.y;
		break;
	case DIR_RIGHT:
		temp.x = LISTTAIL->show.x + 1;  // x���ӣ����ң�
		temp.y = LISTTAIL->show.y;
		break;
	}
	if (_error(temp.x, temp.y) == false)
		return false;
	//����temp�ǽ���ͷ��������
	//��֮ǰͷΪ����
    strcpy(LISTTAIL->show.a, BODY);
	strcpy(temp.a, HEAD);
	Addshow(temp);
	if (temp.x == buffer[0].x && temp.y == buffer[0].y)
	{
		//����Ե�ʳ�� buffer[0]��Ϊfood�洢��������һ��ʳ���֮ǰʳ����ʾ�䱳��
		strcpy(buffer[0].a, BG);
		SHOW food1 = food();
		buffer[0] = food1;
		showfood();
	}
	else {	
		Deltail();//��������������ʾ��û��ʾ����Ļ�ϣ��о�Ҫ������ʾ��
	}
	//�ٰ�ʳ�������ʾһ��
	SLIST temp1;
	temp1 = LISTHEAD;//BIndex��1
	while (temp1 != NULL)
	{
		buffer[BIndex++] = temp1->show;
		temp1 = temp1->next;
	}
	showbuffer();
	return true;
}
bool _error(int x, int y)//�жϽ����������ǲ��ǻ���Լ����߳���ǽ
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
	for (int i = 1; i <BIndex; i++) {//����ʲô������ν�������ߣ�ʳ����˵
		strcpy(buffer[i].a , BG);
	}
	//��������ʾһ�±�����
	showbuffer();
}

void showfood(void)//��ʾbuffer[0]���涫��
{
	setCursorPosition(buffer[0].x, buffer[0].y);
	printf("%s", FOOD);
}