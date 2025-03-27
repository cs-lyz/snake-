#define _CRT_SECURE_NO_WARNINGS
#include "timer.h"
// ��ʱִ�к���   1 ��ʾ���ʱ��(��)��
void timer(bool (*FuncPtr)(void), int seconds) {
    clock_t lastTime = clock();
    while (1) {
        clock_t currentTime = clock();
        if ((currentTime - lastTime) / CLOCKS_PER_SEC >= seconds) {
            if((*FuncPtr)()==false)
                break;        // �������ִ�в���λ���˳�
            lastTime = currentTime;
        }
    }
}