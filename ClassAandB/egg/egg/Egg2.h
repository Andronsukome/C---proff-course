#pragma once

//����� �������� char ������ ������������� �������, ������������ �����
class Egg2
{
private:
	int iMaxVall;
	int iSize;
	char *pcVal;
public:
	Egg2(int iSteMaxVall, int iSetSize);
	Egg2(const Egg2 &CpyObj);
	void Show();
	~Egg2();
};
