#pragma once

#include "stdafx.h"


class D3DSprite {
public:
	D3DSprite();
	virtual ~D3DSprite();
	virtual void Update(float gameTime) = 0;
	virtual void Draw(float gameTime);

public:
	BOOL Create(HWND hWnd, LPDIRECT3DDEVICE9 device, LPCTSTR texturefile, D3DXVECTOR3 position, RECT bounds, D3DXCOLOR color);
	void SetHwnd(HWND hWnd);
	void SetDevice(LPDIRECT3DDEVICE9 device);
	void SetPosition(const D3DXVECTOR3 position);
	void SetBounds(const RECT bounds);
	void SetColor(const D3DXCOLOR color);

private:
	HWND m_hWnd;
	LPDIRECT3DDEVICE9 p_device;
	LPDIRECT3DTEXTURE9 p_texture;
	LPD3DXSPRITE p_sprite;
	D3DXVECTOR3 m_position;
	RECT m_bounds;
	D3DCOLOR m_color;
};

