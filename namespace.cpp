//namespace
//using
#include <iostream>

using namespace std;

namespace ns_1{
	void func(); //在头文件中如此声明即可调用跨文件的命名空间。
}

namespace ns_1{
	void func()
	{
		cout << "ns_1:func()" << endl;
	}
	namespace ns_1_1{ //命名空间的嵌套
		void func_1()
		{
			cout << "ns_1_1:func()" << endl;
		}
	}
}

namespace ns_2{
	void func();
}

namespace ns_2{
	void func()
	{
		cout << "ns_2:func()" << endl;
	}
}

//using namespace ns_1;
using ns_1::func;

using namespace ns_1::ns_1_1;
int main(int argc, char *argv[])
{
	func();
	return 0;
}
