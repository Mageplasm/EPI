/*6.17 Rotate a 2D Array*/
/*Rotate a 2D array by 90 degrees clockwise*/

#include <iostream>
#include <vector> 

using namespace std;

void rotate_array(vector<vector<int> >&); 

int main()
{
	vector<vector<int> > A = {{1, 2, 3, 4, 6, 7},
							  {5, 6, 7, 8, 7, 8},
							  {9, 10, 11, 12, 2, 9},
							  {13, 14, 15, 16, 3, 10},
							  {1, 2, 3, 4, 5, 12},
							  {15, 16, 23, 54, 34, 54}};

	rotate_array(A); 

	for (unsigned int i = 0; i < A.size(); i++)
	{
		for (unsigned int j = 0; j < A[i].size(); j++)
			cout << A[i][j] << " ";

		cout << endl; 
	}

	return 0; 
}

void rotate_array(vector<vector<int> >& A)
{
	int pos1, pos2, temp, temp2; 
	int pos_start = 0, pos_end = A.size();

	//Go through one layer at a time starting
	//from the outer layer, and progressing
	//to the center
	while(pos_end > 1)
	{
		for (int position = pos_start; position < pos_end - 1; position++)
		{
			temp = A[pos_start][position]; 

			//Swap 4 elements at a time
			for (int i = 0; i < 4; i++)
			{
				switch (i)
				{
					case 0: 
						pos1 = position; 
						pos2 = pos_end - 1; 
						break;

					case 1:
						pos1 = pos_end - 1;  
						pos2 = pos_end - (position - pos_start) - 1; 
						break;

					case 2:  
						pos1 = pos_end - (position - pos_start) - 1; 
						pos2 = pos_start;
						break; 

					case 3: 
						pos1 = pos_start; 
						pos2 = position; 
						break; 
				}

				temp2 = A[pos1][pos2];
				A[pos1][pos2] = temp;
				temp = temp2; 
			}
		}

		pos_end--; 
		pos_start++; 
	}
}