// Variation of sliding window
// using 2 for loops
// Input : arr[] = {-8, 2, 3, -6, 10}, k = 2
// Output : -8 0 -6 -6

// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

// Input : arr[] = {12, -1, -7, 8, -15, 30, 16, 28} , k = 3
// Output : -1 -1 -7 -15 -15 0


// C++ implementation to find the first negative
// integer in every window of size k
#include <bits/stdc++.h>
using namespace std;

// function to find the first negative
// integer in every window of size k
void printFirstNegativeInteger(int arr[], int n, int k)
{
	// flag to check whether window contains
	// a negative integer or not
	bool flag;
	
	// Loop for each subarray(window) of size k
	for (int i = 0; i<(n-k+1); i++)		
	{
		flag = false;

		// traverse through the current window
		for (int j = 0; j<k; j++)
		{
			// if a negative integer is found, then
			// it is the first negative integer for
			// current window. Print it, set the flag
			// and break
			if (arr[i+j] < 0)
			{
				cout << arr[i+j] << " ";
				flag = true;
				break;
			}
		}
		
		// if the current window does not
		// contain a negative integer
		if (!flag)
			cout << "0" << " ";
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	printFirstNegativeInteger(arr, n, k);
	return 0;
}
// Time Complexity : The outer loop runs n-k+1 times and the inner loop runs k times for every iteration of outer loop. So time complexity is O((n-k+1)*k) which can also be written as O(nk) when k is comparatively much smaller than n, otherwise when k tends to reach n, complexity becomes O(k). 

// Auxiliary Space: O(1) as it is using constant space for variables
