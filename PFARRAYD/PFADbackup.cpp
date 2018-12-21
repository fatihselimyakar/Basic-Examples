#include"PFADbackup.h"
PFADbackup::PFADbackup():PFArrayD()/*önce base class'ın no parameter constructorunu çağırıyorum bundan türediği için*/,usedb(0){ b=new double[capacity]; }

PFADbackup::PFADbackup(int elementNum):PFArrayD(elementNum)/*önce base class'ın aynı tip constructorunu çağırıyorum bundan türediği için*/,usedb(0){ b=new double[capacity]; }

PFADbackup::PFADbackup(const PFADbackup& object):PFArrayD(object)/*önce base class'ın copy constructorunu çağırıyorum bundan türediği için*/,usedb(0){
    b=new double[capacity];
    usedb=object.usedb;
    for(int i=0;i<usedb;i++)
        b[i]=object.b[i];
}

void PFADbackup::backup(){//base class'ın objesini derived class'ına ulaşıp ondaki arrayi dolduruyor ve yedeklenmiş oluyo
    usedb=used;
    for(int i=0;i<usedb;i++)
        b[i]=a[i];
}

void PFADbackup::restore(){//kaydedilen arrayi geri ana arraye kaydediyor,yedeklemesini yüklüyor yani
    used=usedb;
    for(int i=0;i<usedb;i++)
        a[i]=b[i];

}
//önce baseclass'ın işlemleri yapılır çünkü bu ondan türüyor sonra kendi işlemlerini yapar.
PFADbackup& PFADbackup::operator=(const PFADbackup& rightSide){
    int oldCapacity=capacity;
    PFArrayD::operator=(rightSide);//base class'In assignment'ı
    if(oldCapacity!=rightSide.capacity){
        delete [] b;
        b= new double [rightSide.capacity];
    }
    usedb=rightSide.usedb;
    for(int i=0;i<usedb;i++)
        b[i]=rightSide.b[i];

    return *this;
}

PFADbackup::~PFADbackup(){//destructor sadece kendi class'ının dinamik arrayini siliyor.Destorlar otomatik çağırıldığı için bunun base class ile alakası yok her class kendi destructorunu çağırıyor.
    delete [] b;
}
