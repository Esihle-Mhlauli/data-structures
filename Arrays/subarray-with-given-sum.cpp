/***********************************************
Auther: Esihle Mhlauli
About Code -> Find the starting and ending index
              of the subarray that gives a sum
              of the randomly generated sum.
************************************************/
#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

vector<int> subArrayFunc(vector<int>arr, int sum){
    int subsum = 0;
    vector<int>subarray;
    bool found = false;
    for(int i=0; i<arr.size(); i++){
        for(int j=i; j<arr.size(); j++){
            subsum +=arr.at(j);
            if(subsum==sum){
                subarray.push_back(i);
                subarray.push_back(j);
                found = true;
                return subarray;
            }
        }
        subsum = 0;
    }
    subarray.push_back(-1);
    return subarray;
}

int main()
{
    srand(time(0));
    vector<int>arr;
    vector<int>output;
    int size = rand()%10;
    int sum = rand()%10;
    for(int i=0; i<size; i++){
        arr.push_back(rand()%10);
    }
    output = subArrayFunc(arr,sum);
    for(int i=0; i<output.size(); i++)
    {
        cout<<output.at(i)<<" ";
    }
    return 0;
}