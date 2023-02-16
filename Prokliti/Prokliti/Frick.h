#pragma once

#include "curses.h"
#include "WrawS.h"
class Frick: public WrawS
{
public:
	Frick(int y, int x) {//вспомогательный модуль пустого пространства
		
		this->y = y;
		this->x = x;		
		this->icon = ' ';
		
	}
};

