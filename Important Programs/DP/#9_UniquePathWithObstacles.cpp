#include<bits/stdc++.h>
using namespace std;

int uniquePathWithObstacles(vector<vector<int>>& matrix , int rows , int cols){
    if(rows==0 && cols==0){
        return 1;
    }
    if(rows<0 || cols<0)return 0;
    if(matrix[rows][cols]==-1)return 0;
    int up=uniquePathWithObstacles(matrix,rows-1,cols);
    int left=uniquePathWithObstacles(matrix,rows,cols-1);
    return up+left;
}

int uniquePathObstaclesTabulation(vector<vector<int>>& matrix , int rows , int cols , vector<vector<int>>& dp){
    if(matrix[rows-1][cols-1]==-1 || matrix[0][0]==-1)return 0;
    
    for (int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
             if(i>0 && j>0 && matrix[i][j]==-1){
                dp[i][j]=0;
            }
            else{
                if(i==0 && j==0){
                dp[i][j]=1;
            }
            if(i>0){
                dp[i][j]+=dp[i-1][j];
            }
            if(j>0){
                dp[i][j]+=dp[i][j-1];
            }
            }
            
        }
    }
    return dp[rows-1][cols-1];
}

int main(){
    vector<vector<int>>matrix={
        {0,0,-1},
        {0,0,0},
        {0,0,0}
    };

    int ans=uniquePathWithObstacles(matrix,2,2);
    cout<<ans;
    return 0;
    

}
