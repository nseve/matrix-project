#include "Line.hpp"

Line::Line(int line_length, int speed, bool ep, int delay, int rnd, int probability) : length(line_length), speed(speed), delay(delay), probability(probability)
{
	random_width = rnd;
	r = rand() % 2;
	color = GenColor(ep);
	currentHeight = 0;
	destroy = false;
}

int Line::GenColor(bool ep)
{
	int color = ep ? 1 + rand() % 15 : 2;
	return color;
}
bool Line::GetExplode() {
	if (explode) 
	{
		explode = false;
		return true;
	}
	return false;
}
void Line::Move(int elapsed)
{
	if (elapsed > delay)
	{
		Win.SetColor(color);
		if (currentHeight <= Win.GetHeight())
		{
			if ((currentHeight + r) % 2 == 0)
			{
				Win.SetPos(random_width, currentHeight);
				sym.Print();
			}
			else
			{
				Win.SetPos(random_width + 1, currentHeight);
				sym.Print();
				Win.SetPos(random_width - 1, currentHeight);
				sym.Print();
			}
			if (currentHeight >= length)
			{
				if ((currentHeight + r + length) % 2 == 0)
				{
					Win.SetPos(random_width, currentHeight - length);
					sym.Space();
				}
				else
				{
					Win.SetPos(random_width + 1, currentHeight - length);
					sym.Space();
					Win.SetPos(random_width - 1, currentHeight - length);
					sym.Space();
				}
			}
			currentHeight++;
			if (rand() % 1000 <= probability)
			{
				explode = true;
				currentHeight--;
				if ((currentHeight + r ) % 2 == 0)
				{
					Win.SetPos(random_width, currentHeight);
					sym.Space();
				}
				else
				{
					Win.SetPos(random_width + 1, currentHeight);
					sym.Space();
					Win.SetPos(random_width - 1, currentHeight);
					sym.Space();
				}
				length--;
				if (!length)
					destroy = true;
			}
		}
		else
		{
			End();
		}
		delay += 1000 / speed;
	}
}

void Line::End()
{
	if (currentHeight <= Win.GetHeight() + length)
	{
		if ((currentHeight + r + length) % 2 == 0)
		{
			Win.SetPos(random_width, currentHeight - length);
			sym.Space();
		}
		else
		{
			Win.SetPos(random_width + 1, currentHeight - length);
			sym.Space();
			Win.SetPos(random_width - 1, currentHeight - length);
			sym.Space();
		}
	}
	else
	{
		destroy = true;
	}
	currentHeight++;
}

int Line::GetCurrHeight()
{
	return currentHeight - 1;
}

int Line::GetCurrWidth()
{
	return random_width;
}

bool Line::GetDestroy() { return destroy; }
