/*6.16 The Sudoku Checker Problem*/
/*Check whether a 9 X 9 2D array representing
a partially completed Sudoku is valid.*/

#include <iostream>
#include <vector> 

using namespace std;

bool check_if_valid_puzzle(vector<vector<int> >);

int main()
{
	vector<vector<int> > puzzle = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
							       {6, 0, 0, 1, 9, 5, 0, 0, 0},
								   {0, 9, 8, 0, 0, 0, 0, 6, 0},
								   {8, 0, 0, 0, 6, 0, 0, 0, 3},
								   {4, 0, 0, 8, 0, 3, 0, 0, 1},
								   {7, 0, 0, 0, 2, 0, 0, 0, 6}, 
								   {0, 6, 0, 0, 0, 0, 2, 8, 0}, 
								   {0, 0, 0, 4, 1, 9, 0, 0, 5}, 
								   {0, 0, 0, 0, 8, 0, 0, 7, 9}}; 

	cout << check_if_valid_puzzle(puzzle) << endl; 
	return 0; 
}

bool check_if_valid_puzzle(vector<vector<int> > puzzle)
{
	bool valid = true; 

	for (unsigned int row = 0; row < puzzle.size(); row++)
	{
		for (unsigned int column = 0; column < puzzle[row].size(); column++)
		{
			if (puzzle[row][column] > 0)
			{
				//Iterate through the row and columns
				for (int temp_row = 0; temp_row < puzzle.size(); temp_row++)
				{
					if (temp_row == row)
						continue;

					if (puzzle[temp_row][column] == puzzle[row][column])
						return false; 
				}  

				for (int temp_column = 0; temp_column < puzzle[row].size(); temp_column++)
				{
					if (temp_column == column)
						continue;

					if (puzzle[row][temp_column] == puzzle[row][column])
						return false; 
				} 

				for (int temp_row = row - (row % 3); temp_row < (row - (row % 3)) + 3; temp_row++)
				{
					for (int temp_column = column - (column % 3); temp_column < (column - (column % 3)) + 3; temp_column++)
					{
						if (temp_column == column || temp_row == row)
							continue; 

						if (puzzle[temp_row][temp_column] == puzzle[row][column])
							return false; 
					}
				}
			}
		}
	}

	return valid; 
}



