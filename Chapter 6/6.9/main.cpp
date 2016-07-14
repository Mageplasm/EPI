/*6.9 Permute the Elements of an Array*/
/*Given an array A of n elements and a permutation P, 
apply P to A*/

#include <iostream>
#include <vector> 

using namespace std;

void apply_permutation(vector<char>& A, vector<int> permutation); 

int main()
{
	vector<int> permutation = {2, 0, 1, 3}; 
	vector<char> A = {'a', 'b', 'c', 'd'}; 

	apply_permutation(A, permutation); 

	for (unsigned int i = 0; i < A.size(); i++)
		cout << A[i] << endl; 

	return 0; 
}

void apply_permutation(vector<char>& A, vector<int> permutation)
{
	vector<char> A_copy = A; 

	for (unsigned int i = 0; i < A.size(); i++)
		A[permutation[i]] = A_copy[i];  
}