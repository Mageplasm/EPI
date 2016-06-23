/*6.2 Increment an Arbitrary-Precision Integer*/
/*Write a program which takes as input an array of digits encoding
a decimal number D and updates the array to represent the 
number D + 1*/

/*Time complexity: O(n)*/

#include <iostream> 
#include <vector> 

using namespace std;

void increment(vector<int>& num);

int main()
{
	vector<int> num = {8, 9, 7}; 

	increment(num); 

	for (unsigned int i = 0; i < num.size(); i++)
		cout << num[i] << endl; 
}

void increment(vector<int>& num)
{
	int position = num.size() - 1; 

	if (num[num.size() - 1] + 1 != 10)
		num[num.size() - 1]++; 

	else
	{
		int carry = 1; 

		while (position >= 0)
		{
			if (num[position] + carry == 10)
			{
				num[position--] = 0; 
				carry = 1;
			}

			else 
			{
				num[position] += carry; 
				break; 
			} 
		} 

		if (num[0] == 0)
			num.insert(num.begin(), 1); 
	}

}
