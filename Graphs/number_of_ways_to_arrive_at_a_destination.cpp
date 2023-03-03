// problem link -> https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9+7;
        vector<long long> min_time(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        vector<vector<pair<int, long long>>> l(n + 1); // {nbr, time}

        for(auto vec : roads){
            l[vec[0]].push_back({vec[1], vec[2]});
            l[vec[1]].push_back({vec[0], vec[2]});
        }

        // it's like finding min_distance but how many ways in which you can arrive with min_distance.

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        min_time[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            auto itr = pq.top();
            pq.pop();
            long long time = itr.first;
            int node = itr.second;

            for(auto temp : l[node]){
                int nbr = temp.first;
                long long new_time = temp.second;

                if(time + new_time > min_time[nbr]) continue;

                if(min_time[nbr] > time + new_time){
                    min_time[nbr] = time + new_time;
                    // ways[nbr] = 1 --> it would be wrong
                    ways[nbr] = ways[node]%mod;
                    pq.push({min_time[nbr], nbr});
                }

                else if(min_time[nbr] == time + new_time){
                    ways[nbr] = (ways[nbr] + ways[node])%mod;
                }
            }
        }

        return ways[n-1];

    }
};
