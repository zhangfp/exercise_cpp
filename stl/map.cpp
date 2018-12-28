#include <iostream>
#include <map>
/*
1.构造函数
map():创建一个空map
map(first,last):区间构造函数，复制[first, last)区间内的元素到map中
map(const map&):拷贝构造函数

2.插入函数
insert(pair):插入pair类型的值
insert(position, value): //不知道什么意思，插入后会自动排序，需要指定position?
insert(first, last):把区间[first, last)的元素复制到map中。

3.删除函数
erase(iter_pos)
erase(key)
erase(first, last)
clear()

4.查询函数
operator[]
at(key)
iterator begin()
iterator end()
rbegin():反向起始迭代器
rend():反向终止迭代器
const_iterator cbegin() const: return const_iterator

5.判断函数
empty()
6.大小函数
size()
max_size()

7.其它
swap()
iterator find(key):由key变为对应的iterator
int count(key)
iterator lower_bound(key)
iterator upper_bound(key)
pair<iterator,iterator> equal_range(key)
*/

using namespace std;

int main(int argc, char *argv[])
{
	map<char, int> map1;
	map1.insert(pair<char,int>('a', 100));
	map1.insert(pair<char,int>('b', 200));
	map1['c'] = 100;

	map<char, int>::iterator it;
	map<char, int>::reverse_iterator rit;

	for(it = map1.begin();it != map1.end(); it++)
	{
		cout << it->first << ':' << it->second << endl;
		//cout << *it << endl; //error, map iterator have not operator*
	}

	cout << "----------const iterator-------------" << endl;
	//cout << (map1.cbegin())->first << endl;  //no cbegin()？？
	/*
	for(auto it1 = map1.cbegin();it1 != map1.cend(); it1++)
	{
		cout << it1->first << ':' << it1->second << endl;
		//cout << *it << endl; //error, map iterator have not operator*
	}
	*/
	cout << "----------reverse iterator-------------" << endl;

	for(rit = map1.rbegin(); rit != map1.rend(); rit++)
	{
		cout << rit->first << ':' << rit->second << endl;
		//cout << *it << endl; //error, map iterator have not operator*
	}


	map<char, int> map2(map1.begin(), map1.end());

	map<char, int>::const_iterator it2;
	for (it2 = map2.cbegin(); it2 != map2.cend(); it2++)
	{
		cout << it2->first << "=>" << it2->second << endl;
	}
	
	cout << map1.at('a') << endl;
	cout << map1.at('b') << endl;
	cout << map1.at('c') << endl;

	map1.erase('a');
	for(it = map1.begin();it != map1.end(); it++)
	{
		cout << it->first << ':' << it->second << endl;
		//cout << *it << endl; //error, map iterator have not operator*
	}
	
	map1.erase(map1.begin(), map1.end());
	
	cout << "size : " << map1.size() << endl;
	cout << "max size : " << map1.max_size() << endl;
	map1.clear();

	cout << "size : " << map1.size() << endl;
	cout << "max size : " << map1.max_size() << endl;

	map<char,int> map3;
	map3.insert(pair<char,int>('q',111));
	map3.insert(pair<char,int>('w',222));
	map3.insert(pair<char,int>('e',333));
	map3.insert(pair<char,int>('r',444));
	map3['r'] = 555;

	map2.swap(map3);

	for (it2 = map2.begin(); it2 != map2.end(); it2++)
	{
		cout << it2->first << "=>" << it2->second << endl;
	}

	map1.swap(map3);

	for (it2 = map1.begin(); it2 != map1.end(); it2++)
	{
		cout << it2->first << "=>" << it2->second << endl;
	}

	
	it2 = map1.find('a');
	cout << it2->first << "=>" << it2->second << endl;

	cout << "-------------------------------" << endl;


	pair<map<char,int>::iterator, map<char,int>::iterator> p1;
	p1 = map2.equal_range('e');

	cout << "[" << p1.first->first << "," << p1.second->first << ")"<<endl;
	return 0;
}
