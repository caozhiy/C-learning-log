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
    //���ǳ������ʽ
    unsigned cnt = 42;
    //�ǳ������ʽ
    constexpr unsigned sz = 42;
    /*�Զ�Ĭ�ϳ�ʼ��*/
    int arr[10];
    cout << arr[5] << endl;
    int *parr[sz];
    printf("%p\n", parr[0]);
    std::string *bad = nullptr;
}
