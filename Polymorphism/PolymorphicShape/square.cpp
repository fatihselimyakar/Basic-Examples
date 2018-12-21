#include "square.h"

square::square(double s):rectangle(s,s){
    name="Square";
}
void square::printIt(){
    cout<<"This is a square function"<<endl;
    cout<<"Square Area:"<<Area()<<endl;
    cout<<"Square Perimeter:"<<Perimeter()<<endl;
}
