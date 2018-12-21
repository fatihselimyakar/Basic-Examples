#include "Dog.h"

int main(){
    Pet vpet("Maviş");
    vpet.print();
    Dog vdog("Tomas","Husky");
    vdog.print();
    Pet *ppet=new Pet("Sarı");
    ppet->print();
    Dog *pdog=new Dog("Garip","Alman kurdu");
    pdog->print();

    ppet=pdog;//Slicing problem fixed POINTER
    vpet=vdog;//slicing problem occured NORMAL
    ppet->bas();
    vpet.print();

    //Downcasting
    Dog *pdog2=dynamic_cast<Dog*>(ppet);
    pdog2->print();

    return 0;
}
