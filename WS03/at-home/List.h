/*
Workshop 3
Student name:Badal Sarkar
Student Id: 137226189
Email: bsarkar2@myseneca.ca
Date: October 1, 2019

I confirm that the content of this file is created by me,
with the exception of the parts provided to me by my professor.
*/

#ifndef SDDS_LIST_H
#define SDDS_LIST_H


namespace sdds{
    //template of class
    template<class T, unsigned int N>
    class List{
        T data[N];
        unsigned int element{0};
    public:
        size_t size()const{
            return element;
        }

        //overloaded [] operator for the class List
        const T& operator[](size_t i)const{
            return data[i];
        }
        
        //overloaded += operator for the class List
        //this function adds the parameter tt to the element
        void operator +=(const T& tt){
            if(element<N)
                data[element++]=tt;
        }
        
    };

    
    // derived class 
    //this class was derived from List class
    template<class L, class V, class T, unsigned int N>
    class LVList:public List<T, N>{
        public:
            //this function matches the label with the current object label
            //if matched it adds the value and returns it
            V accumulate(const L& label)const{
                SummableLVPair<L,V> T_summable;
               V result=T_summable.getInitialValue();
               for(unsigned int i=0; i<((List<T,N>&)*this).size();i++){
                   if(label==((List<T,N>&)*this)[i].key()){
                       result=((List<T, N>&)*this)[i].sum(label, result);
                   }
               }
              return result; 
            }
    };
}
#endif
