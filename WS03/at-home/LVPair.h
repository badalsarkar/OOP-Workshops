/*
Workshop 3
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: October 1, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

#include <string>

namespace sdds{
    template <class L, class V>
    class LVPair{
        L Lkey;
        V Lvalue;
        public:
        LVPair():Lkey(L()),Lvalue(V()){}
        LVPair(const L& aa, const V& bb):Lkey{aa}, Lvalue{bb}{
            
        }

        //function to get the value of LKey
        const L& key() const{
            return Lkey;
        }

        //function to get the value of Lvalue
        const V& value() const{
            return Lvalue;
        }


        //virtual function to display key and value 
        virtual void display(std::ostream& os)const{
            os<<Lkey<<" : "<<Lvalue<<std::endl;
        }
    };


    //free helper to over the operator << for LVPair type
    template<class L, class V>
    std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair){
        pair.display(os);
        return os;
    }
  


    //inherited from LVPair class
    //Publicly inherited from base calss

    template<class L, class V>
    class SummableLVPair:public LVPair<L, V>{
        static V initialVal;
        static size_t width;
    public:
        SummableLVPair(){}

        //this parameterized constructor calls the base class constructor
        SummableLVPair(const L& lbl, const V& val):LVPair<L,V>(lbl, val){
            if(width<lbl.size()){
                width=lbl.size();
            }
        }
        
        //this function add the val with the LValue
        //if the lbl matches the LKey
        V sum(const L& lbl, const V& val)const{
            if(LVPair<L,V>::key()==lbl){
                return LVPair<L,V>::value()+val;
            }
            return val;
        }

        //this function displays key and value 
        //it uses the base class display function
        void display(std::ostream& os)const{
            os<<std::left<<std::setw(width);
            LVPair<L,V>::display(os);
            os<<std::right;
        }

        //static function to provide access to the static member
        //this function returns the initial vlaue
        static const V& getInitialValue(){
            return initialVal;
        }
    };

    //static member definition of the summableLVPair class
    template<class L, class V>
    V SummableLVPair<L,V>::initialVal=V();
    template<class L, class V>
    size_t SummableLVPair<L,V>::width=0;
    
    //specialization for summableLVPair<string, int>
    template<>
    int SummableLVPair<std::string, int>::initialVal = 0;
    
    //specialization for summableLVPair<string, string>
    template<>
    std::string SummableLVPair<std::string, std::string>::initialVal = "";
    template<>
    std::string SummableLVPair<std::string, std::string>::sum(const std::string& lbl, const std::string& val) const{
            return (val + " " + LVPair<std::string, std::string>::value());
    } 
}
#endif
