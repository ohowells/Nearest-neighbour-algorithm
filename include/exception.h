#ifndef _MY_EXCEPTION_
#define _MY_EXCEPTION_

#include <stdexcept>
#include <string>

class MyException
	: public std::runtime_error
{
public:
	MyException(const std::string& strError)
		: std::runtime_error(strError) { };
};	
#endif
