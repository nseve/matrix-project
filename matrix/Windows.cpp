#include "Windows.hpp"

Windows::Windows()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 1;
	cursor.bVisible = false;
	SetConsoleCursorInfo(hConsole, &cursor);
}

void Windows::Clear()
{
	system("cls");
}

void Windows::SetPos(int x, int y)
{
	if (x >= 0 && y >= 0 && x <= GetWidth() && y <= GetHeight())
	{
		coord.X = x;
		coord.Y = y;
	//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, coord);
	}
}

void Windows::SetColor(int num)
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, num);
}

int Windows::GetHeight()
{
	GetConsoleScreenBufferInfo(hConsole, &buffer);
	height = buffer.srWindow.Bottom - buffer.srWindow.Top;
	return height;
}

int Windows::GetWidth()
{
	GetConsoleScreenBufferInfo(hConsole, &buffer);
	width = buffer.srWindow.Right - buffer.srWindow.Left;
	return width;
}