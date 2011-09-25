#include <iostream>
#include <conio.h>


using namespace std;

const int SIZE_BYTE = 8;
void BitView(unsigned int Viewed);
unsigned int Var1MinusVar2(unsigned int &Var1,/*Minus*/ unsigned int &Var2);
unsigned int Var1PlusVar2(unsigned int &Var1,/*Plus*/ unsigned int &Var2);
unsigned int Var1PlusVar2_ver2(unsigned int &Var1,/*Plus*/ unsigned int &Var2);





int _tmain(int argc, _TCHAR* argv[])
{
	

	unsigned int Var1 = 159, Var2 = 59;


	BitView(Var1);
	BitView(Var2);

	cout << Var1 << endl;
	cout << Var2 << endl;
	cout << "Plus" << endl;
	cout << "================================" << endl;
	cout << Var1PlusVar2(Var1, Var2) << endl;
	cout << "================================" << endl;

	BitView(Var1);
	BitView(Var2);

	cout << Var1 << endl;
	cout << Var2 << endl;
	cout << "Minus" << endl;
	cout << "================================" << endl;
	cout << Var1MinusVar2(Var1, Var2) << endl;
	cout << "================================" << endl;

	BitView(Var1);
	BitView(Var2);

	
	_getch();
	
	return 0;
}


void BitView(unsigned int Viewed)
{
	int End = sizeof(unsigned int) * SIZE_BYTE;
	for(int i = 0; i < End; ++i)
	{
		if(Viewed & (1<<i))
			cout << '1';
		else
			cout << '0';
	}
	cout << endl;
}

unsigned int Var1MinusVar2(unsigned int &Var1,/*Minus*/ unsigned int &Var2)
{
	int End = sizeof(int) * SIZE_BYTE;
	for(int i = 0, j = 0; i < End; ++i)
	{
		if( !(Var1 & (0<<i)) && (Var2 & (1<<i)) )
		{
			for(j = i; !(Var1 & (1<<j)) && j < End;)
			{
				Var1 = Var1 | (1<<j++);
			}
			Var1 = Var1 & (~(1<<j));
		}
		else
		{
			;
		}
	}
	return Var1;
}

unsigned int Var1PlusVar2(unsigned int &Var1,/*Plus*/ unsigned int &Var2)
{
	int End = sizeof(int) * SIZE_BYTE;
	for(int i = 0, j = 0; i < End; ++i)
	{
		if( (Var1 & (1<<i)) && (Var2 & (1<<i)) )
		{
			Var1 = Var1 & (~(1<<i));
			if(i+1 < End) 
			{
				for(j = i+1; Var1 & (1<<j) && j < End;)
				{
					Var1 = Var1 & (~(1<<j++));
				}
				Var1 = Var1 | (1<<j);
			}
		}
		else if(Var2 & (1<<i))
		{
			Var1 = Var1 | (1<<i);
		}
	}
	return Var1;
}


unsigned int Var1PlusVar2_ver2(unsigned int &Var1,/*Plus*/ unsigned int &Var2)
{
	unsigned int iTempVar1, iTempVar2;
	for(int i = 0; i < 32; ++i)
	{
		iTempVar1 = Var1 ^ Var2;
		iTempVar2 = Var1 & Var2;
		iTempVar2 = iTempVar2 << 1;
		Var1 = iTempVar1;
		Var2 = iTempVar2;
	}
	
	cout << Var1;
	return Var1;
}