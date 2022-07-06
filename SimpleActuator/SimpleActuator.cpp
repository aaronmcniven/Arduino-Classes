/* SimpleActuator.cpp 0.1 */
/* Aaron McNiven - 2022 */

#include "Arduino.h"
#include "SimpleActuator.h"

SimpleActuator::SimpleActuator() {
	
	m_openPin = -1;
	m_closePin = -1;
	m_lockPin = -1;
	
	m_lockDelay = 250;
	m_disable = false;
}

SimpleActuator::SimpleActuator(int openPin, int closePin) {
	
	m_lockPin = -1;
	
	m_lockDelay = 500;
	m_disable = false;
	
	setOpenPin(openPin);
	setClosePin(closePin);
	
	stop(false);
}

void SimpleActuator::setPins(int openPin, int closePin) {
	
	m_lockDelay = 500;
	m_disable = false;
	
	setOpenPin(openPin);
	setClosePin(closePin);
	stop(false);
}

void SimpleActuator::setPins(int openPin, int closePin, int lockPin) {
	
	m_lockDelay = 500;
	m_disable = false;
	
	setOpenPin(openPin);
	setClosePin(closePin);
	setLockPin(lockPin);
	stop(false);
}

void SimpleActuator::setOpenPin(int openPin) {
	
	m_openPin = openPin;
	pinMode(m_openPin, OUTPUT);
	stop(false);
}

void SimpleActuator::setClosePin(int closePin) {
	
	m_closePin = closePin;
	pinMode(m_closePin, OUTPUT);
	stop(false);
}

void SimpleActuator::setLockPin(int lockPin) {
	
	m_lockPin = lockPin;
	pinMode(m_lockPin, OUTPUT);
	stop(false);
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
	
  if(requireReboot) {
	  m_disable = true;
  }
}

void SimpleActuator::setLockDelay(int lockDelay) {
	m_lockDelay = lockDelay;
}

bool SimpleActuator::disabled() {
	return m_disable;
}