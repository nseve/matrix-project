#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Figure.hpp"
#include "Symbol.hpp"
#include "Windows.hpp"
#include <cmath>
#include <chrono>

using namespace std;

class Explosion: public Figure
{
private:
	bool firststep = true;
	int minRadius, maxRadius, currentRadius;
	int currentHeight, random_width, delay;
	bool destroy;
	Windows Win;
	Symbol sym;
	chrono::time_point<chrono::steady_clock> start_time, end_time;
	int elapsed_time;

public:
	Explosion(int height, int width, int minRadius, int maxRadius, int dly);
	void Move(int elapsed) override;
	void End() override;
	int GetCurrHeight() override;
	int GetCurrWidth() override;
	bool GetExplode() override;
	bool GetDestroy() override;
	void drawCircle(int radius, int x, int y, bool write);
	int GenColor();

};

#endif