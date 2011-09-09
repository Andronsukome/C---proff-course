#include "stdafx.h"
#include "Line.h"


bool Line::CheckParallel(const Line Second)
{
	//������� ������ ����� ����� 1 � 0, � ������ �������� �� ������� - ������� ������� 1�
	double TempDotAX = B.x - A.x;
	double TempDotAY = B.y - A.y;
	//������� �������� ��� ������� ������� 1� ����� ������������ ��� � (����)
	double AngleFirstTriangle = TempDotAY / TempDotAX;

	//������� ������ ����� ����� 2 � 0, � ������ �������� �� ������� - ������� ������� 1�
	double TempDotBX = Second.B.x - Second.A.x;
	double TempDotBY = Second.B.y - Second.A.y;
	//������� �������� ��� ������� ������� 2� ����� ������������ ��� � (����)
	double AngleSecondTriangle = TempDotBY / TempDotBX;
	
	//��������� ���������� �������� �� ���������
	if((float)AngleFirstTriangle == (float)AngleSecondTriangle)
		return true;
	return false;
}


void Line::SetParallel(const Line First)
{
	//������� ������ ����� �������� ����� � 0, � ������ �������� �� ������� - ������� ������� 1�
	double TempDotAX = B.x - A.x;
	double TempDotAY = B.y - A.y;
	//������� �������� ��� ������� ������� �������� ����� ������������ ��� � (����)
	double AngleFirstTriangle = TempDotAY / TempDotAX;

	//������� ������ ����� ���������� ����� � 0, � ������ �������� �� ������� - ������� ������� 1�
	double TempDotBX = First.B.x - First.A.x;
	double TempDotBY = First.B.y - First.A.y;

	//�������� ����� ���������� 2� ����� ��� �������� ����� � ���������� �� �� �����
	B.x = TempDotBX + A.x;
	B.y = TempDotBY + A.y;
}


void Line::Show(char * Name = "NoName")
{
	std::cout << Name << " Line == Dot A(" << A.x << ", " << A.y << ") and Dot B(" << B.x << ", " << B.y << ")\n";
}


void Line::SetLine(double AX, double AY, double BX, double BY)
{
	A.x = AX;
	A.y = AY;
	B.x = BX;
	B.y = BY;
}


Line::Line(double AX, double AY, double BX, double BY)
{
	A.x = AX;
	A.y = AY;
	B.x = BX;
	B.y = BY;
}


Line::Line()
{
	A.x = 0;
	A.y = 0;
	B.x = 0;
	B.y = 0;
}


Line::~Line()
{
}