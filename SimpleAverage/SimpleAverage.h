/* SimpleAverage.h */
/* Aaron McNiven - 2019 */

#ifndef SimpleAverage_h
#define SimpleAverage_h

#include "Arduino.h"

class SimpleAverage {
	private:
		float m_value;
		float m_last;
		int m_count;
    
	public:
		SimpleAverage();
		void add(float value);
		void reset();
		float result();
		float last();
		int count();
};

#endif