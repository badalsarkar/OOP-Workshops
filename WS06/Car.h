// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:November 05, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds{
	class Car : public Vehicle{
		std::string car_maker = "";
		std::string car_condition = "";
		int car_topSpeed = 0u;
	public:
		Car(std::istream& is);
		void trim(std::string& str) const;
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& os) const;
	};
} //end of namespace
#endif 
