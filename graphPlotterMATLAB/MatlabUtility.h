#pragma once

#include "MatlabEngine.h"
#include <string>
#include <vector>

using namespace std;

class MatlabUtility
{
private:
	Engine *engine;
public:
	MatlabUtility();
	~MatlabUtility();
public:
	void initFigure(int figureNumber, string title);
	void drawFunction(int figure, string function, double min, double max, int precision, string color);
	void drawDot(int figure, double x, double y, string color);
	void drawBufferedDots(int figure, double x[], double y[], int count, string color);
	void drawGraph();
};