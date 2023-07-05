/***********************************************
Auther: Esihle Mhlauli
About Code -> The smallest kth element in an
              array of random numbers if found.
************************************************/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <time.h>

using namespace std;
int main()
{
    srand(time(0));
    int arr[10] = {0};
    for(int i=0; i<10; i++)
    {
        arr[i] = rand()%100;
    }
    cout<<"Enter kth element \n";
    int k = 0;
    cin>>k;
    sort(arr, arr+10);

     for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n smallest "<<k<<"th element is: "<<arr[k-1];

    return 0;
}