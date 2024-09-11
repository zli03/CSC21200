#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	string Name = "Zi Xuan Li";

    cout << "------------------------------------------------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE : " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    multimap<string, int> Novel = {};
    string myword = "";
    int wordsize = 0;

    ifstream myfile("Smiley.txt");
    while(getline(myfile, myword, ' '))
    {
        int wordsize = myword.length();
        Novel.insert(pair<string, int>(myword, wordsize));
    }
    myfile.close();

    map<string, int>::iterator itr;

    for (itr = Novel.begin(); itr != Novel.end(); ++itr) 
    {
        cout << itr->first << ": " << itr->second << endl;
    }

    int wordlongest = 0;
    for (itr = Novel.begin(); itr != Novel.end(); ++itr) 
    {
        if (itr->second > wordlongest) 
        {
            wordlongest = itr->second;
        }
    }
    cout << "Longest word: " << wordlongest << endl;

    vector<int> histogram(wordlongest, 0);
    for (itr = Novel.begin(); itr != Novel.end(); ++itr) 
    {
        histogram[wordsize - 1]++;
    }

    for (int i = 0; i < wordlongest; i++) {
        cout << i + 1 << ": " << histogram[i] << endl;
    }

    for (itr = Novel.begin(); itr != Novel.end(); ++itr) {
        if (itr->second > 10) {
            cout << itr->first << endl;
        }
    }
    return 0;
}
