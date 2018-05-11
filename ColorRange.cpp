#include "ColorRange.h"


ColorRange::ColorRange(const LPD3DXCOLOR minimum, const LPD3DXCOLOR maximum)
{
	// Creat the alpha float range
	this->p_frAlpha = new FloatRange(minimum->a, maximum->a);
	
	// Create the red float range
	this->p_frRed = new FloatRange(minimum->a, maximum->a);
	
	// Create the green float range
	this->p_frGreen = new FloatRange(minimum->a, maximum->a);
	
	// Create the blue float range
	this->p_frBlue = new FloatRange(minimum->a, maximum->a);
}


ColorRange::~ColorRange()
{
	// Destroy the alpha range
	if (this->p_frAlpha) {
		delete this->p_frAlpha;
		this->p_frAlpha = 0;
	}

	// Destroy the red range
	if (this->p_frRed) {
		delete this->p_frRed;
		this->p_frRed = 0;
	}

	// Destroy the green range
	if (this->p_frGreen) {
		delete this->p_frGreen;
		this->p_frGreen = 0;
	}

	// Destroy the blue range
	if (this->p_frBlue) {
		delete this->p_frBlue;
		this->p_frBlue = 0;
	}

}

LPD3DXCOLOR ColorRange::GetNext() {

	this->m_color.a = this->p_frAlpha->GetNext();
	this->m_color.r = this->p_frRed->GetNext();
	this->m_color.g = this->p_frGreen->GetNext();
	this->m_color.b = this->p_frBlue->GetNext();

	return &this->m_color;
}