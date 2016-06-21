/*Swap Bits*/
/*Implement code that takes as input a 64-bit 
integer and swaps the bits at indices i and j*/

#include <iostream> 

using namespace std; 

long swap (long input, int i, int j); 

int main()
{
    long input; 
    int i, j;

    cout << "Enter the input value you want changed: ";
    cin >> input; 

    cout << "Enter the first index in the swap: ";
    cin >> i; 

    cout << "Enter the second index in the swap: ";
    cin >> j;  

    input = swap (input, i, j);

    cout << "Swapped Value: " << input << endl;  
}

long swap (long input, int i, int j)
{
    int bit_i = (input >> i) & 1; 
    int bit_j = (input >> j) & 1; 

    if (bit_i == bit_j)
        return input; 

    long change_i = 1 << i;
    long change_j = 1 << j;  

    if (bit_i)
    {
        input ^= change_i; 
        input |= change_j; 
    }

    else
    {
        input |= change_i; 
        input ^= change_j; 
    }

    return input; 
}

