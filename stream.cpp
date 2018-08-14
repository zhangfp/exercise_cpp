/*
1.standard input/output stream
2.file stream
3.string stream
*/

#include <iostream>

/*
ifstream:fstream
ofstream:fstream
*/

#include <fstream>


using namespace std;

void test_fstream()
{
	fstream fs;
	string  ss;
	fs.open("mytext", ios::out | ios::in | ios::trunc); //ios::app(append)
	fs << "this is fstream write test." << endl;
	fs.flush();
	fs.seekg(0); //seekg(offset, pos) pos: ios::beg ios::cur ios::end
	fs >> ss;
	cout << ss << endl;
	fs.close();
}

int main(int argc, char *argv[])
{
	test_fstream();
	return 0;
}
