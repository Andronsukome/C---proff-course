//�������� ������ Line
// ��������:
//1. ���������� ����� �����
//2. ������� ������� ����� �����, ������� ������� �����������.
//3. � ������� SetParallel �������� ����� �������� ����� �� �������������� � �������� ����� ������ ���� ��� �� �����������
//   (��� ����������� �������� &&, ��� ������������ ��� ������ ������� this *)

class Line
{
	struct Dot
	{
		double x;
		double y;
	};
	Dot A;//��������� �����
	Dot B;//�������� �����
public:
	Line(double AX, double AY, double BX, double BY);
	Line();
	~Line();

	void SetLine(double AX, double AY, double BX, double BY);
	bool CheckParallel(const Line Second);//���������� true ���� ����� �����������
	void SetParallel(const Line Second);//������ ������ ���������� ������� ������������ ������� ��������� � ����������
	void Show(char * Name);
};