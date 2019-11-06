

namespace sict
{
	const int MAX 3;
	class String
	{
		Private:
		char data[MAX];
		public:
		String (const char* data);
		~String();
		void display(std::ostream& out)const;
		
	}
}
