#include "stdafx.h"
#include "Line.h"

void ResizeLine()
{
	//���������� �����
}


double Line::GetLength()
{
	return this->LengthLine;
}


double Line::GetLingthLine()
{
	//������� ������ ����� �������� ����� � 0, � ������ �������� �� ������� - ������� ������� 1�
	double tmpSecondDotX = this->B.x - this->A.x;
	double tmpSecondDotY = this->B.y - this->A.y;
	//��������� ����� ����������
	double Hypotenuse = std::sqrt(std::pow(tmpSecondDotX, 2) + std::pow(tmpSecondDotY, 2));
	return Hypotenuse;
}


bool Line::CheckParallel(const Line Second)
{
	//������� ������ ����� ����� 1 � 0, � ������ �������� �� ������� - ������� ������� 1�
	double TempDotFirstLineX = this->B.x - this->A.x;
	double TempDotFirstLineY = this->B.y - this->A.y;
	//������� �������� ��� ������� ������� 1� ����� ������������ ��� � (����)
	double AngleFirstTriangle = TempDotFirstLineY / TempDotFirstLineX;

	//������� ������ ����� ����� 2 � 0, � ������ �������� �� ������� - ������� ������� 1�
	double TempDotSecondLineX = Second.B.x - Second.A.x;
	double TempDotSecondLineY = Second.B.y - Second.A.y;
	//������� �������� ��� ������� ������� 2� ����� ������������ ��� � (����)
	double AngleSecondTriangle = TempDotSecondLineY / TempDotSecondLineX;
	
	//��������� ���������� �������� �� ���������1

	if((float)AngleFirstTriangle == (float)AngleSecondTriangle)
		return true;
	return false;
}


void Line::SetParallel(const Line Second)
{
	if(this->CheckParallel(Second))
		return;
	//������� ������ ����� �������� ����� � 0, � ������ �������� �� ������� - ������� ������� 1�
	double tmpSecondDotFirstLineX = this->B.x - this->A.x;
	double tmpSecondDotFirstLineY = this->B.y - this->A.y;
	//������� �������� ��� ������� ������� �������� ����� ������������ ��� � (����)
	double AngleFirstTriangle = tmpSecondDotFirstLineY / tmpSecondDotFirstLineX;

	//������� ������ ����� ���������� ����� � 0, � ������ �������� �� ������� - ������� ������� 1�
	double tmpSecondDotSecondLineX = Second.B.x - Second.A.x;
	double tmpSecondDotSecondLineY = Second.B.y - Second.A.y;

	//�������� ����� ���������� 2� ����� ��� �������� ����� � ���������� �� �� �����
	this->B.x = tmpSecondDotSecondLineX + this->A.x;
	this->B.y = tmpSecondDotSecondLineY + this->A.y;
}


void Line::Show(char * Name = "NoName")
{
	std::cout << Name << " Line == Dot A(" << this->A.x << ", " << this->A.y
		<< ") and Dot B(" << this->B.x << ", " << this->B.y << ")\n";
}


void Line::SetLine(double AX, double AY, double BX, double BY)
{
	this->A.x = AX;
	this->A.y = AY;
	this->B.x = BX;
	this->B.y = BY;
}


Line::Line(Dot X, Dot Y)
{
	this->A.x = X.x;
	this->A.y = X.y;
	this->B.x = Y.x;
	this->B.y = Y.y;
	this->LengthLine = this->GetLingthLine();
}


Line::Line(double AX, double AY, double BX, double BY)
{
	this->A.x = AX;
	this->A.y = AY;
	this->B.x = BX;
	this->B.y = BY;
	this->LengthLine = this->GetLingthLine();
}


Line::Line()
{
	this->A.x = 0;
	this->A.y = 0;
	this->B.x = 0;
	this->B.y = 0;
	this->LengthLine = 0;
}