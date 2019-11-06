/*
Workshop 2
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: September 24, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/

#include <iostream>
#include <iomanip>
#include <utility>
#include "Text.h"
#include "TimedEvents.h"
using namespace sdds;

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc == 1)
	{
        std::cerr << "ERROR: Missing file name!\n";
        return 1;
	}
	else if (argc != 2)
	{
        std::cerr << "ERROR: Too many arguments!\n";
        return 2;
    }

	TimedEvents t;
    {
        std::cout << std::fixed << std::setprecision(3);
		t.startClock();
        Text a;
		t.stopClock();
		t.recordEvent("  0-arg Constructor");
        std::cout << "  0-arg Constructor - a.size = "
			      << std::setw(7) << a.size() << " records\n";

		t.startClock();
		Text b(argv[1]);
		t.stopClock();
		t.recordEvent("  1-arg Constructor");
		std::cout << "  1-arg Constructor - b.size = "
			      << std::setw(7) << b.size() << " records\n";

		t.startClock();
		Text c = b;
		t.stopClock();
		t.recordEvent("  Copy Constructor");
        std::cout << "  Copy Constructor  - c.size = "
			      << std::setw(7) << c.size() << " records\n";

		t.startClock();
		a = b;
		t.stopClock();
		t.recordEvent("  Copy Assignment");
        std::cout << "  Copy Assignment   - a.size = "
			      << std::setw(7) << a.size() << " records\n";

       t.startClock();
    }
    t.stopClock();
	t.recordEvent("  Destructor");

	std::cout << '\n' << t;
}
