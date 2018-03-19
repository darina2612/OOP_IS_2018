#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Toy
{
	const char* _name;
	bool _isBroken;
public:
	Toy(const char* name) : _name(name), _isBroken(false) {};
	void setName(const char* name) { _name = name; }
	const char* getName() { return _name; }
	void destroy() { _isBroken = true; }
	bool isBroken() { return _isBroken; }
};

class Child
{
	Toy* _toy;
public:
	void addToy(Toy* toy) { _toy = toy; }
	Toy* getToy() const { return _toy; }

	void carelessPlay() { _toy->destroy(); }

	bool hasToy() { return _toy && !_toy->isBroken(); }
};

int main()
{
	Child ivan4o;

	Toy spiderman("spiderman");
	ivan4o.addToy(&spiderman);

	cout << ivan4o.hasToy() << endl;

	Child petkan4o = ivan4o;
	petkan4o.carelessPlay();

	cout << ivan4o.hasToy() << endl;

	return 0;
}
