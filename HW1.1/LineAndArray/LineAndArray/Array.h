// Описание класса Array
#ifndef ARRAYh53453453456_524534534153_54345345_001
#define ARRAYh53453453456_524534534153_54345345_001

class Array
{
	typedef int Element;
	
	Element * m_pArr;
	int m_Size;
	int m_Step;//Шаг увеличения массива
	int m_CurrIdx;//Текуший индекс
	int m_FirstIdx;//Индекс первого элемента, всегда == 0
	int m_LastIdx;//Индекс всегда указывает на элемент следующий за последним заполенным в массиве
	
	bool AddMemory();//Увеличивает массив на размер заданный шагом
	bool IfSort;//Указывает отсортирован массив или нет

public:

	Array();
	Array(int iSize, int iStep);//Создает массив заданного размера и устанавливает шаг прироста памяти
	Array(Element *Arr, int iSize);//Создает массив на основе принятого массива
	~Array();

	int GetSize();
	int GetLastIdx();
	void SetLastIdx(int Idx);
	int GetFirstIdx();
	int GetCurrIdx();
	int GetStep();
	int SearchKey(int Key);//Ищет элемент в массиве и возвращает его индекс или -1 если элемента нет
	void PushBack(Element NewElement);//Добавляет 1 элемент в конец
	void PushArrayBack(const Element *NewElements, int iSize);//Добавляет новый массив в конец
	void Show(const char * Name);//Печатает массив, принимает в качестве параметра имя печатаемого массива
	void Sort();//Сортирует массив
	void RemoveElementAtIndex(int Index);//Удаляет элемент из массива по индексу
	void InsertElementAtIndex(int Index, Element NewElement);//Добавляет элемент в массив по индексу
	void SetAllToZero();//Обнуляет весь массив
};

#endif
