#include <vector>
#include <string>
#include <iostream>
using namespace std;

void vector_first()
{
    //ָ��vector��СΪ10��Ȼ������Ĭ��ֵΪ��-1��
    vector<int> ivec(10, -1);
    // vector ��Ԫ��Ϊvector����������������顣
    vector<vector<string>> file;
    //������ʼ�������ַ�ʽ��()���͡�=��
    vector<int> ivec2(ivec);
    vector<int> ivec3 = ivec;
    //�б��ʼ��vector����
    vector<string> articles = {"a", "an", "the"};
    //����vector
    for (int i = 0; i < articles.size(); i++)
    {
        cout << articles.size() << endl;
        cout << articles[i] << endl; /* code */
    }
    //ֵ��Ĭ�ϳ�ʼ��
    /*�����Ĭ�����ͣ��Ͱ���Ĭ�Ϸ�ʽ���������ĳ��������ͣ��Ͱ���Ĭ�Ϲ��캯����ʼ��*/
    vector<int> ivec4(10);
    //������10��string��ÿ��string���ǡ���;
    vector<string> svec(10);

    /*�����б��ʼ��������Ԫ������������*/
    vector<int> v1(10);
    cout << v1.size() << endl; // v1��10��0
    vector<int> v2{10};
    cout << v2.size() << "\t" << v2[0] << endl; // 1,10
    vector<int> v3(10, 1);
    cout << v3.size() << "\t %10d" << v3[0] << endl; // v3��10��Ԫ�أ�ÿ��ֵΪ1
    vector<int> v4{10, 1};
    cout << v4.size() << "\t %10d" << v4[0] << endl; // v4��2��Ԫ�أ��ֱ�Ϊ10��1
    vector<string> v5{"hi"};
    cout << v5.size() << "\t" << v5[0] << endl;
    vector<string> v7{10};                      //�ȼ�����10���մ�
    cout << v7.size() << "\t" << v7[0] << endl; // 10,""
    vector<string> v8{10, "hi"};
    cout << v8.size() << "\t" << v8[0] << endl; // 10,"hi"
    string name;
    rewind(stdin);
    cout << name << endl;
    while (cin >> name)
    {
        if (name == "q")
            break;
        v7.push_back(name);
    }

    return;
}

void vector_second()
{
    vector<string> filename(5);
    vector<string> text(3);
    filename = text;
    /*�Ƚ����ú͸�ֵ�Ĳ�ͬ*/
    for (auto &r : filename)
    {
        cout << r << endl;
        r = "file1";
    }
    cout << "Next\n";
    for (auto q : filename)
    {
        cout << q << endl;
    }

    /*ʹ���±����vector����Ԫ��*/
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
            ++scores[grade / 10]; //��Ӧ�����ε�����+1
    }
    for (auto p : scores)
    {
        cout << p << endl;
    }
    //ע�ⲻ�����±���ʽ���Ԫ�أ���
    /*
    scores[1] = 99 �Ǵ�ģ�
    */
}

void vector_and_iteration()
{
    vector<string> v(5, "hi");
    /*ʹ�õ�������������autoָ������*/
    auto b = v.begin(), c = v.end();
    cout << "����b\n";
    cout << *b << endl
         << b->size() << endl;
    ++b;
    (*b) = "Hello";
    cout << *b << endl;
    /*string ����Ҳ��iteration */
    string s("some words");
    if (s.begin() != s.end())
    {
        auto t = s.begin();
        *t = toupper(*t);
    }
    cout << s << endl;
}