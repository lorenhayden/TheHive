#pragma once

#include "stdafx.h"
#include "AurebeshFont.h"
#include "IParticleEmitter.h"

class AurebeshEmitter :	public IParticleEmitter
{
public:
	AurebeshEmitter(LPDIRECT3DDEVICE9 device);
	virtual ~AurebeshEmitter();
	void Update(float elapsedTime);
	void Render();

private:
	AurebeshFont* p_font;
};

