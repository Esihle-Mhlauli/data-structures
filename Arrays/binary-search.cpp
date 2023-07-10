/***********************************************
Auther: Esihle Mhlauli
About Code -> Find given element using
              binary search.
************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <array>
 
using namespace std;

int findKey(int arr[], int n, int key)
{
    int first = 0;
    
    int last = n-1;

    while (first<= last) {
        int middle = (last - first) / 2;
 
        // Check if key == middle
        if (arr[middle] == key)
            return middle;
 
        //if middle is smaller than key,ignore LHS
        if (arr[middle] < key)
            first= middle + 1;

        //if middle is greater than key,ignore RHS
        else   
            last = middle - 1;  
    }
 
    return -1;
}
 
int main()
{
    int arr[] = { 1, 5, 4, 7, 3};  //random array  
    int n = sizeof(arr) / sizeof(arr[0]);
    int key  = 0;
    cout<<"Enter key to find \n";
    cin>>key;

    sort(arr, arr+n); //Because binary search works on sorted arrays/vectors

    int result = findKey(arr, n, key);

    if(result == -1){
        cout<<"Key not found";
    }
    else{
        cout<<"Key found at index: "<<result;
    }
    return 0;
}