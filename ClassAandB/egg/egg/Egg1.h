#pragma once
class Egg2;

//Класс содержит int массив произвольного размера, произвольных чисел
class Egg1
{
private:
	int iMaxVall;
	int iSize;
	int *piVal;
	Egg2 InternalEgg;
public:
	Egg1(int iSteMaxVall, int iSetSize);
	Egg1(const Egg1 &CpyObj);
	void Show();
	~Egg1();
};
