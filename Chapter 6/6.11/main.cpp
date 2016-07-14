/*6.11 Sample Offline Data*/
/*Implement an algorithm that takes as input 
an array of distinct elements and a size, and
returns a subset of the given size of the array 
elements*/

#include <iostream>
#include <vector> 
#include <cstdlib>
#include <random>
#include <time.h>

using namespace std;

vector<int> construct_subset(vector<int> input, int size); 

int main()
{
	vector<int> A = {1, 2, 3};
	vector<int> subset = construct_subset(A, 2);

	for (unsigned int i = 0; i < subset.size(); i++)
		cout << subset[i] << endl;

	return 0; 
}

vector<int> construct_subset(vector<int> input, int size)
{
	int random_num = -1; 
	vector<int> subset = {};
	srand(time(NULL)); 

	for (int i = 0; i < size; i++)
	{
		random_num = rand() % input.size();
		subset.push_back(input[random_num]);
		input.erase(input.begin() + random_num);
	}	

	return subset; 
}
