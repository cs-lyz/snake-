#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
void setCursorPosition(int x, int y) {
    COORD coord = { 2*x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
