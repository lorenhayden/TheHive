#include "stdafx.h"
#include "IGameObject.h"

IGameObject::IGameObject() {
	this->p_device = 0;
	this->p_position = 0;
	this->p_velocity = 0;
	this->p_bounds = 0;
	this->p_color = 0;
}

IGameObject::IGameObject(const LPDIRECT3DDEVICE9 device, const LPD3DXVECTOR3 position, const LPD3DXVECTOR3 velocity, const LPRECT bounds, const LPD3DXCOLOR color, const float lifespan)
{
	this->p_device = device;
	
	if (position) {
		this->p_position = new D3DXVECTOR3(position->x, position->y, position->z);
	}
	
	if (velocity) {
		this->p_velocity = new D3DXVECTOR3(velocity->x, velocity->y, velocity->z);
	}
	
	if (bounds) {
		this->p_bounds = new RECT();
		this->p_bounds->top = bounds->top;
		this->p_bounds->left = bounds->left;
		this->p_bounds->right = bounds->right;
		this->p_bounds->bottom = bounds->bottom;
	}
	
	if (color) {
		this->p_color = new D3DXCOLOR(color->r, color->g, color->b, color->a);
	}
}

IGameObject::~IGameObject()
{
	if (this->p_position) {
		delete this->p_position;
		this->p_position;
	}

	if (this->p_velocity) {
		delete this->p_velocity;
		this->p_velocity = 0;
	}

	if (this->p_bounds) {
		delete this->p_bounds;
		this->p_bounds = 0;
	}

	if (this->p_color) {
		delete this->p_color;
		this->p_color = 0;
	}
}

void IGameObject::SetDevice(const LPDIRECT3DDEVICE9 device) {
	this->p_device = device;
}

LPDIRECT3DDEVICE9 IGameObject::GetDevice() {
	return this->p_device;
}

void IGameObject::SetPosition(const LPD3DXVECTOR3 position) {
	this->p_position->x = position->x;
	this->p_position->y = position->y;
	this->p_position->z = position->z;
}

LPD3DXVECTOR3 IGameObject::GetPosition() {
	return this->p_position;
}

void IGameObject::SetVelocity(const LPD3DXVECTOR3 velocity) {
	this->p_velocity->x = velocity->x;
	this->p_velocity->y = velocity->y;
	this->p_velocity->z = velocity->z;
}

LPD3DXVECTOR3 IGameObject::GetVelocity() {
	return this->p_velocity;
}

void IGameObject::SetBounds(const LPRECT bounds) {

	if (bounds && this->p_bounds) {
		this->p_bounds->top = bounds->top;
		this->p_bounds->left = bounds->left;
		this->p_bounds->right = bounds->right;
		this->p_bounds->bottom = bounds->bottom;
	}
}

LPRECT IGameObject::GetBounds() {
	return this->p_bounds;
}

void IGameObject::SetColor(const LPD3DXCOLOR color) {
	this->p_color->a = color->a;
	this->p_color->r = color->r;
	this->p_color->g = color->g;
	this->p_color->b = color->b;
}

LPD3DXCOLOR IGameObject::GetColor() {
	return this->p_color;
}
