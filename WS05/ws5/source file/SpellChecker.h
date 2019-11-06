// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:October 18, 2018
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

namespace sdds{
    class SpellChecker{
        std::string m_badWords[5];
        std::string m_goodWords[5];

        public:
        SpellChecker(const char* filename);
        void operator()(std::string& text)const;
    };
    std::string trim(std::string data);
}

#endif
