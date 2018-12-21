#include "Pet.h"

class Dog : public Pet{
public:
    Dog();
    Dog(string name,string newBreed);
    virtual void print()const override final;
	void bas();
private:
    string breed;
};
