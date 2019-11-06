#include <iostream>
#include <iomanip>
#include <fstream>
#include<utility>
#include "Book.h"
#include "Book.h"
#include<string>

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";
	size_t cnt = 0;

	// get the books
	sdds::Book library[7];
	{
		std::ifstream file(argv[1]);

		if (!file)
		{
			std::cerr << "Error: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}
		std::string check;
		do
		{
			std::getline(file, check);
			if (file)
			{
				if (check[0] != '#')
				{
					library[cnt] = check;
					cnt++;
				}
			}

		} while (file);


		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
	}



	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto change = [=](Book& li) {


		if (li.country() == std::string("US"))
		{
			li.price() *= usdToCadRate;
		}

		if (li.country() == "UK")
		{
			if (li.year() >= size_t(1990) && li.year() <= size_t(1999))
			{
				li.price() *= gbpToCadRate;
			}
		}

	};


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.

	for (size_t i = 0; i < cnt; i++)
	{
		change(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}