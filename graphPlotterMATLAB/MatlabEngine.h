#pragma once

#include <engine.h>
#include <stdexcept>

class MatlabEngine
{
private:
	static Engine *engine;
public:
	MatlabEngine();
	~MatlabEngine();
public:
	static Engine *getEngine();
	static void closeEngine();
};

