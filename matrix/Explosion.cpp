#include "Explosion.hpp"


Explosion::Explosion(int height, int width, int minRadius, int maxRadius, int dly) : currentRadius(minRadius), maxRadius(maxRadius)
{
	currentHeight = height;
	random_width = width;
	delay = dly;
	start_time = chrono::steady_clock::now();
}

void Explosion::Move(int elapsed)
{
	end_time = std::chrono::steady_clock::now();
	elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
	if(elapsed_time >= 500 || firststep)
	{
		firststep = false;
		if (currentRadius <= maxRadius && !destroy)
		{
			drawCircle(currentRadius, random_width, currentHeight, true);
			if (currentRadius >= 2)
				drawCircle(currentRadius-1, random_width, currentHeight, false);
			currentRadius++;
			start_time = chrono::steady_clock::now();
		}
		else
		{
			End();
			destroy = true;
		}
		delay += 500;
	}
}

void Explosion::End()
{
	drawCircle(currentRadius-1, random_width, currentHeight, false);
}

int Explosion::GetCurrHeight() { return currentHeight; };
int Explosion::GetCurrWidth() { return random_width; };
bool Explosion::GetExplode() { return false; }
bool Explosion::GetDestroy() { return destroy; }
int Explosion::GenColor() { return rand() % 15 + 1; }


void Explosion::drawCircle(int radius, int centerX, int centerY, bool write) {
	int x = 0;
	int y = radius;
	int d = 3 - 2 * radius;
	if (write)
	{
		while (x <= y) 
		{
			Win.SetColor(GenColor());
			sym.NewPrint(centerX + x, centerY + y);
			Win.SetColor(GenColor());
			sym.NewPrint(centerX + y, centerY + x);
			Win.SetColor(GenColor());
			sym.NewPrint(centerX - y, centerY + x);
			Win.SetColor(GenColor());
			sym.NewPrint(centerX - x, centerY + y);
			Win.SetColor(GenColor());
			sym.NewPrint(centerX - x, centerY - y);
			Win.SetColor(GenColor());
			sym.NewPrint(centerX - y, centerY - x);
			Win.SetColor(GenColor());
			sym.NewPrint(centerX + y, centerY - x);
			Win.SetColor(GenColor());
			sym.NewPrint(centerX + x, centerY - y);

			x++;
			if (d > 0) {
				y--;
				d = d + 4 * (x - y) + 10;
			}
			else {
				d = d + 4 * x + 6;
			}
		}
	}
	else
	{
		while (x <= y) {
			Win.SetPos(centerX + x, centerY + y);
			sym.Space();
			Win.SetPos(centerX + y, centerY + x);
			sym.Space();
			Win.SetPos(centerX - y, centerY + x);
			sym.Space();
			Win.SetPos(centerX - x, centerY + y);
			sym.Space();
			Win.SetPos(centerX - x, centerY - y);
			sym.Space();
			Win.SetPos(centerX - y, centerY - x);
			sym.Space();
			Win.SetPos(centerX + y, centerY - x);
			sym.Space();
			Win.SetPos(centerX + x, centerY - y);
			sym.Space();

			x++;
			if (d > 0) {
				y--;
				d = d + 4 * (x - y) + 10;
			}
			else {
				d = d + 4 * x + 6;
			}
		}
	}
}