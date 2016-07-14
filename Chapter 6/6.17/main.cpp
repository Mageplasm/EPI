/*6.17 Compute the Spiral Ordering of a 2D Array*/

#include <iostream>
#include <vector> 

using namespace std;

vector<int> compute_spiral_ordering(vector<vector<int> >); 

int main()
{
	vector<vector<int> > A = {{1, 2, 3, 4, 6},
							  {5, 6, 7, 8, 7},
							  {9, 10, 11, 12, 8},
							  {13, 14, 15, 16, 10},
							  {9, 10, 11, 12, 8}};

	vector<int> spiral_ordering = compute_spiral_ordering(A); 
	
	for (unsigned int i = 0; i < spiral_ordering.size(); i++)
		cout << spiral_ordering[i] << endl; 

	return 0; 
}

vector<int> compute_spiral_ordering(vector<vector<int> > A)
{
	//Set our boundaries for searching 
	int row_limit = A.size(), column_limit = A[0].size(); 
	int column_start = 0, row_start = 0, top, right, bottom, left;  
	vector<int> spiral_ordering = {}; 
	
	while(column_limit > 1 && row_limit > 1)
	{
		//Top edge
		for (top = column_start; top < column_limit; top++)
			spiral_ordering.push_back(A[row_start][top]); 
		
		//Right edge
		for (right = row_start + 1; right < row_limit; right++)
			spiral_ordering.push_back(A[right][top - 1]); 

		//Bottom edge
		for (bottom = top - 2; bottom >= column_start; bottom--)
			spiral_ordering.push_back(A[right - 1][bottom]); 

		//Left edge
		for (left = right - 2; left > row_start; left--)
			spiral_ordering.push_back(A[left][bottom + 1]); 

		column_start++; 
		row_start++; 
		column_limit--; 
		row_limit--; 
	}

	return spiral_ordering; 
}
