#include "../inc/head.h"
using namespace std;

int main()
{
    string s{"caozhiyuan"};
    cout << s << endl;
    cout << "Hello World!" << endl;
    total();
    array_count();
    char filename[20] = "current.txt";
    user(filename, 20);
    test(s, filename, 20);
    system("pause");
    return 0;
}
