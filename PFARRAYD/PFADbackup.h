#include"pfarrayd.h"
#ifndef PFARRAYDBACKUP_H
#define PFARRAYDBACKUP_H

class PFADbackup : public PFArrayD{
public:
    PFADbackup();//no parameter constructor
    PFADbackup(int elementNum);//normal sayıyla oluşturan constructor
    PFADbackup(const PFADbackup& object);//Copy constructor
    PFADbackup& operator=(const PFADbackup& rightSide);//assignment operator
    void backup();//baştaki arrayin yedeğini alır ve kaydeder.
    void restore();//en son kaydedilen versiyonu geri getirir.
    ~PFADbackup();
private:
    double *b;
    int usedb;
};

#endif
