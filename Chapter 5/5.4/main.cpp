/*Find Closest Interger with the Same Weight*/
/*Write a program which takes as input a nonnegative integer x and returns a number y which
is not equal to x, but has the same weight as x and their difference, |y - x|, is as small
as possible*/

/*Time Complexity*/
/*Worst Case: O(n)*/
/*Best Case: O(1)*/
/*n = integer width*/

#include <iostream> 
#include <cmath>

using namespace std; 

unsigned int same_weight (unsigned int input);

int main()
{
	unsigned int input; 

	cout << "Enter an input value: ";
	cin >> input; 

	input = same_weight(input); 

	cout << input << " has the same weight" << endl; 

	return 0; 
}

unsigned int same_weight (unsigned int input)
{
	int power_of_two = 0;
	int set; 

	do
	{
		set = input & (int)pow(2, power_of_two);

		if (set)
		{
			//Check trailing 0 and front 0
			if (!(input & (int)pow(2, power_of_two - 1)) && (power_of_two > 0))
			{
				//Unset
				input = input ^ (int)pow(2, power_of_two);

				//Set
				input = input ^ (int)pow(2, power_of_two - 1);

				power_of_two = 0; 
			}

			else if (!(input & (int)pow(2, power_of_two + 1)))
			{
				//Unset
				input = input ^ (int)pow(2, power_of_two);

				//Set
				input = input ^ (int)pow(2, power_of_two + 1);

				power_of_two = 0; 
			}

			else
				power_of_two++;  
		}

		else 
			power_of_two++; 

	}while (power_of_two);

	return input; 
}