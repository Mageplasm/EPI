/*6.7 Buy and sell a stock twice*/
/*Does not work*/

#include <iostream>
#include <vector> 

using namespace std;

int maximum_profit(vector<int>); 

int main()
{
	vector<int> A = {2, 30, 15, 10, 8, 25, 80}; 
	cout << maximum_profit(A) << endl; 
	return 0; 
}

int maximum_profit(vector<int> A)
{
	if (A.size() == 0)
		return 0; 

	int lowest_num = A[0]; 
	bool new_lowest_num = true; 
	int max_profit1 = 0, max_profit2 = 0;  
	int prev_lowest_num; 
	bool max_profit2_changed = false, max_profit1_changed = false; 

	for (unsigned int i = 1; i < A.size(); i++)
	{
		if (A[i] <= lowest_num)
		{
			lowest_num = A[i]; 
			new_lowest_num = true; 
		}

		else
		{
			if (new_lowest_num)
			{
				if ((A[i] - lowest_num > max_profit1) && (A[i] - lowest_num - max_profit1 >= A[i] - lowest_num - max_profit2))
				{
					max_profit1 = A[i] - lowest_num;
					max_profit1_changed = true; 
					max_profit2_changed = false; 
				} 

				else if ((A[i] - lowest_num > max_profit2) && (A[i] - lowest_num - max_profit2 >= A[i] - lowest_num - max_profit1))
				{
					max_profit2 = A[i] - lowest_num;
					max_profit2_changed = true; 
					max_profit1_changed = false; 
				} 

				new_lowest_num = false; 
			}

			else 
			{
				if (max_profit2 > 0 && max_profit2_changed)
				{
					if (A[i] - lowest_num > max_profit2)
						max_profit2 = A[i] - lowest_num; 
				}

				else if (max_profit1 > 0 && max_profit1_changed)
				{
					if (A[i] - lowest_num > max_profit1)
						max_profit1 = A[i] - lowest_num;
				}
			}

			cout << "Max profit1: " << max_profit1 << endl; 
			cout << "Max profit2: " << max_profit2 << endl; 
		}
	}

	return max_profit1 + max_profit2; 
}
