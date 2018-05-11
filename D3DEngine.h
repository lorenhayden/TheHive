#pragma once

#include "stdafx.h"
#include "GameTime.h"
#include "AurebeshSystem.h"

class D3DEngine
{
public:
	D3DEngine(HWND hWnd, D3DCOLOR background);
	virtual ~D3DEngine();
	virtual void Update();
	BOOL Render();
	BOOL Reset();
	BOOL IsValidDevice();

protected:
	BOOL Create();
	void Release();

private:	
	D3DCOLOR m_background;
	LPDIRECT3D9 p_d3d;
	LPDIRECT3DDEVICE9 p_device;
	RECT m_windowrect;
	HWND m_hWnd;
	BOOL m_bIsValidDevice;
	BOOL m_bIsTrackingTime;
	GameTime m_gameTime;
	AurebeshSystem* p_aurebesh;
};


