#pragma once

#include "stdafx.h"
#include "IParticleEmitter.h"

typedef std::vector<IParticleEmitter*> ParticleList;

class IParticleSystem
{
public:
	IParticleSystem(size_t capacity, std::size_t grow);
	virtual ~IParticleSystem();
	virtual void Update(float elapsedTime);
	void Render();

protected:
	void AddParticle(IParticleEmitter* particle);

private:
	ParticleList m_particles;
	std::size_t m_growsize;
};

