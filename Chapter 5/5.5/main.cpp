/*Compute X * Y Without Arithmetical Operators*/
/*Does not work*/

#include <iostream> 
#include <cmath>

using namespace std;

int multiply(int X, int Y); 

int main()
{
	int X, Y; 
	int result; 

	cout << "Enter the numbers you want to multiply: " << endl; 
	cin >> X; 
	cin >> Y; 

	result = multiply(X, Y);

	cout << "The result is " << result << endl; 

	return 0; 
}

int multiply(int X, int Y)
{
	int msb1 = X;
	int msb2 = Y; 
	int num_of_shifts1 = 0; 
	int num_of_shifts2 = 0; 
	int clear_msb = 1;
	int new_num; 

/*	while (msb1 != 1)
	{
		msb1 = msb1 >> 1;
		num_of_shifts1++; 
	}

	msb1 = msb1 << num_of_shifts1; 
	cout << msb1 << endl; */

	while (msb2 != 0)
	{
		if ((msb2 & 1) != 0)
		{
			msb1 = msb1 << num_of_shifts2;
			//add here
		}

		msb2 = msb2 >> 1;
		num_of_shifts2++; 
	}

	/*cout << msb1 << endl; 

	X = X ^ (clear_msb << num_of_shifts1); 

	cout << X << endl; 
	new_num = msb1 | X; */
	new_num = msb1; 

	return new_num;  
}

int add (int val1, int val2)
{

}