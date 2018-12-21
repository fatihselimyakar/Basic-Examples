#include"pfarrayd.h"
template<typename T>
PFArrayD<T>::PFArrayD()//no parameter constructor
	:capacity(50),used(0)
{
		a = new T[capacity];
}

template<typename T>
PFArrayD<T>::PFArrayD(int size)// normal constructor
	:capacity(size),used(0)
{
		a = new T[capacity];
}

template<typename T>
PFArrayD<T>::PFArrayD(const PFArrayD& pfaObject)
	:capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
		a=new T[capacity];
		for(int i=0;i<used;i++)
			a[i]=pfaObject.a[i];

}

template<typename T>
void PFArrayD<T>::addElement(T element)
{
	if(used>=capacity){//yani eleman alamıycaksa üzerine
		cout<<"ERROR THE CAPACITY İS MAX";
		exit(1);
	}
	a[used]=element;//arrayin sonuna eleman ekler
	used++;//arrayin kullanılan alanını 1 arttırır

}

template<typename T>
T& PFArrayD<T>::operator[](int index)
{
	if(index>=used)//yani girilen sayı kullanılan alandan küçük olmalı yoksa junk değer atıyor.
	{
		cout<<"ERROR INDEX IS GREATER THEN USED";
		exit(1);
	}

	return a[index];
}

template<typename T>
PFArrayD<T>& PFArrayD<T>::operator=(const PFArrayD& rightSide){//ASSIGNMENT OPERATOR OVERLOAD
	if(capacity!=rightSide.capacity)//eğer sağdaki ve soldaki arraylerin kapasiteleri eşit değilse bunları eşitler
	{
			delete[] a;//önceki a arrayini siler
			a=new T[rightSide.capacity];//yeni right side'ın kapasitesinde bir a arrayi oluşturur
	}
	capacity=rightSide.capacity;//normal sağdaki elemanı sola atama(eşitleme)
	used=rightSide.used;//normal sağdaki elemanı sola atama(eşitleme)
	for(int i=0;i<used;i++){//sağdaki arrayi soldaki arraye eşitleme
		a[i]=rightSide.a[i];
	}

	return *this;//kendini(calling object) döndürür(yani class'ın kendinden gelen objeyi döndürüyor);
}

template<typename T>
PFArrayD<T>& PFArrayD<T>::operator+=(const PFArrayD& add){
	T *buffer=new T[used];
	int i;
	for(i=0;i<used;i++)
		buffer[i]=a[i];

	delete[] a;
	a=new T[capacity+add.capacity];
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

template<typename T>
PFArrayD<T>::~PFArrayD()//buda otomatik(kodda kendimizin kullanmasına gerek yok) olarak class objesi çalışma yerinden çıkarsa çağırılıyor ve siliyor(memoryleak olmasını önlüyor)
{
	delete [] a;
}
