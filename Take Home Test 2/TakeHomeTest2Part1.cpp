/* 1.The following code describes a class Queue for storing ints.  Template this class so that it can work with ints, floats, doubles, chars.
*   •	Demonstrate that your code can create a stack of floats(2.0, 4.0, 6.0, 8.0, 10.0)
*   •	Demonstrate that your code can create a stack of strings(‘A’, ‘B’, ‘C’, ‘D’, ‘E’, ‘F’)
*   •	Exercise all the member functions for this class for each of the two data type examples
*   •	Exercise the external function Foo( ) with int, float,  and char examples
*/

#include<iostream>
using namespace std;

template<class Type>
class queue
{
private:
    Type* arr;
    int front, rear;
    int MAX;

public:
    queue(int maxsize)
    {
        MAX = maxsize;
        arr = new Type[MAX];
        front = -1;
        rear = -1;
    }

    void addq(Type item)
    {
        if (rear == MAX - 1)
        {
            cout << "\nQueue is full";
            return;
        }
        rear++;
        arr[rear] = item;
        if (front == -1)
        {
            front = 0;
        }
    }

    Type delq()
    {
        Type data;
        if (front == -1)
        {
            cout << "\nQueue is Empty";
            return NULL;
        }
        data = arr[front];
        arr[front] = 0;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        return data;
    }
};

int main()
{
    string Name = "Zi Xuan Li";

    cout << "==================================================================================" << endl;
    cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "==================================================================================" << endl;
    cout << "\n";

    queue<int> a(10);
    a.addq(23);
    a.addq(9);
    a.addq(11);
    a.addq(22);
    a.addq(19);
    a.addq(30);
    a.addq(32);

    queue<float> b(5);
    b.addq(2.0);
    b.addq(4.0);
    b.addq(6.0);
    b.addq(8.0);
    b.addq(10.0);

    queue<double> c(5);
    c.addq(2.1);
    c.addq(4.3);
    c.addq(6.5);
    c.addq(8.7);
    c.addq(10.9);

    queue<char> d(6);
    d.addq('A');
    d.addq('B');
    d.addq('C');
    d.addq('D');
    d.addq('E');
    d.addq('F');

    int w = a.delq();
    cout << "Item deleted: " << w << endl;
    float x = b.delq();
    cout << "\nItem deleted: " << x << endl;
    float y = c.delq();
    cout << "\nItem deleted: " << y << endl;
    char z = d.delq();
    cout << "\nItem deleted: " << z << endl;

    return 0;
}
