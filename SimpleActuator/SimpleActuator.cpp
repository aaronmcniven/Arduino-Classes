/* SimpleActuator.cpp 0.1 */
/* Aaron McNiven - 2022 */

#include "Arduino.h"
#include "SimpleActuator.h"

SimpleActuator::SimpleActuator() {
	
	m_openPin = -1;
	m_closePin = -1;
	m_lockPin = -1;
	
	m_lockDelay = 500;
	m_disable = false;
}

SimpleActuator::SimpleActuator(int openPin, int closePin) {
	
	m_openPin = openPin;
	m_closePin = closePin;
	m_lockPin = -1;
	
	m_lockDelay = 500;
	m_disable = false;
	
	setOpenPin(openPin);
	setClosePin(closePin);
	
	stop();
}

void SimpleActuator::setPins(int openPin, int closePin) {
	
	setOpenPin(openPin);
	setClosePin(closePin);
}

void SimpleActuator::setPins(int openPin, int closePin, int lockPin) {
	
	setOpenPin(openPin);
	setClosePin(closePin);
	setLockPin(lockPin);
}

void SimpleActuator::setOpenPin(int openPin) {
	
	m_openPin = openPin;
	pinMode(m_openPin, OUTPUT);
	digitalWrite(m_openPin, LOW);
}

void SimpleActuator::setClosePin(int closePin) {
	
	m_closePin = closePin;
	pinMode(m_closePin, OUTPUT);
	digitalWrite(m_closePin, LOW);
}

void SimpleActuator::setLockPin(int lockPin) {
	
	m_lockPin = lockPin;
	pinMode(m_lockPin, OUTPUT);
	digitalWrite(m_lockPin, LOW);
}

bool SimpleActuator::beginOpen() {
	
	if(m_openPin < 0 || m_disable) {
		return false;
	}
	
	if(m_lockPin >= 0) {
		digitalWrite(m_lockPin, HIGH);
		delay(m_lockDelay);
	}
	
	digitalWrite(m_openPin, HIGH);
	digitalWrite(m_closePin, LOW);
	
	if(m_lockPin >= 0) {
		delay(m_lockDelay);
		digitalWrite(m_lockPin, LOW);
	}
}

bool SimpleActuator::beginClose() {
	
	if(m_closePin < 0 || m_disable) {
		return false;
	}
	
	digitalWrite(m_openPin, LOW);
	digitalWrite(m_closePin, HIGH);
}

void SimpleActuator::stop(bool requireReboot) {
	
	digitalWrite(m_openPin, LOW);
	digitalWrite(m_closePin, LOW);
	digitalWrite(m_lockPin, LOW);
	
	m_disable = true;
}

void SimpleActuator::setLockDelay(int lockDelay) {
	m_lockDelay = lockDelay;
}

bool SimpleActuator::disabled() {
	return m_disable;
}