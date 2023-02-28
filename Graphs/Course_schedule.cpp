// Problem Link - https://leetcode.com/problems/course-schedule/

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // need to create graph first
        // completing all courses in the sense all nodes are visited
        vector<int> dependencies(numCourses, 0);
        queue<int> q;
        vector<vector<int>> l(numCourses, vector<int>());
        for(auto itr : prerequisites){
            l[itr[1]].push_back(itr[0]);
            dependencies[itr[0]]++;
        }
         for(int i=0; i<numCourses; i++){
             if(dependencies[i] == 0) q.push(i);
         }

         while(!q.empty()){
             int course = q.front();
             q.pop();

             for(auto sub : l[course]){
                 dependencies[sub]--;
                 if(dependencies[sub]==0) q.push(sub);
             }
         }

         for(int i=0; i<numCourses; i++){
             if(dependencies[i] != 0) return false;
         }

         return true;
    }
};