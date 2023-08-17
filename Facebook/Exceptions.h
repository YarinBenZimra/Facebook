#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class Exceptions : public std::exception
{
public:

	Exceptions(const std::string& s)  // C'tor
	{
		m_str = s;
	}

	char const* what() const  // overloading the what method from std::exception class
	{
		std::cout << std::endl;
		return m_str.c_str();
	}

private:

	std::string m_str;
};
#endif // !EXCEPTIONS_H
