#pragma once

#include "stdafx.h"
#include "FloatRange.h"

class PositionRange
{
public:
	PositionRange(const LPD3DXVECTOR3 minimum, const LPD3DXVECTOR3 maximum);
	virtual ~PositionRange();
	LPD3DXVECTOR3 GetNext();

private:
	FloatRange* p_frXRange;
	FloatRange* p_frYRange;
	FloatRange* p_frZRange;

	D3DXVECTOR3 m_value;
};

