// �������� ������ Array
#ifndef ARRAYh53453453456_524534534153_54345345_001
#define ARRAYh53453453456_524534534153_54345345_001

class Array
{
	typedef int Element;
	
	Element * m_pArr;
	int m_Size;
	int m_Step;//��� ���������� �������
	int m_CurrIdx;//������� ������
	int m_FirstIdx;//������ ������� ��������, ������ == 0
	int m_LastIdx;//������ ������ ��������� �� ������� ��������� �� ��������� ���������� � �������
	
	bool AddMemory();//����������� ������ �� ������ �������� �����
	bool IfSort;//��������� ������������ ������ ��� ���

public:

	Array();
	Array(int iSize, int iStep);//������� ������ ��������� ������� � ������������� ��� �������� ������
	Array(Element *Arr, int iSize);//������� ������ �� ������ ��������� �������
	~Array();

	int GetSize();
	int GetLastIdx();
	void SetLastIdx(int Idx);
	int GetFirstIdx();
	int GetCurrIdx();
	int GetStep();
	int SearchKey(int Key);//���� ������� � ������� � ���������� ��� ������ ��� -1 ���� �������� ���
	void PushBack(Element NewElement);//��������� 1 ������� � �����
	void PushArrayBack(const Element *NewElements, int iSize);//��������� ����� ������ � �����
	void Show(const char * Name);//�������� ������, ��������� � �������� ��������� ��� ����������� �������
	void Sort();//��������� ������
	void RemoveElementAtIndex(int Index);//������� ������� �� ������� �� �������
	void InsertElementAtIndex(int Index, Element NewElement);//��������� ������� � ������ �� �������
	void SetAllToZero();//�������� ���� ������
};

#endif
