#define _CRT_SECURE_NO_WARNINGS

#ifndef  SNAKE_H
#define  SNAKE_H
#include <stdio.h>
#define BG "¡ö"
#define BODY   "¡ñ"
#define HEAD  "£¤"
#define FOOD  "¡î"

typedef struct  SHOW {
	int x;
	int y;
	char a[2];
}SHOW;//ÏÔÊ¾½Úµã
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