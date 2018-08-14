//function template
//class template

#include <iostream>
#include <vector>
//#include <cstdlib>
//#include <string>
#include <stdexcept>

using namespace std;

template <typename T> T& max(T &a, T &b)
{
	return (a > b)?a:b;
}

template <typename T>
class Stack
{
public:
	void push(T const& elem); //入栈
	T pop(); //出栈
	T top() const; //返回栈顶元素
	bool empty() const //是否为空
	{
		return elems.empty();
	}
private:
	vector<T> elems;

};

template <typename T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);
}

template <typename T>
T Stack<T>::pop() //出栈
{
	if (elems.empty())
	{
		throw out_of_range("Stack<>::pop()::empty stack.");
	}

	T ret = elems.back();
	elems.pop_back();
	return ret;
}

template <typename T>
T Stack<T>::top() const
{
	if (elems.empty())
	{
		throw out_of_range("Stack<>::top()::empty stack.");
	}

	return elems.back();
}

int main(int argc, char *argv[])
{
	try {
		cout << "Max: " << max(2,5) << endl;

		Stack<int> intStack;
		Stack<string> stringStack;

		intStack.push(7);
		cout << intStack.pop() << endl;

		stringStack.push("hello");
		cout << stringStack.top() << endl;

		stringStack.pop();
		stringStack.pop();
	}
	catch(exception const &e){
		cerr << "Exception: " << e.what() << endl;
	}
	
	return 0;
}
