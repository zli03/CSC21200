/*
What is the decimal base value of the following octal/hex constants?

042 = (0 × 8^2) + (4 × 8^1) + (2 × 8^0) = 34
0x42 = (4 × 16^1) + (2 × 16^0) = 66
0XFF = (15 × 16^1) + (15 × 16^0) = 255
0XCAB = (12 × 16^2) + (10 × 16^1) + (11 × 16^0) = 3243
*/

// Write a C++ program that calculates the sum of the first two values above using the twos-complement algorithm; int sum(int x, int y)

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int sum(int x, int y);

int main()
{
	int x, y, sumof;

	string Name = "Zi Xuan Li";

	cout << "==================================================================================" << endl;
	cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
	cout << "==================================================================================" << endl;

	cout << "Enter the first number: ";
	cin >> x;
	cout << "Enter the second number: ";
	cin >> y;

	sumof = sum(x, y);

	cout << "The Sum of " << x << " and " << y << " is: " << sumof << endl;

	string binary = bitset<16>(sumof).to_string();
	binary.erase(0, binary.find_first_not_of('0'));
	cout << "The Sum of " << x << " and " << y << " in binary is: " << binary << endl;

	return 0;
}

int sum(int x, int y)
{
	return (x + y);
}
