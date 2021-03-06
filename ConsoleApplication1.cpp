#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "iomanip"
#include "locale.h"
#include <typeinfo.h>
#include <locale.h> //setlocale(LC_ALL, "russian");
#include "Header1.h" //хеадеродин.x
#include <complex>
#include <math.h>
using namespace std;

template <class Tk>
void Input(Tk& k)
{
	cout << "Тип масива " << typeid(k).name();
}

template <typename T>
void mass()
{        
    int sizea, sizeb;
	MyMass<T> objx("x");
	try
	{
			do
			{
				Input(objx);
				if ((sizea < 1) || (sizea > 1000))
					cout << "\nНеверный размер массива!";
			} 
			while ((sizea < 1) || (sizea > 1000));
			MyMass<T> obja(sizea, "a");
			do
			{
				Input(objx);
				if ((sizeb < 1) || (sizeb > 1000))
					cout << "\nНеверный размер массива!";
			} 
			while ((sizeb < 1) || (sizeb > 1000));
			MyMass<T> objb(sizeb, "b");
			cout << "\nМасивы созданы" << endl;
			cout << obja << endl;
			cout << objb << endl;
			if (obja > objb)
			{
				cout << "\n a > b";
				cout << "\nx = b/a-1";
				objx = objb / obja;
#ifdef _DEBUG
				cout << "\n b / a = " << objx;
#endif // _DEBUG
				objx = objx - 1;
#ifdef _DEBUG
				cout << "\n b / a -1 " << objx;
#endif // _DEBUG
			}
			else
				if (obja < objb)
				{
					cout << "\n a < b";
					cout << "\nx = (a-235)/b";
					objx = obja - 235;
#ifdef _DEBUG
					cout << "\na-235 = " << objx;
#endif // _DEBUG
					objx = objx / objb;
#ifdef _DEBUG
					cout << "\n (a - 235) / b = " << objx;
#endif // _DEBUG
				}
				else
					if (obja == objb)
					{
						cout << "\n a = b";
						cout << "\nx = -295";
						objx = -295;
					}
			cout << objx;
			cout << CONTINUE;
	}
	catch (char*e)
	{
			cout << "\nОшибка! " << e;
			cout << CONTINUE;
	}
	catch (...)
	{
			cout << "\n Что-то пошло не так";
			cout << CONTINUE;
	}
}

int TypeGeneration()
{
	srand((unsigned)time(NULL));
	switch (rand() % 4)
	{
	case 0:
	{
		mass<int>();
	}
	case 1:
	{
		mass<float>();
	}
	case 2:
	{
		mass<double>();
	}
	case 3:
	{
		mass<complex<double>>();
	}
	default:
		cout << "Что-то НЕ так работает..." << endl;
		return 0;
	}
}


int main()
{
	setlocale(LC_ALL, "russian");
	do
	{
	
			cout << "\nЛабораторная робота №4. Вариант №16";
			cout << "\n\n    Гb/a-1, если a>b;";
			cout << "\nX = |-295,        если а = b;";
			cout << "\n    L(a-235)/b, если a<b;\n";
			TypeGeneration();
	} while (_getch() != 27);
	return 0;
}