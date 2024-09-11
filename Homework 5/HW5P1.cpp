/*
* 1.Write a program that creates a singly link list of used automobiles containing nodes that describe the model name (string), price(int) and owner’s name.  
*   The program should create a list containing 12 nodes created by the user.  There are only three types of models (BMW, Cadillac, Toyota) and the prices 
*   range from $7500 – $20,500.  The program should allow the user to provide
•	Print a printout of all cars contained in the list (model, price, owner) – Print(list_ptr*)
•	Provide a histogram(global array) of all cars in the list portioned into $500 buckets
•	Find all cars that cost less $7500 - find_if( list_ptr*, int )
•	Calculate the average price of the cars contained in the list – avrg(list_ptr* )
•	Provide the details for all cars more expensive than the average price
•	Remove all nodes having a price less than 25% of average price – remove(list_ptr*, int average)
•	Print a printout of all cars contained in the updated list (model, price, owner)
*/

#include <iostream>

using namespace std;  

int histogramArr[12];  

class AutoMobile
{
public:         
	int price;         
	string name;         
	string owner;         
	AutoMobile* next;          
	
	AutoMobile()
	{
		price = 0;       
		name = "";             
		owner = "";             
		next = NULL;         
	}         

	AutoMobile(int cost,string car,string ownername)
	{             
		price = cost;             
		name = car;             
		owner = ownername;             
		next = NULL;         
	} 
};  
void carListPrint(AutoMobile* temp)
{
	while(temp)
	{
		cout << temp->name << " " << temp->price << " " << temp->owner << endl;         
		temp = temp->next;     
	}
	cout << endl; 
}

int getAveragePrice(AutoMobile* temp)
{     
	int sum = 0;     
	while(temp)
	{         
		sum += temp->price;         
		temp = temp->next;     
	}     
	int avg = sum/12;     
	return avg; 
}  

void getCarAboveAvg(AutoMobile* temp,int avg)
{     
	while(temp)
	{         
		if(temp->price > avg)             
			cout << temp->name << " " << temp->price << " " << temp->owner << endl;        
		temp = temp->next;     }cout << endl; 

}
AutoMobile* removeBelowAvgCar(AutoMobile* temp,int avg)
{     
	int c = (avg*25)/100;     
	cout << "25% of Average Price is - " << c << endl;     
	AutoMobile* head = temp;     
	AutoMobile* prev = temp;     
	AutoMobile* t = NULL;     
	temp = temp->next;     
	while(temp)
	{         
		if (temp->price < c)
		{
			prev->next = temp->next;             
			t = temp;             
			temp = temp->next;             
			delete t;         
		}
		else
		{             
			prev = temp;             
			temp = temp->next;         
		}    
	}     
	return head; 
}  

int main()
{
	string Name = "Zi Xuan Li";

	cout << "==================================================================================" << endl;
	cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
	cout << "==================================================================================" << endl;
	cout << "\n";

	AutoMobile* head = new AutoMobile(8500,"BMW","Tracy");    
	histogramArr[0] = 8500;     
	AutoMobile* car1 = new AutoMobile(10500,"Cadillac","Eva");     
	histogramArr[1] = 10500;     
	head->next = car1;     
	AutoMobile* car2 = new AutoMobile(11000,"Toyota","Leo");
	histogramArr[2] = 11000;     
	car1->next = car2;     
	AutoMobile* car3 = new AutoMobile(12500,"BMW","Marion");     
	histogramArr[3] = 12500;     
	car2->next = car3;     
	AutoMobile* car4 = new AutoMobile(10000,"Cadillac","Gabriel");     
	histogramArr[4] = 10000;     
	car3->next = car4;     
	AutoMobile* car5 = new AutoMobile(13500,"Toyota","Leroy");
	histogramArr[5] = 13500;     
	car4->next = car5;     
	AutoMobile* car6 = new AutoMobile(7500,"BMW","Amy");     
	histogramArr[6] = 7500;     
	car5->next = car6;     
	AutoMobile* car7 = new AutoMobile(8000,"Cadillac","Christie");     
	histogramArr[7] = 8000;     
	car6->next = car7;     
	AutoMobile* car8 = new AutoMobile(9000,"Toyota","Jeffrey");     
	histogramArr[8] = 9000;     
	car7->next = car8;     
	AutoMobile* car9 = new AutoMobile(13000,"BMW","Andrew");
	histogramArr[9] = 13000;     
	car8->next = car9;     
	AutoMobile* car10 = new AutoMobile(14500,"Cadillac","Joseph");
	histogramArr[10] = 14500;     
	car9->next = car10;     
	AutoMobile* car11 = new AutoMobile(15000,"Toyota","Brandon");
	histogramArr[11] = 15000;     
	car10->next = car11; 

	cout << "List Of all the cars is as follows - \n";     
	carListPrint(head);     

	int avg = getAveragePrice(head);     
	cout << "Average of all the cars price is - " << avg << endl;     
	cout << "List of all cars above the avg price is as follows - \n";    

	getCarAboveAvg(head,avg);     
	cout << "Removing all cars data whose price is less than 25% of the avg price\n";     

	head = removeBelowAvgCar(head,avg);     
	cout << "Updated List - \n";     

	carListPrint(head);     

	return 0; 
}
