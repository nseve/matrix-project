#ifndef WINDOWS_H

#define WINDOWS_H

#include <windows.h>
#include <ctime>

class Windows
{
private:
	int height, width;
	COORD coord;
	HANDLE hConsole;
	CONSOLE_SCREEN_BUFFER_INFO buffer;

public:
	Windows();
	void Clear();
	void SetPos(int x, int y);
	void SetColor(int num);
	int GetHeight();
	int GetWidth();
};

#endif