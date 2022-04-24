#include<iostream>
using namespace std;
void T_4_11_3();

int main()
{
    T_4_11_3();
    return 0;
}

void T_4_11_3()
{
    int i = 2, j = 39;
    double slope;
    /*三种方式进行类型转换*/
    //不包含底层const（指针所指对象是一个常量类型）的类型转换，可以用static_cast<>()
    slope = static_cast<double>(j) / i;
    cout << slope << endl;
    int d = 23;
    void *p = &d;
    double *pd = static_cast<double *>(p);
    // const_cast只能改变运算对象的底层const
    const char *pc;
    char *q = const_cast<char *>(pc); //去掉了const性质，但是通过新的q去写值可能会出现问题
    // static_cast不能改变const类型
    // reinterpret转换,把运算对象按照低等级的数据解释，int->char
    int *ip;
    char *pcb = reinterpret_cast<char *>(ip);
    //reinterpret非常危险，不建议使用
    return;
}