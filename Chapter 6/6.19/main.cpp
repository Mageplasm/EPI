#include <iostream>
#include <vector> 

using namespace std;

vector<vector<int> > generate_pascals_triangle(int n); 

int main()
{
	vector<vector<int> > triangle = generate_pascals_triangle(5); 

	for (unsigned int i = 0; i < triangle.size(); i++)
	{
		for (unsigned int j = 0; j < triangle[i].size(); j++)
			cout << triangle[i][j] << " "; 

		cout << endl; 
	}

	return 0; 
}

vector<vector<int> > generate_pascals_triangle(int n)
{
	vector<vector<int> > triangle = {}; 

	for (int i = 0; i < n; i++)
	{
		vector<int> row = {}; 

		if (triangle.empty())
			row.push_back(1); 

		else
		{
			row.push_back(1); 

			for (unsigned int j = 0; j < triangle[i - 1].size() - 1; j++)
			{
				int sum = triangle[i - 1][j] + triangle[i - 1][j + 1]; 
				row.push_back(sum); 
			}

			row.push_back(1); 
		}

		triangle.push_back(row); 
	}

	return triangle; 
}