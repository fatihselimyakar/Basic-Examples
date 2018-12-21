#include<iostream>
#ifndef PFARRAYD_H
#define PFARRAYD_H
using namespace std;

template<typename T>
class PFArrayD
{
	public:
		PFArrayD();
		PFArrayD(int capacityValue);
		PFArrayD(const PFArrayD<T>& pfaObject);//copy constructor
		void addElement(T element);
		bool full()const{ return (capacity == used); }
		int getCapacity()const{ return capacity; }
		int getNumberUsed()const{ return used; }
		void emptyArray(){ used = 0; }
		T& operator[](int index);
		PFArrayD& operator=(const PFArrayD& rightSide);//assignment overload
		PFArrayD& operator+=(const PFArrayD& add);
		~PFArrayD();//destructor
	protected://protected olmasının nedeni derived class'ta public gibi dışarı ise private gibi davransın diye.
		T *a;//T tipinde bi array aslında sadece pointerla göstermiş
		int capacity;//arrayin maksimum alabildiği eleman sayısı
		int used;//kaç tane eleman için kullanıldığı(içinde olan eleman)
};

#endif
