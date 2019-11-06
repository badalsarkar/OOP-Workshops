/*
Workshop 2
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: September 24, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/

#include <iostream>
#include <fstream>
#include "Text.h"

//default constructor
//
sdds::Text::Text(){
    text_collection=nullptr;
    number=0;
}


//one argument constructor
//
sdds::Text::Text(const char* fileName){
    std::ifstream file(fileName);
    number=0;
    text_collection=nullptr;
    if(!file)
        return;
    do{
        char c=file.get();
        if(c==' '){
            number++;
        }
    }while (!file.eof());

    file.seekg(std::ios::beg);
    text_collection= new std::string[number];
    for(int i=0; i<number; i++){
        std::getline(file,text_collection[i], ' ');
    }
}


//copy constructor
//
sdds::Text::Text(const Text& src){
    text_collection=nullptr;
    *this=src;
}


//copy assignment operator
//
sdds::Text& sdds::Text::operator=(const Text& rhs){
    if(this != &rhs){
        delete [] text_collection;
        init(rhs);
    }
    return *this;
}


//function to copy data
//
void sdds::Text::init(const Text& source){
    number=source.number;
    if(source.text_collection !=nullptr){
        text_collection = new std::string[number];
        for(int i=0; i<number;i++){
            text_collection[i]=source.text_collection[i];
        }
    }
    else{
        text_collection=nullptr;
    }
}



//move assignment operator
//
sdds::Text& sdds::Text::operator=(sdds::Text&& rhs){
    if(this!=&rhs){
        delete [] text_collection;
        text_collection= rhs.text_collection;
        number=rhs.number;
        rhs.text_collection=nullptr;
        rhs.number=0;
    }
    return *this;
}


//move constructor
//
sdds::Text::Text(sdds::Text&& src){
    text_collection=nullptr;
    *this=std::move(src);
}
    
//size function
//
size_t sdds::Text::size()const{
    return number;
}

//destructor
//
sdds::Text::~Text(){
    delete [] text_collection;
    text_collection=nullptr;
}
