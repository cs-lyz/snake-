#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>  // Windows 专属
#include <stdbool.h>
#include "keyboard.h"
DIR dir = DIR_RIGHT;
bool  _ENTER= false;
bool  _ESC=false;
//啥也不用返回了，全局变量
//写键盘输入，用w a s d,enter 跟数字键，esc
//okok,整整思路，现在情况是初始化蛇跟随机出现食物（可能有bug）了
//然后额 ，相当于1s刷新一次吧,这一秒过去，然后嘞重新显示缓冲区里面东西
//那这一秒要干啥  首先刷新蛇，其次刷新食物，食物比较好说，难点是蛇
//okok,蛇怎么刷新，就按正常游戏来说，什么按键都没按下时蛇下一秒会接着前进
// 状态1：游戏中，没吃到食物  读取按键状态，通过按键决定增加哪个坐标
// 新增链表尾巴，尾巴消失一格，删除链表头（删除链表头要比删除链表尾好删除的多）
// 状态2：吃到食物，新增链表尾巴，蛇尾不消失
// 状态3：死亡，刚进入游戏（按enter或者数字键或esc）
bool getkeyboard(void)//更新方向
{
    if (_kbhit()) {  // 检查是否有按键按下
        int key = _getch();  // 获取按键
        if (key == '\r' || key == '\n') {
            _ENTER = 1;
        }
        else if (key == 27) {
            _ESC = 1;
        }
        else {
            switch (key) {
            case 'w': 
                if(dir!=DIR_DOWN)
                dir=DIR_UP; break;
            case 's':
                if (dir != DIR_UP)
                dir = DIR_DOWN; break;
            case 'a': 
                if (dir != DIR_RIGHT)
                    dir = DIR_LEFT; break;
            case 'd': 
                if (dir != DIR_LEFT)
                    dir = DIR_RIGHT; break;
            }
        }
        return true;
    }
    else return false;
}
