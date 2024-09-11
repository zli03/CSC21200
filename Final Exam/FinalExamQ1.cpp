#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
    string Name = "Zi Xuan Li";

    cout << "------------------------------------------------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE : " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    multimap<string, int> Auto = {
        {"Cadillac", 8},
        {"BMW", 3},
        {"Mercedes", 8},
        {"Toyota", 6},
        {"Honda", 5},
        {"Hyundai", 7},
        {"Yugo", 4},
        {"Ford", 4},
        {"GM", 2},
        {"Bentley", 7},
        {"Ferrari", 7},
        {"Alpha-Romeo", 12},
        {"Pugeot", 6},
        {"Jaguar", 6},
        {"Oldsmobile", 10},
        {"Rolls-Royce", 12},
        {"Saab", 4},
        {"Mercury", 7},
        {"Nissan", 6},
        {"Datsun", 6}
    };

    multimap<string, int>::iterator itr;

    cout << "Car names and lengths:" << endl;
    for (itr = Auto.begin(); itr != Auto.end(); ++itr)
    {
        cout << itr->first << ": " << itr->second << endl;
    }
    
    cout << "\nCars with word-length > 5:" << endl;
    for (itr = Auto.begin(); itr != Auto.end(); ++itr) 
    {
        if (itr->second > 5) 
        {
            cout << itr->first << endl;
        }
    }
    
    vector<int> Total;
    for (itr = Auto.begin(); itr != Auto.end(); ++itr) 
    {
        int sum = 0;
        for (char c : itr->first) 
        {
            sum += c;
        }
        Total.push_back(sum);
    }
    
    cout << "\nNumerical sums of car names:" << endl;
    for (int sum : Total) {
        cout << sum << endl;
    }

    int sum = std::accumulate(Total.begin(), Total.end(), 0);
    double Mean = static_cast<double>(sum) / Total.size();
    cout << "\nMean value of numerical sums: " << Mean << endl;

    std::cout << "\nCars with numerical values > Mean:" << endl;
    for (itr = Auto.begin(); itr != Auto.end(); ++itr) {
        int sum = 0;
        for (char c : itr->first) 
        {
            sum += c;
        }
        if (sum > Mean) {
            std::cout << itr->first << endl;
        }
    }
    return 0;
}
