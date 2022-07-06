/* SimpleActuator.h 0.1 */
/* Aaron McNiven - 2022 */

#ifndef SimpleActuator_h
#define SimpleActuator_h

#include "Arduino.h"

class SimpleActuator {
	private:
		int m_openPin;
		int m_closePin;
		int m_lockPin;
		int m_lockDelay;
		bool m_disable;
    
	public:
		SimpleActuator();
		SimpleActuator(int openPin, int closePin);
		void setPins(int openPin, int closePin);
		void setPins(int openPin, int closePin, int lockPin);
		void setOpenPin(int openPin);
		void setClosePin(int closePin);
		void setLockPin(int lockPin);
		bool beginOpen();
		bool beginClose();
		void stop(bool requireReboot = false);
		void setLockDelay(int lockDelay);
		bool disabled();
};

#endif