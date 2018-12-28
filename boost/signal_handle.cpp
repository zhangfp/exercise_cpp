#include <iostream>
#include <boost/signal.hpp>

using namespace std;

void test1(int p)
{
	//if (p == 1)
	cout << "this is test1." << endl;
}

void test2(int p)
{
	//if (p == 2)
	cout << "this is test2." << endl;
}

int test3()
{
	return 3;
}
int main(int argc, char *argv[])
{
	//signals
	cout << "------------------signals-----------------" << endl;
	boost::signal<void (int)> s;
	s.connect(test1);
	s.connect(test2);

	s.disconnect(test1);
	s.disconnect(test2);
	

	s.connect(0,test2);
	s.connect(1,test1);
	s(1);
	s(2);

	cout << "num_slots: " << s.num_slots() << endl;

	s.disconnect_all_slots(); //disconnect all slots

	if (s.empty())
		cout << "s is empty." << endl;

	boost::signal<int ()> s2;
	s2.connect(test3);
	cout << s2() << endl;

	cout << "--------------------connections--------------" << endl;
	boost::signal<void (int)> sc;
	boost::signals::connection c = sc.connect(test1);
	sc(1);
	c.disconnect();
	sc(1);
	
	return 0;
}
