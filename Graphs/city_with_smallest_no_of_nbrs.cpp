// problem link-> https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        // as need to get dist of every city from every city floyd warshall will be used.
        vector<int> temp(n, 0);

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto edge : edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for(int i=0; i<n; i++) dist[i][i] = 0;

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];

                        // if(dist[i][j] <= threshold){
                        //     temp[i]++;
                        // }

                        // we cannot do this as if initially less and gets updated
                        // ans will keep on adding but we need final min distance
                        // and need to compare with threshold
                    }  
                }
            }
        }

        // need t0 traverse each city and return the ans;
        int city_no=0; int probable_cities = n;
        for(int city = 0; city < n; city++){
            int cnt = 0;
            for(int nbr = 0; nbr<n; nbr++){
                if(dist[city][nbr] <= threshold){
                    cnt++;
                }
            }

            // calculated for a particular city.
            if(cnt <= probable_cities){
                probable_cities = cnt;
                city_no = city;
            }
        }

        return city_no;
    }
};