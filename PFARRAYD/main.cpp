#include"PFADbackup.h"
int main(){//kapasite giriyoruz mainde negatif number girene kadar sayı alıyo maksimum kapasiteye kadar
	int cap;
	cout<<"Enter capacity of this super array";
	cin>>cap;
	PFADbackup temp(cap);//backup tipinde bitane değişken oluşturdum "is a" relation tipi yüzünden aslında buda bi PFArrayD ama daha özel yani yedek tutabiliyor ve silindiğinde falan geri getirebiliyor restore ve backup fonksiyonlarıyla


	cout<<"Enter up to "<<cap<<" non negative numbers."<<endl;
	cout<<"Place a negative number at the end."<<endl;

	double next;
	cin>>next;
	while((next>=0)&&(!temp.full()))//burda 0<next<full mü diye bakıyo
	{
		temp.addElement(next);
		cin>>next;
	}
	//burda ana girilmiş arraydeki elemanları basıyor
	cout<<"you entered the fallowing "<< temp.getNumberUsed()<<" numbers:\n";
	int index;
	int count = temp.getNumberUsed();
	for(index=0;index<count;index++)
		cout<< temp[index] << " ";
	cout<<endl;
	cout<<"(plus a sentinel value)"<<endl<<endl;

	//burda arrayimin yedeğini aldım ve kaydettim derived class'a
	cout<<"I backup to array and delete the main array"<<endl<<endl;
	temp.backup();

	//yedeğini aldığım arrayin kendisini sildim ve kullanılan elemanları bastım 0 verdi
	cout<<"Deleting..."<<endl;
	temp.emptyArray();
	cout<<"number of elements:"<<temp.getNumberUsed()<<endl<<endl;

	//Burda sildiğim arrayin yedeğini yeniden yükledim ana arraye ve tekrar bastım
	temp.restore();
	cout<<"Restoring "<< temp.getNumberUsed()<<" numbers...\n";
	count = temp.getNumberUsed();
	for(index=0;index<count;index++)
		cout<< temp[index] << " ";
	cout<<endl;
	cout<<"(plus a sentinel value)\n";


	return 0;
}
