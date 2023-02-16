#pragma once
#include "curses.h"
#include <time.h>
#include <stdlib.h>


#include "Board.h"
#include "WrawS.h"
#include"Food.h"
#include "Frick.h"
#include "SnakeP.h"


class Snake// ��� ����� ����
{

	Board board;
	Food* food;
	bool game_over;	
	SnakeG snn;
	

public:

	Snake(int height, int width) { //������ �������������� ���� �� ���� ������ 
		board = Board(height, width);
		boom();
	}

	~Snake() {
		delete food;
	}

	void boom() {//���������� ���������

		food = NULL;
		board.create();
		game_over = false;
		srand(time(NULL));	

		snn.setDirect(down);

		SnakeP next = SnakeP(1, 1);//������������� �������
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


	void pInpud() {//chtype ��� ��������, � �������� 
		//�������� ncurses (�� �������� � ���� ��� �������, ���� � �������������� ��������)
		chtype input = board.getInpute();
	
	}
	void uState() {
				
		
		if (food != NULL) {
			int y, x;
			board.getEmCrdiinat(y, x);//���������� ������ �����
			food = new Food(y, x);//�������� ������ ������� �� ������ �����				
			board.addd(*food);//��������� �������
		}
		
		SnakeP next = snn.nextHead();

		if (next.getX() != food->getX() && next.getY() != food->getY()) {

			int emptyrow = snn.tail().getY();//����� ������ �� � �
			int emptycol = snn.tail().getX();
			board.addd(Frick(emptyrow, emptycol)); //��������� �� ������ ����������� 
			snn.removePice();
		}
		board.addd(next);
		snn.addP(next);

		
		
		
		//board.addd(WrawS(3, 5, '#'));
	}

	void redraw() {//���������
		board.refresh();
	}

	bool isover() {//���������� 
		return game_over;
	}

	
	
};

