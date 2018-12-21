#include "TemplateClass.h"

template<typename T,typename G,int a>
class PairPolymorhic : public Pair<T,G,a>{
public:
    virtual void printall()const override final;
    virtual T plusTwitha()override final;
    virtual G plusGwitha()override final;
};
