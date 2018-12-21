#include"statistic.h"

int main(){
	Statistic deneme;
	Statistic deneme2(6,6);
	deneme.makeTheArray();
	deneme2=deneme;
	cout<<"results"<<endl;
	cout<<"ortalama:"<<deneme.ortalama()<<endl;
	cout<<"mod:"<<deneme.mod()<<endl;
	cout<<"medyan:"<<deneme.medyan()<<endl;
	//cout<<deneme;
	//deneme.add(4);
	//cout<<deneme;
	
	return 0;
}