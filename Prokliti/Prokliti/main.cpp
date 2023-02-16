#include <curses.h>
#include "Board.h"
#include "Snake.h"
#include "WrawS.h"
#include "SnakeP.h"
#include "Frick.h"
#include"Food.h"




#define BOARD_DIIM 17 //предзагрузка,как констата только лучше
#define BOARD_ROWS BOARD_DIIM 
#define BOARD_COLS BOARD_DIIM * 2.5
int main()
{
    
    initscr();//балда переводящая терминал под курсед
    refresh();// отправляющая проверку изменившихся зон(писать не обязательно
    //но важно)
    noecho();//Выключаем отображение вводимых символов
    curs_set(0);

    Snake game = Snake(BOARD_ROWS, BOARD_COLS);

    while (!game.isover()) {

        game.pInpud();

        game.uState();

        game.redraw();
    }

    getch();//ловит нажатия кнопок
    endwin();//выход из режима курседа, иначе  сломается 

    return 0;
}