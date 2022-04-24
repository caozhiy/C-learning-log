#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <system_error>
void _6_1_1();
/*返回值是数组的指针的函数*/
// pArr(int length)是一个函数
//*pArr(int length)解引用，结果是一个double [20]的数组
double (*pArr(int length))[20];

/*函数形参为数组，下面表达式都一样*/
void print(const int *);
void print(const int[]);
void print(const int ia[10]);

/*其余形式*/
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);
// matrix指向数组的首元素，该数组的每个元素都是由10个int构成的数组
void print(int (*matrix)[10], int rowSize);
void print(const std::string &r);
void print(std::string &r);
void print(const int &ra);
void print(int &ra);
//引用和初值不要同时设，分不开
// void print(int a);
/*含有可变形参的函数*/
void error_msg(std::initializer_list<std::string> il);

/*函数重载*/
/*顶层const：自身是一个常量。底层const：所指对象是一个常量。*/
/*
函数重载忽视顶层const
*/
int lookup(const int *p);
int lookup(int *p);
int lookup(int *const p); //与（int*p）一样

/*不一样的引用声明*/
int lookup(const int &r);
int lookup(int &r);
/*忽略顶层const，等价于int v*/
int lookup(const int v);
int lookup(int v);

/*const_cast与函数重载*/
const std::string &shorterString(const std::string &s1, const std::string &s2);
std::string &shorterString(std::string &s1, std::string &s2);

/*函数指针*/
//int (*(*p_function)(std::string, int i))[10]; //返回值是一个指向一个数组的指针，该数组有10个int
auto f1(int) -> int (*)(int *, int);         //返回值是一个函数指针，指向一个函数【返回值是int，参数为int*，int】
int ii_i(int, int);

