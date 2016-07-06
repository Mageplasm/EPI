/*6.3 Multiply Two Arbirtrary Position Integers*/
/*Write a program which takes two arrays representing
integers, and returns an integer representing their product*/

#include <iostream> 
#include <vector> 

using namespace std;

vector<int> multiply(vector<int> first_num, vector<int> second_num); 
vector<int> add(vector<int> first_num, vector<int> second_num); 

int main()
{
	vector<int> first_num = {1, 9, 3, 7, 0, 7, 7, 2, 1}; 
	vector<int> second_num = {-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7}; 

	vector<int> result = multiply(first_num, second_num);

	if (result[0] == 0)
		result = {0}; 

	for (unsigned int i = 0; i < result.size(); i++)
		cout << result[i];  

	cout << endl;
}

vector<int> multiply(vector<int> first_num, vector<int> second_num)
{
	vector<int> more_digits_num; 
	bool negative = false; 

	if ((first_num[0] < 0) != (second_num[0] < 0))
		negative = true; 

	if (first_num[0] < 0)
		first_num[0] *= -1; 

	if (second_num[0] < 0)
		second_num[0] *= -1; 

	if (first_num.size() < second_num.size())
	{
		more_digits_num  = second_num;
		second_num = first_num; 
		first_num = more_digits_num;
	}

	vector<int> sum = {0}; 
	vector<int> current_num = {}; 
	int digit, zeros = 0, carry = 0; 

	for (int i = second_num.size() - 1; i >= 0; i--)
	{
		current_num = {};

		for (int i = 0; i < zeros; i++)
			current_num.push_back(0);

		for (int j = first_num.size() - 1; j >= 0; j--)
		{
			digit = second_num[i] * first_num[j] + carry;

			if (digit > 9)
			{
				current_num.insert(current_num.begin(), digit % 10); 

				if (j != 0)
					carry = (digit / 10);

				else
					current_num.insert(current_num.begin(), digit / 10); 
			}

			else
			{
				current_num.insert(current_num.begin(), digit);
				carry = 0; 
			}  
		}

		carry = 0; 
		zeros++; 
		sum = add(sum, current_num); 
	}

	if (negative)
		sum[0] *= -1; 

	return sum; 
}

vector<int> add(vector<int> first_num, vector<int> second_num)
{
	for (int i = first_num.size() - 1, j = second_num.size() - 1; i >= 0; i--, j--)
	{
		second_num[j] += first_num[i];

		if (second_num[j] > 9)
		{
			second_num[j] -= 10; 

			if (j > 0)
				second_num[j - 1] = second_num[j - 1] + 1; 

			else
				second_num.insert(second_num.begin(), 1);  
		} 
	} 
		
	return second_num; 
}