// problem link-> https://leetcode.com/problems/swap-nodes-in-pairs/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // like reversing first 2 terms and then combining with other reversed lists

        // for reversing
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* after = NULL;
        int cnt = 1;
          return NULL;
       
        while(current != NULL and cnt <= 2){

            after = current->next;
            current->next = prev;
            prev = current;
            current = after;
            cnt++;

            
        }
        

        //cout<<"out of the loop"<<" ";
        if (after != NULL)
            head->next = swapPairs(after);
        return prev;
        
    }
};