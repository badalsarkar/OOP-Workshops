/*
Workshop 4
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: October 11, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/

#ifndef SDDS_CONFIRMATION_H
#define SDDS_CONFIRMATION_H

#include "Reservation.h"

namespace sdds{
    class ConfirmationSender{
        const Reservation** confirmation{nullptr};
        size_t count{0};
        int reservationFound(const Reservation& res)const;
        bool isempty();
    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& src);
        ConfirmationSender(ConfirmationSender&& src);
        ConfirmationSender& operator=(const ConfirmationSender& rhs);
        ConfirmationSender& operator=(ConfirmationSender&& rhs);
        void init(const ConfirmationSender& src);
        ~ConfirmationSender();
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator<<(std::ostream& os, ConfirmationSender& conf);
            
    };
}

#endif
