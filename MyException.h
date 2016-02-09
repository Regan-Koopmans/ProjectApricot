#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>

using namespace std;

/*Throw an instance of this class wherever you need to throw an exception.  Provide a descriptive string to this class' constructor to explain why the exception has been thrown...

NOTE: You must have an equivalent MyException class in your Java implementation.  All exceptions in Java MUST inherit from the "Throwable" class.*/
class MyException
{
	public:
		MyException(string s)
		{
			reason = s;
		}
		
		string getCause()
		{
			return reason;
		}
		
	private:
		string reason;
};

#endif
