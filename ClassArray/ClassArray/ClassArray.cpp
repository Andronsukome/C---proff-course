// ClassArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array.h"
#include <crtdbg.h>
#include <time.h>
#include <stdlib.h>

void TstShow(Array &Arr, Array &Arr1, Array &Arr2);
void TstInit(int *Arr, int Size);

int _tmain(int argc, _TCHAR* argv[])
{
	{
		srand(time(0));
		int TstSize = rand() % 10000;
		int *TstArr = new int [ TstSize ];
		TstInit(TstArr, TstSize);
		//
		std::cout << "test init:\n";
		Array Arr, Arr1(TstArr, TstSize), Arr2(100, 11);
		TstShow(Arr, Arr1, Arr2);
		//
		std::cout << "\ntest push_back:\n";
		for(int i = 0; i < TstSize; ++i)
		{
			if(rand() % 2)
				Arr.PushBack(rand() % 10);
			if(rand() % 2)
				Arr1.PushBack(rand() % 10);
			if(rand() % 2)
				Arr2.PushBack(rand() % 10);
		}
		TstShow(Arr, Arr1, Arr2);
		//
		std::cout << "\ntest push_Array_Back:\n";
		for(int i = 0; i < rand() % 25 + 10; ++i)
		{
			if(rand() % 2)
				Arr.PushArrayBack(TstArr, TstSize);
			if(rand() % 2)
				Arr1.PushArrayBack(TstArr, TstSize);
			if(rand() % 2)
				Arr2.PushArrayBack(TstArr, TstSize);
		}
		TstShow(Arr, Arr1, Arr2);
		//
		std::cout << "\ntest remove at idx:\n";
		for(int i = 0; i < rand() % 25 + 10; ++i)
		{
			if(rand() % 2)
				Arr.RemoveElementAtIndex(rand() % Arr.GetLastIdx());
			if(rand() % 2)
				Arr1.RemoveElementAtIndex(rand() % Arr1.GetLastIdx());
			if(rand() % 2)
				Arr2.RemoveElementAtIndex(rand() % Arr2.GetLastIdx());
		}
		TstShow(Arr, Arr1, Arr2);
		//
		std::cout << "\ntest insert at idx:\n";
		for(int i = 0; i < rand() % 25 + 10; ++i)
		{
			if(rand() % 2)
				Arr.InsertElementAtIndex(rand() % Arr.GetLastIdx(), rand() % 10);
			if(rand() % 2)
				Arr1.InsertElementAtIndex(rand() % Arr1.GetLastIdx(), rand() % 10);
			if(rand() % 2)
				Arr2.InsertElementAtIndex(rand() % Arr2.GetLastIdx(), rand() % 10);
		}
		TstShow(Arr, Arr1, Arr2);
		//
		std::cout << "\ntest search key:\n";
		int TestIdx = -1;
		for(int i = 0; i < rand() % 25 + 10; ++i)
		{
			if(rand() % 2)
			{
				TestIdx = Arr.SearchKey(rand() % 20);
				if(TestIdx >= 0)
					std::cout << "\nfound you key at index " << TestIdx << "\n";
				else
					std::cout << "\nkey not found\n";
			}
			if(rand() % 2)
			{
				TestIdx = Arr1.SearchKey(rand() % 20);
				if(TestIdx >= 0)
					std::cout << "\nfound you key at index " << TestIdx << "\n";
				else
					std::cout << "\nkey not found\n";
			}
			if(rand() % 2)
			{
				TestIdx = Arr2.SearchKey(rand() % 20);
				if(TestIdx >= 0)
					std::cout << "\nfound you key at index " << TestIdx << "\n";
				else
					std::cout << "\nkey not found\n";
			}
		}

		delete [] TstArr;
	}

	if(_CrtDumpMemoryLeaks() == true)
		std::cerr << "\n\nError memory!!! - (_CrtDumpMemoryLeaks() == true)\n\n";
	else
		std::cerr << "\n\nMemory remove correctly!!!\n\n";

	return 0;
}

void TstShow(Array &Arr, Array &Arr1, Array &Arr2)
{
	Arr.Show("Arr");
	std::cout << "CurrIdx = " << Arr.GetCurrIdx() 
		<< "; FirstIdx = " << Arr.GetFirstIdx() 
		<< "; LastIdx = " << Arr.GetLastIdx() 
		<< "; Size = " <<Arr.GetSize() 
		<< "; Step = " << Arr.GetStep() << "\n\n";
	Arr1.Show("Arr1");
	std::cout << "CurrIdx = " << Arr1.GetCurrIdx() 
		<< "; FirstIdx = " << Arr1.GetFirstIdx() 
		<< "; LastIdx = " << Arr1.GetLastIdx() 
		<< "; Size = " <<Arr1.GetSize() 
		<< "; Step = " << Arr1.GetStep() << "\n\n";
	Arr2.Show("Arr2");
	std::cout << "CurrIdx = " << Arr2.GetCurrIdx() 
		<< "; FirstIdx = " << Arr2.GetFirstIdx() 
		<< "; LastIdx = " << Arr2.GetLastIdx() 
		<< "; Size = " <<Arr2.GetSize() 
		<< "; Step = " << Arr2.GetStep() << "\n\n";
	std::cout << "-------------------------------------------------\n";
}

void TstInit(int *Arr, int Size)
{
	for(int i = 0; i < Size; ++i)
		Arr[ i ] = rand() % 10;
}