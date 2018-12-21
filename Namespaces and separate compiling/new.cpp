
//Interface for the class DigitalTime.
#include <iostream>
using namespace std;

class DigitalTime
{
public:
  DigitalTime(int theHour, int theMinute);
  DigitalTime();                  //initializes time value to 0:00 midnight

  
  int getHour() const;
  int getMinute() const;
  void advance (int minutesAdded);        //changes time to minutesAdded minutes later
  void advance (int hoursAdded,int minutesAdded);  //changes time to hoursAdded hours + minutesAdded minutes later
  
  friend bool operator ==(const DigitalTime& time1,
              const DigitalTime& time2);
  friend istream& operator <<(istream& ins, DigitalTime& theObject);
  friend ostream& operator >>(ostream& outs,const DigitalTime& theObject);
  
//private:
  //member variables helping functions.not part of the public interface
  int hour;
  int minute;
  
  static void readHour(int& theHour);
  static void readMinute(int& theMinute);
  static int digitToInt(char c);//'c' is one of the digits '0' through '9'.
                //Returns the integer for the digit digitToInt('3') returns 3
                
  
};

//Implementation file dtime.cpp of the class DigitalTime
//The interface for the class is in the header file dtime.h
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

//uses iostream and cstdlib
DigitalTime::DigitalTime(int theHour,int theMinute){
  if(theHour<0 || theHour>24 || theMinute<0 || theMinute>59){
    cout<<"Illegal argument to DigitalTime constructor \n";
    exit(1);
  }
  else{
    hour=theHour;
    minute=theMinute;
    
  }
  
  if(hour==24)
    hour = 0;//standardize midnight as 0:00

}

DigitalTime::DigitalTime(){

  hour=0;
  minute=0;
}

int DigitalTime::getHour() const {

  return hour;
}

int DigitalTime::getMinute() const {

  return minute;
}

void DigitalTime::advance(int minutesAdded){

  int grossMinutes = minute + minutesAdded;
  minute = grossMinutes % 60;
  int hourAdjustment = grossMinutes /60;
  hour = (hour + hourAdjustment) % 24;
  
}


void DigitalTime::advance(int hoursAdded,int minutesAdded){

  hour= (hour + hoursAdded) % 24;
  advance(minutesAdded);

}

bool operator ==(const DigitalTime& time1,const DigitalTime& time2){

  return (time1.hour==time2.hour && time1.minute==time2.minute);

}

//uses iostream:
ostream& operator<<(ostream& outs, const DigitalTime& theObject){

  outs<< theObject.hour << ':';
  if(theObject.minute < 10)
    outs<< '0';
  outs << theObject.minute;
  return outs;

}

//uses iostream:
istream& operator>>(istream& ins, DigitalTime& theObject){

  DigitalTime::readHour(theObject.hour);
  DigitalTime::readMinute(theObject.minute);
  return ins;
  
}

int DigitalTime::digitToInt(char c){

  return (static_cast<int>(c) - static_cast<int>('0'));
}

//uses iostream, cctype, and cstdlib:
void DigitalTime:: readMinute(int& theMinute){

  char c1,c2;
  cin >> c1 >> c2;
  
  if(!(isdigit(c1) && isdigit(c2))){
  
    cout << "Error! illegal input to readMinute\n";
    exit(1);
  }
  theMinute = digitToInt(c1)*10 + digitToInt(c2);
  
  if(theMinute < 0 || theMinute > 59){
    
    cout << "Error! illegal input to readMinute\n";
    exit(1);
  }
}

//uses iostream,cctype and cstdlib:
void DigitalTime::readHour(int& theHour){
  
  char c1,c2;
  cin >> c1 >> c2;
  if(!((isdigit(c1) && isdigit(c2))|| (c2 == ':'))){
  
    cout << "Error! illegal input to readHour\n";
    exit(1);  
  
  }
  
  if(isdigit(c1) && c2 == ':'){
    
    theHour = DigitalTime::digitToInt(c1);
    
  }
  
  else { // isdigit(c1)&&isdigit(c2)
    
    theHour = DigitalTime::digitToInt(c1)*10
           + DigitalTime::digitToInt(c2);
           
      cin >> c2; //discard':'  
      
    if(c2 != ':'){
    
    cout << "Error! illegal input to readHour\n";
    exit(1);    
    
    }
  
  }
  
  if(theHour == 24)
    theHour= 0; //standardize midnight 0:00
  
  if(theHour<0 || theHour>23){
    
    cout << "Error! illegal input to readHour\n";
    exit(1);    
    
  }
  

}

//This is the application file timedemo.cpp,which demonstrates use of
//DigitalTime.

#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main(){
  

  DigitalTime clock,oldClock;
  
  cout << "you may write midnight as  0:00 or 24:00.\n"
    << "but i will always write it as 0:00.\n"
    << "Enter the time in 24 hour notation:";
    
  cin >> clock;
  
  oldClock = clock;
  clock.advance(15);
  if(clock == oldClock)
    cout<<"Something is wrong.";
    
  cout << "You entered " << oldClock << endl;
  cout << "15 minutes later the time will be "
     << clock << endl;
     
  clock.advance(2,15);   
  cout << " 2hours and 15 minutes after that \n"
     << "The time will be "
     << clock << endl;
     
  return 0;
     
}