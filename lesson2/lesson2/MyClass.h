#pragma once
#include "MyClass_B.h"

class MyClass
{
private:
	int iValueA;
	MyClass_B Obj;

public:
	MyClass(int ia);
	
	void Show();


	~MyClass();
};
