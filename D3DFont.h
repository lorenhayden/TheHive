#pragma once

#include "stdafx.h"
#include "IGameObject.h"

typedef class D3DFont D3DFONT;
typedef class D3DFont* LPD3DFONT;

class D3DFont : IGameObject
{
public:
	D3DFont();
	D3DFont(const LPDIRECT3DDEVICE9 device, const INT size, const BOOL bold, const BOOL italics, LPCWSTR family, const LPD3DXVECTOR3 position, const LPD3DXCOLOR color, std::string text);
	virtual ~D3DFont();
	void Update(float gameTime);
	void SetSize(const INT size);
	void SetBold(const BOOL bold);
	void SetItalics(const BOOL italics);
	void SetFamily(LPCWSTR family);
	void SetText(std::string text);
	void Draw();

	void SetDevice(const LPDIRECT3DDEVICE9 device);
	LPDIRECT3DDEVICE9 GetDevice();

	void SetPosition(const LPD3DXVECTOR3 position);
	LPD3DXVECTOR3 GetPosition();

	void SetVelocity(const LPD3DXVECTOR3 velocity);
	LPD3DXVECTOR3 GetVelocity();

	void SetBounds(const LPRECT bounds);
	LPRECT GetBounds();

	void SetColor(const LPD3DXCOLOR color);
	LPD3DXCOLOR GetColor();

private:
	INT m_size;
	BOOL m_bold;
	BOOL m_italics;
	LPWSTR m_family;
	LPD3DXFONT p_font;
	std::string m_text;
};

