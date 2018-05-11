#pragma once

class IGameObject
{
public:
	IGameObject();
	IGameObject(const LPDIRECT3DDEVICE9 device, const LPD3DXVECTOR3 position, const LPD3DXVECTOR3 velocity, const LPRECT bounds, const LPD3DXCOLOR color, const float lifespan);
	virtual ~IGameObject();
	virtual void Update(float gameTime) = 0;
	virtual void Draw() = 0;

	virtual void SetDevice(const LPDIRECT3DDEVICE9 device);
	virtual LPDIRECT3DDEVICE9 GetDevice();

	virtual void SetPosition(const LPD3DXVECTOR3 position);
	virtual LPD3DXVECTOR3 GetPosition();

	virtual void SetVelocity(const LPD3DXVECTOR3 velocity);
	virtual LPD3DXVECTOR3 GetVelocity();

	void SetBounds(const LPRECT bounds);
	LPRECT GetBounds();

	void SetColor(const LPD3DXCOLOR color);
	virtual LPD3DXCOLOR GetColor();

private:
	LPDIRECT3DDEVICE9 p_device;
	LPD3DXVECTOR3 p_position;
	LPD3DXVECTOR3 p_velocity;
	LPD3DXCOLOR p_color;
	LPRECT p_bounds;
};

