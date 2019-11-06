#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds{
    class Restaurant{
        Reservation* allReservation{nullptr};
        size_t count{0};
        void init(const Restaurant& src);
        bool isempty()const;
        public:
        Restaurant(Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& src);
        Restaurant& operator=(const Restaurant& rhs);
        ~Restaurant();
        size_t size()const;
        friend std::ostream& operator<<(std::ostream& os, Restaurant& restaurant);
    };
}

#endif
