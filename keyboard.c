#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>  // Windows ר��
#include <stdbool.h>
#include "keyboard.h"
DIR dir = DIR_RIGHT;
bool  _ENTER= false;
bool  _ESC=false;
//ɶҲ���÷����ˣ�ȫ�ֱ���
//д�������룬��w a s d,enter �����ּ���esc
//okok,����˼·����������ǳ�ʼ���߸��������ʳ�������bug����
//Ȼ��� ���൱��1sˢ��һ�ΰ�,��һ���ȥ��Ȼ����������ʾ���������涫��
//����һ��Ҫ��ɶ  ����ˢ���ߣ����ˢ��ʳ�ʳ��ȽϺ�˵���ѵ�����
//okok,����ôˢ�£��Ͱ�������Ϸ��˵��ʲô������û����ʱ����һ������ǰ��
// ״̬1����Ϸ�У�û�Ե�ʳ��  ��ȡ����״̬��ͨ���������������ĸ�����
// ��������β�ͣ�β����ʧһ��ɾ������ͷ��ɾ������ͷҪ��ɾ������β��ɾ���Ķࣩ
// ״̬2���Ե�ʳ���������β�ͣ���β����ʧ
// ״̬3���������ս�����Ϸ����enter�������ּ���esc��
bool getkeyboard(void)//���·���
{
    if (_kbhit()) {  // ����Ƿ��а�������
        int key = _getch();  // ��ȡ����
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
