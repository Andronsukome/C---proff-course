#include "stdafx.h"
#include "MyClass.h"

MyClass::MyClass(int ia) : iValueA(ia), Obj(ia)
{
	std::cout << "Create Obj " << this->iValueA << "    " << this <<std::endl;
}

MyClass::~MyClass()
{
	std::cout << "Delete Obj " << this->iValueA << "    " << this <<std::endl;
}

void MyClass::Show()
{
	std::cout << "Show Obj " << this->iValueA << "    " << this <<std::endl;
	Obj.Show();
}
