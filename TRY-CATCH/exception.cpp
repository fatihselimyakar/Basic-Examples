#include "exception.h"
template<typename T,typename G>
Divide<T,G>::Divide(){
    first=0;
    second=0;
}

template<typename T,typename G>
Divide<T,G>::Divide(T value1,G value2){
    first=value1;
    second=value2;
}

template<typename T,typename G>
T Divide<T,G>::divideT(T denominator){
    if(denominator==0)
        throw MyException("T DIVIDE FUNCTION ERROR");
    return first/denominator;
}

template<typename T,typename G>
G Divide<T,G>::divideG(G denominator){
    if(denominator==0)
        throw 'a';
    return second/denominator;
}
