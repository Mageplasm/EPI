/*Rearrange elements of array such 
that elements in even positions come first*/

#include <iostream> 

using namespace std;

int main()
{
	int array[2] = {1, 2};
	int swaps = 1;
	int temp_index = 0; 

	//Swap every two elements
	for (unsigned int i = 1; i < (sizeof(array)/sizeof(array[0])); i = i + 2)
	{
		int temp = array[i]; 
		array[i] = array[i - 1]; 
		array[i - 1] = temp; 
	}

	//Perform insertion sort for the even positioned elements
	for (unsigned int i = 2; i < (sizeof(array)/sizeof(array[0])) - 1; i = i + 2)
	{ 
		temp_index = i; 

		for (int j = 0; j < swaps; j++)
		{
			int temp = array[temp_index];
			array[temp_index] = array[temp_index - 1]; 
			array[temp_index - 1] = temp;  
			temp_index--; 
		}

		swaps++; 
	}

	for (unsigned int i = 0; i < (sizeof(array)/sizeof(array[0])); i++)
	{
		cout << array[i] << endl; 
	}

	return 0; 
}
