/*
Workshop 4
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: October 11, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds{
    class Restaurant{
        Reservation* allReservation=nullptr;
        size_t count{0};
        void init(const Restaurant& src);
        bool isempty()const;
        public:
        Restaurant(Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& src);
        Restaurant(Restaurant&& src);
        Restaurant& operator=(const Restaurant& rhs);
        Restaurant& operator=(Restaurant&& rhs);
        ~Restaurant();
        size_t size()const;
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
    };
}

#endif
