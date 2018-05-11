#pragma once

#include "stdafx.h"

class FloatRange {
public:
	FloatRange();
	FloatRange(float minimum, float maximum);
	virtual ~FloatRange();
	float GetNext();

private:
	float m_fMinimum;
	float m_fMaximum;
};