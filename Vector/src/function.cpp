#include <vector>
#include <string>
#include <iostream>
using namespace std;

void vector_first()
{
    //指定vector大小为10，然后设置默认值为“-1”
    vector<int> ivec(10, -1);
    // vector 的元素为vector，类似于数组的数组。
    vector<vector<string>> file;
    //拷贝初始化的两种方式“()”和“=”
    vector<int> ivec2(ivec);
    vector<int> ivec3 = ivec;
    //列表初始化vector对象
    vector<string> articles = {"a", "an", "the"};
    //遍历vector
    for (int i = 0; i < articles.size(); i++)
    {
        cout << articles.size() << endl;
        cout << articles[i] << endl;
    }
    //值的默认初始化
    /*如果是默认类型，就按照默认方式处理；如果是某种类的类型，就按找默认构造函数初始化*/
    vector<int> ivec4(10);
    //创建了10个string，每个string都是“”;
    vector<string> svec(10);

    /*区分列表初始化，还是元素数量的问题*/
    vector<int> v1(10);
    cout << v1.size() << endl; // v1有10个0
    vector<int> v2{10};
    cout << v2.size() << "\t" << v2[0] << endl; // 1,10
    vector<int> v3(10, 1);
    cout << v3.size() << "\t %10d" << v3[0] << endl; // v3有10个元素，每个值为1
    vector<int> v4{10, 1};
    cout << v4.size() << "\t %10d" << v4[0] << endl; // v4有2个元素，分别为10和1
    vector<string> v5{"hi"};
    cout << v5.size() << "\t" << v5[0] << endl;
    vector<string> v7{10};                      //等价于有10个空串
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
    /*比较引用和赋值的不同*/
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

    /*使用下标访问vector各个元素*/
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
            ++scores[grade / 10]; //对应分数段的人数+1
    }
    for (auto p : scores)
    {
        cout << p << endl;
    }
    //注意不能用下标形式添加元素！！
    /*
    scores[1] = 99 是错的！
    */

    // vector重载了“ = ”运算符
    vector<int> vi;
    vi = {0, 19, 23, 4};
    cout << vi[0] << "\t" << vi[1] << endl;
    vector<string> textbook(2, "Chinese");

    //直接把Chinese给去掉了，整体变成拷贝过来的值
    textbook = {"English", "Math", "Biology", "Geography", "Physics", "Chemistry"};
    cout << textbook.size() << endl;
    for (const auto &p : textbook)
    {
        cout << p << endl;
    }
}

void vector_and_iteration()
{
    vector<string> v(5, "hi");
    /*使用迭代器，可以用auto指定类型*/
    auto b = v.begin(), c = v.end();
    cout << "测试b\n";
    cout << *b << endl
         << b->size() << endl;
    ++b;
    (*b) = "Hello";
    cout << *b << endl;
    /*string 里面也有iteration */
    string s("some words");
    if (s.begin() != s.end())
    {
        auto t = s.begin();
        *t = toupper(*t);
    }
    cout << s << endl;
    for (auto it = s.begin(); it != s.end() && !isspace(*it); it++)
    {
        *it = toupper(*it);
    }
    cout << s << endl;
    vector<vector<int>> my{{3, 9, 7}, {-4, 7, 10}};
    //定义迭代器类型，iterator不能被引用
    vector<vector<int>>::iterator it = my.begin(); //可以读写vector<int>元素
    string::iterator it2;
    vector<int>::const_iterator it3; //只能读，不能修改
    string::const_iterator it4;
    it2 = s.begin();              // iterator
    auto it5 = s.cbegin();        // const_iterator
    cout << (*it).size() << endl; //(*it)指向的对象是一个vector<int>对象
    vector<string> text{"china", "google", "statistics"};
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); it++)
    {
        cout << *it << endl;
    }
    //使用了迭代器之后不能用循环向对象中添加元素
    auto p = &text;
    p->push_back("today");
    cout << *(--(p->end())) << endl;
}

void iteration()
{
    /*迭代器的运算*/
    vector<string> vi{"GBK", "python"};
    auto mid = vi.begin() + vi.size() / 2; // cbegin的下标是0，size是2，所以mid指向vi[1]
    cout << *mid << endl;
    auto it = vi.begin();
    if (it < mid)
    {
        //处理前半部分元素
        (*it) = "javascript";
    }
    for (auto p = vi.cbegin(); p != vi.cend(); p++)
        cout << (*p) << endl;
    vector<int> text{0, 1, 2, 5, 7, 10, 19, 25};
    cout << "The size of text is " << text.size() << endl;
    auto beg = text.begin(), end = text.end();
    auto midd = beg + (end - beg) / 2;
    int aim = 0;
    cin >> aim;
    while (midd != end && (*midd) != aim)
    {
        if ((*midd) > aim)
        {
            end = midd;
        }
        else
        {
            beg = midd + 1;
        }
        midd = beg + (end - beg) / 2;
    }
    if (midd == end)
        cout << "未找到" << endl;
    else
        cout << *midd << endl;
}
