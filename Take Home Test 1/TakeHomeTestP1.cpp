/*
* 1.Write a program that creates an Integer class Time which contains a pair of Times – (integers), H and M.  The class should contain the following member and friend functions
•	Default constructor (sets H=0, M=0) – print message
•	Parametrized constructor (int h1 , int m2) – print message
•	Copy constructor( ) – print message
•	Destructor( ) – print message
•	Overloaded assignment operator=(const Time &rhs ) – print message
•	Overloaded summation operator+( const Time &rhs ) – adds two times (min % 60)
•	Overloaded difference operator-( const Time &rhs ) – subtracts two times (min % 60)
•	friend function output ostream & operator<<(ostream & os,  const Time &rhs ) – outputs time value
•	void setValue(int H1, int M2) – sets H1 and M2 to argument values
•	This class should contain two private(protected) integer member variables (H,M) that represent a Time value(hour/min) – the largest time can be 23 hours, 59 min
*
*   Demonstrate the following items:
•	Time  A(13,4), B(4,15), C, D;
•	C = A + B;
•	Print C
•	D = A - B;
•	Print D
•	D = A*5;
•	Print D
•	D = 5*A;
•	Print D
•	Recall that all Times have to be mod (%) to 23 hours and 59 min
•	-----------------------------------------------------------
•	Time X_Array[5], Y_Array[5], Z_Array[5];	//create  complex arrays of 5 complex elements - stack
•	Init X_Array: (10,10),(12,12),(14,14)(16,16), (20,20)
•	Init Y_Array: (15,15),(17,17),(19,19), (21,21), (23,23)
•	Calculate  Z_Array[i]  = X_Array[i] + Y_Array[i];  0 <= i <=5
•	Print Z_Array[i]
•	Calculate  Z_Array[i]  = X_Array[i]  -  Y_Array[i];  0 <= i <=5
•	Print Z_Array[i]
•	Calculate  Z_Array[i]  = X_Array[i] * 5;  0 <= i <=5
•	Print Z_Array[i]
•	Calculate  Z_Array[i]  = 5*X_Array[i];  0 <= i <=5
•	Print Z_Array[i]
•	Create  an array of 3 Time objects on the heap
•	Init the created Time array to have values (3*i, 5*i); 0 <= i <=3
•	Print the Time Array on the heap
*/

#include <iostream>

using namespace std;

class Time
{
private:
    int H;
    int M;

public:
    Time()
    {
        H = 0;
        M = 0;
        //cout << "Default constructor" << endl;
    }

    Time(int h, int m)
    {
        H = h;
        M = m;
        //cout << "Parametrized constructor" << endl;
    }

    Time(const Time& t)
    {
        H = t.H;
        M = t.M;
        //cout << "Copy constructor" << endl;
    }

    ~Time()
    {
        H = 0;
        M = 0;
        //cout << "Destructor" << endl;
    }

    void setvalue(int h1, int m2)
    {
        H = h1;
        M = m2;
    }

    void print()
    {
        cout << H << ":" << M << endl;
    }

    Time operator+(Time t)
    {
        Time sum;
        sum.H = H + t.H;
        sum.M = M + t.M;
        if (sum.M >= 60)
        {
            sum.M -= 60;
            sum.H++;
        }
        if (sum.H > 23)
        {
            sum.H -= 24;
        }
        return sum;
    }

    Time operator-(Time t)
    {
        Time diff;
        int t1, t2;
        t1 = H * 60 + M;
        t2 = t.H * 60 + t.M;
        diff.M = (t1 - t2) % 60;
        diff.H = (t1 - t2) / 60;
        if (diff.M < 0)
        {
            diff.M = 60 + diff.M;
            diff.H--;
        }
        if (diff.H < 0)
        {
            diff.H = 24 + diff.H;
        }

        return diff;
    }

    friend ostream& operator<<(ostream& os, Time t)
    {
        os << t.H << ":" << t.M;

        return os;
    }

    Time operator*(int n)
    {
        Time prod;
        int t1;
        t1 = H * n * 60 + M * n;
        prod.M = (t1) % 60;
        prod.H = (t1) % 24;
        return prod;
    }

    friend Time operator*(int n, Time t);
};

Time operator*(int n, Time t)
{
    Time prod;
    int t1;
    t1 = t.H * n * 60 + t.M * n;
    prod.M = (t1) % 60;
    prod.H = (t1) % 24;
    return prod;
}

int main()
{
    string Name = "Zi Xuan Li";

    cout << "------------------------------------------------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    Time A(13, 4), B(4, 15), C, D;

    cout << "Printing C = A + B" << endl;
    C = A + B;
    cout << "C = " << C << endl;

    cout << "\nPrinting D = A - B" << endl;
    D = A - B;
    cout << "D = " << D << endl;

    cout << "\nPrinting C = A * 5" << endl;
    D = A * 5;
    cout << "D = " << D << endl;

    cout << "\nPrinting C = 5 * A" << endl;
    D = 5 * A;
    cout << "D = " << D << endl;

    Time x[5] = { Time(10, 10), Time(12, 12), Time(14, 14), Time(16, 16), Time(20, 20) };
    Time y[5] = { Time(15, 15), Time(17, 17), Time(19, 19), Time(21, 21), Time(23, 23) };
    Time z[5];

    for (int i = 0; i < 5; i++)
    {
        z[i] = x[i] + y[i];
    }

    cout << "\nPrinting z[i] = x[i] + y[i]" << endl;
    for (int i = 0; i < 5; i++)
    {
        z[i].print();
    }

    for (int i = 0; i < 5; i++)
    {
        z[i] = x[i] - y[i];
    }

    cout << "\nPrinting z[i] = x[i] - y[i]" << endl;
    for (int i = 0; i < 5; i++)
    {
        z[i].print();
    }

    for (int i = 0; i < 5; i++)
    {
        z[i] = x[i] * 5;
    }

    cout << "\nPrinting z[i] = x[i] * 5" << endl;
    for (int i = 0; i < 5; i++)
    {
        z[i].print();
    }

    for (int i = 0; i < 5; i++)
    {
        z[i] = 5 * x[i];
    }

    cout << "\nPrinting z[i] = 5 * x[i]" << endl;
    for (int i = 0; i < 5; i++)
    {
        z[i].print();
    }

    Time* heapArray = new Time[3];

    for (int i = 0; i < 3; i++)
    {
        heapArray[i] = Time(3 * i, 5 * i);
    }

    cout << "\nArray on heap" << endl;
    for (int i = 0; i < 3; i++)
    {
        heapArray[i].print();
    }

    return 0;
}