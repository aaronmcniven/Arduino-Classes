/* SimpleTimer.cpp 0.2 */
/* Aaron McNiven - 2022 */

#include "Arduino.h"
#include "SimpleTimer.h"

SimpleTimer::SimpleTimer() {
	
	m_expired = false;
	m_stopped = true;
}

SimpleTimer::SimpleTimer(unsigned long duration) {
	
	setDuration(duration);
	m_stopped = true;
}

SimpleTimer::SimpleTimer(unsigned long duration, bool startNow) {
	
	setDuration(duration, startNow);
}

void SimpleTimer::setDuration(unsigned long duration, bool startNow) {
	
	m_duration = duration;
  
	if(startNow) {
		startTimer();
	} else {
		m_stopped = true;
	}
}

void SimpleTimer::updateTimer() {
	
	if(millis() - m_value >= m_duration) {
		m_expired = true;
	}
}

void SimpleTimer::restartTimer() {
	
	m_stopped = false;
	m_expired = false;
	m_value = millis();
}

void SimpleTimer::startTimer() {
	
	if(m_stopped) {
		restartTimer();
	}
}

void SimpleTimer::stopTimer() {
	
	m_stopped = true;
}

bool SimpleTimer::expired(bool restartNow) {

	if(m_expired && !m_stopped) {

		if(restartNow) {
			restartTimer();
		}

		m_flasher = !m_flasher;

		return true;
	}

	return false;
}

bool SimpleTimer::getFlasher() {
	
	return m_flasher;
}