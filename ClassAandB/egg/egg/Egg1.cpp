#include "stdafx.h"
#include "Egg1.h"

//Конструктор по умолчанию
Egg1::Egg1(int iSteMaxVall, int iSetSize) 
: iMaxVall(iSteMaxVall), iSize(iSetSize), piVal(NULL), InternalEgg(iSteMaxVall,iSetSize)
{
	srand((unsigned int)time(NULL));
	this->piVal = new int[this->iSize];
	
	for(register int i = 0; i < this->iSize; ++i)
	{
		this->piVal[i] = rand() % this->iMaxVall;
	}

	std::cout << "\nCalling the constructor of the class 0x" << this << std::endl; 
}

//Конструктор копирования
Egg1::Egg1(const Egg1 &CpyObj) : piVal(NULL), InternalEgg(CpyObj.InternalEgg)
{
	if(NULL != CpyObj.piVal)
	{
		this->iMaxVall = CpyObj.iMaxVall;
		this->iSize = CpyObj.iSize;
		this->piVal = new int[this->iSize];
		if( memcpy_s(this->piVal, sizeof(int) * this->iSize, CpyObj.piVal, sizeof(int) * this->iSize) )
		{
			exit(1);
		}
		
	}
	std::cout << "\nCall the copy constructor of the class 0x" << this << std::endl;
}

//Метод вывода значений на экран
void Egg1::Show()
{
	for(register int i = 0; i < this->iSize; ++i)
	{
		std::cout << '\n' << this->piVal[i] << std::endl;
	}
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	this->InternalEgg.Show();
	std::cout << "\nCall, \"Show\" class 0x" << this << std::endl;
}

//Деструктор класса
Egg1::~Egg1()
{
	delete[] this->piVal;
	this->piVal = NULL;
	std::cout << "\nCalling the destructor of the class 0x" << this << std::endl; 
}
