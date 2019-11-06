// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:October 18, 2018
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

namespace sdds{
    const int MAX_ELEMENT_MOVIE=3;
    class Movie{
        std::string m_title;
        int m_releaseYear;
        std::string m_description;
        //bool dataFormatIsValid(const std::string& rawData)const;
        std::string trim(std::string data)const;
        public:
        Movie();
        Movie(const std::string& strMovie);
        const std::string& title()const;
		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(this->m_title);
			spellChecker(this->m_description);
		}
        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    };

    //free helper
    std::string extract(std::string& s, char delimiter);
}
#endif

