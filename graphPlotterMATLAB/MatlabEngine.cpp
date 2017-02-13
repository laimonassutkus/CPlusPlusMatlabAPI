#include "MatlabEngine.h"

Engine *MatlabEngine::engine = nullptr;

MatlabEngine::MatlabEngine()
{
}


MatlabEngine::~MatlabEngine()
{
}

Engine * MatlabEngine::getEngine()
{
	if (MatlabEngine::engine != NULL || MatlabEngine::engine != nullptr)
		return MatlabEngine::engine;

	if (!(engine = engOpen(NULL)))
			throw new std::domain_error("Failed to open Matlab engine !");

	return engine;
}

void MatlabEngine::closeEngine()
{
	engClose(engine);
}
