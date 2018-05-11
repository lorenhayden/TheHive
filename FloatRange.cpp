#include "FloatRange.h"

FloatRange::FloatRange() {
	this->m_fMinimum = 0;
	this->m_fMaximum = 100;
}

FloatRange::FloatRange(float minimum, float maximum) {
	this->m_fMinimum = minimum;
	this->m_fMaximum = maximum;
}

FloatRange::~FloatRange() {
}

float FloatRange::GetNext() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> unique(this->m_fMinimum, this->m_fMaximum);
	return static_cast<float>(unique(gen));
}