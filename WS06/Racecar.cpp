// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:November 05, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Racecar.h"

namespace sdds{
	// Custome constructor 
	//
	Racecar::Racecar(std::istream& is) : Car(is) {
		size_t i = 0;
		std::string token;
		std::getline(is, token);

		for (i = 0; i < token.size() && token[i] == ' '; i++);
		token = token.substr(i);
		for (i = token.size(); i > 0 && token[i - 1] == ' '; i--);
		token = token.substr(0, i);

		m_booster = std::stod(token);
	}

	// Display
	//
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	// topSpeed 
    //this function returns the top speed of the car plus booster effect
	//
	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}
