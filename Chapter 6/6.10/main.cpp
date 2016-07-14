/*6.10 Compute the Next Permutation*/
/*Write a program that takes as input a permutation
, and returns the next permutation under dictionary 
ordering*/

#include <iostream>
#include <vector> 

using namespace std;

vector<int> next_permutation(vector<int>); 

int main()
{
	vector<int> A = {6, 6, 2, 7, 2}; 
	A = next_permutation(A); 

	for (unsigned int i = 0; i < A.size(); i++)
		cout << A[i] << endl; 

	return 0; 
}

vector<int> next_permutation(vector<int> A)
{ 
	int swap1 = -1, swap2 = -1; 

	//Find the first number that is less than the 
	//number to its right, search starting from the end
	//of the array
	for (unsigned int i = A.size() - 1; i > 0; --i)
	{
		if (A[i - 1] < A[i])
		{
			swap1 = i - 1;
			break; 
		}
	}

	if (swap1 == -1)
	{
		vector<int> A = {};
		return A; 
	} 

	else 
	{
		//Swap "swap1" with the smallest number greater than it in 
		//the prefix array 
		for (unsigned int i = A.size() - 1; i > swap1; --i)
		{
			if (A[i] > A[swap1])
			{
				swap2 = i;
				break;
			} 
		}

		int temp = A[swap1]; 
		A[swap1] = A[swap2]; 
		A[swap2] = temp; 

		//Sort the prefix array
		for (int i = swap1 + 2; i < A.size(); i++)
		{
			int temp_i = i; 
			
			for (int j = i - 1; j > swap1; --j)
			{
				if (A[j] > A[temp_i])
				{
					//swap
					int temp = A[temp_i]; 
					A[temp_i] = A[j]; 
					A[j] = temp;
					--temp_i; 
				}
			}
		}
	}

	return A; 
}
