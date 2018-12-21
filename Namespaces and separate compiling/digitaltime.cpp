#include"digitaltime.h"


inline DigitalTime::DigitalTime():hour(0),minute(0){/*int empty*/}

DigitalTime::DigitalTime(int newHour,int newMinute){
	if(newHour>24||newHour<0||newMinute<0||newMinute>60){
		cout<<"Error you entered wrong value"<<endl;
		exit(1);
	}
	else{
		hour=newHour;
		minute=newMinute;
	}
	if(hour==24)
		hour=0;
}

void DigitalTime::advance(int minutesAdded){
	int resultMinutes = minute + minutesAdded;
	minute = resultMinutes % 60;
	int resultHour = resultMinutes / 60;
    hour = (hour + resultHour)%24;
	
}

void DigitalTime::advance(int hoursAdded, int minutesAdded){
	advance(minutesAdded);
    hour = (hour+hoursAdded)%24;
}

ostream& operator <<(ostream& outs, const DigitalTime& theObject) {
      outs << theObject.hour << ':';
      if (theObject.minute < 10)
          outs << '0';
      outs << theObject.minute;
      return outs;
}

