#include <iostream>
#include <vector>

using namespace std;
/*
come from: https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html
1.构造函数
vector():创建一个空vector
vector(int nSize):创建一个vector,元素个数为nSize
vector(int nSize,const t& t):创建一个vector，元素个数为nSize,且值均为t
vector(const vector&):复制构造函数
vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中

2.插入函数
void push_back(const T& x):向量尾部增加一个元素X
iterator insert(iterator it,const T& x):向量中迭代器指向元素前增加一个元素x
iterator insert(iterator it,int n,const T& x):向量中迭代器指向元素前增加n个相同的元素x
iterator insert(iterator it,const_iterator first,const_iterator last):向量中迭代器指向元素前插入另一个相同类型向量的[first,last)间的数据

3.删除函数
iterator erase(iterator it):删除向量中迭代器指向元素
iterator erase(iterator first,iterator last):删除向量中[first,last)中元素
void pop_back():删除向量中最后一个元素
void clear():清空向量中所有元素

4.查询函数
reference at(int pos):返回pos位置元素的引用
reference front():返回首元素的引用
reference back():返回尾元素的引用
iterator begin():返回向量头指针，指向第一个元素
iterator end():返回向量尾指针，指向向量最后一个元素的下一个位置
reverse_iterator rbegin():反向迭代器，指向最后一个元素
reverse_iterator rend():反向迭代器，指向第一个元素之前的位置

5.判断函数
bool empty() const:判断向量是否为空，若为空，则向量中无元素

6.大小函数
int size() const:返回向量中元素的个数
int capacity() const:返回当前向量张红所能容纳的最大元素值
int max_size() const:返回最大可允许的vector元素数量值

7.其它函数
void swap(vector&):交换两个同类型向量的数据
void assign(int n,const T& x):设置向量中第n个元素的值为x
void assign(const_iterator first,const_iterator last):向量中[first,last)中元素设置成当前向量元素

*/
int main(int argc, char *argv[])
{
	cout << "This is vector test..." << endl;

	//iterator贯穿整个vector操作
	//1.构造函数
	vector<int> iv;
	vector<int> iv1(5); //size
	vector<int> iv2(2, 9); //size, value
	vector<int> iv3(iv1); //copy construct
	vector<int> iv4(iv2.begin(), iv2.end()); //iterator [begin, end)

	vector<int>::iterator it;

	//2.增加函数
	iv.push_back(1);
	iv.push_back(2);
	iv.push_back(3);

	cout << "iv.size: " << iv.size() << endl;
	cout << "iv.capacity: " << iv.capacity() << endl;
	for(it = iv.begin();it != iv.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl << "---------------------" << endl;

	it = iv.begin() + 1;
	iv.insert(it, 4);  //value
	iv.insert(it, 3, 5); //n, value
	//iv.insert(it, iv2.begin(), iv2.end()); //[first, end), error,it has no effective.
	it = iv.begin()+1;
	iv.insert(it, iv2.begin(), iv2.end());

	//display by iterator
	for(it = iv.begin();it != iv.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl << "---------------------" << endl;

	//display by operator []
	for(int i = 0; i < iv.size(); i++)
	{
		cout << iv[i] << " ";
	}

	cout << endl << "---------------------" << endl;

	//3.删除函数pop_back erase clear
	iv.pop_back();
	for(it = iv.begin();it != iv.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl << "---------------------" << endl;
	
	iv.erase(iv.begin());
	for(it = iv.begin();it != iv.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl << "---------------------" << endl;
	
	iv.erase(iv.begin(), iv.begin()+2);
	for(it = iv.begin();it != iv.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl << "---------------------" << endl;
	
	iv.clear();
	cout << "iv.size: " << iv.size() << endl;
	cout << "iv.capacity: " << iv.capacity() << endl;

	//4.查询函数front, back, at, begin, end, rbegin, rend
	cout << "vector test end." << endl;
	
	return 0;
}
