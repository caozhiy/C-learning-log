#include <iostream>
using namespace std;
void array_operation();
int main()
{
    array_operation();
    system("pause");
    return 0;
}

void array_operation()
{
    //不是常量表达式
    unsigned cnt = 42;
    //是常量表达式
    constexpr unsigned sz = 42;
    /*自动默认初始化*/
    int arr[10];
    cout << arr[5] << endl;
    int *parr[sz];
    printf("%p\n", parr[0]);
    std::string *bad = nullptr;
}
