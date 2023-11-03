#include <iostream>
#include <string>
#include<fstream>

using namespace std;

  
class Animal{
  public:
    Animal(){}
    virtual ~Animal(){cout <<"Animal deconstructor called"<< endl;}
    virtual void speak() {cout<<"no sound"<<endl;}
};
class Dog: public Animal{
  public:
    Dog(): Animal(){}
    virtual ~Dog(){cout <<"Dog deconstructor called"<< endl;}
    void speak(){cout<<"bark"<<endl;}
};
class Cat: public Animal{
  public:
    Cat(): Animal(){}
    virtual ~Cat(){cout <<"Cat deconstructor called"<< endl;}
    void speak(){cout<<"meow"<<endl;}
};
class Duck: public Animal{
  public:
    Duck(): Animal(){}
    virtual ~Duck(){cout <<"Duck deconstructor called"<< endl;}
    void speak(){cout<<"quack"<<endl;}
};

int main(){
  Animal* p_animal = new Animal();
  p_animal->speak();
  p_animal= new Dog();
  p_animal->speak();
  p_animal= new Cat();
  p_animal->speak();
  p_animal= new Duck();
  p_animal->speak();
}
