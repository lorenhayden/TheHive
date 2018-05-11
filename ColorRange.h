#pragma once

#include "stdafx.h"
#include "FloatRange.h"

class ColorRange
{
public:
	ColorRange(const LPD3DXCOLOR minimum, const LPD3DXCOLOR maximum);
	virtual ~ColorRange();
	LPD3DXCOLOR GetNext();

private:
	FloatRange* p_frAlpha;
	FloatRange* p_frRed;
	FloatRange* p_frGreen;
	FloatRange* p_frBlue;

	D3DXCOLOR m_color;
};

