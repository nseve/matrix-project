#ifndef SYMBOL_H

#define SYMBOL_H

#include <iostream>
#include "Windows.hpp"

class Symbol
{
private:
	char sym;
	Windows Win;

public:
	void Print();
	void Space();
	void NewPrint(int x, int y);
};

#endif 