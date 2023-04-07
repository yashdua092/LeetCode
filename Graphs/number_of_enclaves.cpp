// problem link -> https://leetcode.com/problems/number-of-enclaves/

#include<bits/stdc++.h>
using namespace std;

class Solution {


    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int dx[], int dy[],
    int &m, int &n){
        vis[i][j] = 1;
        for(int k=0; k<4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni>=0 and ni<m and nj>=0 and nj<n and vis[ni][nj] == 0 and grid[ni][nj] == 1)
                dfs(ni, nj, vis, grid, dx, dy, m, n);
        }

        return;
    }


public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int rows=0; rows<m; rows++){
            if(grid[rows][0] == 1) dfs(rows, 0, vis, grid, dx, dy, m, n);
            if(grid[rows][n-1] == 1) dfs(rows, n-1, vis, grid, dx, dy, m, n);
        }
        for(int col=0; col<n; col++){
            if(grid[0][col] == 1) dfs(0, col, vis, grid, dx, dy, m, n);
            if(grid[m-1][col] == 1) dfs(m-1, col, vis, grid, dx, dy, m, n);
        }

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 and vis[i][j] != 1) ans+=1;
            }
        }

        return ans;
    }
};