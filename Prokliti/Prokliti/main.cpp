#include <curses.h>
#include "Board.h"
#include "Snake.h"
#include "WrawS.h"
#include "SnakeP.h"
#include "Frick.h"
#include"Food.h"




#define BOARD_DIIM 17 //������������,��� �������� ������ �����
#define BOARD_ROWS BOARD_DIIM 
#define BOARD_COLS BOARD_DIIM * 2.5
int main()
{
    
    initscr();//����� ����������� �������� ��� ������
    refresh();// ������������ �������� ������������ ���(������ �� �����������
    //�� �����)
    noecho();//��������� ����������� �������� ��������
    curs_set(0);

    Snake game = Snake(BOARD_ROWS, BOARD_COLS);

    while (!game.isover()) {

        game.pInpud();

        game.uState();

        game.redraw();
    }

    getch();//����� ������� ������
    endwin();//����� �� ������ �������, �����  ��������� 

    return 0;
}