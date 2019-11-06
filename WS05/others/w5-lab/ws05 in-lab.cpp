//sk

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    // get the books
    sdds::Book library[7];
    {
        // TODO: load the collection of books from the file "argv[1]".
        //       - read one line at a time, and pass it to the Book constructor
        //       - store each book read into the array "library"
        //       - lines that start with "#" are considered comments and should be ignored
        std::ifstream file(argv[1]); // call file from arguement
        size_t count = 0; // location of array
        if(!file){ // If file has error, come here and print out
            std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
            return 1;
        }
        
        std::string strBooks;
        do
        {
            std::getline(file,strBooks);
            if(file){
                if(strBooks[0] != '#'){
                    library[count] = Book(strBooks); // Call constructor and save array
                    count++;
                }
            }
        }while(file);
        file.close();
    }

    double usdToCadRate = 1.3;
    double gbpToCadRate = 1.5;

    // TODO: create a lambda expression that fixes the price of a book accoding to the rules
    //       - the expression should receive a single parameter of type "Book&"
    //       - if the book was published in US, multiply the price with "usdToCadRate"
    //            and save the new price in the book object
    //       - if the book was published in UK between 1990 and 1999 (inclussive),
    //            multiply the price with "gbpToCadRate" and save the new price in the book object
    auto fixedBookPrice = [&](Book& obj)-> double { // lambda function for adding cadRate
        if(obj.country() == "US"){
            return obj.price() *= usdToCadRate;
        }
        else if(obj.country() == "UK" && obj.year() >= 1990 && obj.year() <= 1999){
            return obj.price() *= gbpToCadRate;
        }
        else{
            return obj.price();
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
    for(size_t i = 0; i < 7; i++){ // call lambda and check each array
        fixedBookPrice(library[i]);
    }

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content (updated prices)\n";
    std::cout << "-----------------------------------------\n";
    for (auto& book : library)
        std::cout << book;
    std::cout << "-----------------------------------------\n";

    return 0;
}
