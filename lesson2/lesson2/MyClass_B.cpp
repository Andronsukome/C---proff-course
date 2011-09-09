#include "stdafx.h"
#include "MyClass_B.h"

MyClass_B::MyClass_B(int ia) : iValueA(ia)
{
	std::cout << "Create Obj b " << this->iValueA << "    " << this <<std::endl;
}

MyClass_B::~MyClass_B()
{
	std::cout << "Delete Obj b " << this->iValueA << "    " << this <<std::endl;
}

void MyClass_B::Show()
{
	std::cout << "Show Obj b " << this->iValueA << "    " << this <<std::endl;
}