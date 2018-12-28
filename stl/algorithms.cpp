#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	//[](){};  //lambda
	vector<int> vec;
	int i;
	for (i = 0;i < 10; i++)
		vec.push_back(i);
	vector<int>::iterator it;
	for(it=vec.begin();it != vec.end();it++)
		cout << *it << ' ';
	cout << endl;

	//template <class BidirectionalIterator>
	//void reverse(BidirectionalIterator first, BidirectionalIterator last)
	reverse(vec.begin(), vec.end());
	cout << "-----------------------" << endl;
	for(it=vec.begin();it != vec.end();it++)
		cout << *it << ' ';
	cout << endl;

	//template <class InputIterator,class UnaryPredicate>
	//bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred)
	if (all_of(vec.begin(), vec.end(), [](int i){return i < 10;}))
		cout << "all is low to 10" << endl;

	map<char,int> imap;
	imap.insert(pair<char,int>('a',1));
	imap.insert(pair<char,int>('b',2));
	imap.insert(pair<char,int>('c',3));

	return 0;
}
