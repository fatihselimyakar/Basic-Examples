#include "TemplateClass.cpp"


int main(){
    Pair<char,double,20>a('N',10.22);
    Pair<double,int,10>b(20.42,32);
    Pair<>c(3,5);//bu şekilde yapınca hepsi default halde oluyo <int,int,0> ile yapmış gibi oluyo aynı

    a.printAll();
    b.printAll();
    c.printAll();
}
