#ifndef D_TIME_H
#define D_TIME_H

#include<iostream>
using namespace std;

class DigitalTime{
	public:
		DigitalTime();
		DigitalTime(int hour,int minute);
		
		int getHour()const{ return hour; }
		int getMinute()const{ return minute; }
		
		void advance(int minutesAdded);
        void advance(int hoursAdded, int minutesAdded);
		
		friend bool operator ==(const DigitalTime& time1,const DigitalTime& time2)
		{ return (time1.hour==time2.hour)&&(time1.minute==time2.minute); }
        
		friend istream& operator >>(istream& ins, DigitalTime& theObject);
        friend ostream& operator <<(ostream& outs, const DigitalTime& theObject);
	private:
		int hour;
		int minute;
		static void readHour(int& theHour);
		static void readMinute(int& theMinute);
		static int digitToInt(char c);
		

};


#endif