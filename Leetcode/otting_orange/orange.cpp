// leetcode: https://leetcode-cn.com/problems/rotting-oranges/
#include <iostream>
#include <vector>

using namespace std;
int main() {
    // construct the input
    int arr[3][3] = {{2,1,1},{1,1,0}, {0,1,1}};
    vector<vector<int>> a(3,vector<int>(3,0));
    for(int i=0; i< 3; i++){
        for(int j=0;j<3;j++){
            a[i][j] = arr[i][j];
        }
    }


    int row = a.size();
    int col = a[0].size();

    int count_N =0;
    bool ToDone = true;
    while(ToDone){
        int time_N=0;
        count_N++;
        vector<vector<int>> tmp;
        tmp.assign(a.begin(),a.end());
        for(int i=0; i<row; i++){
            for(int j=0; j< col;j++){
                if(a[i][j] == 1){
                    time_N++;
                    if((a[max(0,i-1)][j] == 2) || (a[min(row-1,i+1)][j] ==2) || (a[i][max(0,j-1)] == 2) || (a[i][max(col-1,j+1)] == 2) ){
                        tmp[i][j] = 2;
                    }
                }
            }
        }
        if(time_N==0){
            break;
        }
        a.assign(tmp.begin(),tmp.end());
    }
    cout  << count_N-1  << endl;

    return 0;
}