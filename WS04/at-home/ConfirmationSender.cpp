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
#include "ConfirmationSender.h"


namespace sdds{

    //default constructor
    //
    ConfirmationSender::ConfirmationSender(){
        //empty
    }
    //
    //copy constructor
    //
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& src){
        init(src);
    }


    //
    //move constructor
    //
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& src){
        *this=std::move(src);
    }

    


    //
    //copy assignment operator
    //
    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& rhs){
        if (this != &rhs){
            delete [] confirmation;
            init(rhs);
        }
        return *this;
    }



    //
    //move assignment operator
    //
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& rhs){
        if(this!=&rhs){
			count = rhs.count;
            confirmation=rhs.confirmation;
			rhs.count = 0;
            rhs.confirmation=nullptr;
        }
        return *this;
    }



    //
    //this function provides the copy functionality
    //
    void ConfirmationSender::init(const ConfirmationSender& src){
        count=src.count;
        //allocate new memory
        confirmation=new const Reservation*[src.count];
        for(size_t i=0; i<count; i++){
            confirmation[i]=src.confirmation[i];
        }
    }


    //destructor
    //
    ConfirmationSender::~ConfirmationSender(){
        delete [] confirmation;
        confirmation=nullptr;
    }


    //this function searches the parameter in the confirmation array
    //the search criteria is reservationID 
    int ConfirmationSender::reservationFound(const Reservation& res)const{
        //if the confirmation is not empty 
        //check if reservation already exist in the confirmation
        //for each element in confirmation match the reservationID
        //with the reservationID of the res
        //return value -1 means not found
        int index{-1};
        if(count>0){
            for(size_t i=0; i<count && (index==-1); i++){
                *(confirmation[i])==res?(index=i):(index=-1);
            }
        }
        return index;
    }






    //this function overloads += operator
    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
        if(reservationFound(res)==-1){
            //allocate new memory to a temporary variable by prefix 
            //incrementing count. Therefore, count is already updated
            //copay each element from confirmation to temporary var
            //add the new element to the temp var
            //deallocate memory from confirmation(which is old memory)
            //assign temporary var to confirmation 
            const Reservation** tempConfirmation=new const Reservation*[++count];
            for(size_t i=0; i<(count-1); i++){
                tempConfirmation[i]=confirmation[i];
            }
            tempConfirmation[count-1]=&res;
            delete [] confirmation;
            confirmation=tempConfirmation;
            tempConfirmation=nullptr;
        }
        return *this;
    }


    //
    //overloaded operator -=
    //This function removes one element from the confirmation array
    //then resizes the array
    //
    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
        //if reservation is found in the collection
        //make the element a nullptr
        //allocate new memory space to a temporary var
        //copy each element from old array to new array, except element with nullptr
        //deallocate old array
        //assign new array to old array
        //assign nullptr to the tempvar
        int index=reservationFound(res);
        if(index!=-1){
            confirmation[index]=nullptr;
            count--;
            const Reservation** tempConfirmation=new const Reservation*[count];
			size_t j = 0;
            for (size_t i=0; i<count+1;i++){
                if(confirmation[i]!=nullptr){
                    tempConfirmation[j]=confirmation[i];
					j++;
                }
            }
            delete [] confirmation;
            confirmation=tempConfirmation;
            tempConfirmation=nullptr;
        }
        return *this;
    }



    //
    //this function checks if the object is empty
    //empty when there is no reservation, count==0
    bool ConfirmationSender::isempty(){
        return(count==0);
    }




    //friend function
    //this function prints the ConfirmationSender object 
    //to the given stream
    //
    std::ostream& operator<<(std::ostream& os, ConfirmationSender& conf){
        if(!conf.isempty()){
            //print reservation
			os << "--------------------------" << std::endl
				<< "Confirmations to Send" << std::endl
				<< "--------------------------" << std::endl;
            for(size_t i=0; i<conf.count;i++){
                os<<*(conf.confirmation[i]);
            }
			os << "--------------------------" << std::endl;
        }
        else{
			os << "--------------------------" << std::endl
				<< "Confirmations to Send" << std::endl
				<< "--------------------------" << std::endl;
            os<<"The object is empty!"<<std::endl;
			os<<"--------------------------" << std::endl;
        }
        return os;
    }


}// end of namespace
