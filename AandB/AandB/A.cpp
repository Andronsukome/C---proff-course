#include "stdafx.h"
#include "A.h"

void A::PrintA()
{
	cout << "A(" << this << "): " << this->a << endl;
}

A::A(int tmp):a(tmp)
{
}