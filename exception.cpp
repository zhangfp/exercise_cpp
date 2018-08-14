#include <iostream>
#include <exception>
using namespace std;

int division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero Condition!";
	}
	return (a/b);
}

class MyException:public exception
{
public:
	MyException(const char *message):message_(message)
	{
		cout << "MyException..." << endl;
	}

	MyException(const MyException &other):message_(other.message_)
	{
		cout << "Copy MyException..." << endl;
	}

	virtual ~MyException() throw()
	{
		cout << "~MyException" << endl;
	}
	
	const char *what() throw() //可以抛出任何异常，若写成const throw(),则是不抛出异常
	{
		//return "C++ Exception";
		return message_.c_str();
	}

	const char *reason() const throw() //也行
	{
		return "C++ Exception";
	}
private:
	string message_;
};

class MyExceptionD:public MyException
{
public:
	MyExceptionD(const char *message):MyException(message)
	{
		cout << "MyExceptionD" << endl;
	}
	MyExceptionD(const MyExceptionD &other):MyException(other)
	{
		cout << "Copy MyExceptionD" << endl;
	}
	~MyExceptionD() throw()
	{
		cout << "~MyExceptionD..." << endl;
	}
};

void fun(int n) throw (int, MyException, MyExceptionD)
{
	if (n == 1)
	{
		throw 1;
	}
	else if (n == 2)
	{
		throw MyException("test MyException.");
	}
	else if (n == 3)
	{
		throw MyExceptionD("test MyExceptionD");
	}
}

int main(int argc, char *argv[])
{
	try{
		//division(1, 0);
		//throw MyException();
		fun(3);
	}
	catch(const char *e){ //must have const
		cout << e << endl;
	}
	catch(MyException &e){
		cout << e.what() << endl;
	}
	catch(...){ //can catch all exception
		cout << "nothing to do!" << endl;
	}
	return 0;
}
