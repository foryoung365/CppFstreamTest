#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // 输出操作系统相关信息
#ifdef _WIN32
    cout << "Running on Windows" << endl;
#elif __APPLE__
    cout << "Running on macOS" << endl;
#elif __linux__
    cout << "Running on Linux" << endl;
#else
    cout << "Running on unknown OS" << endl;
#endif

    cout << "Testing directory '.\\':" << endl;

    {
        ifstream ifs(".\\");
        cout << "ifstream .\\:" << endl;
        cout << "  good(): " << ifs.good() << endl;
        cout << "  fail(): " << ifs.fail() << endl;
        cout << "  bad():  " << ifs.bad() << endl;
    }

    {
        fstream fs(".\\", ios::in);
        cout << "\nfstream .\\:" << endl;
        cout << "  good(): " << fs.good() << endl;
        cout << "  fail(): " << fs.fail() << endl;
        cout << "  bad():  " << fs.bad() << endl;
    }

    // 为了比较，也测试 "./" 路径
    cout << "\nTesting directory './':" << endl;

    {
        ifstream ifs("./");
        cout << "ifstream ./:" << endl;
        cout << "  good(): " << ifs.good() << endl;
        cout << "  fail(): " << ifs.fail() << endl;
        cout << "  bad():  " << ifs.bad() << endl;
    }

    {
        fstream fs("./", ios::in);
        cout << "\nfstream ./:" << endl;
        cout << "  good(): " << fs.good() << endl;
        cout << "  fail(): " << fs.fail() << endl;
        cout << "  bad():  " << fs.bad() << endl;
    }

    return 0;
}