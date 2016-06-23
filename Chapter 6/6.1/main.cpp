/*Dutch Flag Problem*/
/*Write a program that takes an array A and 
an index i into A, and rearranges the elements 
such that all elements less than A[i] appear first, 
followed by elements equal to the pivot, followed
by elements greater than the pivot*/

#include <iostream> 
#include <vector> 

using namespace std;

int reorder_pass1(vector<int>&, int i);
void reorder_pass2(vector<int>&, int i); 
void swap (vector<int>& arr, int top, int bottom);

int main()
{
	vector<int> arr = {1, 5, 6, -3, 10, -1, 2, 3, 10, 8};

	int i = reorder_pass1(arr, 3); 

	reorder_pass2(arr, i); 

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl; 
	}

	return 0; 
}

int reorder_pass1(vector<int>& arr, int i)
{
	int pivot = arr[i];

	int bottom = i - 1; 
	int top = i + 1; 

	while (bottom >= 0 && top < arr.size())
	{
		while (arr[bottom] < pivot || arr[bottom] == pivot)
			bottom--; 

		while ((arr[top] > pivot || arr[top] == pivot) && top < arr.size())
		{
			top++; 
		}

		if(bottom >= 0 && top < arr.size())
			swap(arr, top, bottom); 
	}


	if (bottom < 0)
	{
		while (top < arr.size())
		{
			while (arr[top] > pivot || arr[top] == pivot)
				top++;

			if (top < arr.size())
			{
				if (top != (i + 1))
				{
					swap(arr, top, i + 1); 
					swap(arr, i + 1, i);
					i = i + 1;  
				}

				else
				{
					swap(arr, top, i); 
					i = i + 1; 
				}
			}
		}
	}

	else if (top >= arr.size())
	{
		while (bottom >= 0)
		{
			while (arr[bottom] < pivot || arr[bottom] == pivot)
				bottom--; 

			if (bottom >= 0)
			{
				if (bottom != (i - 1))
				{
					swap(arr, bottom, i - 1); 
					swap(arr, i - 1, i);
					i = i - 1;  
				}

				else
				{
					swap(arr, bottom, i); 
					i = i - 1; 
				}
			}
		}
	}

	return i; 
}

void reorder_pass2(vector<int>& arr, int i)
{
	int pivot = arr[i]; 
	int bottom = i - 1; 
	int top = i + 1; 

	for (int j = 0; j < arr.size(); j++)
	{
		//Two cases: j > i and j < i
		if (arr[j] == pivot && j != i)
		{
			if (j > i + 1)
			{
				while (arr[top] == pivot)
					top++; 

				swap(arr, j, top);
			}

			else if (j < i - 1)
			{
				while (arr[bottom] == pivot)
					bottom--; 

				swap(arr, j, bottom); 
			}

			else
				continue;
		}	
	}
}

void swap(vector<int>& arr, int top, int bottom)
{
	int temp = arr[top]; 
	arr[top] = arr[bottom]; 
	arr[bottom] = temp; 
}