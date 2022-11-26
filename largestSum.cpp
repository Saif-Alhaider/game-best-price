
// CPP program to Maximize the sum of selected
// numbers by deleting three consecutive numbers.
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


int maximizeSum(int arr[], int n)
{
 
    // Largest element in the array
    int mx = -1;
    for (int i = 0; i < n; i++) {
        mx = max(mx, arr[i]);
    }
 
    // An array to count the occurrence of each element
    int freq[mx + 1];
 
    memset(freq, 0, sizeof(freq));
 
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
 
    // ans to store the result
    int ans = 0, i = mx;
 
    // Using the above mentioned approach
    while (i > 0) {
 
        // if occurrence is greater than 0
        if (freq[i] > 0) {
            // add it to ans
            ans += i;
 
            // decrease i-1th element by 1
            freq[i - 1]--;
 
            // decrease ith element by 1
            freq[i]--;
        }
        else {
            // decrease i
            i--;
        }
    }
 
    return ans;
}

// Driver code
int main()
{
    int a[] = {10,20,50,100,200,250,300};
    int n = sizeof(a) / sizeof(a[0]);
    cout << maximizeSum(a, n);
    return 0;
}