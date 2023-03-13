// problem link -> https://leetcode.com/problems/symmetric-tree/

#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    bool helper(TreeNode* LEFT, TreeNode* RIGHT){

        if(LEFT == NULL and RIGHT == NULL) return true;
        else if ((LEFT != NULL and RIGHT == NULL) or (LEFT == NULL and RIGHT != NULL)) return false;

        bool lleft = helper(LEFT->left, RIGHT->right);
        bool lright = helper(LEFT->right, RIGHT->left);

        if(lleft and lright and LEFT->val == RIGHT->val) return true;
        return false;
    }


public:
    bool isSymmetric(TreeNode* root) {
        // for mirror left->right == right->left and vice versa
        if(root->left == NULL and root->right == NULL) return true;
        return helper(root->left, root->right);
    }
};