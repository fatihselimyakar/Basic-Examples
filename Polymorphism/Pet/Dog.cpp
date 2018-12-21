#include "Dog.h"
void Dog::print()const{//virtual,override ve final'ın hepsi declaration kısmında oluyo IMPLEMENTTE DEGIL
    cout<<breed<<" "<<name<<endl;
    return;
}
Dog::Dog():Pet("NoName"){
    breed="NoBreed";
}
Dog::Dog(string name,string newBreed):Pet(name){
    breed=newBreed;
}
void Dog::Bas(){
	cout<<"cmasklkmcsalmkcs";
}
