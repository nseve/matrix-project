#ifndef LINE_H

#define LINE_H

#include "Symbol.hpp"
#include "Windows.hpp"
#include <chrono>
#include <ctime>
#include "Figure.hpp"
#include <random>

class Line : public Figure
{
private:
	Symbol sym;
	bool r, destroy, explode = false;
	int length, speed, color, delay, probability;
	int currentHeight, random_width;
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	Windows Win;

public:
	
	//void SetRandom();

//	Line();
	Line(int line_length, int speed, bool ep, int delay, int rnd, int probability);

	void Move(int elapsed) override;
	void End() override;

	int GenColor(bool ep);
	int GetCurrHeight() override;
	int GetCurrWidth() override;

	bool GetExplode() override;
	bool GetDestroy() override;
};

#endif