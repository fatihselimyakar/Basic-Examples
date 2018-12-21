#include<iostream>
using namespace std;

class Pet{
public:
    Pet();
    Pet(string newName);
    virtual void print()const;
protected:
    string name;
};
