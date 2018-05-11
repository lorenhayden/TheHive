#include "IParticleSystem.h"


IParticleSystem::IParticleSystem(size_t capacity, std::size_t grow)
{
	this->m_particles.reserve(capacity);
	this->m_growsize = grow;
}

IParticleSystem::~IParticleSystem()
{
	std::size_t size = this->m_particles.size();
	for (size_t index = 0; index < size; index++) {
		IParticleEmitter* emitter = this->m_particles[index];
		if (emitter) {
			delete emitter;
			emitter = 0;
		}
	}
	this->m_particles.clear();
	this->m_particles.shrink_to_fit();
}

void IParticleSystem::Update(float elapsedTime) {
	std::size_t size = this->m_particles.size();
	for (size_t index = 0; index < size; index++) {
		IParticleEmitter* emitter = this->m_particles[index];
		if (emitter) {
			emitter->Update(elapsedTime);
		}
	}
}

void IParticleSystem::Render() {
	std::size_t size = this->m_particles.size();
	for (size_t index = 0; index < size; index++) {
		IParticleEmitter* emitter = this->m_particles[index];
		if (emitter) {
			emitter->Render();
		}
	}
}

void IParticleSystem::AddParticle(IParticleEmitter* particle) {
	
	std::size_t newsize = this->m_particles.size() + 1;
	std::size_t capacity = this->m_particles.capacity();
	
	if (newsize > capacity) {
		this->m_particles.reserve(capacity + this->m_growsize);
	}
	this->m_particles.push_back(particle);
}