#ifndef BOOK_H
#define BOOK_H

#include<iostream>

namespace sdds
{
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::string m_description;
		double m_price = 0;
		size_t m_year = 0;

		//void check(std::string& str) const;
		void trim(std::string& str)const;

	public:
		Book() {};
		Book(const std::string& strBook);
		const std::string& title() const { return this->m_title; };
		const std::string& country() const { return this->m_country; }
		const size_t& year() const { return this->m_year; };
		double& price() { return m_price; };



		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};

}

#endif