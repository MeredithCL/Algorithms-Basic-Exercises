#include <bits/stdc++.h>
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
public:
    int result;
    void addx(TreeNode* root, int status)
    {
        if (status == 1 && !root->left && !root->right)
        {
            result += root->val;
            return;
        }
        if (root->left)
        {
            addx(root->left, 1);
        }
        if (root->right)
        {
            addx(root->right, -1);
        }
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        result = 0;
        if (!root)
        {
            return result;
        }
        if (root->left)
        {
            addx(root->left, 1);
        }
        if (root->right)
        {
            addx(root->right, -1);
        }
        return result;
    }
};
