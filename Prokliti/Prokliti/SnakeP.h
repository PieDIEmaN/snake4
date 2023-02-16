#pragma once
#include <curses.h>
#include "WrawS.h"
#include <queue>

using namespace std;

enum Direct //метод очередности 
{

	up,
	down,
	left,
	right

};


class SnakeP :public WrawS
{
public:
	


	SnakeP() {
		this->x = this->y = 0;
		this->icon = '#';
	}

	SnakeP(int y, int x) {
		this->x =  x;
		this->y = x;
		this->icon = '#';
	}

};


class SnakeG 
{
	queue<SnakeP> prev_pieces;//объявление очередности класса
	Direct cur_direct;

public:
	SnakeG()//движущий класс
	{
		cur_direct = down;
	}

	void addP(SnakeP piece) {
		prev_pieces.push(piece);//приорететная очередь
	}

	void removePice( ) {
		prev_pieces.pop();//удаление элемента очереди
	}

	SnakeP tail() {
		return prev_pieces.front();//обращение к первому элементу очереди
	}

	SnakeP head() {
		
		return prev_pieces.back();//обращение к последнему элементу очереди
	}

	Direct get_direct()
	{
		return cur_direct;//возвращение очередности 
	}
	void setDirect(Direct d) {
		cur_direct = d;
	}


	SnakeP nextHead() {//движущий элемент
		int row = head().getY();
		int col = head().getX();
		switch (cur_direct)
		{
		case down:
			row++;
			break;
		case up:
			row--;
			break;
		case left:
			col--;
			break;
		case right:
			col++;
			break;
		}
		return SnakeP(row, col);
	}


};
