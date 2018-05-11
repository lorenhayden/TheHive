#include "IParticle.h"

IParticle::IParticle()
{
	// Set default values for position
	this->m_position.x = 0.0f;
	this->m_position.y = 0.0f;
	this->m_position.z = 0.0f;

	// Set default values for velocity
	this->m_velocity.x = 0.0f;
	this->m_velocity.y = 0.0f;
	this->m_velocity.z = 0.0f;

	// Set the default bounds;
#if _DEBUG
	this->m_bounds.top = 0;
	this->m_bounds.left = 0;
	this->m_bounds.right = GetSystemMetrics(SM_CXSCREEN);
	this->m_bounds.left = GetSystemMetrics(SM_CYSCREEN);
#else
	this->m_bounds.top = GetSystemMetrics(SM_XVIRTUALSCREEN);
	this->m_bounds.left = GetSystemMetrics(SM_YVIRTUALSCREEN);
	this->m_bounds.right = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	this->m_bounds.left = GetSystemMetrics(SM_CYVIRTUALSCREEN);
#endif

	// Set the default color white
	this->m_color.a = 1.0f;
	this->m_color.r = 1.0f;
	this->m_color.g = 1.0f;
	this->m_color.b = 1.0f;

	// Set the default lifespan
	this->m_lifespan = 0.0f;
}

IParticle::~IParticle()
{
}

void IParticle::SetPosition(const LPD3DXVECTOR3 position) {
	this->m_position.x = position->x;
	this->m_position.y = position->y;
	this->m_position.z = position->z;
}

LPD3DXVECTOR3 IParticle::GetPosition() {
	return &this->m_position;
}

void IParticle::SetVelocity(const LPD3DXVECTOR3 velocity) {
	this->m_velocity.x = velocity->x;
	this->m_velocity.y = velocity->y;
	this->m_velocity.z = velocity->z;
}

LPD3DXVECTOR3 IParticle::GetVelocity() {
	return &this->m_velocity;
}

void IParticle::SetAcceleration(const LPD3DXVECTOR3 accelerations) {
	this->m_accelerations.x = accelerations->x;
	this->m_accelerations.y = accelerations->y;
	this->m_accelerations.z = accelerations->z;
}

LPD3DXVECTOR3 IParticle::GetAcceleration() {
	return &this->m_accelerations;
}


void IParticle::SetBounds(const LPRECT rect) {
	this->m_bounds.top = rect->top;
	this->m_bounds.left = rect->left;
	this->m_bounds.right = rect->right;
	this->m_bounds.bottom = rect->bottom;
}

LPRECT IParticle::GetBounds() {
	return &this->m_bounds;
}

void IParticle::SetColor(const LPD3DXCOLOR color) {
	this->m_color.a = color->a;
	this->m_color.r = color->r;
	this->m_color.g = color->g;
	this->m_color.b = color->b;
}

LPD3DXCOLOR IParticle::GetColor() {
	return &this->m_color;
}

void IParticle::SetLifeSpan(const float lifespan) {
	this->m_lifespan = lifespan;
}

float* IParticle::GetLifeSpan() {
	return &this->m_lifespan;
}

