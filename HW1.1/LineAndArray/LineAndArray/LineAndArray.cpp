// LineAndArray.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Array.h"
#include "Dot.h"
#include "Line.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <crtdbg.h>

//инициализирует временный массив
void Init(int * Arr, int Size);
//использует функцию печати класса Array, для печати нескольких обьектов одновременно
void ShowArray(Array &Arr, Array &Arr1, Array &Arr2);
//использует функцию печати класса Line, для печати нескольких обьектов одновременно
void ShowLine(Line &First, Line &Second);
//использует все функции добавления или удаления элементов в/из обьект/а класса Array, для нескольких обьектов
void AddAndRemove(Array &Arr, Array &Arr1, Array &Arr2, int *tmpArr, int Size);
//использует функции поиска и печати класса Array, для нескольких обьектов
void Search(Array &Arr, Array &Arr1, Array &Arr2);
//использует функцию сортировки класса Array, для нескольких обьектов
void Sort(Array &Arr, Array &Arr1, Array &Arr2);
//использует функцию установки всех элементов в 0 класса Array, для нескольких обьектов
void SetZero(Array &Arr, Array &Arr1, Array &Arr2);
//использует функципроверки на параллельность с добавлением вывода результатов класса Line, для тестов
void IfParallel(Line &First, Line &Second);
//печать проверки результатов поиска в массиве
void PrintRezSearch(char * Name, int Rez);
//тестирование
void Testing(Array &Arr, Array &Arr1, Array &Arr2, Line &First, Line &Second, int *tmpArr, int Size);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	//создаем и инициализируем массив для тестов
	int Size = rand() % 100 + 10;
	int Step = rand() % 10 + 1;
	int * tmpArr = new int [ Size ];
	Init(tmpArr, Size);
	{
		//инициализируем все обьекты
		Array Arr, Arr1(Size, Step), Arr2(tmpArr, Size);
		Line First;
		Line Second(rand() % 20 - 10, 
			rand() % 20 - 10, 
			rand() % 20 - 10, 
			rand() % 20 - 10);

		//печать результатов инициализации
		std::cout << "Init Arrays & Line:\n\n";
		ShowArray(Arr, Arr1, Arr2);
		ShowLine(First, Second);
		std::cout << "\n\n";
		system("Pause");
		system("Cls");

		char Key = 27;//ESC
		do
		{
			system("Cls");
			Testing(Arr, Arr1, Arr2, First, Second, tmpArr, Size);
			std::cout << "\t Press Esc to EXIT, or  ANY key to continue...\n";
			Key = _getch();
			Arr.SetLastIdx(0);
			Arr1.SetLastIdx(0);
			Arr2.SetLastIdx(0);
		}while(Key != 27);
		std::cout << "\n\nUsing struct DOT:\n-create 2 dots (using all constructors of this struct)\n-init class line this dots\n\n";
		Dot A, B(3, 4);
		Line X(A, B);
		X.Show("X");
		std::cout << X.GetLength() << std::endl;
		system("Pause");
	}
	
	delete [] tmpArr;

	system("Cls");

	if(_CrtDumpMemoryLeaks() == true)
		std::cerr << "\n\n\tERROR MEMORY!!! - (_CrtDumpMemoryLeaks() == true)\n\n";
	else
		std::cerr << "\n\n\tMemory remove correctly!!!\n\n";

	return 0;
}

void Testing(Array &Arr, Array &Arr1, Array &Arr2, Line &First, Line &Second, int *tmpArr, int Size)
{
	//проверяем функции добавления и удаления из обьектов массива и печатаем результаты
	for(int i = 0; i < rand()% 10 + 3; ++i)
		AddAndRemove(Arr, Arr1, Arr2, tmpArr, Size);
	std::cout << "Add & remove from arrays:\n\n";
	ShowArray(Arr, Arr1, Arr2);
	std::cout << "\n";
	system("Pause");
	system("Cls");

	//проверяем функцию поиска в массиве
	std::cout << "Search in arrays:\n\n";
	Search(Arr, Arr1, Arr2);
	std::cout << "\n\n";
	system("Pause");
	system("Cls");

	//проверяем функцию сортировки
	std::cout << "Sort arrays:\n\n";
	Sort(Arr, Arr1, Arr2);
	ShowArray(Arr, Arr1, Arr2);
	std::cout << "\n";
	system("Pause");
	system("Cls");

	//обнуляем массивы
	std::cout << "Set all arrays to zero:\n\n";
	SetZero(Arr, Arr1, Arr2);
	ShowArray(Arr, Arr1, Arr2);
	std::cout << "\n";
	system("Pause");
	system("Cls");

	//проверяем функцию установки координат линии
	std::cout << "Set First Line:\n\nBefore:\n";
	ShowLine(First, Second);
	First.SetLine(rand() % 20 - 10,
		rand() % 20 - 10,
		rand() % 20 - 10,
		rand() % 20 - 10);
	Second.SetLine(rand() % 20 - 10,
		rand() % 20 - 10,
		rand() % 20 - 10,
		rand() % 20 - 10);
	std::cout << "After:\n";
	ShowLine(First, Second);

	//проверяем линии на параллельность
	std::cout << "\n\nCheck parallel First & Second lines:\n\n";
	ShowLine(First, Second);
	IfParallel(First, Second);

	//делаем линии паралельными
	std::cout << "\n\nSet First Line parallel at Second line:\n\n";
	First.SetParallel(Second);
	ShowLine(First, Second);
	IfParallel(First, Second);
	std::cout << "\n\n\n";
}

