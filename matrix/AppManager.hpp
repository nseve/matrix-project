#ifndef APP_MANAGER_H

#define APP_MANAGER_H

#include "Line.hpp"
#include "Explosion.hpp"
#include <vector>
#include <algorithm>
#include <chrono>

class AppManager
{
private:
	int height, width;

public:
	AppManager();

	void GO(int argc, char** argv);
};

#endif