// ClassLine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Line.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Line First, Second, Third(1,2,3,4), Five(1,2,3,4);
	Second.SetLine(1,6,7,8);
	First.Show("First");
	Second.Show("Second");
	Third.Show("Third");
	if(Second.CheckParallel(Third))
		std::cout << "\n\nOK!!\n\n";
	else
		std::cout << "\n\nNO!!\n\n";
	Third.SetParallel(Second);
	Second.Show("Second");
	Third.Show("Third");
 	if(Second.CheckParallel(Third))
		std::cout << "\n\nOK!!\n\n";
	else
		std::cout << "\n\nNO!!\n\n";
	return 0;
}

