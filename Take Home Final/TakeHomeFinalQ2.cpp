/*1.Ernest Hemingway is considered to be one of America’s greatest writers. He  was known to have a writing style that was very simple but yet very powerful.  
*	A few phrases from the Intro to the  “The Old Man and the Sea” can be found in oldmanSea.txt
* 
*	Write a program that executes the following steps:
*	•	Reads the oldmanSea.txt and stores each word into a set<string> container Novel
*		o	Reading SunHem.txt should use:
*		o	getline(cin, WORD, ' ';
*		o	where WORD is a string
*
*	•	Calculates the total number of unique words in this text
*	•	Calculates the number of characters in each unique word and store this result I a histogram array, int Hist[20]
*		o	Hist[0] – contains the number of words having one character
*		o	Hist[1] – contains the number of words having two characters
*		o	               ::::::::::
*		o	Hist[6] = contains the number of words having seven characters
*		o	                etc, etc …
*	•	Print Histogram results
*	•	Calculates the number of words that start with an upper case letter (numerical value of first letter < 92 && letter > 64 ) – Prints result
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string Name = "Zi Xuan Li";
    set<string> Novel;
    string WORD;
    int wordCount = 0;

    cout << "------------------------------------------------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE : " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    ifstream cin("oldmanSea.txt");
    while (getline(cin, WORD, ' '))
    {
        if (WORD[0] > 64 && WORD[0] < 92)
        {
            wordCount++;
        }
        Novel.insert(WORD);
    }
    cin.close();

    size_t num_unique_words = Novel.size();
    cout << "Total number of unique words: " << num_unique_words << endl;

    int hist[20] = {0}; 

    for (const string& WORD : Novel) 
    {
        size_t word_length = WORD.length();
        if (word_length > 0 && word_length < 20) 
        {
            hist[word_length - 1]++; 
        }
    }
    cout << endl;

    cout << "Histogram of word lengths:" << endl;
    for (int i = 0; i < 20; i++) 
    {
        cout << i + 1 << ": " << hist[i] << endl;
    }

    cout << endl;

    cout << "Number of words starting with an upper case letter: " << wordCount << endl;

    return 0;
}
