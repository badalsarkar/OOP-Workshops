// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:November 05, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "Autoshop.h"

namespace sdds
{
	// operator+=
	//
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	// Call the display of the vehicle in the autoshop vector
	// -> notice the brackets around the iterator i. Without it you could not use display
	//
	void Autoshop::display(std::ostream& os) const {
		os << "--------------------------------\n";
		os << "| Cars in the autoshop!        |\n";
		os << "--------------------------------\n";
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			(*i)->display(os);
			os << std::endl;
		}
		os << "--------------------------------\n";
	}

	// Destructor
	// Before calling the clear method. You must first delalocate all memery 
	//
	Autoshop::~Autoshop()
	{
		std::vector<Vehicle*>::iterator i;
		for (i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			delete (*i);
		}
		m_vehicles.clear();
	}
}
