// problem link -> https://leetcode.com/problems/linked-list-cycle-ii/


#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;

        ListNode* slow = head, * temp = head, * fast = head;

        while(fast->next != NULL and fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                while(slow != temp){
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp;
            }
        }

        return NULL;
    }
};