#include "PolyTemplate.h"
template<typename T,typename G,int a>
void PairPolymorhic<T,G,a>::printall()const{
    cout<<a<<" "<<first<<" "<<second<<endl;
}

template<typename T,typename G,int a>
T PairPolymorhic<T,G,a>::plusTwitha(){ return a+first; }

template<typename T,typename G,int a>
G PairPolymorhic<T,G,a>::plusGwitha(){ return a+second; }
