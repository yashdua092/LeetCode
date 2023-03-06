// problem link -> https://leetcode.com/problems/jump-game-iv/description/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minJumps(vector<int>& arr) {
        // will use bfs to find shortest distance or min jumps to reach n-1 index
        int n = arr.size();
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        unordered_map<int , vector<int>> m;
        for(int i=0;i<n; i++){
            m[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        int count = 0;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            // cout << i << " ";
            if(i == n-1) break;
            if(i-1>=0 and dist[i-1] == 1e9){
                dist[i-1] = dist[i] + 1;
                q.push(i-1);
            }
            if(i+1<=n and dist[i+1] ==1e9){
                dist[i+1] = dist[i] + 1;
                q.push(i+1);
            }
            for(int adj : m[arr[i]]){
                if(dist[adj] == 1e9){
                    dist[adj] = dist[i] + 1;
                    q.push(adj);
                }
            }
            m.erase(arr[i]); // help to decrease time complexity
        }

        return dist[n-1];

    }
};