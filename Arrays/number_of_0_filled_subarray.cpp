// problem link -> https://leetcode.com/problems/number-of-zero-filled-subarrays/

#include<iostream>
#include<vector>              
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // if zeros continuous
        // 1st zero -> 1
        // 2nd zero -> 1 + 1
        // 3rd zero -> 1 + 1 + 1 and so on

        int zeros = 0;
        long long ans = 0;
        for(int itr : nums){
            if(itr == 0){
                zeros += 1;
                ans += zeros;
            }
            else zeros = 0;
        }

        return ans;
    }
};