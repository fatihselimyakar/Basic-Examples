#include "shape2D.h"

class rectangle : public shape2D{
public:
    rectangle(double w,double h);
    //bunları artık tanımlayacağım için virtual olmayacaklar override keywordunu ise compilerın bilmesi için kullandım
    double Area()override final;//final keyword'u kullandım çünkü bundan sonrakilerin bu fonksiyonları değiştirmesini istemiyorum
    double Perimeter()override final;
    void printIt()override;
protected:
    double w;
    double h;
};
