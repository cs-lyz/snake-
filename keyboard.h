#ifndef  KEYBOARD_H
#define KEYBOARD_H
#include <stdbool.h>
typedef enum direction {
    DIR_UP,     // 避免与系统宏冲突（如Windows的`up`）
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} DIR;
extern DIR dir;
// 修正2：声明外部变量（定义应在.c文件中）
extern bool _ENTER; // 使用bool而非int
extern bool _ESC;   // 避免与系统`esc`冲突
bool getkeyboard(void);
#endif