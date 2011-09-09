#include "stdafx.h"
#include "Line.h"


bool Line::CheckParallel(const Line Second)
{
	//смещаем первую точку Линии 1 в 0, а вторую сдвигаем на столько - сколько сметили 1ю
	double TempDotAX = B.x - A.x;
	double TempDotAY = B.y - A.y;
	//находим значения для таблицы брадиса 1й линии относительно оси Х (угол)
	double AngleFirstTriangle = TempDotAY / TempDotAX;

	//смещаем первую точку Линии 2 в 0, а вторую сдвигаем на столько - сколько сметили 1ю
	double TempDotBX = Second.B.x - Second.A.x;
	double TempDotBY = Second.B.y - Second.A.y;
	//находим значения для таблицы брадиса 2й линии относительно оси Х (угол)
	double AngleSecondTriangle = TempDotBY / TempDotBX;
	
	//проверяем полученные значения на равенство
	if((float)AngleFirstTriangle == (float)AngleSecondTriangle)
		return true;
	return false;
}


void Line::SetParallel(const Line First)
{
	//смещаем первую точку исходной линии в 0, а вторую сдвигаем на столько - сколько сметили 1ю
	double TempDotAX = B.x - A.x;
	double TempDotAY = B.y - A.y;
	//находим значения для таблицы брадиса исходной линии относительно оси Х (угол)
	double AngleFirstTriangle = TempDotAY / TempDotAX;

	//смещаем первую точку переданной линии в 0, а вторую сдвигаем на столько - сколько сметили 1ю
	double TempDotBX = First.B.x - First.A.x;
	double TempDotBY = First.B.y - First.A.y;

	//получаем новые координаты 2й точки для исходной линии и возвращаем ее на место
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