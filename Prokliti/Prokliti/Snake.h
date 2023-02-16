#pragma once
#include "curses.h"
#include <time.h>
#include <stdlib.h>


#include "Board.h"
#include "WrawS.h"
#include"Food.h"
#include "Frick.h"
#include "SnakeP.h"


class Snake// для самой игры
{

	Board board;
	Food* food;
	bool game_over;	
	SnakeG snn;
	

public:

	Snake(int height, int width) { //запуск полупокерского поля на этом классе 
		board = Board(height, width);
		boom();
	}

	~Snake() {
		delete food;
	}

	void boom() {//реализация программы

		food = NULL;
		board.create();
		game_over = false;
		srand(time(NULL));	

		snn.setDirect(down);

		SnakeP next = SnakeP(1, 1);//инициализация змейкии
		board.addd(next);
		snn.addP(next);

		next = snn.nextHead();
		board.addd(next);
		snn.addP(next);

		next = snn.nextHead();
		board.addd(next);
		snn.addP(next);

		snn.setDirect(right);

		next = snn.nextHead();
		board.addd(next);
		snn.addP(next);
		
		
		
	}


	void pInpud() {//chtype тип символов, с которыми 
		//работает ncurses (он включает в себя код символа, цвет и дополнительные атрибуты)
		chtype input = board.getInpute();
	
	}
	void uState() {
				
		
		if (food != NULL) {
			int y, x;
			board.getEmCrdiinat(y, x);//нахождение пустых коорд
			food = new Food(y, x);//создание нового объекта по пустым коорд				
			board.addd(*food);//отрисовка объекта
		}
		
		SnakeP next = snn.nextHead();

		if (next.getX() != food->getX() && next.getY() != food->getY()) {

			int emptyrow = snn.tail().getY();//поиск хвоста по х у
			int emptycol = snn.tail().getX();
			board.addd(Frick(emptyrow, emptycol)); //отрисовка на пустом пространсве 
			snn.removePice();
		}
		board.addd(next);
		snn.addP(next);

		
		
		
		//board.addd(WrawS(3, 5, '#'));
	}

	void redraw() {//отрисовка
		board.refresh();
	}

	bool isover() {//концовочка 
		return game_over;
	}

	
	
};

