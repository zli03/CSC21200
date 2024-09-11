/*

Write a function that takes as argument an array of integers and the size of the array and returns the average of the input values.
Example: Int = avrg(int * array, int size) 

*/

#include <iostream>

using namespace std;

int average(int* array, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];

	return (int)sum / size;
}

int main()
{
	string Name = "Zi Xuan Li";

	cout << "==================================================================================" << endl;
	cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
	cout << "==================================================================================" << endl;

	int array[] = { 1,2,3,4,5 }; 
	int size = sizeof(array) / sizeof(array[0]);

	cout << average(array, size) << endl;
	
	return 0;
}