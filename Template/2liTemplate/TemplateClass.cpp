#include "TemplateClass.h"

template<typename T,typename G,int a>
Pair<T,G,a>::Pair(T firstValue,G secondValue){
    first=firstValue;
    second=secondValue;
}

template<typename T,typename G,int a>
void Pair<T,G,a>::setFirst(T newValue){
    first=newValue;
}

template<typename T,typename G,int a>
void Pair<T,G,a>::setSecond(G newValue){
    second=newValue;
}

template<typename T,typename G,int a>
T Pair<T,G,a>::getFirst()const{
    return first;
}

template<typename T,typename G,int a>
G Pair<T,G,a>::getSecond()const{
    return second;
}

template<typename T,typename G,int a>
void Pair<T,G,a>::printAll()const{
    cout<<a<<' '<<first<<' '<<second<<endl;
}
