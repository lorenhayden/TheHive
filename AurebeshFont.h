#pragma once

#include "stdafx.h"
#include "IParticle.h"
#include "D3DFont.h"
#include "FloatRange.h"
#include "IntegerRange.h"
#include "ColorRange.h"

class AurebeshFont : public IParticle
{
public:
	AurebeshFont(LPDIRECT3DDEVICE9 device);
	virtual ~AurebeshFont();
	void Update(float elsapedTime);
	void Render();
	void Flip();

protected:
	BOOL IsAlive();
	void Default();
	void ReSpawn();

private:
	std::string m_text;
	std::string m_character;
	D3DFont* p_font;
	FloatRange* p_frXPos;
	FloatRange* p_frYPos;
	FloatRange* p_frVelocity;
	IntegerRange* p_irStartCharacterIndex;
	IntegerRange* p_irFontSize;
	ColorRange* p_crFontColor;
	INT m_nStartIndex;

};

