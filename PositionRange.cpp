#include "PositionRange.h"


PositionRange::PositionRange(const LPD3DXVECTOR3 minimum, const LPD3DXVECTOR3 maximum)
{
	// Create the xposition float range
	this->p_frXRange = new FloatRange(minimum->x, maximum->y);

	// Create the y position float range
	this->p_frYRange = new FloatRange(minimum->y, maximum->y);

	// Create the z position float range
	this->p_frZRange = new FloatRange(minimum->z, maximum->z);
}


PositionRange::~PositionRange()
{

	// Destroy the xposition float range
	if (this->p_frXRange) {
		delete this->p_frXRange;
		this->p_frXRange = 0;
	}

	// Destroy the y position float range
	if (this->p_frYRange) {
		delete this->p_frYRange;
		this->p_frYRange = 0;
	}

	// Destroy the z position float range
	if (this->p_frZRange) {
		delete this->p_frZRange;
		this->p_frZRange = 0;
	}
}

LPD3DXVECTOR3 PositionRange::GetNext() {

	this->m_value.x = this->p_frXRange->GetNext();
	this->m_value.y = this->p_frYRange->GetNext();
	this->m_value.z = this->p_frZRange->GetNext();

	return &this->m_value;
}
