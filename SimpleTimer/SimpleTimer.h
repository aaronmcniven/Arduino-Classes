/* SimpleTimer.h 0.2 */
/* Aaron McNiven - 2022 */

#ifndef SimpleTimer_h
#define SimpleTimer_h

#include "Arduino.h"

class SimpleTimer {
	private:
		unsigned long m_duration;
		unsigned long m_value;
		bool m_expired;
		bool m_stopped;
		bool m_flasher;
    
	public:
		SimpleTimer();
		SimpleTimer(unsigned long duration);
		SimpleTimer(unsigned long duration, bool startNow);
		void setDuration(unsigned long duration, bool startNow = false);
		void updateTimer();
		void restartTimer();
		void startTimer();
		void stopTimer();
		bool expired(bool restartNow);
		bool getFlasher();
};

#endif
