//описание класса Line
// Доделать:
//1. Определить длину линии
//2. Вернуть прежнюю длину линии, которую сделали паралельной.
//3. В функции SetParallel добавить вызов проверки линий на параллельность и изменять линию ТОЛЬКО если они не параллельны
//   (или перегрузить оператор &&, или использовать для вызова функции this *)

class Line
{
	struct Dot
	{
		double x;
		double y;
	};
	Dot A;//начальная точка
	Dot B;//конечная точка
public:
	Line(double AX, double AY, double BX, double BY);
	Line();
	~Line();

	void SetLine(double AX, double AY, double BX, double BY);
	bool CheckParallel(const Line Second);//возвращает true если линии параллельны
	void SetParallel(const Line Second);//делает обьект вызывающий функцию параллельным обьекту принятому в параметрах
	void Show(char * Name);
};