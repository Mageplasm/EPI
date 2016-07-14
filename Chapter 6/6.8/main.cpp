
/*Does not work*/

#include <iostream>
#include <vector> 

using namespace std;

vector<int> enumerate_primes(int); 

int main()
{
	vector<int> result = enumerate_primes(18); 

	for (unsigned int i = 0; i < result.size(); i++)
		cout << result[i] << endl; 

	return 0; 
}

vector<int> enumerate_primes(int num)
{
	vector<int> primes; 

	for (int i = 2; i < num + 1; i++)
	{
		if (i > 3)
		{
			if (i % 2 == 0 || i % 3 == 0)
				continue; 

			else 
				primes.push_back(i); 
		}

		else
			primes.push_back(i); 
	}

	return primes; 
}
