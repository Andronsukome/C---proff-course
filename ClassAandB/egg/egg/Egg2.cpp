#include "stdafx.h"
#include "Egg2.h"

//Конструктор по умолчанию
Egg2::Egg2(int iSteMaxVall, int iSetSize) : iMaxVall(iSteMaxVall), iSize(iSetSize), pcVal(NULL)
{
	srand((unsigned int)time(NULL));
	this->pcVal = new char[this->iSize];
	
	for(register int i = 0; i < this->iSize; ++i)
	{
		this->pcVal[i] = rand() % this->iMaxVall;
	}

	std::cout << "\nCalling the constructor of the class 0x" << this << std::endl;
}

//Конструктор копирования
Egg2::Egg2(const Egg2 &CpyObj) : pcVal(NULL)
{
	if(NULL != CpyObj.pcVal)
	{
		this->iMaxVall = CpyObj.iMaxVall;
		this->iSize = CpyObj.iSize;
		this->pcVal = new char[this->iSize];
		if( memcpy_s(this->pcVal, sizeof(char) * this->iSize, CpyObj.pcVal, sizeof(char) * this->iSize) )
		{
			exit(1);
		}
	}
	std::cout << "\nCall the copy constructor of the class 0x" << this << std::endl;
}


//Метод вывода значений на экран
void Egg2::Show()
{
	for(register int i = 0; i < this->iSize; ++i)
	{
		std::cout << '\n' << this->pcVal[i] << std::endl;
	}
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

	std::cout << "\nCall, \"Show\" class 0x" << this << std::endl;
}


//Деструктор класса
Egg2::~Egg2()
{
	delete[] this->pcVal;
	this->pcVal = NULL;
	std::cout << "\nCalling the destructor of the class 0x" << this << std::endl;
}
