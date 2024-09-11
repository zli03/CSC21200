/*

Write a program having a String class that contains a function that can reverse the order of the characters in a string.
A palindrome is a word or group of words that read the same forward and backward. For example “madam” or “wow”.
Write a program that takes a string argument from the command line and returns TRUE if the string is a palindrome.

*/

#include <iostream>

using namespace std;

int main()
{
	string Name = "Zi Xuan Li";

	cout << "==================================================================================" << endl;
	cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
	cout << "==================================================================================" << endl;

	string s, r = "";

	cout << "Enter a string: ";
	cin >> s;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
		r += s[i];
	}
	
	cout << "The reverse of the string you entered is " << r << endl;

	if (r == s)
		cout << "True, the string " << s << " is a palindrome" << endl;
	else
		cout << "False, the string " << s << " is not a palindrome" << endl;
}