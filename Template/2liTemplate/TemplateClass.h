#include <iostream>
using namespace std;

template<typename T=int,typename G=int,int a=0>
class Pair{
public:
    Pair();
    Pair(T firstValue,G secondValue);
    void setFirst(T newValue);
    void setSecond(G newValue);
    T getFirst()const;
    G getSecond()const;
    void printAll()const;
private:
    T first;
    G second;
};
