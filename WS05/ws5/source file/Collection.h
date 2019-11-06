// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:October 18, 2018
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

namespace sdds{
    template<class T>
    class Collection{
        std::string collectionName;
        T* wholeCollection;
        size_t collectionSize;
        void (*observeAddition)(const Collection<T>&, const T&);
        public:
        //constructor
        Collection(std::string name):collectionName{name}, wholeCollection{nullptr}, collectionSize{0}{};
        Collection(const Collection& )=delete;   //delete copy constructor
        Collection& operator=(const Collection& )=delete;    //delete copy assignment operator
        //destructor
        ~Collection(){
            delete [] wholeCollection;
            wholeCollection=nullptr;
        }
        //this function returns the name of the collection
        //name is stored as collectionName
        const std::string& name()const{//returns the name of the collection
            return collectionName;
        }

        //this function returns the collection size
        //this is stored at collectionSize
        size_t size()const{ //returns the value of collectionSize
            return collectionSize;
        }


        //this function stores the parameter into a function pointer
        //the function pointer is a data member named as observeAddition 
        void setObserver(void (*observer)(const Collection<T>&, const T&)){ //sets the value of observeAdd function pointer 
            observeAddition=observer;
        }




        /*
         this function addes item to the collection array
         upon addition of the item it calls the observer function
       */ 
        Collection<T>& operator+=(const T& item){   //adds item to the collection
            //check if item exists in the collection
            bool itemFound{false};
            for(size_t i=0; i<collectionSize&& !itemFound;i++){
                wholeCollection[i].title()==item.title()?(itemFound=true):(itemFound=false);
            }
            //if the item doesn't exist 
            //increase the array size
            //add the item
            //call the observer function
            if(!itemFound){
                T* tempCollection=new T[collectionSize+1];
                //copy each element to temporary array
                for (size_t i=0; i<collectionSize;i++){
                    tempCollection[i]=wholeCollection[i];
                }
                //add the new element to the temp array
                //post increment used with collectionSize
                //now collectionSize will reflect new array size
                tempCollection[collectionSize++]=item;
                //copy the address of temporary collection array to 
                //data member and then make temp array nullptr
                wholeCollection=tempCollection;
                tempCollection=nullptr;
                //call the observer function
				if (observeAddition != nullptr) {
					observeAddition(*this, item);
				}
            }
			return *this;
        }




        /*
         this function returns item at index idx
         if idx is out of range it throws out_of_range error
        */
        T& operator[](size_t idx)const{ //returns array item at idx
            if(idx>=collectionSize){
                throw std::out_of_range("Bad index "+std::to_string(idx)+". Collection has "+std::to_string(collectionSize)+" items.");
            }
            else{
                return wholeCollection[idx];
            }
        }



        //this function match the title with the title 
        //of each element of the collection array
        //if found, it returns the address of the element
        //otherwise returns nullptr
        T* operator[](std::string title)const{  //finds the title item in the array
			T* titleFoundAt{ nullptr };
            if(!title.empty()){
                //search title in the array
                for(size_t i=0; i<collectionSize && titleFoundAt==nullptr;i++){
                    wholeCollection[i].title()==title?(titleFoundAt=wholeCollection+i):titleFoundAt=nullptr;
                }
            }
            return titleFoundAt;
        }
                    
    };  //end of class 

    //free helper
    //this function puts each data element into the ostream 
	template<class T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& data){
        for(size_t i=0; i<data.size();i++){
            os<<data[i];
        }
        return os;
    }

}
#endif
