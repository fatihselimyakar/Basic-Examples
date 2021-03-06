#include"statistic.h"

void Statistic::makeTheArray(){
	cout<<"Please enter the array capacity"<<endl;
	cin>>capacity;
	cout<<"Please enter the array size"<<endl;
	cin>>size;
	array=new double[capacity];
	cout<<"please enter the numbers"<<endl;
	for(int i=0;i<size;i++)
		cin>>array[i];
}
void Statistic::set(int newSize,int newCapacity){
	if(capacity!=newCapacity){
		delete[]array;
		array=new double[newCapacity];
		capacity=newCapacity;
	}
	size=newSize;
	
}
Statistic& Statistic::operator=(const Statistic& rightSide){
	delete[]array;
	array=new double[rightSide.capacity];
	for(int i=0;i<rightSide.size;i++)
		array[i]=rightSide.array[i];
	size=rightSide.size;
	capacity=rightSide.capacity;
	
	return *this;
	
}
Statistic& Statistic::operator+(const Statistic& rightSide){
	double buffer[size];
	for(int i=0;i<size;i++)
		buffer[i]=array[i];
	delete[]array;
	array=new double[capacity+rightSide.capacity];
	int i;
	for(i=0;i<size;i++)
		array[i]=buffer[i];
	for(int j=0;j<rightSide.size;i++){
		array[i]=rightSide.array[j];
		i++;
	}
	capacity=rightSide.capacity;
	size=rightSide.size;
	
	return *this;
	
}
ostream& operator<<(ostream& outputStream,const Statistic& object){
	for(int i=0;i<object.size;i++){
		outputStream<<object.array[i]<<" ";
	}
	outputStream<<endl;
	outputStream<<"size:"<<object.size<<endl;
	outputStream<<"capacity:"<<object.capacity<<endl;
	
	return outputStream;
}
double Statistic::ortalama()const{
	double total;
	for(int i=0;i<size;i++){
		total+=array[i];
	}
	
	return total/size;
}
double Statistic::mod()const{
	double max=0;
	for(int i=0;i<size;i++){
		int temp=max;
		max=array[i];
		if(temp>max)
			max=temp;
	}
	
	return max;
}
double Statistic::medyan()const{
	double arr[size];
	for(int i=0;i<size;i++){
		arr[i]=array[i];
	}
	for(int i=0;i<size-1;i++){
		if(arr[i+1]<arr[i])
			arr[i]=arr[i+1];
	}
	if(size%2==0)
		return (arr[size/2]+arr[(size/2)-1])/2;
	return arr[(size/2)];
}

void Statistic::add(double number){
	if(capacity>size){
		array[size]=number;
		size+=1;
	}
	else
		cout<<"You dont add this in the array"<<endl;
	
}