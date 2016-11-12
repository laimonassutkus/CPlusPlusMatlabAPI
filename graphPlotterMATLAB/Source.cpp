#include <engine.h>
#include <iostream>

using namespace std;

int main()
{
	Engine *ep;

	mxArray *T = nullptr;
	double time[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	if (!(ep = engOpen(NULL)))
	{
		cout << "Failed to open MATLAB engine." << endl;
	}

	T = mxCreateDoubleMatrix(1, 10, mxREAL);
	memcpy((char *)mxGetPr(T), (char *)time, sizeof(double) * 10);

	engPutVariable(ep, "T", T);
	engEvalString(ep, "D = 0.5  .* (-9.8) .* T .^2;");

	engEvalString(ep, "plot(T,D);");
	engEvalString(ep, "title('Position vs. Time for a falling object');");
	engEvalString(ep, "xlabel('Time (seconds)');");
	engEvalString(ep, "ylabel('Position (meters)');");
	engEvalString(ep, "input('Press return to exit');");

	engClose(ep);
}