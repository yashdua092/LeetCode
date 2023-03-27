// problem link -> https://leetcode.com/problems/minimum-path-sum/


#include<bits/stdc++.h>
using namespace std;

class Solution {

    int f(int i, int j, vector<vector<int>>& grid, int m, int n, vector<vector<int>> &dp){

        if(i==m or j==n) return 1e9; // bcz if we have reached i==m-1 and j==n-1 will return so wont reach here.
        if(i==m-1 and j==n-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int sum = grid[i][j];
        int down = sum + f(i+1, j, grid, m, n, dp);
        int right = sum + f(i, j+1, grid, m, n, dp);

        return dp[i][j] = min(down, right);
    }




public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //return f(0, 0, grid, m, n, dp);

        for(int j=0; j<=n; j++){
            dp[m][j] = 1e9;
        }

        for(int i=0; i<=m; i++){
            dp[i][n] = 1e9;
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i==m-1 and j== n-1){
                    dp[m-1][n-1] = grid[m-1][n-1];
                    continue;
                }
                int sum = grid[i][j];
                int down = sum + dp[i+1][j];
                int right = sum + dp[i][j+1];

                dp[i][j] = min(down, right);
            }
        }

        return dp[0][0];
    }
};