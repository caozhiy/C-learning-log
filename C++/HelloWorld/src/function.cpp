#include "../inc/head.h"
using namespace std;
int total()
{
    string line{"I am a student!"};
    cout << 1 + 1 << line << endl;
    return 2;
}

int array_count()
{
    int *a = new int[10]{1, 2, 3};
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }
    delete[] a;
    return 0;
}

void user(char *name, int size)
{
    cout << name << "\t"
         << "name 的大小是:" << sizeof(name) << endl;
    cout << size << endl;
}

void test(string s, char *name, int length)
{
    s = name;
    cout << "name is " << name << "\t"
         << "length is " << length << endl;
    cout << "string is " << s << endl;
    return;
}