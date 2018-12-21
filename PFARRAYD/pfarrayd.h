#include<iostream>
#ifndef PFARRAYD_H
#define PFARRAYD_H

using namespace std;
class PFArrayD
{
	public:
		PFArrayD();
		PFArrayD(int capacityValue);
		PFArrayD(const PFArrayD& pfaObject);//copy constructor
		void addElement(double element);
		bool full()const{ return (capacity == used); }
		int getCapacity()const{ return capacity; }
		int getNumberUsed()const{ return used; }
		void emptyArray(){ used = 0; }
		double& operator[](int index);
		PFArrayD& operator=(const PFArrayD& rightSide);//assignment overload
		PFArrayD& operator+=(const PFArrayD& add);
		~PFArrayD();//destructor
	protected://protected olmasının nedeni derived class'ta public gibi dışarı ise private gibi davransın diye.
		double *a;//double tipinde bi array aslında sadece pointerla göstermiş
		int capacity;//arrayin maksimum alabildiği eleman sayısı
		int used;//kaç tane eleman için kullanıldığı(içinde olan eleman)
};

#endif
