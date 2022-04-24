#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
void array_operation();
void complicate();
void exercise_3_5_2();
void pointer_and_array();
void array_C_string();
void MultiArr_3_6();
void pointer_and_Multiarr();

int main()
{
    // array_operation();
    // exercise_3_5_2();
    // complicate();
    // pointer_and_array();
    // array_C_string();
    // MultiArr_3_6();
    pointer_and_Multiarr();
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
    char ar1[] = {'C', '+', '+'};
    char ar2[] = {'C', '+', '+', '\0'};
    char ar3[] = "C++";
    const char a4[7] = "Daniel";
    cout << *(ar1 + 2) << endl
         << ar2 << endl
         << ar3 << endl
         << a4 << endl;
}

void complicate()
{
    int *ptrs[10];

    // int &refs[10];不允许使用引用的数组
    int arr[10]{0, 14};
    int(*Parray)[10] = &arr; // Parray指向一个有10个整数的数组
    int(&arrRef)[10] = arr;  // arrRef引用一个含有10个整数的数组
    int *(&arry)[10] = ptrs; // arry 引用一个数组，该数组有10个指针
    unsigned scores[11] = {};
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
        {
            ++scores[grade / 10];
        }
        cout << scores[grade / 10] << endl;
    }
}

void exercise_3_5_2()
{
    int arr[10] = {};
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    vector<int> myvect;
    for (int i = 0; i < 10; i++)
    {
        myvect.push_back(arr[i]);
    }
    cout << "This is myvect\n";
    for (auto &p : myvect)
    {
        cout << p << endl;
    }
}

void pointer_and_array()
{
    string nums[] = {"one", "two", "three"};
    string *p2 = nums; //等价于string*p = &nums[0]
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto ia2(ia); // auto ia2(&ia[0])
    decltype(ia) ia3{0, 1, 2, 3, 4, 5};
    ia3[2] = 7;
    cout << ia3[2] << endl;
    /*使用指针，结合迭代器*/
    int arr[10] = {1, 2, 5, 8, 9, 4, 5, 1};
    int *e = &arr[10]; // e指向数组尾部元素的下一个位置，并不存在
    for (int *p = arr; p != e; p++)
    {
        cout << *p << endl;
    }

    /*使用标准库函数begin 和 end*/
    int *beg = begin(ia); //指向ia首元素的指针
    int *last = end(ia);  //指向arr尾元素的下一位置的指针
    constexpr size_t sz = 5;
    int arru[sz] = {1, 2, 3};
    int *ip = arr;
    int *ip2 = ip + 4;
    auto n = end(arr) - begin(arr); //计算arr数组中的数量
    int ia0[] = {0, 2, 4, 8};
    int last2 = *(ia0 + 4);
    int *p = &ia[2];
    int j = p[1];
    cout << j << endl;
    int k = p[-2];
    cout << k << endl;
}

void array_C_string()
{
    string s1 = "A string example";
    string s2 = "A different string";
    if (s1 < s2)
    {
        cout << s2 << endl;
    }
    else
        cout << s1 << endl;
    cout << s1.length() << "\t" << s2.length() << endl;
    // string类型的拼接
    string largeStr = s1 + " " + s2;
    cout << largeStr << endl;
    /*允许用字符串数组为string队形初始化和赋值*/
    string s("Hello World");
    cout << s << endl;
    /*允许使用字符串数组作为一个运算对象，但是不能两个都是字符串;
    string对象赋值运算允许使用字符串*/
    string b = s + ", today is Monday.";
    cout << b << endl;
    /*但是使用string对象不能直接对字符串数组进行初始化,需要用string.c_str(),类型是const char**/
    const char *str = s.c_str();
    char str2[20];
    strcpy(str2, str);
    cout << *str << endl;
    /*但是如果s改变,str也会变，所以最好先拷贝*/
    s = s + " Mr.john";
    cout << *str << "\n"
         << str2 << endl;

    /*不允许使用vector对象初始化数组，但是可以用数组初始化vector对象*/
    /*内置类型可以操作扩展定义类型，但反过来不成立*/
    int int_arr[] = {0, 1, 2, 3, 4, 5, 6};
    /*输入数组的首元素和尾后位置的指针*/
    vector<int> ivec(begin(int_arr), end(int_arr));
    /*利用指针，初始化部分元素,注意最后一个位置是取不到的*/
    vector<int> subVec(int_arr + 1, int_arr + 4); //有了int_arr[1],int_arr[2],int_arr[3]4
    auto p = subVec.begin();
    vector<int>::iterator q = subVec.begin() + 1;
    cout << *p << "\n"
         << *q << endl;
}

void MultiArr_3_6()
{
    int ia[3][4] = {{0, 1, 2, 3},
                    {4, 5, 6, 7},
                    {8, 9, 10, 11}}; //大小为3的数组，每个元素是4个int的数组
    //大小为10的数组，每个元素为大小为20的数租，这些数组的元素是含有30个int的数组
    int arr[10][20][30] = {0};
    /*也可以显示初始化每行的首元素*/
    int ib[3][4] = {{1}, {9}, {-4}};
    /*多维数组的下标引用*/
    ia[2][3] = arr[2][3][4];
    int(&row)[4] = ia[1]; // row是引用4个int的数组
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ic[rowCnt][colCnt];
    for (size_t i = 0; i != rowCnt; i++)
    {
        for (size_t j = 0; j != colCnt; j++)
        {
            ic[i][j] = i * colCnt + j;
        }
    }
    /*防止自动转换成指针,使用引用类型标定*/
    for (const auto &p : ia)
    {
        for (auto &q : p)
        {
            cout << q << endl;
        }
    }
}

void pointer_and_Multiarr()
{
    int ia[3][4] = {{-1, 7, 9, 5}, {6, 8, 5, -9}, {7, -4, 2, 0}};
    int(*p)[4] = ia; // p指向4个整数的数组
    p = &ia[2];      // p指向ia的为元素

    /*使用auto和decltype自动推断指针类型*/
    for (auto p = begin(ia); p != end(ia); p++)
    {
        for (auto q = begin(*p); q != end(*p); q++)
        {
            cout << *q << "\t";
        }
        cout << "\n";
    }
    cout << "\n\n\n";
    /*尝试使用类型别名简化多维数组指针*/
    using int_arr = int[4];
    typedef int int_arr[4];
    for (int_arr *p = ia; p != end(ia); p++)
    {
        for (int *q = begin(*p); q != end(*p); q++)
        {
            cout << *q << "\t";
        }
        cout << "\n";
    }
}
