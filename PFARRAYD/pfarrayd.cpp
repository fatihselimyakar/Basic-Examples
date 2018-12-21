#include"pfarrayd.h"
PFArrayD::PFArrayD()//no parameter constructor
	:capacity(50),used(0)
{
		a = new double[capacity];
}

PFArrayD::PFArrayD(int size)// normal constructor
	:capacity(size),used(0)
{
		a = new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD& pfaObject)
	:capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
		a=new double[capacity];
		for(int i=0;i<used;i++)
			a[i]=pfaObject.a[i];

}

void PFArrayD::addElement(double element)
{
	if(used>=capacity){//yani eleman alamıycaksa üzerine
		cout<<"ERROR THE CAPACITY İS MAX";
		exit(1);
	}
	a[used]=element;//arrayin sonuna eleman ekler
	used++;//arrayin kullanılan alanını 1 arttırır

}

double& PFArrayD::operator[](int index)
{
	if(index>=used)//yani girilen sayı kullanılan alandan küçük olmalı yoksa junk değer atıyor.
	{
		cout<<"ERROR INDEX IS GREATER THEN USED";
		exit(1);
	}

	return a[index];
}

PFArrayD& PFArrayD::operator=(const PFArrayD& rightSide){//ASSIGNMENT OPERATOR OVERLOAD
	if(capacity!=rightSide.capacity)//eğer sağdaki ve soldaki arraylerin kapasiteleri eşit değilse bunları eşitler
	{
			delete[] a;//önceki a arrayini siler
			a=new double[rightSide.capacity];//yeni right side'ın kapasitesinde bir a arrayi oluşturur
	}
	capacity=rightSide.capacity;//normal sağdaki elemanı sola atama(eşitleme)
	used=rightSide.used;//normal sağdaki elemanı sola atama(eşitleme)
	for(int i=0;i<used;i++){//sağdaki arrayi soldaki arraye eşitleme
		a[i]=rightSide.a[i];
	}

	return *this;//kendini(calling object) döndürür(yani class'ın kendinden gelen objeyi döndürüyor);
}

PFArrayD& PFArrayD::operator+=(const PFArrayD& add){
	double *buffer=new double[used];
	int i;
	for(i=0;i<used;i++)
		buffer[i]=a[i];

	delete[] a;
	a=new double[capacity+add.capacity];
	for(i=0;i<used;i++)
		a[i]=buffer[i];
	for(int j=0;j<add.used;j++){
		a[i]=add.a[j];
		i++;
	}

	used=used+add.used;
	capacity=capacity+add.capacity;

	return *this;
}

PFArrayD::~PFArrayD()//buda otomatik(kodda kendimizin kullanmasına gerek yok) olarak class objesi çalışma yerinden çıkarsa çağırılıyor ve siliyor(memoryleak olmasını önlüyor)
{
	delete [] a;
}
