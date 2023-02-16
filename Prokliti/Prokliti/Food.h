#pragma once
#include <curses.h>
#include "WrawS.h"
class Food : public WrawS 
{
public:

	Food(int y, int x) {//вспомогательный модуль отрисовки "еды"для змеи

		this->y = y;
		this->x = x;
		this->icon = 'A';
	}

};

