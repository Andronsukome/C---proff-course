#pragma once
class Egg2;

//����� �������� int ������ ������������� �������, ������������ �����
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
