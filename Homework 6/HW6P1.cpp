/*
* 1.Write a program that implements a binary tree having nodes that contain the following items: (i) Fruit name (ii) price per lb.  
*   The program should allow the user to input any fruit name (duplicates allowed), price.  The root node should be initialized to 
*   {“Lemon” , $3.00}.  The program should be able to do the following tasks:
*   •   create a basket of 16 fruits/prices
*   •	list all the fruits created (name/price)
*   •	calculate the average price of the basket
*   •	print out all fruits having the first letter of their name >= ‘L’
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
double avg_price = 0; 
int Cnt = 0;

struct Node {    
    string fruit_name;
    double fruit_price;
    struct Node* left;
    struct Node* right;

    Node(string name, double price) 
    {   
        fruit_name = name;
        fruit_price = price;
        left = NULL;
        right = NULL;
    }
};

void basket(Node* root) {    

    if (root == NULL)  
        return;

    basket(root->left); 

    cout << root->fruit_name << " " << "$" << root->fruit_price << ", ";  

    basket(root->right);  
}

double average_price(Node* root)  
{
    if (root == NULL)         
        return 0;

    avg_price += root->fruit_price;  

    average_price(root->left);
    average_price(root->right);

    return (avg_price /Cnt);    
}

void l_name(Node* root) {    

    if (root == NULL)
        return;

    if (root->fruit_name[0] == 'L')   
        cout << root->fruit_name << " ";   

    l_name(root->left);
    l_name(root->right);

}

int main() 
{
    string Name = "Zi Xuan Li";

    cout << "==================================================================================" << endl;
    cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "==================================================================================" << endl;
    cout << "\n";

    struct Node* root = new Node("Lemon", 3);
    Cnt++;
    string name;
    double price;

    cout << "Enter the name of 15 fruits and their prices" << endl;
    cin >> name >> price;
    root->left = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->right = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->left->left = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->left->right = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->right->left = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->right->right = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->left->left->left = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->left->left->right = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->left->right->left = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->left->right->right = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->right->left->left = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->right->left->right = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->right->right->left = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->right->right->right = new Node(name, price);
    Cnt++;
    cin >> name >> price;
    root->left->left->left->left = new Node(name, price);
    Cnt++;

    cout << "\nFruits in the basket :" << endl;

    basket(root);
    cout << endl;

    cout << "\nAverage price of the basket = " << average_price(root) << endl;

    cout << "\nFruits having first letter of their name => 'L' are shown below:" << endl;
    l_name(root);
    cout << endl;

    return 0;
}