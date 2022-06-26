/* SimpleAverage.cpp */
/* Aaron McNiven - 2019 */

#include "Arduino.h"
#include "SimpleAverage.h"

SimpleAverage::SimpleAverage() {
	
	reset();
	m_last = 0;
}

void SimpleAverage::add(float value) {
	
	m_last = value;
	++m_count;
	m_value = m_value + ((value - m_value) / m_count);
}

void SimpleAverage::reset() {
	
	m_value = 0;
	m_count = 0;
}

float SimpleAverage::result() {
	
	return m_value;
}

float SimpleAverage::last() {
	
	return m_last;
}

int SimpleAverage::count() {
	
	return m_count;
}