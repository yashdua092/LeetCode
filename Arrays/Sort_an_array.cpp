// problem link-> https://leetcode.com/problems/sort-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {


    void sorted_merge(int s, int e, int mid, vector<int>&nums){
        // we need to store s as after getting sorted array we need to copy temp elements into nums
        // not necessary that s will start from zero only as could be subpart of array as well 
        // like s=3 and e=6
        
        int i=s, j=mid+1;
        vector<int> temp;
        while(i<=mid and j<=e){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);

            }
        }

        while(i<=mid){
            temp.push_back(nums[i++]);
        }

        while(j<=e){
            temp.push_back(nums[j++]);
        }

        int k=0;
        for(int itr=s; itr<=e; itr++){
            nums[itr] = temp[k++];
        }
    }


    void merge(int s, int e, vector<int> &nums){
        if(s>=e) return;

        int mid = (s+e)/2;
        merge(s, mid, nums);
        merge(mid+1, e, nums);

        return sorted_merge(s, e, mid, nums);
    }


public:
    vector<int> sortArray(vector<int>& nums) {
        int s=0;
        int e=nums.size() - 1;
        merge(s, e, nums);
        return nums;
    }
};