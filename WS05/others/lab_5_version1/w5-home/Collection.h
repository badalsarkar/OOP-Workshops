//SK

#ifndef COLLECTION_H
#define COLLECTION_H

namespace sdds
{
	template<typename T>
	class Collection
	{

		std::string m_name;
		T* m_items = nullptr;
		size_t m_cnt = 0;

		void(*onItemAdded)(const Collection&, const T&)= nullptr;
		
	public:
`
		Collection(std::string name) { this->m_name = name; }
		collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection()
		{
			delete[] m_items; 
		}

		void setObserver(void (*observer)(const Collection&, const T& ))
		{
			this->onItemAdded = observer;
		}
		
		const std::string& name() const { return m_name; }
		size_t size() const { return m_cnt; }

		Collection& operator+=(const T& item)
		{
			for(auto i=0u;i<m_cnt; ++i)
				if(this->m_items[i].title()==item.title())
		   
	       return *this;
		   
        T *tmp = new T[m_cnt+1];
         for (auto i = 0u; i<m_cnt; ++i)
		 tmp[i]=this->m_items[i];
         tmp[m_cnt] = item;
          delete [] m_items;
           m_items = tmp;
	
			++ m_cnt;

		if (onItemAdded != nullptr)
			onItemAdded(*this, m_items[m_cnt - 1]);
		
		     return *this;
		}
		T& operator[](size_t idx) const
		{
			if (idx >= m_cnt)
			{
				std::string msg = "bd indx[";
				msg += std::to_string(idx);
				msg += "]. COlletciton has[";
				msg += std::to_string(m_cnt);
				msg += "] items.";
				throw std::out_of_range(msg);

			}
			return this->m_items[idx];
		}

		T* operator[](std::string title)const
		{
			for (size_t i = 0; i < m_cnt; ++i)
			{
				if (m_items[i].title() == title)
					return &(m_items);
			}
			return nullptr;
		}

		operator //I have to use operator
	};

}
#endif