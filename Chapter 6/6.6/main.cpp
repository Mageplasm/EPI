/*6.6 Buy and Sell a Stock Once*/
/*Write a program that takes an array denoting the 
daily stock price, and returns the maximum profit 
that could be made by buying and then selling 
one share of the stock.*/
#include <iostream>
#include <vector> 

using namespace std;

int maximum_profit(vector<int>); 

int main()
{
	vector<int> A = {310, 360, 330, 300}; 

	cout << maximum_profit(A) << endl; 
	return 0; 
}

int maximum_profit(vector<int> A)
{
	if (A.size() == 0)
		return 0; 

	int lowest_num = A[0]; 
	int max_profit = 0; 

	for (unsigned int i = 1; i < A.size(); i++)
	{
		if (A[i] <= lowest_num)
			lowest_num = A[i]; 

		else
		{
			if (A[i] - lowest_num > max_profit)
				max_profit = A[i] - lowest_num; 
		}
	}

	return max_profit; 
}

