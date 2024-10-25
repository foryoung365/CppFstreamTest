#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream ifs(".\\");

	std::cout << ifs.good() << std::endl;

	fstream fs(".\\", ios::in);
	std::cout << fs.good() << std::endl;

	return 0;
}