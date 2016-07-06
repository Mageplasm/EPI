/*6.4 Advancing Through an Array*/
/*Write a program which takes an array of n intergers
, where A[i] denotes the maximum you can advance from 
index i, and returns whether it is possible to advance
to the last index from the beginning of the array*/
/*Time complexity: O(n^2)*/

#include <iostream> 
#include <vector> 

using namespace std;

bool advance(vector<int>); 

int main()
{
	vector<int> A = {3, 2, 0, 0, 2, 0, 1}; 
	cout << advance(A) << endl; 
	return 0; 
}

bool advance(vector<int> A)
{
	vector<int> steps, position; 
	int new_pos, step_pos; 
	bool end = false; 

	cout << A.size() << endl; 

	for (int i = 0; i < A.size() - 1;)
	{
		steps.push_back(A[i]);
		position.push_back(i);  

		while (steps.size() != 0)
		{
			step_pos = steps.size() - 1; 

			if (steps[step_pos] == 0)
			{
				steps.pop_back(); 
				position.pop_back(); 
				continue;
			}

			cout << "Step: " << steps[step_pos] << endl;

			new_pos = steps[step_pos] + position[step_pos];
			cout << "New_pos: " << new_pos << endl; 
			steps[step_pos]--; 

			if (new_pos >= A.size() - 1)
			{
				end = true; 
				break; 
			}

			if (A[new_pos] < 1)
				continue;

			else
			{
				i = new_pos;
				break;
			}	   
		}

		if (end)
			return end; 

		if (steps.size() == 0)
		{
			end = false; 
			return end; 
		}
	}

	return end; 
}
