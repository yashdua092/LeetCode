// problem link -> https://leetcode.com/problems/kth-missing-positive-number/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int number = 1;
        int count = 0;
        int i = 0;

        while(i<n){

            if(arr[i] != number){
                count++;
                if(count == k) return number;
                number++;
            }
            else{
                // both equal
                i++;
                number++;
            }
        }

        // what if size of array is small and count != k yet
        // if both equal at last-> number++ already so we are at next number
        // if both not equal at last-> count++ not == k yet and number++ already

       return (number - 1) + k - count;
    }
};