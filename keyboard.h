#ifndef  KEYBOARD_H
#define KEYBOARD_H
#include <stdbool.h>
typedef enum direction {
    DIR_UP,     // ������ϵͳ���ͻ����Windows��`up`��
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} DIR;
extern DIR dir;
// ����2�������ⲿ����������Ӧ��.c�ļ��У�
extern bool _ENTER; // ʹ��bool����int
extern bool _ESC;   // ������ϵͳ`esc`��ͻ
bool getkeyboard(void);
#endif