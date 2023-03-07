// problem link -> https://leetcode.com/problems/minimum-time-to-complete-trips/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool total_trips_in_mid(long long mid, int totalTrips, vector<int> &time, int n){

        long long ans = 0;

        for(int i=0; i<n; i++){
            ans += mid/time[i];
            if(ans >= totalTrips) return true;
        }

        return false;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long n = time.size(), ans = 1;
        if(n==1) return (long long)time[0]*totalTrips;
        long long i = 1;
        long long  temp = *max_element(time.begin(), time.end());
        long long  j = 1e14;

        while(i<=j){

            long long mid = i + (j - i)/2;
            if(total_trips_in_mid(mid, totalTrips, time, n)){
                ans = mid;
                j = mid-1;
            }

            else i = mid + 1;

        }

        return ans;
    }
};