// problem link -> https://leetcode.com/problems/number-of-closed-islands/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int dx[], int dy[], int m, int n){
        if (grid[i][j] == 1){
            return true;
        }
        vis[i][j] = 1;
        bool island = true;
        for(int k=0; k<4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (!(ni>=0 and ni<m and nj>=0 and nj<n)){
                island = false;
            }
            else if(vis[ni][nj] == 0){
                island &= dfs(ni, nj, vis, grid, dx, dy, m, n); 
            }
        }
        return island;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count=0;
        vector<vector<int>> vis(m, vector<int>(n , 0));
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0 and vis[i][j] == 0){
                    bool island = dfs(i, j, vis, grid, dx, dy, m, n);
                    if(island) count++;
                }
            }
        }
        return count;
    }
};