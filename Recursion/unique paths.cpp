/*63. Unique Paths II
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below)
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.                                     */


class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int dp[m][n];
        
        //for first row 
        int flag=0;
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]==1 || flag==1){
                dp[0][j]=0;
                flag=1;
             }
            else 
                dp[0][j]=1;
            
        }
        
        int flag1=0;
        //for first column 
        for(int i=0;i<m;i++){
           if(flag1==1 ||obstacleGrid[i][0]==1){
               dp[i][0]=0;
               flag1=1;
           } 
            else dp[i][0]=1;
        }
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
            }
        }
        
        return dp[m-1][n-1];
        
        
    }
};






































/*
💗 the first cell i.e. obstacleGrid[0,0] contains 1, this means there is an obstacle in the first cell. Hence the robot won't be able to make any move and we would return the number of ways as 0.


💗otherwise, if obstacleGrid[0,0] has a 0 originally we set it to 1 and move ahead.


💗Iterate the first row. If a cell originally contains a 1, this means the current cell has an obstacle and shouldn't contribute to any path. Hence, set the value of that cell to 0. Otherwise, set it to the value of previous cell i.e. obstacleGrid[i,j] = obstacleGrid[i,j-1]


💗Iterate the first column. If a cell originally contains a 1, this means the current cell has an obstacle and shouldn't contribute to any path. Hence, set the value of that cell to 0. Otherwise, set it to the value of previous cell i.e. obstacleGrid[i,j] = obstacleGrid[i-1,j]


💗Now, iterate through the array starting from cell obstacleGrid[1,1]. If a cell originally doesn't contain any obstacle then the number of ways of reaching that cell would be the sum of number of ways of reaching the cell above it and number of ways of reaching the cell to the left of it.
 obstacleGrid[i,j] = obstacleGrid[i-1,j] + obstacleGrid[i,j-1]
 
 
💗If a cell contains an obstacle set it to 0 and continue. This is done to make sure it doesn't 
contribute to any other path.*/















/*
//recursion--------------------ACCEPTED BUT will give  TLE for large values------------>
class Solution {
public:
    int solve(vector<vector<int>>grid,int m,int n, int i , int j){
        if(i>=m || j>=n || grid[i][j]==1)return 0;
        if(i==m-1 && j==n-1) return 1;
        
        return solve(grid,m,n,i+1,j)+solve(grid,m,n,i,j+1);
        
    }   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        return solve(obstacleGrid, m, n,0,0);
        
    }
};
*/







/*
//RECURSION + MEMOIZATION-------------Accepted-------------------------->
class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>grid,int m,int n, int i , int j){
        if(i>=m || j>=n || grid[i][j]==1)return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(grid,m,n,i+1,j)+solve(grid,m,n,i,j+1);
        
    }   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        dp.resize(m+1, vector<int>(n+1, -1));
        
        return solve(obstacleGrid, m, n,0,0);
        
    }
};



*/








/*

//tech dose💗 ------------Dynamic programming💗 ------O(MN)---------------->
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int dp[rows][cols];
        
        bool flag = false;//💗to check whether the obstacle has appeared before or not 
        //Fill  1st row
        for(int i=0;i<cols;++i)
        {
            if(flag || obstacleGrid[0][i]==1)
            {
                flag = true;
                dp[0][i] = 0;
            }
            else
                dp[0][i] = 1;
        }
        
        //Fill 1st column
        flag = false;
        for(int i=0;i<rows;++i)
        {
            if(flag || obstacleGrid[i][0]==1)
            {
                flag = true;
                dp[i][0] = 0;
            }
            else
                dp[i][0] = 1;
        }
        
        for(int i=1;i<rows;++i)
        {
            for(int j=1;j<cols;++j)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[rows-1][cols-1];
    }
};*/
