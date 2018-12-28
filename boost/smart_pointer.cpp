#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>


using namespace std;

/*
1.auto_ptr
2.scope_ptr  作用域指针
3.scope_array  作用域数组
4.shared_ptr  共享指针
5.shared_array  共享数组
6.weak_ptr  弱指针
7.intrusive_ptr  介入式指针
*/
int main(int argc, char *argv[])
{
	boost::scoped_ptr<int> i(new int);
	*i = 1;
	*i.get() = 2;

	cout << *i << endl;

	i.reset(new int);
	cout << *i << endl;

	cout << "-------------------------------" << endl;
	boost::scoped_array<int> ai(new int[2]);
	ai[0] = 1;
	ai[1] = 2;
	*ai.get() = 3;

	cout << ai[0] << endl;
	cout << ai[1] << endl;

	ai.reset(new int[3]);

	cout << ai[0] << endl;
	cout << ai[1] << endl;

	cout << "-------------------------------" << endl;
	
	
	return 0;
}
