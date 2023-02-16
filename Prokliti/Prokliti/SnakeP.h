#pragma once
#include <curses.h>
#include "WrawS.h"
#include <queue>

using namespace std;

enum Direct //����� ����������� 
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
	queue<SnakeP> prev_pieces;//���������� ����������� ������
	Direct cur_direct;

public:
	SnakeG()//�������� �����
	{
		cur_direct = down;
	}

	void addP(SnakeP piece) {
		prev_pieces.push(piece);//������������ �������
	}

	void removePice( ) {
		prev_pieces.pop();//�������� �������� �������
	}

	SnakeP tail() {
		return prev_pieces.front();//��������� � ������� �������� �������
	}

	SnakeP head() {
		
		return prev_pieces.back();//��������� � ���������� �������� �������
	}

	Direct get_direct()
	{
		return cur_direct;//����������� ����������� 
	}
	void setDirect(Direct d) {
		cur_direct = d;
	}


	SnakeP nextHead() {//�������� �������
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
