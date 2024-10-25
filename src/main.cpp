#include <iostream>
#include <fstream>
#include <system_error>
using namespace std;

static int SafeFOpen(FILE** fp, const char* filename, const char* mode)
{
#ifdef _WIN32
    return fopen_s(fp, filename, mode);
#else
    // Unix-like 系统的安全实现
    if (!fp || !filename || !mode) {
        errno = EINVAL;
        return EINVAL;
    }

    *fp = fopen(filename, mode);
    return (*fp == NULL) ? errno : 0;
#endif
}

void test_path(const char* path) {
    cout << "\nTesting path \"" << path << "\":" << endl;

    {
        ifstream ifs(path);
        cout << "ifstream status:" << endl;
        cout << "  good(): " << ifs.good() << endl;
        cout << "  fail(): " << ifs.fail() << endl;
        cout << "  bad():  " << ifs.bad() << endl;
        cout << "  error: " << std::error_code(errno, std::system_category()).message() << endl;
    }

    {
        fstream fs(path, ios::app);
        cout << "\nfstream status:" << endl;
        cout << "  good(): " << fs.good() << endl;
        cout << "  fail(): " << fs.fail() << endl;
        cout << "  bad():  " << fs.bad() << endl;
        cout << "  error: " << std::error_code(errno, std::system_category()).message() << endl;
    }

    {
        FILE* fp = nullptr;
        int nErr = SafeFOpen(&fp, path, "r");
        cout << "\nFILE* status:" << endl;
        cout << "  good(): " << (fp != nullptr) << endl;
        cout << "  error: " << nErr << endl;
        if (fp)
        {
	        fclose(fp);
        }
    }
}

int main() {
#ifdef _WIN32
    cout << "Running on Windows" << endl;
#elif __APPLE__
    cout << "Running on macOS" << endl;
#elif __linux__
    cout << "Running on Linux" << endl;
#else
    cout << "Running on unknown OS" << endl;
#endif

    cout << "Current working directory test:\n";
    test_path(".");
    test_path("./");

#ifdef _WIN32
    test_path(".\\");
#endif

    return 0;
}