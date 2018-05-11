#pragma once

#include "stdafx.h"

class IParticle
{
public:
	IParticle();
	virtual ~IParticle();
	virtual void Update(float elapsedTime) = 0;
	virtual void Render() = 0;

	void SetPosition(const LPD3DXVECTOR3 position);
	LPD3DXVECTOR3 GetPosition();

	void SetVelocity(const LPD3DXVECTOR3 velocity);
	LPD3DXVECTOR3 GetVelocity();

	void SetAcceleration(const LPD3DXVECTOR3 accelerations);
	LPD3DXVECTOR3 GetAcceleration();

	void SetBounds(const LPRECT rect);
	LPRECT GetBounds();

	void SetColor(const LPD3DXCOLOR color);
	LPD3DXCOLOR GetColor();

	void SetLifeSpan(const float lifespan);
	float* GetLifeSpan();

protected:
	virtual BOOL IsAlive() = 0;
	virtual void Default() = 0;
	virtual void ReSpawn() = 0;

private:
	D3DXVECTOR3 m_position;
	D3DXVECTOR3 m_velocity;
	D3DXVECTOR3 m_accelerations;
	RECT m_bounds;
	D3DXCOLOR m_color;
	float m_lifespan;
};

