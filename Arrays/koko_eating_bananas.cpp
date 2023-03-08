// problem link -> https://leetcode.com/problems/koko-eating-bananas/

#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool can_complete_before_h(int mid, int h, vector<int>& piles){
        // mid here is the speed
        unsigned long long int time = 0;

        for(int i=0; i<piles.size(); i++){
            time += piles[i]/mid;
            if(piles[i]%mid != 0) time += 1;
            if(time > h) return false;
        }

        return true;
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // piles.length <= h <= 109
        // need to search the speed of eating / hour (k) in range 
        int i = 1, j = *max_element(piles.begin(), piles.end()), ans = 1;

        while(i<=j){
            int mid = (i+j)/2;

            if(can_complete_before_h(mid, h, piles)){
                ans = mid;
                j = mid-1;
            }

            else i = mid+1;
        }

        return ans;
    }
};