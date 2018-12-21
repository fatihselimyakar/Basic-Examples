#include<iostream>
#include<string>
#include <vector>
using namespace std;

class shape2D{//Abstract class->yani içinde pure virtual fonksiyon olucak objesi oluşturulsa bile anlam ifade edemiycek.
public:
    shape2D(string n);//normal bir constructor
    virtual double Area()=0;//Pure virtual function->Nasıl tanımlayacağımı bilemiyorum o yüzden pure yaptım.
    virtual double Perimeter()=0;
    string getName();//normal fonksiyon
    virtual void printIt();
protected:
    string name;
};
double totalArea(const vector<shape2D*>vect);
