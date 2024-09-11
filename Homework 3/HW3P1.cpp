#include <iostream>  

using namespace std;

class Animal
{
private:
	double weight;
	int age;
public:
	Animal(double weight, int age)
	{
		this->weight = weight;
		this->age = age;
	}
	void eat()
	{
		cout << "I can eat" << endl;
	}
	void sleep()
	{
		cout << "I can sleep" << endl;
	}
	void showData()
	{
		cout << "Weight: " << weight << " ";
		cout << "Age: " << age << endl;
	}
};

class Dog : public Animal
{
private:
	string species;
public: 
	Dog(string species, double weight, int age) : Animal(weight, age)
	{
		this->species = species;
	}
	void showData()
	{
		cout << "I am a dog and my species is " << this->species << endl;
	}
};

int main()
{
	string Name = "Zi Xuan Li";

	cout << "==================================================================================" << endl;
	cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
	cout << "==================================================================================" << endl;

	Animal a1(40, 5);
	a1.showData();
	Dog d1("bulldog", 50, 10);
	d1.eat();
	d1.sleep();
	d1.showData();

	return 0;
}