#include <iostream>
#include <vector>

using namespace std;

vector<int> fibonacci_(int n, int prev, int curr, vector<int> fib){

    int temp = 0;
    for(int i = 0; i<n; i++){
        if(i==0){
            fib.push_back(prev);
        }else if(i==1){
            fib.push_back(curr);
        }
        else{
            temp = curr;
            curr = prev+curr;
            prev = temp;
            fib.push_back(curr);
        }
    }

    return fib;
}
int main(){

    int prev = 0;
    int curr = 1;
    int n = 10;
    vector<int> fib;

    fib = fibonacci_(n,prev,curr, fib);

    for(int i = 0; i<n; i++){
        cout<<fib.at(i)<<" ";
    }
    return 0;
}