#include "IntegerRange.h"

IntegerRange::IntegerRange() {
	this->m_nMinimum = 0;
	this->m_nMaximum = 100;
}

IntegerRange::IntegerRange(INT minimum, INT maximum) {
	this->m_nMinimum = minimum;
	this->m_nMaximum = maximum;
}

IntegerRange::~IntegerRange() {
}

INT IntegerRange::GetNext() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<INT> unique(this->m_nMinimum, this->m_nMaximum);
	return static_cast<INT>(unique(gen));
}