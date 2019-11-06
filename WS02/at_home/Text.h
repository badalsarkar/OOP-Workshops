/*
Workshop 2
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: September 24, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/

#ifndef SDD_TEXT_H
#define SDD_TEXT_H

#include <iostream>
#include <string>

namespace sdds{
    class Text{
        std::string *text_collection;
        int number;
        void init(const Text& source);
    public:
        Text();
        Text(const char* fileName);
        Text(const Text& src);
        Text(Text&& src);
        Text& operator=(const Text& rhs);
        Text& operator=(Text&& rhs);  
        size_t size()const;
        ~Text();
    };
}



#endif
