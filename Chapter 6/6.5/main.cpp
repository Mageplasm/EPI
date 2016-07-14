/*6.5 Delete Duplicates From a Sorted Array*/
/*Write a program which takes as input a sorted array
and updates it so that all duplicated have been 
removed and the remaining elements have been shifted
left to fill the emptied indices*/

#include <iostream> 
#include <vector> 

using namespace std; 

void remove_duplicates(vector<int>&); 

int main()
{
	vector<int> A = {-1, -1}; 
	remove_duplicates(A);

	for (unsigned int i = 0; i < A.size(); i++)
		cout << A[i] << endl; 
}

void remove_duplicates(vector<int>& A)
{
	if (A.size() == 0)
		return;

	int last_num = A[0]; 
	int first_zero = -1; 

	for (unsigned int i = 1; i < A.size(); i++)
	{
		if (A[i] == last_num)
		{
			A[i] = 0; 

			if (A[i - 1] != 0)
				first_zero = i; 
		}

		else 
		{
			last_num = A[i]; 

			if (first_zero >= 0) 
			{
				A[i] = A[first_zero]; 
				A[first_zero] = last_num; 
				first_zero = first_zero + 1; 
			}
		}
	}
}
