#include<bits/stdc++.h>
using namespace std;

int maxPathSumUtil(vector<vector<int>>&mat,int rows, int cols , int colsSize){
    if(cols<0 || cols>colsSize) return INT_MIN;
    if(rows==0) return mat[rows][cols];
    
    int up = mat[rows][cols]+maxPathSumUtil(mat,rows-1,cols,colsSize);
    int diagonalLeft = mat[rows][cols]+maxPathSumUtil(mat,rows-1,cols-1,colsSize);
    int diagonalRight = mat[rows][cols]+maxPathSumUtil(mat,rows-1,cols+1,colsSize);
    return max({up,diagonalLeft,diagonalRight});

}

int maxPathSum(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    int maxSum=INT_MIN;
    for(int j=0;j<m;j++){
        maxSum=max(maxSum,maxPathSumUtil(mat,n-1,j,m));
    }
}
int main(){
    vector<vector<int>>mat={
        {7,2,5},
        {6,2,9},
        {9,5,2}
        };
        int ans=maxPathSum(mat);
        cout<<ans;
    
    return 0;

}