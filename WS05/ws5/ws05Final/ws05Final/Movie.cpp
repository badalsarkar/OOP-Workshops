// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:October 18, 2018
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include<string>
#include<algorithm>
#include "Movie.h"


namespace sdds{
    //default constructor
    Movie::Movie():m_releaseYear(0){};

    //custom constructor
    //receives the movie information as string
    //parses the string and store the valid value 
    //into data members
    Movie::Movie(const std::string& strMovie){
        //if strMovie is not empty and data format is valid
        if(!strMovie.empty()){
            //extract data from the string and store into an array
            //the valid format of the data allows 5 ','
            //which means there can be maximum 6 element
            //MAX_ELEMENT_BOOK refers to that
            //this loop goes for 6 times and extract each string portion
            //into the array
            //make copy or parameter
            std::string tempStrMovie = strMovie;
            //define array
            std::string tempString[MAX_ELEMENT_MOVIE];

            //extract data into array
            for(int i=0; i<(MAX_ELEMENT_MOVIE-1);i++){
                tempString[i]=trim(sdds::extract(tempStrMovie,','));
            }
			tempString[MAX_ELEMENT_MOVIE - 1] = trim(tempStrMovie);
            //the releaseYear, array index 1, is a int and  
            //should be greater than 0, validate this value
            //if valid store array item into member variable
            //otherwise enforce safe empty state

            try{
                //if there is no exception and data is valid
                if(std::stoi(tempString[1])>=0){
                    //store into member variable
                    m_title=tempString[0];
                    m_releaseYear=std::stoi(tempString[1]);
                    m_description=tempString[2];
                }
                else{
                    //ensure safe empty state
                    m_releaseYear=0;
                }
            }
            //on exception
            catch(std::logic_error& err){
                //enforce safe empty state
                m_releaseYear=0;
            }
        }
        else{
            //enforce safe empty state
            m_releaseYear=0;
        }
    }


    //this function returns the title of the movie
    const std::string& Movie::title()const{
        return m_title;
    }


	/*
    //this function validates the format of the 
    //string provided as parameter 
    //format is valid if
    //there are 2 ','s
    bool Movie::dataFormatIsValid(const std::string& rawData)const{
        size_t totalComma;
        totalComma=std::count(rawData.begin(),rawData.end(),',');
        return (totalComma==(MAX_ELEMENT_MOVIE-1)); 
    }
	*/



    /*
     function to remove leading and trailing space
   */
    std::string Movie::trim(std::string data)const{
        size_t start, end;
        std::string newData;
        start=data.find_first_not_of(" ");
        end=data.find_last_not_of(" ");
        newData=data.substr(start, ((end+1)-start));
        return newData;
    }




    /*
     friend helper function
     this function prints the content of the 
     movie object into the ostream object
    */
    std::ostream& operator<<(std::ostream& os, const Movie& movie){
        os<<movie.m_title<<" | "<<movie.m_releaseYear<<" | "<<movie.m_description<<std::endl;
        return os;
    }




    /*
     this free helper function receives a string reference,
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



}//end of namespace

