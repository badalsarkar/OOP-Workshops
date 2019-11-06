// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:November 05, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds{
	class Racecar : public Car{
	private:
		double m_booster = 0.0;
	public:
		Racecar(std::istream& is);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif
