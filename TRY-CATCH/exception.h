#include<iostream>
#include <string>
#ifndef EXCEPTION_H
#define EXCEPTION_H
using namespace std;

template<typename T,typename G>
class Divide{
public:
    Divide();
    Divide(T value1,G value2);
    T divideT(T denominator);
    G divideG(G denominator);
private:
    T first;
    G second;
};

class MyException:public exception{
public:
    MyException(string a):str(a){}
    virtual const char* what() const noexcept override final{
        return str.c_str();
    }
private:
    string str;
};
#endif
