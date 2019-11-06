// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:November 05, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <sstream>
#include <iomanip>
#include "Car.h"

namespace sdds{
	// Custom Constructor
	Car::Car(std::istream& is){
        //extract the maker
		std::getline(is, car_maker, ',');
		trim(car_maker);
        //extract the condition into temporary var
		std::string tempCondition;
		std::getline(is, tempCondition, ',');
		trim(tempCondition);
        //determine the condition
		if (tempCondition == "n" || tempCondition == "") {
			car_condition = "new";
		}
		else if (tempCondition == "u") {
			car_condition = "used";
		}
		else if (tempCondition == "b") {
			car_condition = "broken";
		}
		else {
			throw "Invalid record!";
			car_condition = "";
		}

		// extract speed into temp var
		std::string tempSpeed;
		std::getline(is, tempSpeed, ',');
		std::stringstream ss(tempSpeed);

		ss >> car_topSpeed;
		if (ss.fail()) {
			throw "Invalid record!";
		}
	}
	

	// This function take out the white space from begining and end 
	//
	void Car::trim(std::string& str) const {
		size_t i = 0u;
		// start at 0 and if that index is a whitespace then move to the next index
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		// i will be at the position with the first non whitespace then substr from that pos to the end
		str = str.substr(i);
		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}




	// this function returns the value of the car_condition var
	//
	std::string Car::condition() const{
		return car_condition;
	}



	// this function returns the speed as double
	//
	double Car::topSpeed() const{
		return static_cast<double>(car_topSpeed);
	}




	// Display function
	//
	void Car::display(std::ostream& os) const{
		os << "| " << std::setw(10) << std::right << car_maker << " | " 
			<< std::setw(6) << std::left << car_condition << " | " 
			<< std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() 
			<< " |";
	}
} //end of namespace
