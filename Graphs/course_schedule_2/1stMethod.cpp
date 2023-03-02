// problem link -> https://leetcode.com/problems/word-ladder-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginword, string endword, vector<string>& wordlist) {
        vector<vector<string>> ans; // will store the shortest transformation sequence
        queue<vector<string>> q;
        unordered_set<string> s(wordlist.begin(), wordlist.end()); // for searching in constant time

        q.push({beginword});
        int min_size = INT_MAX;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            string word = temp.back();
            s.erase(word);
            int size = temp.size();

            if(size > min_size) break;

            if(word == endword){
                min_size = size;
                ans.push_back(temp);

            }

            

            // need to change the character of the word to find it in the wordlist.
            for(int i=0; i<word.size(); i++){
                char c = word[i];

                for(char chr ='a'; chr<='z'; chr++){
                    if(chr == c) continue;
                    word[i] = chr;
                    if(s.find(word) != s.end()){
                        // it's like we found out another node in the path of transformations to end
                        temp.push_back(word);
                        q.push(temp);
                        temp.pop_back();
                    } 

                    // we cannot delete this word at this point as could be part of another vector.
                }

                // need to get the same WORD back
                word[i] = c; 
            }
        }

        return ans;
        
    }
};