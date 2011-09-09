//�������� ������ Line
// ��������:
//2. ������� ������� ����� �����, ������� ������� �����������.
#include "Dot.h"

#ifndef LINEh14534321584645_8678913618649646_8641_001
#define LINEh14534321584645_8678913618649646_8641_001

class Line
{
	Dot A;//��������� �����
	Dot B;//�������� �����
	double LengthLine;

	double GetLingthLine();
	void ResizeLine();
public:
	Line(double AX, double AY, double BX, double BY);
	Line(Dot X, Dot Y);
	Line();

	double GetLength();
	void SetLine(double AX, double AY, double BX, double BY);
	bool CheckParallel(const Line Second);//���������� true ���� ����� �����������
	void SetParallel(const Line Second);//������ ������ ���������� ������� ������������ ������� ��������� � ����������
	void Show(char * Name);
};

#endif
