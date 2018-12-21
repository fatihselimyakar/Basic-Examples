#include "rectangle.h"

rectangle::rectangle(double width,double height):w(width),h(height),shape2D("rectangle"){};

void rectangle::printIt(){
    cout<<"This is a rectangle function"<<endl;
    cout<<"Rectangle Area:"<<Area()<<endl;
    cout<<"Rectangle Perimeter:"<<Perimeter()<<endl;
}

double rectangle::Area(){ return w*h; }

double rectangle::Perimeter(){ return 2*(w+h); }
