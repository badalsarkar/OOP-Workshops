#ifndef SDDS_LIST_H
#define SDDS_LIST_H
namespace sdds{
    template<class T, unsigned int N>
    class List{
        T data[N];
        unsigned int element;
        T dummy;
        public:
        List():element(0), dummy(T()){};
        size_t size()const{
            return element;
        }
        const T& operator[](size_t i)const{
            return(i<element?data[i]:dummy);
        }
        void operator +=(const T& tt){
            if(element<N)
                data[element++]=tt;
        }
        
    };
}
#endif
