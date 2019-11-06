// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:October 18, 2018
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <fstream>
#include "SpellChecker.h"

namespace sdds{
	
	SpellChecker::SpellChecker(const char* filename) {
		//if filename is not valid 
		//throw exception
		if (filename == nullptr)
			return;

		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
        
            std::string line;
            //read line by line and 
            //store into data member
            size_t i=0;
            do{
                getline(file,line);
                line=trim(line);
                m_badWords[i]=line.substr(0,line.find(' '));
                line.erase(0,line.find(' '));
                m_goodWords[i]=trim(line);
                i++;
            }while(file && i<5);

    }
	

	
    //
    //operator overloading
    //
    void SpellChecker::operator()(std::string& text)const{
        //loop the string to find 
        size_t pos=0;
        for (size_t i=0; i<5;i++){
            do{
				pos = 0;
                pos=text.find(m_badWords[i],pos);
                if(pos!=std::string::npos){
                    //replace the word
                    text.replace(pos,m_badWords[i].length(),m_goodWords[i]);

                    //increment pos by 1
                    pos=pos+m_goodWords[i].length();
                }
            }while(pos!=std::string::npos);
        }
    }



    //trim function
    //this function removes leading and 
    //trailing space
    std::string trim(std::string data){
        size_t start, end;
        std::string newData;
        start=data.find_first_not_of(" ");
        end=data.find_last_not_of(" ");
        newData=data.substr(start, ((end+1)-start));
        return newData;
    }
}