void IfParallel(Line &First, Line &Second)
{
	if(First.CheckParallel(Second))
		std::cout << "\nFirst line is parallel Second line.\n";
	else
		std::cout << "\nFirst line is NOT parallel Second line.\n";
}

void SetZero(Array &Arr, Array &Arr1, Array &Arr2)
{
	Arr.SetAllToZero();
	Arr1.SetAllToZero();
	Arr2.SetAllToZero();
}

void Sort(Array &Arr, Array &Arr1, Array &Arr2)
{
	Arr.Sort();
	Arr1.Sort();
	Arr2.Sort();
}

void PrintRezSearch(char * Name, int Rez)
{
	if(Rez >= 0)
		std::cout << "\n"  << Name << ". Index of you key is " << Rez << "\n";
	else
		std::cout << "\n" << Name << ". You key not found\n";
}

void Search(Array &Arr, Array &Arr1, Array &Arr2)
{
	int Rez, Idx;

	Arr.Show("Arr");
	Rez = Arr.SearchKey(Idx = rand()% 10 + 1);
	PrintRezSearch("1", Rez);
	Rez = Arr.SearchKey(Idx = rand()% 20 + 1);
	PrintRezSearch("2", Rez);

	Arr1.Show("Arr1");
	Rez = Arr1.SearchKey(Idx = rand()% 10 + 1);
	PrintRezSearch("1", Rez);
	Rez = Arr1.SearchKey(Idx = rand()% 20 + 1);
	PrintRezSearch("2", Rez);

	Arr2.Show("Arr2");
	Rez = Arr2.SearchKey(Idx = rand()% 10 + 1);
	PrintRezSearch("1", Rez);
	Rez = Arr2.SearchKey(Idx = rand()% 20 + 1);
	PrintRezSearch("2", Rez);
}

void AddAndRemove(Array &Arr, Array &Arr1, Array &Arr2, int *tmpArr, int Size)
{
	Arr.PushBack(rand() % 10 +1);
	Arr.PushArrayBack(tmpArr, rand() % Size + 1);
	Arr.InsertElementAtIndex(rand() % Arr.GetLastIdx(), rand() % 10 + 1);
	Arr.RemoveElementAtIndex(rand() % Arr.GetLastIdx());

	Arr1.PushBack(rand() % 10 +1);
	Arr1.PushArrayBack(tmpArr, rand() % Size + 1);
	Arr1.InsertElementAtIndex(rand() % Arr1.GetLastIdx(), rand() % 10 + 1);
	Arr1.RemoveElementAtIndex(rand() % Arr1.GetLastIdx());

	Arr2.PushBack(rand() % 10 +1);
	Arr2.PushArrayBack(tmpArr, rand() % Size + 1);
	Arr2.InsertElementAtIndex(rand() % Arr2.GetLastIdx(), rand() % 10 + 1);
	Arr2.RemoveElementAtIndex(rand() % Arr2.GetLastIdx());
}

void Init(int * Arr, int Size)
{
	for(int i = 0; i < Size; ++i)
		Arr[ i ] = rand() % 10 + 1;
}

void ShowArray(Array &Arr, Array &Arr1, Array &Arr2)
{
	Arr.Show("Arr");
	Arr1.Show("Arr1");
	Arr2.Show("Arr2");
}

void ShowLine(Line &First, Line &Second)
{
	First.Show("First");
	Second.Show("Second");
}