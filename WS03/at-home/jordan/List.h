#define _CRT_SECURE_NO_WARNINGS

#ifndef _SDDS_LIST_H
#define _SDDS_LIST_H

namespace sdds {

    template <typename T, size_t N>
        class List {
            size_t m_length{ 0 };
            T m_arr[N]; //Using vector to declare a type T array

            public:
            size_t size() const {   //member function to return the the size of the array - length of elements
                return m_length;
            }

            //returns the element at index i(assume the parameter is valid)
            ////The first const indicate the return type is immutable, second const prohibit any changes to the source argument
            const T& operator[](size_t i) const {   
                return m_arr[i];                        
            }

            //if the list hasn't reached the capacity, add a copy of the parameter to the array.
            void operator+=(const T& tt) {
                if (m_length < N) 
                    m_arr[m_length++] = tt;
            }

        };

    /////////////////////
    ////// AT HOME //////
    /////////////////////

    //Add to this module another template class called LVList, that can manage a collection of summable elements.
    //This class is derived from List<T, N>, and receives 4 template parameters :
    //L: the type of a label
    //V: the type summation value
    //T: the type of any element in the collection
    //N: the maximum number of elements in the collection(an integer without sign)
    template <typename L, typename V, typename T, size_t N>
        class LVList : public List<T, N> {

            public:
                //In this design, summable elements are objects of a type that supports the operation V sum(const L& l, const V& v).
                //Public Members for LVList
                //V accumulate(const L& label) const: this function accumulates all the values stored in the list that have the label 'label' matches 
                //to the local object of type V.
                //iterate over the collection and call the function sum() for each item(use the overloaded operator[] to access the item at index i).
                //Store the result of sum() into the accumulator.
                //return the accumulator to the client.
                V accumulate(const L& p_label) const
                {
                    SummableLVPair<L, V> tp_Summable;
                    V v_accumList = tp_Summable.getInitialValue();

                    for (size_t i = 0; i < ((List<T, N>&)*this).size(); ++i)
                    {
                        if (p_label == ((List<T, N>&)*this)[i].label())
                            v_accumList = ((List<T, N>&)*this)[i].sum(p_label, v_accumList);
                    }
                    return v_accumList;
                }
        };
}

#endif //!_SDDS_LIST_H

