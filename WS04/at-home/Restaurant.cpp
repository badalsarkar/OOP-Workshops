/*
Workshop 4
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: October 11, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Restaurant.h"

namespace sdds{
    /*
    custom constructor
    receives an array of pointer to Reservation
    copies array element to data member which is an array of Reservation
    */
    Restaurant::Restaurant(Reservation* reservations[], size_t cnt){
        if(cnt>0){
            allReservation=new Reservation[cnt];
            //copy each array element 
            for(size_t i=0;i<cnt;i++){
                allReservation[i]=*(reservations[i]);
            }
            count=cnt;
        }
    }


    //
    //this function returns the number of reservations in the system
    //
    size_t Restaurant::size()const{
        return count;
    }


    //
    //copy constructor
    //
    Restaurant::Restaurant(const Restaurant& src){
        init(src);
    }


    //copy assignment operator
    //
    Restaurant& Restaurant::operator=(const Restaurant& rhs){
        if(this!=&rhs){
            delete [] allReservation;
            init(rhs);
        }
        return *this;
    }




    //
    //this function provides the copy functionality
    //
    void Restaurant::init(const Restaurant& src){
        count=src.count;
        allReservation=new Reservation [src.count];
        for(size_t i=0;i<count;i++){
            allReservation[i]=src.allReservation[i];
        }
    }


    /*
     move constructor
    */
    Restaurant::Restaurant(Restaurant&& src){
        *this=std::move(src);
    }


    /*
     move assignment operator
    */
    Restaurant& Restaurant::operator=(Restaurant&& rhs){
        if(this!=&rhs){
            allReservation=rhs.allReservation;
            count=rhs.count;
            rhs.allReservation=nullptr;
        }
        return *this;
    }



    //
    //destructor
    //
    Restaurant::~Restaurant(){
        delete [] allReservation;
        allReservation=nullptr;
    }


    //
    //this function checks whether the object is empty or not
    //
    bool Restaurant::isempty()const{
        return (allReservation==nullptr);
    }


    //
    //friend helper to print the restaurant object into screen
    //
    std::ostream& operator<<(std::ostream& os, const Restaurant& res){
        if(!res.isempty()){
			os << "--------------------------" << std::endl
				<< "Fancy Restaurant" << std::endl
				<< "--------------------------" << std::endl;
            for(size_t i=0; i<res.count; i++){
                os<<res.allReservation[i];
            }
			os<<"--------------------------" << std::endl;
        }
        else{
			os << "--------------------------" << std::endl
				<< "Fancy Restaurant" << std::endl
				<< "--------------------------" << std::endl;
			os << "The object is empty!" << std::endl
				<< "--------------------------" << std::endl;
        }
        return os;
    }



}//end of namespace
