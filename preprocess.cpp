#include <iostream>

using namespace std;

#define MKSTR(x) #x
#define CONCAT(x, y) x ## y
int main(int argc, char *argv[])
{
	int vxy = 100;
	cout << MKSTR(HELLO C++) << endl;
	cout << CONCAT(vx, y) << endl;
	cout << "Value of __FILE__: " << __FILE__ << endl;
	#line 100 //指定下一行的行号
	
	cout << "Value of __LINE__: " << __LINE__ << endl;
	
	cout << "Value of __LINE__: " << __LINE__ << endl;
	cout << "Value of __DATE__: " << __DATE__ << endl;
	cout << "Value of __TIME__: " << __TIME__ << endl;
	
	return 0;
}
