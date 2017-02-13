#include <engine.h>
#include <iostream>

#include "MatlabUtility.h"

using namespace std;

int main()
{
	MatlabUtility ut;
	ut.initFigure(1, "Test");
	ut.drawDot(1, 100, 100, "ro");
}