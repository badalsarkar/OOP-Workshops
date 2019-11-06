// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:November 05, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds{
	Vehicle* createInstance(std::istream& in);
}

#endif 
