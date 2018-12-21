#include "exception.cpp"

int main(){
    try{
        Divide<int,double>a(10,20.5);
        a.divideT(1);
        a.divideG(0);
    }
    catch(MyException a){
        cerr<<a.what();
    }
    catch(char a){
        cerr<<"Error2 Occured"<<a;
    }
    catch(...){
        unexpected();
    }
}
