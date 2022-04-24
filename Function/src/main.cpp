#include "../inc/func.h"
#include <cassert>
using namespace std;
int main()
{
    vector<decltype(ii_i) *> object;
    int time = 0;
    assert(cin >> time && time > 0);
    for (int i = 0; i < time; i++)
    {
        object.push_back(ii_i);
    }
    for (auto ri = object.begin(); ri != object.end(); ++ri)
    {
        static int value = 1;
        (*ri)(value, value % 3);
        ++value;
    }
    object.clear();
    string msg;
    assert(cin >> msg && msg != "q");
    int shuzu[9]{0, 1, 9, 7};
    const int te = 99;
    const int &rte = te;
    print(rte);
    print(const_cast<int &>(te));
    print(95);
    int a = 9;
    print(a);
    print(const_cast<const int &>(a));

    // print(99);
    //  print(shuzu);
    _6_1_1();
    std::initializer_list<int> li{54, 7};
    std::string expected("Hello");
    /* π”√÷∏’Î*/
    int arr[10];
    int(*p)[10] = &arr;
    error_msg({"functionX", "OK"});
    return 0;
}