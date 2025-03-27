#define _CRT_SECURE_NO_WARNINGS
#ifndef  TIMER_H
#define TIMER_H
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
void timer(bool (*FuncPtr)(void), int seconds);
#endif
