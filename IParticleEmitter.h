#pragma once

#include "stdafx.h"
#include "IParticle.h"

class IParticleEmitter
{
public:
	IParticleEmitter();
	virtual ~IParticleEmitter();
	virtual void Update(float elapsedTime) = 0;
	virtual void Render() = 0;
};

