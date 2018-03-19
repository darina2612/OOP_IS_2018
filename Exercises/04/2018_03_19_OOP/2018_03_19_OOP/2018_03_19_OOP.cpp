#include "stdafx.h"
#include <iostream>
using namespace std;

class Foo {};

class Square
{
	int _size;
public:
	Square(int size)
	{
		_size = size;
	}

	int getSize() const { return _size; }
};

class Test
{
	int* _arr;

	void copyFrom(const Test& t)
	{
		//_arr = t._arr;

		_arr = new int[10];
		for (int i = 0; i < 10; i++)
		{
			_arr[i] = t._arr[i];
		}
	}
public:
	Test()
	{
		_arr = new int[10];
	}

	~Test()
	{
		delete[] _arr;
	}

	Test(const Test& t)
	{
		cout << "copy constructor called" << endl;
		copyFrom(t);
	}

	Test& operator=(const Test& t)
	{
		cout << "operator = called" << endl;
	
		if (this != &t)
		{
			copyFrom(t);
		}
		
		return *this;
	}

	void foo()
	{
		_arr[0] = 5;
	}
	
	void bar()
	{
		_arr[0] = 10;
	}

	int getFirstElement() const { return _arr[0]; }
};

int main()
{
	/*int* a = new int[5];
	Foo* f = new Foo();

	delete[] a;
	delete f;
*/

	/*int a = 5;
	int b = 3;
	b = a;

	int c = a;
    
	Foo f;
	Foo f2 = f;
	Foo f3;
	f3 = f;

	Square s(5);
	Square s2 = s;
	cout << s2.getSize() << endl;*/

	Test t;
	t.foo();

	cout << t.getFirstElement() << endl;

	Test t2(t);
	cout << t2.getFirstElement() << endl;

	t2.bar();
	cout << t2.getFirstElement() << endl;
	cout << t.getFirstElement() << endl;

	Test t3 = t; // copy constructor!!!
	t3 = t2;

	Test t4;
	t4 = t4;


	return 0;
}

