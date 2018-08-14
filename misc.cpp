#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int a = 78;
	int *pa, *pc;
	int *&pb = pa; //引用不分配内存，只在编译的时候取了一个别名而已。
	pb = &a;

	int aa[10];
	//int &bb = aa; //不能建立数组的引用，因为数组名是常量地址，不是变量标识符。
 	cout << *pb << endl;
	return 0;
}
