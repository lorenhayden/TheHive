#pragma once

#include "stdafx.h"

class IntegerRange {
public:
	IntegerRange();
	IntegerRange(INT minimum, INT maximum);
	virtual ~IntegerRange();
	INT GetNext();

private:
	INT m_nMinimum;
	INT m_nMaximum;
};


