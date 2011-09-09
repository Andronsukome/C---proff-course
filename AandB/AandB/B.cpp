#include "stdafx.h"
#include "B.h"


void B::PrintB(char * Name)
{
	cout << Name << "(" << this << "): " << this->b << endl;
	b1.PrintA("B");
}

B::B(int tmp):b(tmp), b1(tmp)
{
}
