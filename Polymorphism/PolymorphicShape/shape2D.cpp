#include"shape2D.h"
shape2D::shape2D(string n):name(n){};

string shape2D::getName(){ return name; }

double totalArea(const vector<shape2D*>vect){
    double res=0.;
    for(shape2D *ptr:vect)
        res+=ptr->Area();//late binding var bu virtual olduğu için hangi class'a ait runtime'da belli olur.
    return res;
}
