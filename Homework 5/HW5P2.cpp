/*
* 2.Write a program that creates a stack container from a Singly Linked List.  Demonstrate using it by creating a stack of 9 car models. 
*/

#include <iostream>

using namespace std;

class Node
{
public:
	string data;
	Node* link;

	Node(string n)
	{
		this->data = n;
		this->link = NULL;
	}
};

class Stack
{
	Node* top;
	
public: 
	Stack() { top = NULL; }

	void push(string data)
	{
		Node* temp = new Node(data);
		if (!temp)
		{
			cout << "\nStack Overflow";
			exit(1);
		}
		temp->data = data;
		temp->link = top;
		top = temp;
	}

	void display()
	{
		Node* temp;

		if (top == NULL) {
			cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {

				cout << temp->data;

				temp = temp->link;
				if (temp != NULL)
					cout << " -> ";
			}
		}
	}
};

int main()
{
	string Name = "Zi Xuan Li";

	cout << "==================================================================================" << endl;
	cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
	cout << "==================================================================================" << endl;
	cout << "\n";
	Stack s;

	s.push("Sedan");
	s.push("Hatchback");
	s.push("Roadster");
	s.push("CUV");
	s.push("SUV");
	s.push("Pickup");
	s.push("Micro");
	s.push("Cabriolet");
	s.push("Supercar");

	s.display();

	cout << "\n";

	return 0;
}
