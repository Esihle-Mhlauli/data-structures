#include <iostream>
#include <vector>

using namespace std;

int hourglassSum(int arr[6][6]) {
    int n = 6;
    int max = 0;
    int center = 0;
    int bottom = 0;
    int top = 0;

    vector<int>sums;
    
    for (int row = 0; row<(n-2); row++){
        for(int col=0; col<(n-2); col++){
            center = arr[row+1][col+1];
            top = arr[row][col]+arr[row][col+1]+arr[row][col+2];
            bottom = arr[row+2][col]+arr[row+2][col+1]+arr[row+2][col+2];
            sums.push_back(center+top+bottom);
        }
        
    }

    for(int i=0; i<n; i++){
        if(sums.at(i)>max){
            max = sums.at(i);
        }
    }
   return max; 
}

int main()
{

    int arr[6][6];

    for (int i = 0; i < 6; i++) {

        int arr_row_temp_temp;

        for (int j = 0; j < 6; j++) {
            cin>> arr_row_temp_temp;

            arr[i][j] = arr_row_temp_temp;
        }
    }

    int result = hourglassSum(arr);

    return 0;
}





