#include "Pet.h"
Pet::Pet(string newName){
    name=newName;
}
Pet::Pet(){
    name="NoName";
}
void Pet::print()const{
    cout<<name<<endl;
    return;
}
