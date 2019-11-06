#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include"Reservation.h"

namespace sdds{

    /*
     default constructor
     puts the object into a safe empty state
    */
    Reservation::Reservation():reservationID{nullptr}{
        //empty 
    }


    /*
     custom constructor
     store the parameter value into the object
    */
    Reservation::Reservation(const std::string& m_res){
        //check if the string is empty and data is valid
        if(!m_res.empty() && dataFormatIsValid(m_res)){
            //copy m_res into a temporary variable and create 
            //some temporary variable to hold extracted data
            int tempGuestNo, tempDay, tempHour;
            std::string tempM_res=m_res,tempName, tempEmail, tempReservId;
            //call extract function to parse the tempM_res
            //and store value into temp variable
            tempReservId=trim(sdds::extract(tempM_res, ':'));
            tempName=trim(sdds::extract(tempM_res, ','));
            tempEmail=trim(sdds::extract(tempM_res, ','));
            tempGuestNo=std::stoi(trim(sdds::extract(tempM_res, ',')));
            tempDay=std::stoi(trim(sdds::extract(tempM_res, ',')));
            tempM_res=trim(tempM_res);
            tempHour=std::stoi(trim(sdds::extract(tempM_res,' ')));
            
            //if inputs are valid store into member variable
            //otherwise put object into safe empty state
            if(tempGuestNo>0 && tempDay>0 && tempDay<32 && tempHour>0 &&tempHour<25){
                //transfer the temporary variable value to data member
                totalGuest=(unsigned int)tempGuestNo;
                day=(unsigned int)tempDay;
                hour=(unsigned int)tempHour;
                name=tempName;
                email=tempEmail;
                reservationID=new char[tempReservId.length()+1];
                std::strncpy(reservationID, tempReservId.c_str(),tempReservId.length()+1);
            }
            else{
                reservationID=nullptr;
            }
        }
        else{
            reservationID=nullptr;
        }
    }



    //
    //Destructor
    //
    Reservation::~Reservation(){
        delete [] reservationID;
        reservationID=nullptr;
    }


    /*
    Copy constructor
    This is needed as ther is a resource data member
    It calls init() function which provides copy functionality
    */
    Reservation::Reservation(const Reservation& src){
        //todo
        init(src);

    }



    /*
    Copy assignment operator for deep copying
    calls init() function which provides copy functionality
    */
    Reservation& Reservation::operator=(const Reservation& rhs){
        //check for self assignment
        if(this != &rhs){
            //deallocate previously allocated space
            delete [] reservationID;
            init(rhs);
        }
        return *this;
    }





    /*
    Function to provide copy facility
    */
    void Reservation::init(const Reservation& src){
        //copy static member
        totalGuest=src.totalGuest;
        day=src.day;
        hour=src.hour;
        name=src.name;
        email=src.email;
        //copy resource variable
        if(src.reservationID!=nullptr){
            //find the length of reservationID
            size_t count{0};
            do{
                count++;
            }while(src.reservationID[count-1]!='/0');
            //dynamically allocate space
            reservationID=new char [count];
            //copy each element
            for(size_t i=0; i<count;i++){
                reservationID[i]=src.reservationID[i];
            }
        }
        else{
            reservationID=nullptr;
        }
    }







    /*
     function to validate rawData
     rules: ':' appears only once 
            ':' appears before any ','
            ',' appears 4times
    if all rules are satisfied data is valid
    this function validates data before storing into data members
    */

    bool Reservation::dataFormatIsValid(const std::string& rawData)const{
        size_t colonPos, commaPos, totalComma,totalColon;
        colonPos=rawData.find(':');
        commaPos=rawData.find(',');
        totalComma=std::count(rawData.begin(),rawData.end(),',');
        totalColon=std::count(rawData.begin(),rawData.end(), ':');
        return (colonPos<commaPos && totalColon==1 && totalComma==4); 
    }





    /*
     function to remove leading and trailing space
   */
    std::string Reservation::trim(std::string data){
        size_t start, end;
        std::string newData;
        start=data.find_first_not_of(" ");
        end=data.find_last_not_of(" ");
        newData=data.substr(start, ((end+1)-start));
        return newData;
    }




    /*
     overloaded << operator
     prints the reservation object into the ostream operator
    */
    std::ostream& operator<<(std::ostream& os, const Reservation& reserve){
        std::string meal;
        if(reserve.hour>5 && reserve.hour<10){
            meal="Breakfast";
        }
        else if (reserve.hour>10 && reserve.hour<16){
            meal="Lunch";
        }
        else if (reserve.hour>16 && reserve.hour<22){
            meal="Dinner";
        }
        else{
            meal="Drinks";
        }
        std::string modifiedEmail="<";
        modifiedEmail.append(reserve.email);
        modifiedEmail.append(">");
        os<<reserve.reservationID<<": "<<std::setw(10)<<std::right<<reserve.name<<" "<<std::setw(20)<<std::left<<modifiedEmail<<meal<<" on day "<<reserve.day<<" @ "<<reserve.hour<<":00 for "<<reserve.totalGuest<<" people."<<std::endl;

    return os;  
    }




    /*
     this function receives a string reference,
     extracts data from begining to the first occurance of the delimiter
     erases the extracted string from original string
     returns the extracted string
    */

    std::string extract(std::string& s, char delimiter){
        size_t delimiterPos=s.find(delimiter);
        std::string extractedString=s.substr(0,delimiterPos);
        //erase the extracted portion
        s.erase(0,delimiterPos+1);
        return extractedString;
    }
}
