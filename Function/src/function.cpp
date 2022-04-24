#include "../inc/func.h"
using namespace std;
static size_t count_calls();

void _6_1_1()
{
    /*�ֲ�����*/
    /*�ڿ��ж���ı�������������е����βʱ���������١�ֻ�����ڿ�ִ���ڼ�Ķ����Ϊ�Զ�����*/
    /*�ֲ���̬����*/
    for (size_t i = 0, ans; i < 10; ++i)
    {
        ans = count_calls();
        cout << ans << " ";
    }
    cout << "\n";
    print("Hello World");
    string temptation("COFFEE!");
    // print(temptation);�������ȥ����Ϊstringû�����const string

    return;
}
size_t count_calls()
{
    /*�ֲ���̬�����������ڹᴩ�������ü�֮���ʱ��
    ����ֻ�ڵ�һ�ξ������������ִ��һ�Σ�����ֱ��������ֹ�ű�����*/
    static size_t ctr = 0;
    return ++ctr;
}

/*arr��һ�����ã����ö���Ϊһ�����飬��������10��Ԫ�أ�ÿ��Ԫ��Ϊint*/
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
/*���пɱ��βεĺ���*/
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

/*����һ����С�ĳ��ȵ�const string��������*/
const std::string &shorterString(const std::string &s1, const std::string &s2)
{
    return s1.size() >= s2.size() ? s2 : s1;
}
std::string &shorterString(std::string &s1, std::string &s2)
{
    /*����const_cast<T>()��������const����*/
    auto &r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string &>(r);
}
/*����ƥ��*/
/*
1��ѡ������ѡ�ö�Ӧ�����غ�����
    1�������뱻����������ͬ
    2�������ڵ��ô��ɼ�
2�����챾�ε����ṩ��ʵ�Σ�Ȼ��Ӻ�ѡ������ѡ���ܱ�ʵ�ε��õĺ�������Ϊ���к���
    1���β�������ʵ��������ͬ
    2��ʵ�����ͺ��β�������ͬ�����߿���ת�����β�����
##  �����������Ĭ��ʵ�Σ��������ڵ��øú���ʱ�����ʵ����������������ʵ��ʹ�õ�ʵ������
3��Ѱ�����ƥ�䣬��һ��麯�������ṩ��ʵ�Σ�Ѱ���β�������ʵ��������ƥ����Ǹ����к���
    1������ÿ��ʵ�ε�ƥ�䶼�������������еĺ���
    2��������һ��ʵ�ε�ƥ�������������к����ṩ��ƥ��

*��ȷƥ��
    1��ʵ���������β�������ȫƥ��
    2��ʵ�δ�����ָ���������ת���ɶ�Ӧ��ָ������
    3����ʵ����Ӷ���const���ߴ�ʵ����ɾ������const
*/
int ii_i(int a, int b)
{
    cout << "a = " << a << "\t"
         << "b = " << b << endl;
    return a + b;
}
