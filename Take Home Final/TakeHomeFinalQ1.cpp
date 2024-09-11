/*1.Two-dimensional matrices are employed in a wide variety of disciplines; seismology, digital displays, digital radiology, financial engineering, 
*	finite element analysis, etc.  Manipulating the data in large matrices(e.g. 100x100) can be a time consuming enterprise. Access and manipulation of 
*	the data in matrices is expedited by creating an array of pointers to the rows for a 2-D matrix, namely;
*
*		int M[N][M];		//2D matrix declaration
*		int *M_ptr[N];		//array of int pointers to rows
*	
*		for(int cnt = 0; cnt < N; cnt++)
*			M_ptr[cnt] = &M[cnt][0];
*
*	Create an 6 x12  int  M[6][12] whose elements represent rainfall for each month over 6 years.  
* 
*	a)	Write a function Populate(int *M_ptr[], int row, int col) that populates the rainfall for each month using a pseudo random number generator (PRNG).  
*		The C++ programming language provides a random function that provides such capability.
*			
*			#include <cstdlib>
*			srand(seed)  - primes the random generator 
*			seed – unsigned int (Prime number – pick 37)
*			unsigned in RV = rand( ) – returns a new random number(0-4Gig)
*			RV = RV % 75	- normalizes the numbers to be less than 50
* 
*	b)	Write a function YearAvrg(int *M_ptr[], int row, int col);that calculates the average rain   per year over 12 months and prints the value
* 
*	c)	Write a function MonthAvrg(int *M_ptr[], int row, int col) that prints the average rain per month over 5 years.
* 
*	d)	Find the total rainfall for year #3.
*/

#include <iostream>
#include <cstdlib> 
#include <string>

using namespace std;

void Populate(int* M_ptr[], int row, int col) 
{
    srand(37);
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            unsigned int RV = rand();
            RV = RV % 75;
            //unsigned int RV = rand() % 75;
            M_ptr[i][j] = RV;
        }
    }
}

void YearAvg(int* M_ptr[], int row, int col) {

    for (int i = 0; i < row; i++) 
    {
        int year_sum = 0; 
        for (int j = 0; j < col; j++) 
        {
            year_sum += M_ptr[i][j];
        }
        double year_avg = static_cast<double>(year_sum) / col;
        cout << "The average rainfall for year " << i + 1 << " is: " << year_avg << endl;
    }
}

void MonthAvg(int* M_ptr[], int row, int col) 
{
    for (int i = 0; i < col; i++) 
    {
        int month_sum = 0; 
        for (int j = 0; j < row; j++) 
        {
            month_sum += M_ptr[j][i];
        }
        double month_avg = static_cast<double>(month_sum) / row;
        cout << "The average rainfall for month " << i + 1 << " is: " << month_avg << endl;
    }
}

int main()
{
    string Name = "Zi Xuan Li";
    cout << "------------------------------------------------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE : " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    int M[6][12]{};
    int* M_ptr[6]{};

    for (int i = 0; i < 6; i++) {
        M_ptr[i] = M[i];
    }

    Populate(M_ptr, 6, 12);

    YearAvg(M_ptr, 6, 12);
    cout << endl;

    MonthAvg(M_ptr, 6, 12);
    cout << endl;

    int year_3_sum = 0; 
    for (int j = 0; j < 12; j++)
    {
        year_3_sum += M_ptr[2][j];
    }
    cout << "Total rainfall for year 3: " << year_3_sum << endl;

    return 0;
 }
 