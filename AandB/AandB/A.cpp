#include "stdafx.h"
#include "A.h"

void A::PrintA(char * Name)
{
	cout << Name << "(" << this << "): " << this->a << endl;
}

A::A(int tmp):a(tmp)
{
}