// Workshop 3 - Templates
// 2019/01/23 - Chris Szalwinski
// 2019/09/20 - Cornel

#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include "LVPair.h"
#include "List.h"


int main(int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n";

	// Process the parameter
	// The values in this file will be interpreted as numbers
	//     Sumation means mathematical addition of numbers.
	{
		sdds::List<sdds::LVPair<std::string, int>, 50> ticketSales;
		std::ifstream sales(argv[1]);
		if (!sales) {
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 3;
		}
		do {
			char ticketType[50];
			int number;
			sales >> ticketType;
			if (sales) {
				sales >> number;
				sales.ignore();
				ticketSales += sdds::LVPair<std::string, int>(ticketType, number);
			}
		} while (sales);
		sales.close();

		std::cout << "\nDetail Ticket Sales"
			<< "\n--------------------------\n";
		for (size_t i = 0; i < ticketSales.size(); ++i)
			std::cout << ticketSales[i];
	}

	// done
	return 0;
}
