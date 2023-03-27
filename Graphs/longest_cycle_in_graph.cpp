// problem link -> https://leetcode.com/problems/longest-cycle-in-a-graph/

#include<bits/stdc++.h>
using namespace std;

class Solution {

    int dfs(int node, vector<int> &vis, vector<int> &stack, vector<int> &pos, int no, vector<int> &edges){

        vis[node] = 1;
        stack[node] = 1;
        pos[node] = no;
        int ans = -1;
        int nbr = edges[node];
        if(nbr == -1){
            stack[node] = 0;
            return -1;
        }

        if(stack[nbr] == 1){
            int length = pos[node] - pos[nbr] + 1;
            ans = max(ans, length);
        }

        else if (vis[nbr] == 0){
            int length = dfs(nbr, vis, stack, pos, no+1, edges);
            ans = max(ans, length);
        }

        stack[node] = 0;

        return ans;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n  = edges.size();
        vector<int> vis(n, 0);
        vector<int> stack(n, 0);
        // not visiting a node more than once
        vector<int> pos(n, 0);
        int ans = -1;
        for(int node=0; node<n; node++){
            if(vis[node] == 0){
                ans = max(ans, dfs(node, vis, stack, pos, 1, edges));
            }
        }

        return ans;
    }
};