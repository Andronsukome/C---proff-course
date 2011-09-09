#include "stdafx.h"
#include "B.h"

void B::PrintB()
{
	cout << "B(" << this << "): " << this->b << endl;
}

B::B(int tmp):b(tmp)
{
}
