/*2.Create the following HashTable demo according to the following instructions:
*	a.	Use the following struct template to create nodes that contain a string and a price
*	struct Node{
*		string auto;		//name
*		int price;		//#Autos
*	}; 
* 
*	b.	Create a Node Auto array(e.g. Node Auto[21]) and initialize it  with the following Auto names  and price values:
*		o	“BMW(32000)”,  “Cadillac(22000)”, “Toyota(33000)”, “Honda(24000)”, “KIA(18000)”, 
*		o	“Ferrari(66000)”, “GM(27000)”, “Hyundi(28000)”, ”Jaguar(900000)” “Bentley(15000)”, Lemon(11000)”, “Mercedes(123000)”, “Nissan(37000)”, “Opel(34000)”,
*			“Peugeot(35000)”, “Rolls(170000)”, “Subaru(28000)”, “TNT(19000)”,  ”VW(29000)”, “Yves(21500)”  
*
*	c.	Create a HashArray[Size = 13] that stores pointers to  array of Nodes  
*		o	Node * HashArray[13];
*		o	Each pointer(e.g. HashArray[i]  = new Node[10]) contains the address to an array of Node pointers  provided by the heap where 10 Auto Nodes are stored.
*		o	Initialize each Auto Node  stored on the heap to have price = 0;
* 
*	d.	For each input Auto[i], exercise the HashFunction(“auto name”) which  calculates the numerical sum of  each item name % 13. 
*		o	The value produced is the key(index)  into the HashArray.
* 
*	e.	Using the calculated key[index}, store the respective Auto[i] values(e.g. item, pricet) into the next free entry  Node 
* 
*	f.	After storing all (item/price)  values in the HashArray table,  print the entire HashArray  table  for only the occupied nodes.
* 
*	g.	Create a Historgram array(Size = 13) whose elements  contains the number of occupied Nodes in HashArray.
* 
*	h.	Print the Histogram array indicating how many entries are associated with each count. 
* 
*	i.	 Test whether the following autos exist as entries in the HashTable and indicate the index[key] , item and price
*		o	“Dodge”, “GM”, “Toyota”, “AlphaRomeo”, “Ferrari”, “Opel”, “Mercedea”, “Subaru”
*		o	If the test auto name does not exist in the HashTable, print a message that the auto could not be found in calculated (key)index.
*/

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string Auto; 
    int price = 0;          
};

Node Auto[21] = {{"BMW", 32000}, {"Cadillac", 22000}, {"Toyota", 33000}, {"Honda", 24000}, {"KIA", 18000}, {"Ferrari", 66000}, {"GM", 27000}, {"Hyundi", 28000}, {"Jaguar", 900000}, {"Bentley", 15000}, {"Lemon", 11000}, {"Mercedes", 123000}, {"Nissan", 37000}, {"Opel", 34000}, {"Peugeot", 35000}, {"Rolls", 170000}, {"Subaru", 28000}, {"TNT", 19000}, {"VW", 29000}, {"Yves", 21500}};

int HashFunction(string Auto)
{
    int sum = 0;
    for (char c : Auto)
    {
        sum += c;
    }
    return sum % 13;
}

int main()
{
    string Name = "Zi Xuan Li";

    cout << "==================================================================================" << endl;
    cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "==================================================================================" << endl;
    cout << "\n";

    Node* HashArray[13]{};
    for (int i = 0; i < 13; i++)
    {
        HashArray[i] = new Node[10];
    }

    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            HashArray[i][j].price = 0;
        }
    }

    for (int i = 0; i < 21; i++)
    {
        int key = HashFunction(Auto[i].Auto);
        int j = 0;
        while (HashArray[key][j].price != 0)
        {
            j++;
        }
        HashArray[key][j] = Auto[i];
    }

    cout << "Hash Array:" << endl;
    for (int i = 0; i < 13; i++)
    {
        cout << "HashArray[" << i << "]: ";
        for (int j = 0; j < 10; j++)
        {
            if (HashArray[i][j].price != 0)
            {
                cout << HashArray[i][j].Auto << "(" << HashArray[i][j].price << ") ";
            }
        }
        cout << endl;
    }

    int Histogram[13] = { 0 };
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (HashArray[i][j].price != 0)
            {
                Histogram[i]++;
            }
        }
    }

    cout << "\nHistogram:" << endl;
    for (int i = 0; i < 13; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < Histogram[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    cout << endl;

    string testAutos[8] = {"Dodge", "GM", "Toyota", "AlphaRomeo", "Ferrari", "Opel", "Mercedea", "Subaru"};
    for (string Auto : testAutos)
    {
        int key = HashFunction(Auto);
        bool found = false;
        for (int j = 0; j < 1; j++)
        {
            if (HashArray[key][j].Auto == Auto)
            {
                found = true;
                cout << Auto << " found at index " << key << " with price " << HashArray[key][j].price << endl;
            }
            else
            {
                cout << Auto << " could not be found in calculated (key)index" << endl;
            }
        }
    }
    return 0;
}
