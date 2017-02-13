#include "MatlabUtility.h"

MatlabUtility::MatlabUtility()
{
	engine = MatlabEngine::getEngine();
}


MatlabUtility::~MatlabUtility()
{
}

void MatlabUtility::initFigure(int figureNumber, string title)
{
	string syms = "syms x f";

	string figure = ""; 
	figure.append("figure(");
	figure.append(to_string(figureNumber));
	figure.append(");");

	string graphTitle = ("title('");
	graphTitle.append(title);
	graphTitle.append("');");

	string figureOptions = "hold on; grid on; axis equal;";

	engEvalString(engine, syms.c_str());
	engEvalString(engine, figure.c_str());
	engEvalString(engine, figureOptions.c_str());
	engEvalString(engine, graphTitle.c_str());
}

// figureNumber not implemented yet
void MatlabUtility::drawFunction(int figureNumber, string function, double min, double max, int precision, string color)
{
	string syms = "syms x f";

	string functionValue = "f=";
	functionValue.append(function);
	function.append(";");

	string minValue = "xmin=";
	minValue.append(to_string(min));
	minValue.append(";");

	string maxValue = "xmax=";
	maxValue.append(to_string(max));
	maxValue.append(";");

	string precValue = "nst=";
	precValue.append(to_string(precision));
	precValue.append(";");

	string evalX = "x = xmin :(xmax-xmin)/nst : xmax;";

	string plot = "plot(x,eval(f), '";
	plot.append(color);
	plot.append("');");

	engEvalString(engine, syms.c_str());
	engEvalString(engine, functionValue.c_str());
	engEvalString(engine, minValue.c_str());
	engEvalString(engine, maxValue.c_str());
	engEvalString(engine, precValue.c_str());
	engEvalString(engine, evalX.c_str());
	engEvalString(engine, plot.c_str());
}

void MatlabUtility::drawDot(int figure, double x, double y, string color)
{
	string plot = "plot(";
	plot.append(to_string(x));
	plot.append(",");
	plot.append(to_string(y));
	plot.append(",'");
	plot.append(color);
	plot.append("');");

	engEvalString(engine, plot.c_str());
}

void MatlabUtility::drawBufferedDots(int figure, double x[], double y[], int count, string color)
{
	mxArray *X = nullptr, *Y = nullptr;

	X = mxCreateDoubleMatrix(1, count, mxREAL);
	Y = mxCreateDoubleMatrix(1, count, mxREAL);

	memcpy((void *)mxGetPr(X), (void *)x, sizeof(x) * count);
	memcpy((void *)mxGetPr(Y), (void *)y, sizeof(y) * count);

	engPutVariable(engine, "X", X);
	engPutVariable(engine, "Y", Y);

	string plot = "plot(X,Y,'";
	plot.append(color);
	plot.append("');");

	engEvalString(engine, plot.c_str());
}
