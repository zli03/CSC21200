#include <iostream>  

using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;
public:
	Date(int month, int day, int year)
	{
		this->month = month;
		this->day = day;
		this->year = year;
	}
	void showData()
	{
		cout << "Date: " << month << " " << day << " " << year << endl;
	}
};

class Employee : public Date
{
private:
	string name;
	long float salary;
	int month;
	int day;
	int year;
public:
	Employee(string name, long float salary, int month, int day, int year) : Date(month, day, year)
	{
		this->name = name;
		this->salary = salary;
		this->month = month;
		this->day = day;
		this->year = year;
	}
	void showData()
	{
		cout << "Name: " << this->name << endl;
		cout << "Salary: " << this->salary << endl;
		cout << "Date of birth: " << month << " " << day << " " << year << endl;
	}
};

struct Dates
{
	int d, m, y;
};

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };

int leapYears(Dates d)
{
	int years = d.y;
	if (d.m <= 2)
		years--;
	return years / 4
		- years / 100
		+ years / 400;
}

int dateDifference(Dates dt1, Dates dt2)
{
	long int n1 = dt1.y * 365 + dt1.d;
	for (int i = 0; i < dt1.m - 1; i++)
		n1 += monthDays[i];
	n1 += leapYears(dt1);
	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i < dt2.m - 1; i++)
		n2 += monthDays[i];
	n2 += leapYears(dt2);

	return(n2 - n1);
}

int main()
{
	string Name = "Zi Xuan Li";

	cout << "==================================================================================" << endl;
	cout << Name << " File: " << __FILE__ << " Date: " << __DATE__ << endl;
	cout << "==================================================================================" << endl;

	Date d1(9, 20, 2022);
	d1.showData();
	Employee e1("George", 75000.25, 6, 10, 1998);
	e1.showData();

	Dates dt1 = { 10, 6, 1998 };
	Dates dt2 = { 20, 9, 2022 }; 

	cout << "The difference between the two dates in terms of days is " << dateDifference(dt1, dt2);

	return 0;
}
