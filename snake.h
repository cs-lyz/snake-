#define _CRT_SECURE_NO_WARNINGS

#ifndef  SNAKE_H
#define  SNAKE_H
#include <stdio.h>
#define BG "��"
#define BODY   "��"
#define HEAD  "��"
#define FOOD  "��"

typedef struct  SHOW {
	int x;
	int y;
	char a[2];
}SHOW;//��ʾ�ڵ�
typedef struct   slist {
	SHOW  show;
	struct slist* next;
}SNODE;
typedef SNODE* SLIST;
void init_snake(int len);
void free_snake(void);
void Addshow(SHOW  w);
void Deltail(void);
extern SLIST LISTHEAD;
extern SLIST LISTTAIL;
#endif