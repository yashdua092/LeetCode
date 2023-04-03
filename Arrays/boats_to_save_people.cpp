// problem link -> https://leetcode.com/problems/boats-to-save-people/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater());
        int s=0, e=people.size()-1, boats=0;
        while(s<e){
            if(people[s] + people[e] <= limit){
                boats+=1;
                s+=1; e-=1;
            }

            else{
                boats+=1;
                s+=1;
            }
        }

        if(s==e) boats+=1;

        return boats;
    }
};