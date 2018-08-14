#include <iostream>
#include <string.h>

using namespace std;

#define HELLO 
class CAnimal {
	virtual void run() = 0;
};

//纯虚函数一定没有定义，纯虚函数用来规范派生类的行为，即接口。但在此处定义纯虚函数却是可以的。
void CAnimal::run()
{
	return;
}

class Person:public CAnimal
{
private:
	char name[32];
	int age;
	float stature;
	float weight;
	char gender[16];
	static Person *p_obj; //不可初始化
public:
	//定义了任何一种构造函数，则在实例化的时候不会再有默认构造函数
	Person()
	{
		memset(this->name, 0, sizeof(name));
		this->age = 0;
		this->stature = 0;
		this->weight = 0;
		memset(gender, 0, sizeof(gender));
	}

	Person(const char *name, int age)
	{
		strncpy(this->name, name, sizeof(name) - 1);
		this->age = age;
		this->stature = 0;
		this->weight = 0;
		memset(gender, 0, sizeof(gender));
	}

	Person(const char *name, int age, float stature, float weight):age(age),stature(stature),weight(weight)
	{
		strncpy(this->name, name, sizeof(name) - 1);
		memset(gender, 0, sizeof(gender));
	}

	Person(Person &obj)
	{
		cout << "copy struct function." << endl;
	}

	void operator=(Person &obj);
	char *getName();
	void run();

public:
	~Person(){}
};

Person* Person::p_obj = NULL;
//float Person::weight = 0.0; //not a static member

char *Person::getName()
{
	return this->name;
}

void Person::operator=(Person &obj)
{
	cout << "this is assignement." << endl;
}

void Person::run()
{
	cout << "person run." << endl;
	return;
}

int __attribute__((cdecl)) add(int a, int b)
{
	return a + b;
}

int main()
{
	char aa[sizeof(int)] = {0};  //编译的时候能确定sizeof(int)的值。
	cout << "hello world." << endl;
	Person person;
	Person p("lilei", 10);
	cout << "name : " << p.getName() << endl;
	Person p1 = p;//初始化，调用拷贝构造函数
	p1 = p; //调用赋值运算符
	return 0;
}
