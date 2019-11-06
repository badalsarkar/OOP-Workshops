// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:November 05, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"

namespace sdds{
	// 1) Notice that the the stream 'in' is the text file
	// 2) The stream we are sending to Car is the string stream which
	//    has already had the type and delimeter extracked
	//
	Vehicle* createInstance(std::istream& in){
		std::string line;
		char type = '\0';
		char delim = '\0';
		std::getline(in, line);
		std::stringstream ss(line);
		ss >> type >> delim;

		if (ss) {
			switch (type)
			{
			case 'c':
			case 'C':
				return new Car(ss);
				break;
			case 'r':
			case 'R':
				return new Racecar(ss);
				break;
			default:
				std::string msg = "Unrecognized record type : [";
							msg += type;
							msg += "]";
				throw msg;
				return nullptr;
				break;
			}
		}
		return nullptr;
	}
}
