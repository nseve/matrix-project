#include "Symbol.hpp"

using namespace std;

void Symbol::Print()
{
	printf("%c", rand() % 94 + 33);
}

void Symbol::Space()
{
	printf(" ");
}

void Symbol::NewPrint(int x, int y)
{
	if (x >= 0 && y >= 0 && x <= Win.GetWidth() && y <= Win.GetHeight())
	{
		Win.SetPos(x, y);
		Print();
	}
}