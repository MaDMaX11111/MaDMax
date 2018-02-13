#pragma once
#include <math.h>
#include <conio.h>
#include <iostream>
#include <string>
const char* CONTINUE = "\nДЛЯ ПРОДОЛЖЕНИЯ НАЖМИТЕ ЛЮБУЮ КЛАВИШУ...  ESC - ВЫХОД";
using namespace std;
template <class Tk>
class MyMass
{
protected:
	Tk *a;
	int size;
	string name;
public:
	MyMass() {};
	MyMass(string name)
	{
		this->name = name;
	}
	MyMass(int& size, string name)
	{
		if (size == 1)
		{
			delete a;
			a = new Tk(0);
		}
		else
		{
			delete[] a;
			a = new Tk[size];
		}
		this->size = size;
		this->name = name;
		ini(a, size);
	}
	MyMass(const MyMass<Tk>& init)
	{
		this->size = init.size;
		if (this->size == 1)
		{
			this->a = new Tk(*init.a);
		}
		else
		{
			this->a = new Tk[size];
			for (int i = 0; i < this->size; i++)
				this->a[i] = init.a[i];
		}
	}
	~MyMass()
	{
		if (size == 1)
			delete a;
		else
			delete[] a;
	}
	void Input(Tk& k)
	{
		while (!(cin >> k))
		{
			cout << "\n Ошибка ввода, введите ещё раз: ";
			cin.clear();
			while (cin.get() != '\n') continue;
		}
	}
	void ini(Tk* a, int size)
	{
		if (size == 1)
		{
			cout << "\nВведите элемент " << name << " = ";
			Input(*a);
		}
		else
			if ((size > 1) && (size <= 10))
			{
				for (int i = 0; i < size; i++)
				{
					cout << "\nВведите элемент масива " << name << "[" << i << "] = ";
					Input(a[i]);
				}
			}
			else
			{
				if ((size > 10) && (size <= 1000))
				{
					for (int i = 0; i < size; i++)
						a[i] = rand() % 10 + 1;
				}
			}
	}
	MyMass operator = (MyMass<Tk> right)
	{
		size = right.size;
		if (size == 1)
		{
			a = new Tk(right.a[0]);
		}
		else
		{
			a = new Tk[size];
			for (int i = 0; i <size; i++)
				a[i] = right.a[i];
		}
		return *this;
	}
	MyMass operator = (Tk right)
	{
		size = 1;
		delete[] a;
		a = new Tk(right);
		return *this;
	}
	MyMass operator - (MyMass<Tk> right)
	{
		MyMass x(*this);
		if (right.size == 1)
			for (int i = 0; i<size; i++)
				x.a[i] -= *right.a;
		else
			if (size == 1)
				*x.a -= right.a[0];
			else
				if (x > right)
					for (int i = 0; i < right.size; i++)
						x.a[i] -= right.a[i];
				else
					if (x < right)
						for (int i = 0; i<x.size; i++)
							x.a[i] -= right.a[i];
					else
						for (int i = 0; i<x.size; i++)
							x.a[i] -= right.a[i];
		return x;
	}
	MyMass operator - (Tk koef)
	{
		MyMass x(*this);
		for (int i = 0; i<x.size; i++)
			x.a[i] -= koef;
		return x;
	}
	MyMass operator / (MyMass<Tk>& right)
	{
		MyMass x(*this);
		if (right.size == 1)
			for (int i = 0; i < size; i++)
				if (*right.a == 0) throw "Деление на ноль!";
				else
					x.a[i] /= *right.a;
		else
			if (size == 1)
				if (right.a[0] == 0) throw "Деление на ноль!";
				else
					*x.a /= right.a[0];
			else
				if (x > right)
					for (int i = 0; i<right.size; i++)
						if (right.a[i] == 0) throw "Деление на ноль!";
						else
							x.a[i] /= right.a[i];
				else
					if (x < right)
						for (int i = 0; i<x.size; i++)
							if (right.a[i] == 0) throw "Деление на ноль!";
							else
								x.a[i] /= right.a[i];
					else
						for (int i = 0; i<x.size; i++)
							if (right.a[i] == 0) throw "Деление на ноль!";
							else
								x.a[i] /= right.a[i];
		return x;
	}
	friend bool operator < (MyMass<Tk>& left, MyMass<Tk>& right)
	{
		if (left.size < right.size)
			return true;
		else
			return false;
	}
	friend bool operator > (MyMass<Tk>& left, MyMass<Tk>& right)
	{
		if (left.size > right.size)
			return true;
		else
			return false;
	}
	friend bool operator == (MyMass<Tk>& left, MyMass<Tk>& right)
	{
		if ((left.size) == (right.size))
			return true;
		else
			return false;
	}
	friend ostream& operator << (ostream &s, const MyMass<Tk> &v)
	{
		if (v.size == 1)
		{
			s << "\nЭлемент " << v.name << ": " << *v.a << endl;
		}
		else
		{
			s << "\nМасив " << v.name << ": ";
			for (int i = 0; i < v.size; i++)
			{
				s << " " << v.a[i];
			}
			s << endl;
		}
		return s;
	}
};