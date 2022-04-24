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

    // int &refs[10];������ʹ�����õ�����
    int arr[10]{0, 14};
    int(*Parray)[10] = &arr; // Parrayָ��һ����10������������
    int(&arrRef)[10] = arr;  // arrRef����һ������10������������
    int *(&arry)[10] = ptrs; // arry ����һ�����飬��������10��ָ��
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
    string *p2 = nums; //�ȼ���string*p = &nums[0]
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto ia2(ia); // auto ia2(&ia[0])
    decltype(ia) ia3{0, 1, 2, 3, 4, 5};
    ia3[2] = 7;
    cout << ia3[2] << endl;
    /*ʹ��ָ�룬��ϵ�����*/
    int arr[10] = {1, 2, 5, 8, 9, 4, 5, 1};
    int *e = &arr[10]; // eָ������β��Ԫ�ص���һ��λ�ã���������
    for (int *p = arr; p != e; p++)
    {
        cout << *p << endl;
    }

    /*ʹ�ñ�׼�⺯��begin �� end*/
    int *beg = begin(ia); //ָ��ia��Ԫ�ص�ָ��
    int *last = end(ia);  //ָ��arrβԪ�ص���һλ�õ�ָ��
    constexpr size_t sz = 5;
    int arru[sz] = {1, 2, 3};
    int *ip = arr;
    int *ip2 = ip + 4;
    auto n = end(arr) - begin(arr); //����arr�����е�����
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
    // string���͵�ƴ��
    string largeStr = s1 + " " + s2;
    cout << largeStr << endl;
    /*�������ַ�������Ϊstring���γ�ʼ���͸�ֵ*/
    string s("Hello World");
    cout << s << endl;
    /*����ʹ���ַ���������Ϊһ��������󣬵��ǲ������������ַ���;
    string����ֵ��������ʹ���ַ���*/
    string b = s + ", today is Monday.";
    cout << b << endl;
    /*����ʹ��string������ֱ�Ӷ��ַ���������г�ʼ��,��Ҫ��string.c_str(),������const char**/
    const char *str = s.c_str();
    char str2[20];
    strcpy(str2, str);
    cout << *str << endl;
    /*�������s�ı�,strҲ��䣬��������ȿ���*/
    s = s + " Mr.john";
    cout << *str << "\n"
         << str2 << endl;

    /*������ʹ��vector�����ʼ�����飬���ǿ����������ʼ��vector����*/
    /*�������Ϳ��Բ�����չ�������ͣ���������������*/
    int int_arr[] = {0, 1, 2, 3, 4, 5, 6};
    /*�����������Ԫ�غ�β��λ�õ�ָ��*/
    vector<int> ivec(begin(int_arr), end(int_arr));
    /*����ָ�룬��ʼ������Ԫ��,ע�����һ��λ����ȡ������*/
    vector<int> subVec(int_arr + 1, int_arr + 4); //����int_arr[1],int_arr[2],int_arr[3]4
    auto p = subVec.begin();
    vector<int>::iterator q = subVec.begin() + 1;
    cout << *p << "\n"
         << *q << endl;
}

void MultiArr_3_6()
{
    int ia[3][4] = {{0, 1, 2, 3},
                    {4, 5, 6, 7},
                    {8, 9, 10, 11}}; //��СΪ3�����飬ÿ��Ԫ����4��int������
    //��СΪ10�����飬ÿ��Ԫ��Ϊ��СΪ20�����⣬��Щ�����Ԫ���Ǻ���30��int������
    int arr[10][20][30] = {0};
    /*Ҳ������ʾ��ʼ��ÿ�е���Ԫ��*/
    int ib[3][4] = {{1}, {9}, {-4}};
    /*��ά������±�����*/
    ia[2][3] = arr[2][3][4];
    int(&row)[4] = ia[1]; // row������4��int������
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ic[rowCnt][colCnt];
    for (size_t i = 0; i != rowCnt; i++)
    {
        for (size_t j = 0; j != colCnt; j++)
        {
            ic[i][j] = i * colCnt + j;
        }
    }
    /*��ֹ�Զ�ת����ָ��,ʹ���������ͱ궨*/
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
    int(*p)[4] = ia; // pָ��4������������
    p = &ia[2];      // pָ��ia��ΪԪ��

    /*ʹ��auto��decltype�Զ��ƶ�ָ������*/
    for (auto p = begin(ia); p != end(ia); p++)
    {
        for (auto q = begin(*p); q != end(*p); q++)
        {
            cout << *q << "\t";
        }
        cout << "\n";
    }
    cout << "\n\n\n";
    /*����ʹ�����ͱ����򻯶�ά����ָ��*/
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
