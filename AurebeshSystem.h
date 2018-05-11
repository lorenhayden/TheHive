#pragma once

#include "stdafx.h"
#include "IParticleSystem.h"
#include "AurebeshEmitter.h"

class AurebeshSystem : public IParticleSystem
{
public:
	AurebeshSystem(LPDIRECT3DDEVICE9 device, size_t capacity, std::size_t grow);
	virtual ~AurebeshSystem();
	void Update(float elapsedTime);

private: 
	LPDIRECT3DDEVICE9 p_device;
	size_t m_nMaxParticles = 1000;
	size_t m_nParticleCount;
};

