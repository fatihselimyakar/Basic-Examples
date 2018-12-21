#ifndef NAMESPACES_H
#define NAMESPACES_H

#include<iostream>
using namespace std;
namespace A{
	void func(){
		cout<<"THİS FUNCTİON İS ELEMENT OF A"<<endl;
	}
	int add(int a,int b){
		return a+b;
	}
	int somefunc(int a,int b){
		return a*b;
	}
}

namespace B{
	void func(){
		cout<<"THİS FUNCTİON İS ELEMENT OF B"<<endl;
	}
	int add(int a,int b){
		return a+b;
	}
	double somefunc(int a,int b){
		return static_cast<double>(a)/b;
	}
}

#endif//NAMESPACES_H