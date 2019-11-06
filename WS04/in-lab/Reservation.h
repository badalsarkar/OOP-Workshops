#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

namespace sdds{
    class Reservation{
        unsigned int totalGuest;
        int day;
        int hour;
        char* reservationID;
        std::string name;
        std::string email;
        bool dataFormatIsValid(const std::string& rawData)const;
        std::string trim(std::string data);
        void extractData(const std::string& rawData);
        void init(const Reservation& src);
    public:
        Reservation();
        Reservation(const std::string& m_res);
        Reservation(const Reservation& src);
        ~Reservation();
        Reservation& operator=(const Reservation& rhs); 
        friend std::ostream& operator<<(std::ostream& os, const Reservation& reserve);
    };

    //free helper
    std::string extract(std::string& s, char delimiter);
    
}

#endif
