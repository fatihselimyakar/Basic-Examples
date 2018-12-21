#include"namespaces.h"

int main(){
	{
		using namespace A;
		func();
		cout<<add(2,3)<<endl;
		cout<<somefunc(3,4)<<endl;
	}
	//LOKAL OLURLARSA USİNG İLE ÇALIŞIYOR İKİSİ BİR ARADA 
	{
		using namespace B;
		func();
		cout<<add(2,3)<<endl;
		cout<<somefunc(3,4)<<endl;
	}
	//veya bu şekilde
	A::func();
	B::func();
	
	
	return 0;
}