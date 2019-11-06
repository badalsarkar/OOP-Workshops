
/*
Workshop 2
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: September 24, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
	const int MAX_RECORDS = 7;
	class TimedEvents {
		int nr {0};
		std::chrono::steady_clock::time_point ts;
		std::chrono::steady_clock::time_point te;
		struct {
			std::string msg;
			std::string units;
			std::chrono::steady_clock::duration duration;
		} events[MAX_RECORDS];
	public:
        TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
	};
}
#endif
