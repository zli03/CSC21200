/*
Write a short program that reads phrases from the input stream and stores each new line into an array of  C++ strings.
For each new line, the program computes the numeric sum value of each phrase terminated with ‘\n’. For the following
section of the Gettysburg Address store the numeric values of each phrase into a int cnt[32] array.

“Four score and seven years ago our fathers brought forth upon this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal.
Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and so dedicated, can long endure.
We are met on a great battle-field of that war. We have come to dedicate a portion of that field, as a final resting place for those who here gave their lives that that nation might live.
It is altogether fitting and proper that we should do this. .”
*/

#include <iostream>
#include <string>

using namespace std;

int sumofascii(string phrase)
{
	int sum = 0;
	for (int i = 0; i <= phrase.size(); i++)
	{
		cout << (int)phrase[i] << ", ";
		sum = sum + phrase[i];
	}
	return sum;
}

int main()
{
	string Name = "Zi Xuan Li";

	cout << "==================================================================================" << endl;
	cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
	cout << "==================================================================================" << endl;

	string phrase[4] = {"Four score and seven years ago our fathers brought forth upon this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal.","Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and so dedicated, can long endure.","We are met on a great battle-field of that war. We have come to dedicate a portion of that field, as a final resting place for those who here gave their lives that that nation might live.","It is altogether fitting and proper that we should do this." };
	int cnt[32];

	for (int i = 0; i <= 3; i)
	{
		cnt[i] = sumofascii(phrase[i]);
		cout << "\nThe numeric sum value of the phrase: \"" << phrase[i] << "\" is: " << cnt[i] << endl;
		i++;
	}

	cout << "\nThe values stored in the array int cnt[32] is: ";
	for (size_t i = 0; i <= 3; i++) 
	{
		cout << cnt[i] << ' ';
	}

	return 0;
};