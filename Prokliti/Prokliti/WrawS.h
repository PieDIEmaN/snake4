#pragma once
#include <curses.h>





class WrawS//вспомогательный класс отрисовки
{
public:
	WrawS() {
		y = x = 0;
		icon = ' ';

	}

	WrawS(int y, int x, chtype ch) {//принятие координат

		this->y = y;
		this->x = x;
		this->icon =  ch;

	}
	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	chtype getIcone() {
		return icon;
	}


protected://доступ открыт классам, производным от 
	//данного. То есть, производные классы получают свободный доступ
		//к таким свойствам или метода. Все другие классы такого доступа не имеют.
	int y , x;
	chtype icon;
};

