#define _CRT_SECURE_NO_WARNINGS
#include "timer.h"
// 定时执行函数   1 表示间隔时间(秒)。
void timer(bool (*FuncPtr)(void), int seconds) {
    clock_t lastTime = clock();
    while (1) {
        clock_t currentTime = clock();
        if ((currentTime - lastTime) / CLOCKS_PER_SEC >= seconds) {
            if((*FuncPtr)()==false)
                break;        // 如果函数执行不到位，退出
            lastTime = currentTime;
        }
    }
}