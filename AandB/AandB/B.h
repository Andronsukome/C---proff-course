#pragma once

#include "A.h"

class B
{
	int b;
	A b1;//обьект класса А, имеет доступ ко всем открытым функциям класса А

public:
	B(int tmp);

	void PrintB(char * Name = "B");

};