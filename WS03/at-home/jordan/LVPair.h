#ifndef _SDDS_LVPAIR_H
#define _SDDS_LVPAIR_H

#include <iostream>
#include <string>

namespace sdds {

    // LVPair - managing a label - value pair.
    // The template parameters identify the types of the label and value objects that constitute an LVPair object
    // L: the type of the label
    // V : the type of the value
    template<typename L, typename V >
        class LVPair {

            L m_label;
            V m_value;

            public:
            //Default sets the object in an empety state
            LVPair() : m_label{}, m_value{} {}

            //Copies the values received in the parameters into the instance variables.
            LVPair(const L& p_label, const V& p_value) : m_label{ p_label }, m_value{ p_value } {
            }

            //Returns the label component of the pair
            const L& label() const {
                return m_label;
            }
            //Returns the value component of the pair
            const V& value() const {
                return m_value;
            }

            //Inserts into the parameter the stored values in the following format
            //AT HOME - Modify the function display() in the class LVPair to enable polymorphism on it(make it virtual).
            //LABEL : VALUE<endl>
            virtual void display(std::ostream& os) const {
                os << m_label << " : " << m_value << std::endl;
            }
        };

    //-------------------------//
    //    Helper Operators     //
    //-------------------------//

    //Calls the function LVPair<L, V>::display() to insert the pair into the stream.
    template <typename L, typename V>
        std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
            pair.display(os);
            return os;
        }

    /////////////////////
    ////// AT HOME //////
    /////////////////////

    //Add to this module a class template named SummableLVPair to manage the summation and pretty displaying of labeled values.
    //This class is derived from LVPair<L, V>, and receives 2 template parameters :
    //L: the type of the label
    //V: the type of the value
    template <typename L, typename V>
        class SummableLVPair : public LVPair<L, V> {

            //Static Private Members for SummableLVPair
            //an object of type V that holds the initial value for starting a summation.The initial value depends on the type of the value 
            //in the label - value pair and will be defined separately.
            static V ms_initialValue;

            //a variable of type size_t that holds the minimum field width for pretty columnar output of label - value pairs(initialize it with 0).
            //This is the minimum number of characters needed to display any of the labels in a set of labels.
            //This value must be updated every time a new pair is added to the collection.
            static size_t ms_minFieldWidth;

            public:

            //Public Members for SummableLVPair
            //default constructor
            SummableLVPair() {};

            //Parameters constructor - Stores the pair in the current instance, and updates the field width if necessary.
            //This functions assumes that the type L supports a function named size() that returns the number of characters required to 
            //display lbl -- use it to check if the field width need updated or not.
            SummableLVPair(const L& p_label, const V& p_value) : LVPair<L, V>(p_label, p_value) {
                if (ms_minFieldWidth < p_label.size())
                    ms_minFieldWidth = p_label.size();
            }

            //Get the initial value from the type T and store it into a local variable of type V : this is the accumulator. 
            //In this design, the type T must have a static member called getInitialValue().
            static const V& getInitialValue() {
                return ms_initialValue;
            }

            //If the label of the pair stored in the current instance is lbl, then add the value of the pair and val together and return the result.
            //Use + for addition. Otherwise, return val.
            V sum(const L& p_label, const V& p_value) const {
                if (LVPair<L, V>::label() == p_label) {
                    return LVPair<L, V>::value() + p_value;
                }
                return p_value;
            }

            //Set the alignment to left and the field width and then call display() from the parent class. 
            //At the end, restore the alignment to right.
            void display(std::ostream& os) const {
                os << std::left << std::setw(ms_minFieldWidth);
                LVPair<L, V>::display(os);
                os << std::right;
            }

        };

    //-------------------------//
    //    Specializations      //
    //-------------------------//

    //A template that receives 2 parameters and set default field width to 0
    template<typename L, typename V>
        size_t SummableLVPair<L, V>::ms_minFieldWidth{ 0u };

    //for SummableLVPair<std::string, std::string>, the initial value for summation should be set to empty string("").
    template<>
        std::string SummableLVPair<std::string, std::string>::ms_initialValue = "";

    //for SummableLVPair<std::string, int>, the initial value for summation should be set to 0.
    template<>
        int SummableLVPair<std::string, int>::ms_initialValue = 0;

    //for SummableLVPair<std::string, std::string>, the function sum() should concatenate the values stored using, as separator(use operator + to concatenate strings)
    template<>
        std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const
        {
            return (value + " " + LVPair<std::string, std::string>::value());
        }





}
#endif //!_SDDS_LVPAIR_H>
