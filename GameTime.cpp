#include "GameTime.h"

GameTime::GameTime()
{
}


GameTime::~GameTime()
{
}

BOOL GameTime::Create() {
	LARGE_INTEGER i;

	// Get query performance frequency
	if (!QueryPerformanceFrequency(&i)) {
		return FALSE;
	}
	
	// Set the frequency
	this->frequencySeconds = (float)(i.QuadPart);

	//Get the current query performance counter
	QueryPerformanceCounter(&i);
	this->start = i.QuadPart;
	this->totalGameTime = 0;
	this->elapsedGameTime = 0;

	return TRUE;
}

void GameTime::Update() {
	LARGE_INTEGER i;
	
	// Get the elapsed time
	QueryPerformanceCounter(&i);
	this->elapsedGameTime = (float)(i.QuadPart - start) / this->frequencySeconds;

	// Increment the total game time
	this->start = i.QuadPart;
	this->totalGameTime += elapsedGameTime;
}
