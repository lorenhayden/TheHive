#include "AurebeshSystem.h"

AurebeshSystem::AurebeshSystem(LPDIRECT3DDEVICE9 device, size_t capacity, std::size_t grow) : IParticleSystem(capacity, grow)
{

	this->m_nParticleCount = capacity;
	this->p_device = device;

	for (size_t index = 0; index < capacity; index++) {
		AurebeshEmitter* particle = new AurebeshEmitter(device);
		this->AddParticle(particle);
	}

}

AurebeshSystem::~AurebeshSystem() 
{

}

void AurebeshSystem::Update(float elapsedTime) {
	static float fElapsedTime = 0;
	static size_t capacity = 5;

	if (this->m_nParticleCount < this->m_nMaxParticles) {
		fElapsedTime += elapsedTime;
		if (fElapsedTime >= 0.5f) {
			for (size_t index = 0; index < capacity; index++) {
				AurebeshEmitter* particle = new AurebeshEmitter(this->p_device);
				this->AddParticle(particle);
				this->m_nParticleCount += 1;
			}
			fElapsedTime = 0.0f;
		}
	}
	IParticleSystem::Update(elapsedTime);
}