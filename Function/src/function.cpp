#include "../inc/func.h"
using namespace std;
static size_t count_calls();

void _6_1_1()
{
    /*局部对象*/
    /*在块中定义的变量，当程序进行到块结尾时，变量销毁。只存在于块执行期间的对象成为自动对象*/
    /*局部静态对象*/
    for (size_t i = 0, ans; i < 10; ++i)
    {
        ans = count_calls();
        cout << ans << " ";
    }
    cout << "\n";
    print("Hello World");
    string temptation("COFFEE!");
    // print(temptation);编译过不去，因为string没法变成const string

    return;
}
size_t count_calls()
{
    /*局部静态对象，生命周期贯穿函数调用及之后的时间
    程序只在第一次经过对象定义语句执行一次，并且直到程序终止才被销毁*/
    static size_t ctr = 0;
    return ++ctr;
}

/*arr是一个引用，引用对象为一个数组，该数组有10个元素，每个元素为int*/
void print(int (&arr)[10])
{
    for (auto elem : arr)
    {
        cout << elem << endl;
    }
}
void print(const string &r)
{
    cout << r.size() << "\t" << r << endl;
    return;
}
void print(string &r)
{
    cout << "String: " << r << endl;
    return;
}
void print(double a)
{
    cout << "Double: " << a << endl;
}
void print(const int &ra)
{
    cout << "Const Reference int: " << ra << endl;
}
void print(int &ra)
{
    cout << "Reference int: " << ra << endl;
}
/*含有可变形参的函数*/
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
    {
        cout << *beg << " ";
    }
    cout << endl;
}

void error_msg(error_code e, initializer_list<string> il)
{
    cout << e.message() << ": ";
    for (const auto &elem : il)
    {
        cout << elem << " ";
    }
    cout << endl;
    return;
}

/*返回一个较小的长度的const string对象引用*/
const std::string &shorterString(const std::string &s1, const std::string &s2)
{
    return s1.size() >= s2.size() ? s2 : s1;
}
std::string &shorterString(std::string &s1, std::string &s2)
{
    /*利用const_cast<T>()进行增减const操作*/
    auto &r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string &>(r);
}
/*函数匹配*/
/*
1、选定本次选用对应的重载函数集
    1）函数与被调函数名相同
    2）声明在调用处可见
2、考察本次调用提供的实参，然后从候选函数中选出能被实参调用的函数，称为可行函数
    1）形参数量与实参数量相同
    2）实参类型和形参类型相同，或者可以转换成形参类型
##  如果函数含有默认实参，则我们在调用该函数时传入的实参数量可能少于它实际使用的实参数量
3、寻找最佳匹配，逐一检查函数调用提供的实参，寻找形参类型与实参类型最匹配的那个可行函数
    1）函数每个实参的匹配都不劣于其他可行的函数
    2）至少有一个实参的匹配优于其他可行函数提供的匹配

*精确匹配
    1、实参类型与形参类型完全匹配
    2、实参从数组指针或函数类型转换成对应的指针类型
    3、向实参添加顶层const或者从实参中删除顶层const
*/
int ii_i(int a, int b)
{
    cout << "a = " << a << "\t"
         << "b = " << b << endl;
    return a + b;
}
