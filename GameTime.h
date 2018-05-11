#pragma once

#include "stdafx.h"

class GameTime
{
public:
	GameTime();
	virtual ~GameTime();
	BOOL Create();
	void Update();
	float elapsedGameTime;
	float totalGameTime;


private:
	LONGLONG start;
	float frequencySeconds;
};

