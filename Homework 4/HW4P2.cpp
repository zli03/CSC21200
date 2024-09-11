/*
Two words are said to be anagrams if they contained the same characters but in different order – for instance “rescue” and “secure”.
Write a program that takes to strings and determines if they are anagrams of each other (hint – sort both words and check if they match)
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool Anagram(string str1, string str2)
{
	int n1 = str1.length();
	int n2 = str2.length();

	if (n1 != n2)
		return false;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	for (int i = 0; i < n1; i++)
		if (str1[i] != str2[i])
			return false;
	return true;
}

int main()
{
	string str1 = "";
	string str2 = "";
	string Name = "Zi Xuan Li";

	cout << "==================================================================================" << endl;
	cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
	cout << "==================================================================================" << endl;

	cout << "This program checks whether two strings are anagrams of each other" << endl;
	cout << "Enter a word for the first string: " << endl;
	cin >> str1;

	cout << "Enter another word for the second string: " << endl;
	cin >> str2;

	if (Anagram(str1, str2))
		cout << "The two strings are anagrams of each other.";
	else
		cout << "The two strings are not anagrams of each other.";

	return 0;
}
