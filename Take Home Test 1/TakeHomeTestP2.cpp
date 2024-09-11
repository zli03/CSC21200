/*
* 2.Write a program that creates a class Shape that contains the following private member data:
* •	int x,y
* •	Color X (R,O,Y,G,B,I,V) – Color is an enumerator data type
* •	static int Cnt – total count of how many shapes exist
* •	int Id (set to Cnt)
*   and the usual member functions:
* •	Default Constructor
* •	Parametrized Constructor
* •	Destructor
* •	Copy Constructor
* •	Overloaded assignment operator=( )
* •	Calculate distance( ) from origin (sqrt(x*x+y*y) )
* •	Print( ) – prints the (x,y) coordinates, Color and Id of a specific Shape
* •	The constructors/destructor/copy constructor and assignment operators should provide messages
*
*   After creating the Shape class, you should create:
* • a  Square class derived publicly from Shape. The Square class should have a  private member, Len.
* •	a  Triangle class derived publicly from Shape. The Triangle class should have private member, Base, Heigh.
* •	The two derived classes should provide the following member functions:
* o	Default constructors – print message
* o	Parametrized constructors – print message
* o	Copy constructors – print message
* o	Overloaded assignment operators operator=() – print message
* o	Float CalcArea( ) – calculates the area for specific derived object
* o	Print( ) – prints the Shape attributes and specific derived attributes of the derived object (e.g. Radius for Circle, Len/Width for Rectangle)
* •	Demonstrate the followings
* o	Shape X, Amoeba(3,4, ‘Y’)
* o	Square C1(3,4,’B’,5) – blue square located at (5,6) of side=5
* o	Square C2(15, 20, ’Y’,10) – yellow square located at (15,20) of side =10
* o	Triangle T(12, 5, ‘V’, 8,4) – Violet triangle located at (12,5) of dimension (8,4)
* o	Calculate the Area of each derived object; float CalcArea( )
* o	For all created objects use the appropriate Print functions
* o	Calculate and print the distance between C1 and C2 – use the respective (x,y) locations
* o	Calculate the distance from origin for C1, C2 and T
* o	Print the total number of created shapes
*/

#include <iostream>
#include <math.h>
using namespace std;

enum Color { R, O, Y, G, B, I, V };

class Shape
{
protected:
	int x, y;
	Color X;
	static int Cnt;
	int Id;

public:
	Shape() : x(0), y(0), X(R), Id(Cnt)
	{
		//cout << "Default constructor" << endl;
	}

	Shape(int x, int y, Color X) : x(x), y(y), X(X), Id(Cnt)
	{
		//cout << "Parametrized constructor" << endl;
	}

	Shape(const Shape& S)
	{
		x = S.x;
		y = S.y;
		X = S.X;
		Id = Cnt;
		//cout << "Copy constructor" << endl;
	}

	~Shape()
	{
		x = x;
		y = y;
		X = R;
		Id = Cnt;
		//cout << "Destructor" << endl;
	}

	Shape& operator=(const Shape& S)
	{
		if (this != &S) {
			x = S.x;
			y = S.y;
			X = S.X;
			Id = Cnt;
		}
		return *this;
	}

	float distance()
	{
		return sqrt(x * x + y * y);
	}

	void Print()
	{
		cout << "(" << x << "," << y << ") " << "[" << X << "] " << endl;
	}
};

int Shape::Cnt;

class Square : public Shape {
protected:
	int Len;

public:
	Square() : Shape(), Len(0)
	{
		//cout << "Default constructor" << endl;
	}

	Square(int x, int y, Color X, int Len) : Shape(x, y, X), Len(Len)
	{
		//cout << "Parametrized constructor" << endl;
	}

	Square(const Square& S) : Shape(S)
	{
		Len = S.Len;
		//cout << "Copy constructor" << endl;
	}

	Square& operator=(const Square& S)
	{
		if (this != &S) {
			Shape::operator=(S);
			Len = S.Len;
		}
		return *this;
	}

	float CalcArea()
	{
		return Len * Len;
	}

	void Print()
	{
		Shape::Print();
		cout << "Len = " << Len << endl;
	}
};

class Triangle : public Shape
{
protected:
	int Base, Height;

public:
	Triangle() : Shape(), Base(0), Height(0)
	{
		//cout << "Default constructor" << endl;
	}

	Triangle(int x, int y, Color X, int Base, int Height) : Shape(x, y, X), Base(Base), Height(Height)
	{
		//cout << "Parametrized constructor" << endl;
	}

	Triangle(const Triangle& T) : Shape(T)
	{
		Base = T.Base;
		Height = T.Height;
		//cout << "Copy constructor" << endl;
	}

	Triangle& operator=(const Triangle& T)
	{
		if (this != &T) {
			Shape::operator=(T);
			Base = T.Base;
			Height = T.Height;
		}
		return *this;
	}

	float CalcArea()
	{
		return (Base * Height) / 2;
	}

	void Print()
	{
		Shape::Print();
		cout << "Base = " << Base << " Height = " << Height << endl;
	}
};

int main()
{
	string Name = "Zi Xuan Li";

	cout << "------------------------------------------------------------------------------\n";
	cout << "Name: " << Name << endl;
	cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
	cout << "------------------------------------------------------------------------------\n";

	Shape X, Amoeba(3, 4, Y);
	Square C1(3, 4, B, 5);
	Square C2(15, 20, Y, 10);
	Triangle T(12, 5, V, 8, 4);

	cout << "Square C1 Data" << endl;
	C1.Print();
	cout << "\nSquare C2 Data" << endl;
	C2.Print();
	cout << "\nTriangle T Data" << endl;
	T.Print();

	cout << "\nArea of C1: " << C1.CalcArea() << endl;
	cout << "\nArea of C2: " << C2.CalcArea() << endl;
	cout << "\nArea of T: " << T.CalcArea() << endl;

	cout << "\nDistance between C1 and C2: " << sqrt((3 - 15) * (3 - 15) + (4 - 20) * (4 - 20)) << endl;

	cout << "\nDistance from origin for C1: " << C1.distance() << endl;
	cout << "\nDistance from origin for C2: " << C2.distance() << endl;
	cout << "\nDistance from origin for T: " << T.distance() << endl;

	cout << "\nTotal number of created shapes is 4" << endl;

	return 0;
}
