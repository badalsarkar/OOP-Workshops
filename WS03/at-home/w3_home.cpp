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

	// Process the first file
	// The values in this file will be interpreted as strings
	//     Sumation means string concatenation.
	{
		sdds::LVList<std::string, std::string, sdds::SummableLVPair<std::string, std::string>, 50> products;
		std::ifstream index(argv[1]);
		if (!index)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 3;
		}
		do
		{
			char label[50], value[50];
			index >> label;
			if (index)
			{
				index >> value;
				index.ignore();
				sdds::SummableLVPair<std::string, std::string> record(label, value);
				products += record;
			}
		} while (index);
		index.close();

		std::cout << "\nIndividual Index Entries\n--------------------------\n";
		for (size_t i = 0; i < products.size(); ++i)
			std::cout << products[i];
		std::cout << "\nCollated Index Entries\n--------------------------\n";
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "      Tools: " << products.accumulate("Tools") << std::endl;
		std::cout << " Grocerries: " << products.accumulate("Grocerries") << std::endl;
		std::cout << " Electrnics: " << products.accumulate("Electrnics") << std::endl;
		std::cout << "Electronics: " << products.accumulate("Electronics") << std::endl;
	}

	// Process the second file
	// The values in this file will be interpreted as numbers
	//     Sumation means mathematical addition of numbers.
	{
		const double studentFare = 2.05;
		double adultFare = 3.25;
		sdds::LVList<std::string, int, sdds::SummableLVPair<std::string, int>, 50> ticketSales;
		std::ifstream sales(argv[2]);
		if (!sales) {
			std::cerr << "ERROR: Cannot open file [" << argv[2] << "].\n";
			return 4;
		}
		do {
			char ticketType[50];
			int number;
			sales >> ticketType;
			if (sales) {
				sales >> number;
				sales.ignore();
				sdds::SummableLVPair<std::string, int> record(ticketType, number);
				ticketSales += record;
			}
		} while (sales);
		sales.close();

		std::cout << "\nDetail Ticket Sales"
			<< "\n--------------------------\n";
		for (size_t i = 0; i < ticketSales.size(); ++i)
			std::cout << ticketSales[i];
		std::cout << "\nSummary of Ticket Sales"
			<< "\n--------------------------\n";
		std::cout << std::fixed << std::setprecision(2) << std::right;
		std::cout << "Student Tickets = " << std::setw(7) << ticketSales.accumulate("Student") * studentFare << std::endl;
		std::cout << "Adult Tickets   = " << std::setw(7) << ticketSales.accumulate("Adult") * adultFare << std::endl;
	}

	// done
	return 0;
}