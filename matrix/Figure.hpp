#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
	virtual void Move(int elapsed) = 0;
	virtual void End() = 0;
	virtual int GetCurrHeight() = 0;
	virtual int GetCurrWidth() = 0;
	virtual bool GetExplode() = 0;
	virtual bool GetDestroy() = 0;
};

#endif