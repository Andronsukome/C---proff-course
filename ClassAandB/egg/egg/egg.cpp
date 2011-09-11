// egg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Egg1 Obj1(10,10);
	Obj1.Show();
	std::cout << "***********************************" << std::endl;
	Egg1 Obj2(Obj1);
	Obj2.Show();
	
	
	
	
	return 0;
}

