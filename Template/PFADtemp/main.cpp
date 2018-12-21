#include"pfarrayd.cpp"
#include"pfarrayd.h"
int main(){//kapasite giriyoruz mainde negatif number girene kadar sayı alıyo maksimum kapasiteye kadar
	int cap;
	cout<<"Enter capacity of this super array";
	cin>>cap;
	PFArrayD<double> temp(cap);//burda oluştururken int veya double oluşturulabilir


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


	return 0;
}
