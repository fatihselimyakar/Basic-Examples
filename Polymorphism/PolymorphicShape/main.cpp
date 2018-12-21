#include "square.h"

int main(){
    rectangle r1(10,2);
    square s1(7);
    cout<<r1.getName()<<endl;
    cout<<s1.getName()<<endl;
    r1.printIt();
    s1.printIt();
    vector<shape2D*> v;
    v.push_back(&r1);
    v.push_back(&s1);
    cout<<"Total area:"<<totalArea(v)<<endl<<endl;

    //with the "is a" relation
    rectangle r2(5,1);
    square s2(3);
    r2=s2;//rectangle'a square atadım
    cout<<r2.getName()<<endl;
    r2.printIt();

    //s2=r2; hata alır ancak pointer olarak downcast yapılabilir
    rectangle *r2ptr=&r2;
    square *s2ptr=&s2;
    s2ptr=dynamic_cast<square*>(r2ptr);//saçmalama olasılığı çok yüksek
    //s2ptr->getName(); segmentation yiyor

    return 0;
}
