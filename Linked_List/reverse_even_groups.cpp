// problem link-> https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

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

    ListNode* helper(ListNode* head, int k){
        if(head == NULL) return head;
        // for last group we don't know how many nodes there
        int count = 0;
        ListNode* temp = head, *last_node = temp;
        for(int i=1; i<=k; i++){
            if(temp == NULL) break;
            last_node = temp;
            temp = temp->next;
            count++;
        }

        if(count % 2 != 0){
            // no need to reverse the list
            last_node->next =  helper(temp, k+1);
            return head;
        }

        ListNode* current = head, *prev = NULL, *after = NULL;
        int new_count = 1;

        while(current != NULL and new_count <= k){
            after = current->next;
            current->next = prev;
            prev = current;
            current = after;
            new_count++;
        }

        if(after != NULL){
            // not the end of the list
            head->next = helper(after, k+1);
        }
        return prev;
    }



public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        return helper(head, 1);
    }
};