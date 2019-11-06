/*
Workshop 4
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: October 11, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/


#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#define _CRT_SECURE_NO_WARNINGS
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
        Reservation(Reservation&& src);
        ~Reservation();
        Reservation& operator=(const Reservation& rhs); 
        Reservation& operator=(Reservation&& rhs);
        bool operator==(const Reservation& rhs)const;
        friend std::ostream& operator<<(std::ostream& os, const Reservation& reserve);
    };

    //free helper
    std::string extract(std::string& s, char delimiter);
    
}

#endif
