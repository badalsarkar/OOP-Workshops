Sk

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

namespace sdds{
class Book {
    std::string author;
    std::string titles;
    std::string c_public;
    size_t yearOfPub;
    double priceOfBook;
    std::string desc;
public:
    Book();
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    Book(const std::string& strBook);
    friend std::ostream& operator<<(std::ostream& os, const Book& bk);
};
}

#endif /* Book_hpp */
